//
// Created by lucac on 16/11/2016.
//

#include <stdio.h>
#include <malloc.h>
#include <time.h>

typedef struct movimento{
    int importo;
    int tipologia; // -1 -> prelievo, +1 -> versamento
    struct tm time;
    struct movimento * next;
} movimento_t;

int conto, numero_prelievi, numero_versamenti;
//movimento lista_movimenti[1000];

void prelievo();
void versamento();
void estrattoConto();

void push(movimento_t ** head, int importo, int tipologia);
void print_list(movimento_t * head);

movimento_t * head;

int main(){

    // istanzio un primio elemento vuoto
    head = malloc(sizeof(movimento_t));
    head -> importo = 0;
    head -> tipologia = 0;
    head -> next = NULL;

    conto = 10000;  //saldo iniziale
    numero_prelievi, numero_versamenti = 0;

    int scelta;

    while (1) {
        printf("Menu principale\n1 - Prelievo\n2 - Versamento\n3 - Estratto conto\n4 - exit\n");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
                prelievo();
                break;
            case 2:
                versamento();
                break;
            case 3:
                estrattoConto();
                break;
            case 4:
                return(0);
            default:
                printf("Scelta non valida\n");
        }
    }
}


void push(movimento_t ** testa, int importo, int tipologia) {

    time_t t = time(NULL);

    movimento_t * new_node;
    new_node = malloc(sizeof(movimento_t));

    new_node->importo = importo;
    new_node->tipologia = tipologia;
    new_node->time = *localtime(&t);
    new_node->next = *testa;
    *testa = new_node;
}

void printList(movimento_t * head) {
    movimento_t * current = head;

    while (current != NULL) {
        printf(" %d %d\n", current->importo, current->tipologia);
        current = current->next;
    }
}


void addPrelievo(int importo) {
    push(&head, importo, -1);
    numero_prelievi += 1;
}

void addVersamento(int importo) {
    push(&head, importo, 1);
    numero_versamenti += 1;
}


void prelievo(){
    printf("***PRELIEVO***\n");
    int prelievo;

    printf("Inserisci la cifra da prelevare:\n");
    scanf("%d", &prelievo);

    if (conto - prelievo >= 0){
        conto -= prelievo;
        printf("Hai prelevato %d euro dal tuo conto\n\n", prelievo);
        addPrelievo(prelievo);
    } else {
        printf("Non hai abbastanza soldi\n\n");
    }
}

void versamento(){
    printf("***VERSAMENTO***%d\n", conto);
    int versamento;

    printf("Inserisci la cifra da versare:\n");
    scanf("%d", &versamento);

    conto += versamento;
    addVersamento(versamento);

    printf("Hai versato %d euro sul tuo conto\n\n", versamento);
}

void estrattoConto(){

    movimento_t* current = head;

    int scelta;
    printf("Estratto conto\n1 - Saldo contabile\n2 - Lista movimenti\n");
    scanf("%d", &scelta);

    switch (scelta) {
        case 1:
            printf("***SALDO CONTABILE***\nHai %d euro sul conto\n\n", conto);
            break;
        case 2:
            printf("***LISTA MOVIMENTI***\n");
            for (int i = 0; i < (numero_prelievi + numero_versamenti); ++i) {
                printf("%d - ", (i+1));
                printf("%d-%d-%d %d:%d:%d - ", current->time.tm_mday, current->time.tm_mon+1, current->time.tm_year+1900, current->time.tm_hour, current->time.tm_min, current->time.tm_sec);
                if (current->tipologia == -1){
                    printf("PRELIEVO DI ");
                } else {
                    printf("VERSAMENTO DI ");
                }

                printf("%d EURO\n", current->importo);
                current = current->next;
            }
            printf("\n");
            break;
        default:
            printf("Scelta non valida\n");
    }
}
