def vigenere_encrypt(plaintext, key, alphabet):
    ciphertext = ""
    key_index = 0
    N = len(alphabet)

    for char in plaintext:
        if char in alphabet:
            p = alphabet.index(char)
            k = alphabet.index(key[key_index % len(key)])
            c = (p + k) % N
            ciphertext += alphabet[c]
            key_index += 1
        else:
            ciphertext += char  # keep characters not in alphabet

    return ciphertext


def vigenere_decrypt(ciphertext, key, alphabet):
    plaintext = ""
    key_index = 0
    N = len(alphabet)

    for char in ciphertext:
        if char in alphabet:
            c = alphabet.index(char)
            k = alphabet.index(key[key_index % len(key)])
            p = (c - k) % N
            plaintext += alphabet[p]
            key_index += 1
        else:
            plaintext += char

    return plaintext
