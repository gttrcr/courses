from collections import Counter


def conta_caratteri(testo):
    contatore = Counter(testo)

    print(f"Caratteri nel file :\n")
    for carattere, occorrenze in sorted(contatore.items()):
        if carattere == "\n":
            nome = "\\n (newline)"
        elif carattere == " ":
            nome = "SPAZIO"
        elif carattere == "\t":
            nome = "\\t (tab)"
        else:
            nome = carattere
        print(f"  '{nome}': {occorrenze}")


def cifra_cesare(testo, shift):
    risultato = []

    for carattere in testo:
        if carattere.isalpha():
            base = ord("A") if carattere.isupper() else ord("a")
            nuovo = chr((ord(carattere) - base + shift) % 26 + base)
            risultato.append(nuovo)
        else:
            risultato.append(carattere)  # spazi, punteggiatura, numeri invariati

    return "".join(risultato)


def decifra_cesare(testo, shift):
    return cifra_cesare(testo, -shift)


percorso_file = "italian.txt"
with open(percorso_file, "r", encoding="utf-8") as f:
    testo = f.read()

conta_caratteri(testo)

for i in range(0, 26):
    cifrato = cifra_cesare(testo, i)
    conta_caratteri(cifrato)
