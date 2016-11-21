//
// Created by lucac on 02/11/2016.
//

#include <stdio.h>
#include <afxres.h>


void es1(int elements[], int number_of_elements);
void es2(int elements[], int number_of_elements);
void es3(int elements[], int number_of_elements);
void es4(float elements[], int number_of_elements);
void es5(float elements[], int number_of_elements);
void es6(float elements[], int number_of_elements);
void es7(float elements[], int number_of_elements);
void es8(float elements[], int number_of_elements);
void es9(float elements[], int number_of_elements);

int main(){

    int scelta;

    // array di test INT
    int array_int[] = {1,5,5,89,11,22};
    int size_int = sizeof array_int / sizeof *array_int;

    // array di test FLOAT
    float array_float[] = {100.2,5.2, 2.0};
    int size_float = sizeof array_float / sizeof *array_float;

    float array_float_1[] = { 35.4, 46.7, 77.55, 11.1, 9.04, 0.75 };
    int size_float_1 = sizeof array_float_1 / sizeof *array_float_1;

    while (1) {
        printf("\n*******************************\nInserisci il numero dell'esercizio da eseguire [1-9]\nPremi 0 per uscire.");
        scanf("%d", &scelta);

        switch (scelta){
            case 0:
                exit(0);
            case 1:
                es1(array_int, size_int);
                break;
            case 2:
                es2(array_int, size_int);
                break;
            case 3:
                es3(array_int, size_int);
                break;
            case 4:
                es4(array_float, size_float);
                break;
            case 5:
                es5(array_float, size_float);
                break;
            case 6:
                es6(array_float_1, size_float_1);
                break;
            case 7:
                es7(array_float_1, size_float_1);
                break;
            case 8:
                es8(array_float_1, size_float_1);
                break;
            case 9:
                es9(array_float_1, size_float_1);
                break;
            default:
                printf("\nNumero inserito non corretto\n");
        }
    }

    return 0;
}

void es1(int elements[], int number_of_elements){
    printf("***Esercizio 1. Stampa a video elementi array di interi***\n\n");
    int i;
    for (i = 0; i < number_of_elements; i++) {
        printf("Elemento %d: %d\n", i, elements[i]);
    }
}

void es2(int elements[], int number_of_elements){
    printf("***Esercizio 2. Somma elementi array di interi***\n\n");
    int i;
    int sum = 0;
    for (i = 0; i < number_of_elements; i++) {
        sum += elements[i];
    }
    printf("Somma: %d\n", sum);
}

void es3(int elements[], int number_of_elements){
    printf("***Esercizio 3. Differenza elementi array di interi***\n\n");
    int i;
    int sum = 0;
    for (i = 0; i < number_of_elements; i++) {
        sum -= elements[i];
    }
    printf("Sottrazione: %d\n", sum);
}

void es4(float elements[], int number_of_elements){
    printf("***Esercizio 4. Moltiplicazione elementi array di float***\n\n");
    int i;
    float moltiplication = 1;
    for (i = 0; i < number_of_elements; i++) {
        moltiplication *= elements[i];
    }
    printf("Moltiplicazione: %.2f\n", moltiplication);
}

void es5(float elements[], int number_of_elements){
    printf("***Esercizio 5. Sottrazione elementi array di float***\n\n");
    int i;
    float subtraction = 0;
    for (i = 0; i < number_of_elements; i++) {
        subtraction -= elements[i];
    }
    printf("Sottrazione: %.2f\n", subtraction);
}

void es6(float elements[], int number_of_elements){
    printf("***Esercizio 6. Media aritmetica elementi array di float***\n\n");
    int i;
    float sum = 0;
    for (i = 0; i < number_of_elements; i++) {
        sum += elements[i];
    }
    printf("Media: %f\n", sum/number_of_elements);
}

void es7(float elements[], int number_of_elements){
    printf("***Esercizio 7. Media ponderata elementi array di float***\n\n");
    int i;
    float sum = 0;
    float weight = 0;
    for (i = 0; i < number_of_elements; i++) {
        sum += (elements[i] * (number_of_elements-1 - i));
        weight += i;
    }
    printf("Media: %f\n", sum/weight);
}

void es8(float elements[], int number_of_elements){
    printf("***Esercizio 8. Maggiore, minore e valore medio array di float***\n\n");
    int i;
    float sum = 0;
    float maxN = 0;
    float minN = elements[0];
    for (i = 0; i < number_of_elements; i++) {
        sum += elements[i];
        maxN = max(maxN, elements[i]);
        minN = min(minN, elements[i]);
    }
    printf("Media: %f Min: %f Max: %f\n", sum/number_of_elements, minN, maxN);
}

void es9(float elements[], int number_of_elements){
    printf("***Esercizio 9. Ordinamento crescente e decrescente array di float***\n\n");
    int i, j;
    float swap;

    for (i = 0 ; i < ( number_of_elements - 1 ); i++) {
        for (j = 0 ; j < number_of_elements - i - 1; j++) {
            if (elements[j] > elements[j+1]) {
                swap = elements[j];
                elements[j] = elements[j+1];
                elements[j+1] = swap;
            }
        }
    }

    printf("Ordine crescente:\n");
    for (int k = 0; k < number_of_elements; k++) {
        printf("%.2f\n", elements[k]);
    }

    printf("\nOrdine decrescente:\n");
    for (int l = number_of_elements-1; l >= 0; l--) {
        printf("%.2f\n", elements[l]);
    }


}
