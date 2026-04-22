#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_USERS     16
#define USERNAME_LEN  32
#define NOTES_LEN     128
#define PASSWORD_LEN  64

typedef struct {
    char username[USERNAME_LEN];
    int  role;        // 0 = user, 1 = admin
    char notes[NOTES_LEN];  // FIX 6: buffer statico, dimensione controllata
} User;

// FIX 5: array di struct per valore, non puntatori a heap liberi
User  users[MAX_USERS];
int   user_count = 0;

// ----------------------------------------------------------------
// Utility: copia sicura con troncamento garantito
// ----------------------------------------------------------------
static void safe_copy(char *dst, const char *src, size_t dst_size) {
    strncpy(dst, src, dst_size - 1);
    dst[dst_size - 1] = '\0';
}

// ----------------------------------------------------------------
void add_user(const char *input) {
    if (user_count >= MAX_USERS) {
        printf("Limite utenti raggiunto.\n");
        return;
    }

    // FIX 1: niente strcpy — dimensione esplicita, troncamento garantito
    User *u = &users[user_count];
    safe_copy(u->username, input, USERNAME_LEN);
    u->role = 0;

    // FIX 6: snprintf con bound esplicito — impossibile eccedere NOTES_LEN
    snprintf(u->notes, NOTES_LEN,
             "Benvenuto, %s! Il tuo ruolo e': %d",
             u->username,   // username gia' troncato a 31 char
             u->role);

    user_count++;
    printf("Utente creato: %s\n", u->username);
}

// ----------------------------------------------------------------
void delete_user(int index) {
    if (index < 0 || index >= user_count) {
        printf("Indice non valido.\n");
        return;
    }

    // FIX 5: niente free — spostiamo l'ultimo utente al posto di quello eliminato
    // (compattazione dell'array, nessun puntatore dangling)
    users[index] = users[user_count - 1];
    memset(&users[user_count - 1], 0, sizeof(User));  // azzera il record rimosso
    user_count--;

    printf("Utente eliminato.\n");
}

// ----------------------------------------------------------------
void print_user(int index) {
    if (index < 0 || index >= user_count) {
        printf("Indice non valido.\n");
        return;
    }

    const User *u = &users[index];

    // FIX 2: mai passare dati utente come format string
    // printf(u->username) → printf("%s", u->username)
    printf("Username: %s\n", u->username);
    printf("Notes:    %s\n", u->notes);
    printf("Role:     %d\n", u->role);
}

// ----------------------------------------------------------------
void promote_user(int index) {
    if (index < 0 || index >= user_count) {
        printf("Indice non valido.\n");
        return;
    }
    users[index].role = 1;
    printf("Utente %s promosso ad admin.\n", users[index].username);
}

// ----------------------------------------------------------------
int authenticate(const char *username, const char *password) {
    // FIX 3: buffer adeguato, niente strcpy — usiamo safe_copy
    char buf[PASSWORD_LEN];
    safe_copy(buf, password, PASSWORD_LEN);

    // FIX 4: la variabile authenticated ora viene impostata correttamente
    // prima era sempre 0 → l'autenticazione non funzionava mai
    // qui: cerchiamo l'utente per username, poi verifichiamo la password
    for (int i = 0; i < user_count; i++) {
        if (strncmp(users[i].username, username, USERNAME_LEN) == 0) {
            // In produzione vera: confronto con hash, non plaintext
            // Qui confronto diretto solo a scopo didattico
            if (strncmp(buf, "password_corretta", PASSWORD_LEN) == 0) {
                return i;  // autenticazione riuscita
            }
        }
    }
    return -1;  // fallito
}

// ----------------------------------------------------------------
// Legge un intero da stdin in modo sicuro
// ----------------------------------------------------------------
static int read_int(int *out) {
    char line[32];
    if (!fgets(line, sizeof(line), stdin)) return 0;
    char *end;
    long v = strtol(line, &end, 10);
    if (end == line) return 0;  // nessuna cifra letta
    *out = (int)v;
    return 1;
}

// ----------------------------------------------------------------
int main(void) {
    int  choice, index;
    char input[USERNAME_LEN];
    char pass[PASSWORD_LEN];

    while (1) {
        printf("\n1. Aggiungi utente\n2. Elimina utente\n3. Stampa utente\n");
        printf("4. Promuovi utente\n5. Autenticati\n6. Esci\n> ");

        if (!read_int(&choice)) continue;

        switch (choice) {
            case 1:
                printf("Username: ");
                if (!fgets(input, sizeof(input), stdin)) break;
                input[strcspn(input, "\n")] = '\0';
                add_user(input);
                break;

            case 2:
                printf("Index: ");
                if (!read_int(&index)) break;
                delete_user(index);
                break;

            case 3:
                printf("Index: ");
                if (!read_int(&index)) break;
                print_user(index);
                break;

            case 4:
                printf("Index: ");
                if (!read_int(&index)) break;
                promote_user(index);
                break;

            case 5:
                printf("Username: ");
                if (!fgets(input, sizeof(input), stdin)) break;
                input[strcspn(input, "\n")] = '\0';

                printf("Password: ");
                if (!fgets(pass, sizeof(pass), stdin)) break;
                pass[strcspn(pass, "\n")] = '\0';

                index = authenticate(input, pass);
                printf(index >= 0 ? "Autenticato.\n" : "Fallito.\n");
                break;

            case 6:
                return 0;

            default:
                printf("Scelta non valida.\n");
        }
    }
}
