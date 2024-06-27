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

`sudo apt install ufw net-tools`

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
