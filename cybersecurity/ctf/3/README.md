# Challenge 3

Difficoltà: Media
Categoria: Linux PrivEsc
Tempo stimato: 30–35 min

## Scenario

Hai accesso shell come utente limitato su una VM Linux.

## Obiettivo

Ottenere root e leggere:

/root/flag.txt

## Competenze richieste

* sudo misconfigurations
* SUID binaries
* PATH hijacking
* environment variables
* GTFOBins

## Setup suggerito

* Utente:
* student:student123

## Possibili vettori

sudo -l mostra:
(user) NOPASSWD: /usr/bin/tar

Oppure:

binario custom SUID vulnerabile
script root che usa comandi senza path assoluto

## Twist

Esistono falsi positivi:

diversi SUID inutili
cron jobs non sfruttabili

## Flag

FLAG{pr1v_3sc_c0mpl3t3}

Valutazione:

enumerazione
scelta del vettore corretto
exploitation pulita
