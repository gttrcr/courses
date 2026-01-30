sudo adduser challenge
sudo passwd challenge

echo -e "Check if\nMaxSessions 50\nMaxStartups 50\nPermitUserEnvironment yes"
sudo nano /etc/ssh/sshd_config

sudo systemctl restart sshd
