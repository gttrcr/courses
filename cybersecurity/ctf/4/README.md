# Challenge 4

Difficoltà: Medio-alta
Categoria: Reverse Engineering / Malware Analysis
Tempo stimato: 40–45 min

## Scenario

Un presunto malware Linux è stato recuperato da un host compromesso.

## Obiettivo

Capire:

* cosa fa il malware
* dove comunica
* recuperare la flag nascosta

## Materiale

* ELF binario stripped
* eventuale file di configurazione
* output di rete simulato

## Competenze richieste

* strings
* ltrace/strace
* objdump
* Ghidra/radare2
* XOR/base64 decoding

## Comportamento malware

legge /etc/hostname
costruisce una richiesta HTTP
usa XOR single-byte per offuscare la flag

## Twist

La flag non è mai in chiaro nel binario.

## Possibile flow

* strings rivela dominio sospetto
* strace mostra apertura file
* reversing individua chiave XOR
* decoding finale

## Flag

FLAG{x0r_1s_n0t_3ncrypt10n}
