# Challenge 1

Difficoltà: Facile
Categoria: Linux / Log Analysis
Tempo stimato: 15–20 min

## Scenario

Un server Linux interno è stato compromesso. L’attaccante ha lasciato una flag nel sistema ma ha cercato di nasconderla sfruttando file di log e tecniche basilari di obfuscation.

## Obiettivo

Recuperare la flag nel formato:

FLAG{...}

## Materiale fornito

* Archivio .tar.gz
* Contiene:
* /var/log/auth.log
* /var/log/apache2/access.log
* directory home di un utente

## Competenze richieste

* grep
* awk/sed/cut
* base64
* ricerca ricorsiva
* cronologia shell

## Hint impliciti

* Un accesso SSH sospetto
* Un comando eseguito con echo ... | base64
* File nascosti nella home

## Twist

La flag è spezzata in due parti:

* una in un log Apache codificata base64
* una dentro .bash_history

## Flag finale

Concatenazione delle due metà.
