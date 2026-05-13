tshark -r capture.pcap
strings capture.pcap

echo 464c41477b646e735f616e645f687474707d | xxd -r -p