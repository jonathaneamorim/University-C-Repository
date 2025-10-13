#include <stdio.h>
#include <stdlib.h>

void retornaMaior(int *num1, int *num2) { // RECEBE PONTEIROS COMO REFERENCIA
    if(*num2 > *num1) {
        int temp = *num1;
        *num1 = *num2;
        *num2 = temp;
    }
}

void printaValores(float *array, int size){
    for(int i = 0; i < size; i++) {
        printf("Valor %d: %.2f\n", i + 1, *(array + i));
    }
}

void printaPares(int * vet, int size) {
    for(int i = 0; i < size; i++) {
        if(vet[i] % 2 == 0) {
            printf("%x", &vet[i]);
        }
    }
}

int main()
{

    printf("Questão 1: ");
    printf("\n");
    int num1 = 1;
    float num2 = 2;
    char letter = 'a';

    int * pon_int;
    pon_int = &num1;

    float * pon_real;
    pon_real = &num2;

    char * pon_char;
    pon_char = &letter;

    printf("%d", num1);
    printf("\n");
    printf("%f", num2);
    printf("\n");
    printf("%c", letter);
    printf("\n");
    printf("\n");
    printf("\n");


    *pon_int = 10;
    *pon_real = 20;
    *pon_char = 'b';

    printf("%d", num1);
    printf("\n");
    printf("%f", num2);
    printf("\n");
    printf("%c", letter);
    printf("\n");

    printf("Questão 2: ");
    printf("\n");
    int valor1 = 10;
    int valor2 = 12;

    printf("Endereco do valor 1: %p", &valor1);
    printf("\n");
    printf("Endereco do valor 2: %p", &valor2);
    printf("\n");

    if(&valor1 > &valor2) {
        printf("Endereco do valor 1 é maior!\n\n");
    } else {
        printf("Endereco do valor 2 é maior!\n\n");
    }

    printf("Questão 3: ");
    printf("\n");

    int numero1 = 0;
    int numero2 = 0;

    printf("Digite o primeiro valor inteiro: ");
    scanf("%d", &numero1);

    printf("Digite o segundo valor inteiro: ");
    scanf("%d", &numero2);

    printf("Numero 1: %d\n", numero1);
    printf("Numero 2: %d\n", numero2);
    printf("\n");

    retornaMaior(&numero1, &numero2);

    printf("Numero 1: %d\n", numero1);
    printf("Numero 2: %d\n", numero2);
    printf("\n");
    printf("\n");

    // Crie um programa que contenha um array de float contendo 10 elementos.
    // Imprima o endereço de cada posiçao desse array.
    printf("Questão 4: ");
    printf("\n");
    float array[] = {21.2, 12.2, 23.4, 76.3, 8.2, 8.5, 34.2, 23.1, 234.23, 124.5};
    for(int i = 0; i < 10; i++) {
        printf("Posição: %p \n", &array[i]);
    }
    printf("\n");

    printf("Questão 5: ");
    printf("\n");
    printaValores(array, 10); // Aqui pode passar só o vetor, pq vetor meio que é um ponteiro saca?

    printf("Questão 6: ");
    printf("\n");
    float array[] = {21, 12, 23, 76, 8};

    return 0;
}
