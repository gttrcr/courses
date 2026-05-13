#!/bin/bash

gcc malware.c -o malware
strip malware

echo "Binary generated."