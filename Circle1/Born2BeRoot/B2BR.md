# Born2beRoot

**Summary:** This document is a system administration exercise.

**Version:** 3.4

---

## Project Overview

**Born2beRoot** is a system administration project that introduces you to the world of virtualization. You will create your first virtual machine using VirtualBox (or UTM if VirtualBox doesn't work on your machine) following specific instructions and strict security guidelines.

### Main Objectives

By completing this project, you will:

- **Set up a virtual machine** with minimal services (no graphical interface allowed)
- **Install and configure** either Debian (latest stable) or Rocky Linux
- **Implement strong password policies** with specific requirements
- **Configure sudo** with strict security rules
- **Set up SSH service** on port 4242 only
- **Configure firewall** (UFW for Debian / firewalld for Rocky)
- **Create encrypted partitions** using LVM (Logical Volume Manager)
- **Develop a monitoring script** to display system information every 10 minutes
- **Understand fundamental system administration** concepts

### Key Requirements

#### System Configuration
- Operating System: Debian (latest stable) or Rocky Linux
- Partitioning: At least 2 encrypted partitions using LVM
- SSH: Running on port 4242, root login disabled
- Firewall: Only port 4242 open
- Hostname: Your login ending in 42 (e.g., wil42)

#### User Management
- Root user + user with your login name
- Users must belong to user42 and sudo groups
- Strong password policy enforced

#### Password Policy
- Expires every 30 days
- Minimum 2 days before modification
- Warning 7 days before expiration
- Minimum 10 characters (uppercase, lowercase, number required)
- Maximum 3 consecutive identical characters
- Cannot contain username
- At least 7 characters different from old password (non-root)

#### Sudo Configuration
- Maximum 3 authentication attempts
- Custom error message for wrong password
- Log all sudo commands (input/output) to `/var/log/sudo/`
- TTY mode enabled
- Restricted sudo paths

#### Monitoring Script
A bash script (`monitoring.sh`) that displays every 10 minutes:
- OS architecture and kernel version
- Physical and virtual CPU cores
- Current RAM usage and percentage
- Current disk usage and percentage
- CPU load percentage
- Last boot date and time
- LVM status
- Active TCP connections
- Number of logged-in users
- Server IPv4 and MAC address
- Number of sudo commands executed

### Skills Developed

This project teaches essential skills in:
- Linux system administration
- Security configuration and hardening
- Virtualization technologies
- Firewall management
- User and permission management
- Bash scripting
- System monitoring
- Network configuration

---

## Bonus Part (Optional)

Additional challenges include:
- Advanced partition setup
- WordPress installation with lighttpd, MariaDB, and PHP
- Additional useful service of your choice (excluding NGINX/Apache2)

## Project Deliverable

Submit a `signature.txt` file containing the SHA1 signature of your virtual machine's disk file to your Git repository.
