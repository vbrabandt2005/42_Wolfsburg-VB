# RANT: Wolfsburg I Accept Thing

(Note: This guide might me out of date, since many of things I'm decribing here is for MacOS, I was told that in the future (after Feb 2024), 42 Wolfsburg would replace MacOS with Ubuntu (or some other Linux Distro), but this RANT/Guide still have some info which you might find interesting)

The task itself is actually very easy, they are just lying to you about one crucial step.

### So, What's the task?

The Task was to download a txt file through the terminal using ***"Wget"*** and then use git to upload/push the file to be check by moulinette. The point of this task is to teach you how git & the evaluation system works at 42.

### So, Where's the lie?

Well, it's **Wget**, wget is technically installable on MacOS through Homebrew, but to do that you would need administrator rights which of course we don't as Pisciners and Students, so the task was really to think out of the box and find another way to download the txt file.

### So, How then?

There are two ways you can get through this

1. Use **Curl** instead of **Wget**

   If I understand correctly **Curl** is installed by default on MacOS and has many of the same features as **Wget**.

   So on the subject page in your browser, right click on the txt file and click **copy link address**, then just paste it into curl in your terminal.

   **example:**\
   `curl -O ILoveCapybaras.com/capy.txt`

   (The -O signifies that you want to download it into a file, if you use a small -o then you need to signify the name if the downloaded file, this is handy in case you need to change the name of the downloaded file, you can learn more from the handy [site](https://www.digitalocean.com/community/tutorials/workflow-downloading-files-curl))

   After running the command in the terminal, you should have it somewhere in your directory. (if you haven't cd anywhere then it should be in your home directory)

2. This is the last resort option really and that is by just opening the txt file in your browser and copy it's contents into a newly made txt file.\
   (This technically works, it's just isn't not really that cool lol)

### So, What's next?

   Now you have to learn how to use **Git**, Ok to tell you the truth before my piscine I had only used **Git** using **Github Desktop**, but trust me after you get a hang of it (for me was like 2 hours lol), it's actually way more simple than you think.

   I won't explain everything but this is what is needed for this task (and most of the later tasks too)

1. Press start Project (if you haven't done so already), by this point you should see a unique **Git Repository** for your project.

   (Think of a Git Repository as a shared folder in a server, you can add things into the folder, you can download the folder and if they have the rights they can download the folder too)

2. If you're a new Pisciner, you'll need a new **SSH-Key**, an SSH-Key is like an account which give you access to your repository, so it's kinda important.

   1. To make an **SSH-Key**, use the command `ssh-keygen` in the terminal, this part should be easy enough (There's actually a really nice youtube video on this on the subject page, so it's probably a good idea to watch them).
   2. If you suceeded with making your **SSH-Key**, you should now have a **.ssh** folder in your home directory and there should be two main files in there being\
**`id_rsa`** which is your private key (**so never share this**)\
**`id_rsa.pub`** which is your public key, this is the one you need.

       since we're still in the beginning, you can just open it with a text editor of your choice. then just copy it's contents (which should start with `ssh-rsa`) into the settings in your intra.

3. You should now be able to clone your repository\
   1. so just the command `git clone [repository address thing from your intra]` and you should have a folder somewhere in your directory (if you have set passphrase when you made your ssh-key then you would have to enter that too).
   2. When you find your repository folder (most likely your home directory), make a folder called ex00 and copy your txt file into that folder

