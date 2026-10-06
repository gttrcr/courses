PASS="password123"
echo -n "$PASS" | openssl dgst -md5 | awk '{print $NF}' > hash_md5
cat hash_md5
