# Born2beRoot

## Description

Born2beRoot is a system administration project that introduces you to the world of virtualization and system configuration. You will create your first virtual machine and configure it following strict rules.

## Project Overview

This project requires you to set up a server with specific security policies and configurations. You'll work with either Debian or Rocky Linux, configure services, implement security measures, and understand how a server works.

This project teaches you:
- Virtual machine setup and management
- Linux system administration
- Security policies and user management
- Service configuration (SSH, UFW/firewalld)
- Partition schemes and LVM
- Bash scripting for monitoring
- Sudo configuration

## Key Requirements

### Operating System
- Debian (latest stable) or Rocky Linux
- Minimal installation (no graphical interface)
- Encrypted partitions using LVM

### Partitioning Scheme
- At least 2 encrypted partitions using LVM
- Specific partition layout following project requirements

### Security Policies

**Password Policy:**
- Password expires every 30 days
- Minimum 2 days before password modification
- Warning 7 days before expiration
- Minimum 10 characters
- Must contain uppercase, lowercase, and numbers
- Maximum 3 consecutive identical characters
- Cannot contain username
- Must have at least 7 characters different from old password (not for root)

**Sudo Configuration:**
- Limited authentication attempts (3 tries)
- Custom error message for wrong password
- Log all sudo commands (inputs and outputs)
- TTY mode enabled
- Restricted paths for security

### Services

**SSH:**
- Running on port 4242 only
- Root login disabled
- Public key authentication recommended

**Firewall:**
- UFW (Debian) or firewalld (Rocky)
- Only port 4242 open

### Monitoring Script

A bash script (`monitoring.sh`) that displays system information every 10 minutes:
- Operating system and kernel version
- Number of physical and virtual processors
- Available RAM and usage percentage
- Available disk space and usage percentage
- CPU load percentage
- Last reboot date and time
- LVM active status
- Number of active connections
- Number of users logged in
- IPv4 and MAC address
- Number of commands executed with sudo

## Commands to Know

### System Information
```bash
uname -a                    # System information
lsblk                       # Block devices
df -h                       # Disk usage
free -h                     # Memory usage
top / htop                  # Process monitor
```

### User Management
```bash
sudo adduser <username>     # Add user
sudo usermod -aG <group> <user>  # Add user to group
sudo userdel <username>     # Delete user
getent group <groupname>    # List group members
```

### Service Management
```bash
sudo systemctl status <service>   # Check service status
sudo systemctl start <service>    # Start service
sudo systemctl enable <service>   # Enable at boot
```

### Firewall
```bash
sudo ufw status             # UFW status
sudo ufw allow <port>       # Allow port
sudo ufw delete <rule>      # Delete rule
```

## Evaluation Preparation

Be ready to:
- Explain what a virtual machine is
- Explain your choice of OS (Debian/Rocky)
- Explain differences between Debian and Rocky
- Explain what APT/DNF is
- Explain what LVM is
- Explain UFW/SELinux
- Explain how SSH works
- Demonstrate creating users and groups
- Show password policy in action
- Explain and modify the monitoring script
- Add/remove firewall rules

## Skills Acquired

- Virtual machine management
- Linux system administration
- Security hardening
- Service configuration
- Bash scripting
- User and group management
- Partition and LVM management
- Network security basics
- Documentation and system auditing

## Circle

**Circle 1** - System administration introduction at 42 School
