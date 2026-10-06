PASS="password123"
SALT="123456"
HASH=$(echo -n "${PASS}${SALT}" | openssl dgst -sha256 | awk '{print $NF}')
echo "${HASH}:${SALT}" > hash_sha256_salted
cat hash_sha256_salted
