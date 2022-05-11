keywords: var, filesystem

---
### The /var Directory


/var is a standard subdirectory of the root directory in Linux and other Unix-like operating systems that contains files to which the system writes data during the course of its operation.

The root directory is the directory that contains all other directories and files on a system and which is designated by a forward slash ( / ). Among the other directories that are usually installed by default in the root directory are /bin, /boot, /dev, /etc, /home, /initrd, /lib, /lost+found, /misc, /mnt, /opt, /proc, /root, /sbin, /tmp and /usr.

/var is specific for each computer; that is, it is not shared over a network with other computers, in contrast to many other high-level directories. Its contents are not included in /usr because situations can occur in which it is desired to mount /usr as read-only, such as when it is on a CDROM or on another computer. /usr, which is generally the largest directory (at least on a newly installed system) and is used to store application programs, should only contain static data.

Among the various subdirectories within /var are /var/cache (contains cached data from application programs), /var/games (contains variable data relating to games in /usr), /var/lib (contains dynamic data libraries and files), /var/lock (contains lock files created by programs to indicate that they are using a particular file or device), /var/log (contains log files), /var/run (contains PIDs and other system information that is valid until the system is booted again) and /var/spool (contains mail, news and printer queues).

### quick note:
***/var/run*** : 
	* contains PIDs and other system information that is valid untile the system is booted again.
	* Run-time variable files, like files holding process identifiers (PIDs) and logged user information (utmp).  Files in this directory are usually cleared when the system boots.