# Born2BeRoot

## 1. make a virtual machine

**What's a virtual machine?**

A virtual machine is a way to emulate a functioning computer through software

(Note: set network adapter to `bridged adapter`)

## 2. Install Debian

**Why Debian?**

Debian is a community-based distro (unlike Rocky Linux which is designed for enterprises) and because of that, it is much easier to install Debian than Rocky Linux.

### Install requirements

Use guided-encrypted partitioning

**Hostname:** username42
**Password:** [password]

## Post-install

**Install:** sudo git curl

Add user to sudo group: `usermod -aG sudo vbraband`

Check if user is in group: `getent group sudo`

Add user to `sudoers` file: `sudo visudo`

add `vbraband ALL=(ALL) ALL`

### SSH setup

`sudo apt install openssh-server`

`sudo systemctl status ssh`

`sudo nano /etc/ssh/sshd_config`

Change `#Port22` to `Port 4242`

`sudo service ssh restart`

`sudo service sshd status`

### Install UFW

`sudo apt install ufw net-tools` installs ufw and net-tools (net-tools to test for IP adresse)

`sudo ufw enable`

`sudo ufw status numbered`

`sudo ufw allow ssh`

`sudo ufw allow 4242`

`sudo ufw status numbered`

`ip a`

### Connect to the virtual machine from host

From host: `ssh vbraband@[IP-Adress] -p 4242`

### Setting password policy

`sudo apt-get install libpam-pwquality`

`sudo nano /etc/pam.d/common-password`

Find `password requisite`

Then add `password requisite pam_pwquality.so retry=3 minlen=10 ucredit=-1 lcredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root`

`sudo nano /etc/login.defs`

Find `PASS_MAX_DAYS 9999` & `PASS_MIN_DAYS 0`

Change them too `PASS_MAX_DAYS 30` and `PASS_MIN_DAYS 2`

Then `sudo reboot`

### Creating groups

`sudo groupadd user42` to create a group

`sudo groupadd evaluating` to create a group for evaluators

`getent group` check if the groups has been created

### Creating users

Check all local users `cut -d: -f1 /etc/passwd`

`sudo adduser new_username` to create new user

to add user to group `sudo usermod -aG user42 your_username`

to add evaluating user `sudo usermod -aG evaluating new_username`

check if users is in groups `getent group [group name]`

`groups`

Check if password policy is working `chage -l new_username`

### sudo.log file

`cd ~/../../` go to root

`cd var/log`

`mkdir sudo`

`cd sudo && touch sudo.log`

`cd ~/../`

Configuring `sudoers` group again

find these and edit them to:
```
Defaults env_reset
Defaults mail_badpass
Defaults secure_path="/usr/local/sbin:/usr/local/bin:/usr/bin:/sbin:/bin"
Defaults badpass_message="Password is wrong, please try again!"
Defaults passwd_tries=3
Defaults logfile="/var/log/sudo/sudo.log"
Defaults log_input, log_output
Defaults requiretty
```

### Monitoring.sh

`cd /usr/local/bin/` go to directory

`touch monitoring.sh` make the monitoring script

 `chmod 777 monitoring.sh` change the permissions of the file

 Somehow copy this script into the file:
```
 #!/bin/bash
arc=$(uname -a)
pcpu=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l) 
vcpu=$(grep "^processor" /proc/cpuinfo | wc -l)
fram=$(free -m | awk '$1 == "Mem:" {print $2}')
uram=$(free -m | awk '$1 == "Mem:" {print $3}')
pram=$(free | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')
fdisk=$(df -BG | grep '^/dev/' | grep -v '/boot$' | awk '{ft += $2} END {print ft}')
udisk=$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} END {print ut}')
pdisk=$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} {ft+= $2} END {printf("%d"), ut/ft*100}')
cpul=$(top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf("%.1f%%"), $1 + $3}')
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')
lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -eq 0 ]; then echo no; else echo yes; fi)
ctcp=$(ss -Ht state established | wc -l)
ulog=$(users | wc -w)
ip=$(hostname -I)
mac=$(ip link show | grep "ether" | awk '{print $2}')
cmds=$(journalctl _COMM=sudo | grep COMMAND | wc -l)
wall "	#Architecture: $arc
	#CPU physical: $pcpu
	#vCPU: $vcpu
	#Memory Usage: $uram/${fram}MB ($pram%)
	#Disk Usage: $udisk/${fdisk}Gb ($pdisk%)
	#CPU load: $cpul
	#Last boot: $lb
	#LVM use: $lvmu
	#Connections TCP: $ctcp ESTABLISHED
	#User log: $ulog
	#Network: IP $ip ($mac)
	#Sudo: $cmds cmd"
```

(Tip: use SSH from host)

#### Activating the script

`sudo visudo`

Add `your_username ALL=(ALL) NOPASSWD: /usr/local/bin/monitoring.sh` under `%sudo ALL=(ALL:ALL) ALL`

exit and then `sudo reboot`

then to test out the script run `sudo /usr/local/bin/monitoring.sh`

#### To have it run every 10mins

open crontab by `sudo crontab -u root -e`

At the end of the crontab add `*/10 * * * * /usr/local/bin/monitoring.sh` which will make the system run every 10 mins

### signature.txt

find your freaking vdi (virtual disk file) in the terminal and run `shasum [virtualdiskfile.vdi]`, you should get a weird number string, just copy that into a file called `signature.txt` and tada :)

## Post-VM

### Aptitude vs Apt

Why the fuck is this a question?!? I never fucking use aptitude.

Aptitude is a "smarter" TUI frontend for apt, which claims to also auto-remove things which isn't needed and install things which are needed while install things.

Apt is only in the command-line and only does things you tell it too.

### AppArmor

AppArmor is a Mandatory Access Control (MAC) security system which allows the admin to restrict actions that processes can perform.

`aa-status`

### LVM

LVM stands for Logical Volume Manager, which allows us to easily manipulate partitions on a storage device.

### UFW (Uncomplicated Firewall)

UFW is an interface to modify the device's firewall easily.

### SSH

SSH stands for Secure Shell, and it allows encrypted communication between clients and hosts.

### Cron

Cron is a command line utility which allows the scheduling of scripts/commands to happen at specific times/intervals.

`cd /usr/local/bin`

`sudo crontab -u root -e`
