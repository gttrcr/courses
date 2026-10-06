import bcrypt

password = b"password123"
hashed = bcrypt.hashpw(password, bcrypt.gensalt(rounds=10))
with open("hash_bcrypt.txt", "w") as f:
    f.write(hashed.decode("utf-8") + "\n")
