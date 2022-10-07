


log as root

#Update package index and Upgrade packages
	sudo apt update
	sudo apt ugrade

## Aptitude install.
	apt install aptitude
	aptitude update
	aptitude safe-upgrade

## Sudo install and config
	`aptitude install sudo`
	`sudo addgroup user42`			//Create group "user42"
	sudo adduser USERNAME sudo		//sudo is the sudoer group
	sudo adduser USERNAME user42
	sudo mkdir /var/log/sudo
	sudo nano /etc/sudoers.d/sudoconfig
		Defaults    passwd_tries=3
		Defaults    badpass_message="Take a deep breath and remember it. You only have 3 tries."
		Defaults    log_input,log_output
		Defaults    iolog_dir="/var/log/sudo"
		Defaults    requiretty
		Defaults    secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"

## Setup password policy
	aptitude install libpam-pwquality		//Password quality check lib adds more options to pass policy
	sudo nano /etc/pam.d/common_password
		//after "retry=3" on the 1st uncommented line add:
		reject_username difok=7 minlen=10 ucredit=-1 lcredit=-1 dcredit=-1 maxrepeat=3 enforce_for_root

	//Policies descriptions:
		minlen		= minimum password length
		minclass	= the minimum number of character types that must be used (i.e., uppercase, lowercase, digits, other)
		maxrepeat	= the maximum number of times a single character may be repeated
		maxclassrepeat	= the maximum number of characters in a row that can be in the same class
		lcredit		= maximum number of lowercase characters that will generate a credit
		ucredit		= maximum number of uppercase characters that will generate a credit
		dcredit		= maximum number of digits that will generate a credit
		ocredit		= maximum number of other characters that will generate a credit
		difok		= the minimum number of characters that must be different from the old password
		remember	= the number of passwords that will be remembered by the system so that they cannot be used again
		gecoscheck	= whether to check for the words from the passwd entry GECOS string of the user (enabled if the value is not 0)
		dictcheck	= whether to check for the words from the cracklib dictionary (enabled if the value is not 0)
		usercheck	= whether to check if the password contains the user name in some form (enabled if the value is not 0)
		enforcing	= new password is rejected if it fails the check and the value is not 0
		dictpath	= path to the cracklib dictionaries. Default is to use the cracklib default.
		
	sudo nano /etc/pam.d/common_auth
		//at the end of the 1st uncommented line add:
		remember=1		//It will remember last password and tell if new matchs old
		
	sudo nano /etc/login.defs
		//Look for PASS_MAX_DAYS
		PASS_MAX_DAYS	30
		PASS_MIN_DAYS	2
		PASS_WARN_DAYS	7

	//To set the same config to existing users do:
		sudo chage --mindays 2 --maxdays 30 --warndays 7 USERNAME
	//To check password status
		sudo chage --list USERNAME
	
## SSH
	aptitude install openssh-server

## Firewall
	
## Monitoring info
	First create the bash script (check the monitoring.sh file)
	crontab -e		//Opens the file to schedule the desired command (https://crontab.guru/crontab.5.html)
		@reboot sleep 15 && bash FILE_PATH
		*/10 * * * * bash /root/monitoring.sh

## # BONUS