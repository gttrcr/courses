# Suggerimenti per le 6 flag

Da dare in mano agli studenti (o da rivelare a richiesta, una riga alla volta se vuoi dosarli). Nessuno contiene la soluzione.

---

**Flag 1 — Git archaeology**
> `main` non è l'unico branch che esiste. Cerca tra tutti i branch, anche quelli che `git branch` da solo non mostra. Il file che trovi non è in italiano leggibile: prova tutti e 26 gli shift di Cesare, o pensa a quali lettere ricorrono di più in un testo italiano.

**Flag 2 — Integrità**
> C'è una cartella con dei file e una lista di "impronte digitali" ufficiali. Ricalcola le impronte di oggi e confrontale con quelle della lista: una non torna. Il file incriminato nasconde la flag in una riga che il manifest non si aspettava.

**Flag 3 — hashcat**
> Il vault ha una password breve e segue uno schema preciso: qualche lettera minuscola, poi un paio di cifre, poi un simbolo. Hai già visto in classe come costruire una maschera hashcat per questo schema — e hai già un pezzo della password, trovato prima.

**Flag 4 — Steganografia**
> Un'immagine normalissima nasconde qualcosa, ma serve una passphrase per tirarlo fuori. Non è una passphrase nuova: l'hai già usata un passo fa.

**Flag 5 — Permessi**
> Dodici file, permessi tutti diversi. Cerchi quello che il proprietario può eseguire, ma che chiunque altro può solo leggere — niente di più. `ls -l` ti mostra tutto, una regex ti fa trovare solo quello.

**Flag 6 — GTIN-13 + HMAC (bonus)**
> Due numeri a cui manca l'ultima cifra: sai già come si calcola, l'hai fatto a lezione con i codici a barre. Un messaggio ha anche un codice di autenticazione allegato: se ricalcolandolo con la chiave data ottieni lo stesso codice, il messaggio è genuino e l'ultima parola conta.
