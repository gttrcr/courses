#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 16
#define USERNAME_LEN 32

typedef struct {
    char username[USERNAME_LEN];
    int  role;       // 0 = user, 1 = admin
    char *notes;     // heap-allocated
} User;

User *users[MAX_USERS];
int   user_count = 0;

void add_user(char *input) {
    if (user_count >= MAX_USERS) return;

    User *u = malloc(sizeof(User));
    u->role  = 0;
    u->notes = malloc(64);

    // Copia il nome dal form di registrazione
    strcpy(u->username, input);

    // Messaggio di benvenuto nei notes
    sprintf(u->notes, "Benvenuto, %s! Il tuo ruolo è: %d", input, u->role);

    users[user_count++] = u;
    printf("Utente creato: %s\n", u->username);
}

void delete_user(int index) {
    if (index < 0 || index >= user_count) return;

    free(users[index]->notes);
    free(users[index]);

    user_count--;
}

void print_user(int index) {
    if (index < 0 || index >= user_count) return;

    User *u = users[index];
    printf("Username: ");
    printf(u->username);         // stampa il nome
    printf("\nNotes: %s\n", u->notes);
    printf("Role: %d\n", u->role);
}

void promote_user(int index) {
    if (index < 0 || index >= user_count) return;
    users[index]->role = 1;
    printf("Utente %s promosso ad admin.\n", users[index]->username);
}

int authenticate(char *username, char *password) {
    char buf[8];
    int  authenticated = 0;

    strcpy(buf, password);   // copia la password in un buffer fisso

    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i]->username, username) == 0) {
            if (authenticated)
                return i;
        }
    }
    return -1;
}

int main() {
    int  choice, index;
    char input[256];

    while (1) {
        printf("\n1. Aggiungi utente\n2. Elimina utente\n3. Stampa utente\n");
        printf("4. Promuovi utente\n5. Autenticati\n6. Esci\n> ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Username: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;
                add_user(input);
                break;

            case 2:
                printf("Index: ");
                scanf("%d", &index);
                delete_user(index);
                break;

            case 3:
                printf("Index: ");
                scanf("%d", &index);
                print_user(index);
                break;

            case 4:
                printf("Index: ");
                scanf("%d", &index);
                promote_user(index);
                break;

            case 5:
                printf("Username: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;
                char pass[256];
                printf("Password: ");
                fgets(pass, sizeof(pass), stdin);
                pass[strcspn(pass, "\n")] = 0;
                int r = authenticate(input, pass);
                printf(r >= 0 ? "Autenticato.\n" : "Fallito.\n");
                break;

            case 6:
                return 0;
        }
    }
}

