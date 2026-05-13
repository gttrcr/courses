#!/bin/bash

mkdir -p files/home/student

PART1="FLAG{l0gs_"
PART2="n3v3r_l13}"

ENCODED=$(echo -n "$PART1" | base64)

cat > files/access.log <<EOF
192.168.1.10 - - [11/May/2026:10:22:11 +0000] "GET /index.html HTTP/1.1" 200 1234
10.0.0.5 - - [11/May/2026:10:25:00 +0000] "GET /$ENCODED HTTP/1.1" 404 321
EOF

cat > files/auth.log <<EOF
May 11 10:20:00 server sshd[1337]: Accepted password for student from 10.0.0.5 port 49822 ssh2
EOF

cat > files/home/student/.bash_history <<EOF
ls
cd /tmp
echo "$PART2"
EOF

tar -czf ghost_logs.tar.gz files

echo "Challenge generated."