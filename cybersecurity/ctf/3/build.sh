#!/bin/bash

useradd -m student
echo "student:student123" | chpasswd

echo "student ALL=(ALL) NOPASSWD: /usr/bin/tar" >> /etc/sudoers

mkdir -p /root
echo "FLAG{pr1v_3sc_c0mpl3t3}" > /root/flag.txt
chmod 600 /root/flag.txt

echo "Challenge ready."