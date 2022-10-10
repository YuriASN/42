##	Creating a Virtual Machine.

1.	Create new VM. Name it, and select appropriate OS.

2.	Select RAM size to be used (minimmum 1Gb).

3.	Create a new Virtual Hard Disk as VDI and Dynamically allocated size.

# Load the Debian Image to the VM.

1.	Settings -> Storage

2.	Under "Controller: IDE" select the disk and open the OS iso file.

## Installing OS.

Run the Virtual Machine

1.	Select `Install`.

2.	Select Language, Location and Keyboard.

3.	Hostname: "...must be your login ending with 42..."<br/>
	Domain name: N/A.<br/>
	Set users and passwords<br/>
	...<br/>
	Timezone<br/>

# The following goes for **Bonus partitions**.

4.	Manual Partition.<br/>
	Select disk. "create new empty partition on this device?" YES<br/>
	/boot<br/>
	pri/log<br/>
	Create a new partition<br/>
	500M<br/>
	Primary<br/>
	Beginning<br/>
	Mount point<br/>
	/boot<br/>
	Done<br/>

5.	Create new partition<br/>
	pri/log<br/>
	Create a new partition<br/>
	"max"<br/>
	Logical<br/>
	Mount Point -> Do not mount it<br/>
	Done<br/>

6.	Configure encrypted volumes<br/>
	Yes<br/>
	Create encrypted volumes<br/>
	/dev/sda5<br/>
	Done<br/>
	Finish<br/>
	Erase data? YES<br/>
	Set password<br/>

7.	Configure the Logical Volume Manager<br/>
	Yes<br/>
	Create volume group<br/>
	LVMGroup<br/>
	/dev/mapper/sda5_crypt<br/>
	Create logical volume<br/>
	root, swap, home, var, srv, tmp, var-log<br/>

8.	Select partitions and place them as:<br/>
```
	home #1		|	Ext4		|	/home
	root #1		|	Ext4		|	/
	srv #1		|	Ext4		|	/srv
	swap #1		|	swap area	|	N/A
	tmp #1		|	Ext4		|	/tmp
	var #1		|	Ext4		|	/var
	var-log #1	|	Ext4		|	/var/log
```

9.	Finish... YES

10. Scan extra media?<br/>
	NO

11.	Proxy -> empty

12.	Unselect all softwares leaving only Core Debian.

13.	Install GRUB


##	Configurating the Virtual Machine

**Tip**: During configuration log as root so you don't have to "*sudo*" every command.

#	Update package index and Upgrade packages
```
apt update
apt ugrade
```

#	Aptitude install.
```
apt install aptitude
aptitude update
aptitude safe-upgrade
```
To check if any package is installed run
``` dpkg -l | grep PACKAGE NAME ```

#	Sudo install and config
Create group *user42* and add users to both groups
```
aptitude install sudo
sudo addgroup user42
sudo adduser USERNAME sudo
sudo adduser USERNAME user42
```
Set sudo logs location secure path and password policies.
```
sudo mkdir /var/log/sudo
sudo nano /etc/sudoers.d/sudoconfig
```
```
Defaults    passwd_tries=3
Defaults    badpass_message="Take a deep breath and remember it. You only have 3 tries."
Defaults    log_input,log_output
Defaults    iolog_dir="/var/log/sudo"
Defaults    requiretty
Defaults    secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
```

## Setup password policy
Install the *Password Quality Check Lib* to add more options to pass policy<br/>
```aptitude install libpam-pwquality```<br/>
Edit the file to add the desired policies.<br/>
```sudo nano /etc/pam.d/common_password```<br/>
After "*retry=3*" on the 1st uncommented line add:<br/>
`	reject_username difok=7 minlen=10 ucredit=-1 lcredit=-1 dcredit=-1 maxrepeat=3 enforce_for_root`

**Policies descriptions**:
>	minlen		= minimum password length.

>	minclass	= the minimum number of character types that must be used (i.e., uppercase, lowercase, digits, other).

>	maxrepeat	= the maximum number of times a single character may be repeated.

>	maxclassrepeat	= the maximum number of characters in a row that can be in the same class.

>	lcredit		= maximum number of lowercase characters that will generate a credit.

>	ucredit		= maximum number of uppercase characters that will generate a credit.

>	dcredit		= maximum number of digits that will generate a credit.

>	ocredit		= maximum number of other characters that will generate a credit.

>	difok		= the minimum number of characters that must be different from the old password.

>	remember	= the number of passwords that will be remembered by the system so that they cannot be used again

>	gecoscheck	= whether to check for the words from the passwd entry GECOS string of the user (enabled if the value is not 0)

>	dictcheck	= whether to check for the words from the cracklib dictionary (enabled if the value is not 0)

>	usercheck	= whether to check if the password contains the user name in some form (enabled if the value is not 0)

>	enforcing	= new password is rejected if it fails the check and the value is not 0

>	dictpath	= path to the cracklib dictionaries. Default is to use the cracklib default.

```
sudo nano /etc/login.defs
```
Look for PASS_MAX_DAYS and change to:
```
PASS_MAX_DAYS	30
PASS_MIN_DAYS	2
PASS_WARN_DAYS	7
```

To set the same config to existing users:
```
sudo chage --mindays 2 --maxdays 30 --warndays 7 USERNAME
```
Check password status with
```
sudo chage --list USERNAME
```

## Firewall

If already not installed, install **UFW**.
```
aptitude install ufw
```
Enable it
```
ufw enable
```
Allow **4242 port** connections
```
ufw allow 4242
```
Check UFW status
```
ufw status
```

## SSH
Install SSH service.
```
aptitude install openssh-server
```

Setup ssh port
In the file below, at **line 13**, uncomment and set the wanted value (4242).<br/>
To disable ssh connection as root, in **line 32** uncomment and set, `PermitRootLogin no`.
```
sudo nano /etc/ssh/sshd_config
```
Reboot the system and check `sudo service ssh status`<br/>
To connect with your virtual machine using ssh:
```
ssh <username>@<ip-address> -p 4242
```
Finish connection with `logout` or `exit`.

## Monitoring info
First create the bash script (check the monitoring.sh file)
```crontab -e```		//Opens the file to schedule the desired command (https://crontab.guru/crontab.5.html)
`@reboot sleep 15 && bash FILE_PATH<br/>
*/10 * * * * bash /root/monitoring.sh`

## # BONUS