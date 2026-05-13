# Challenge 2

Difficoltà: Medio-bassa
Categoria: Networking / Traffic Analysis
Tempo stimato: 25–30 min

## Scenario

Il SOC ha intercettato un file .pcap relativo a un possibile esfiltrazione dati.

## Obiettivo

Identificare:

* IP dell’attaccante
* protocollo usato per esfiltrare
* flag

## Materiale fornito

capture.pcap

## Competenze richieste

Wireshark/tshark
DNS analysis
HTTP stream extraction
filtri display

## Progressione

1. Traffico normale
2. DNS sospetti con payload encoded
3. HTTP POST contenente frammenti della flag

## Twist

La flag è hex-encoded e frammentata in più richieste.

## Esempio

464c41477b...

## L’utente deve

* ricostruire l’ordine
* convertire hex → ASCII

## Hint

"Not every DNS query is really DNS."
