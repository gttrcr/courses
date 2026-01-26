#!/bin/bash
while true; do
	echo "$(date) - ITS Server alive" >> /var/log/its_alive.log
	sleep 10
done
