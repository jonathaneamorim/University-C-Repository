#include <stdio.h>
#include <stdlib.h>

int fatorial(int num) {
    if(num == 0) {
        return 1;
    }
    return num * fatorial(num - 1);
}

int soma(int num) {
    if (num == 0) {
        return 0;
    }
    return num + soma(num - 1);
}

float dividir(int num) {
    if(num == 0) {
        return 0;
    }
    return (float) 1/num + dividir(num - 1);
}

float pow(float num, float potencia) {
    if(potencia == 0) {
        return 1;
    }
    return num * pow(num, potencia - 1);
}

float calcVet(float *vet, int size) {
    if(size <= 1) {
        return vet[size - 1];
    }

    return vet[size - 1] + calcVet(vet, size - 1);
}

void invert_array(int *vet, int start, int size) {
    int aux;
    if(start >= size - 1) {
        return;
    }
    aux = vet[start];
    vet[start] = vet[size - 1];
    vet[size - 1] = aux;
    invert_array(vet, start + 1, size - 1);
}

int count(int num, int k) {
    int tem = 0;
    if(num == 0)
        return 0;

    if(k == num % 10) {
        tem = 1;
    }

    return tem + count(num/10, k);
}


int main()
{
    int num = 10;
    int size = 5;
    float vet[] = {10.0, 20.0, 200.0, 20.0, 50.0};

    int vet2[] = {1,2,3,4,5};

    invert_array(vet2, 0, size);

    printf("O resultado do fatorial e: %d \n", fatorial(num));
    printf("O resultado da soma e: %d \n", soma(5));
    printf("O resultado da divisao e: %.2f \n", dividir(3));
    printf("O resultado da potencia e: %.2f \n", pow(6.0, 9.0));
    printf("O resultado do calculo do vetor e: %.2f\n", calcVet(vet, size));
    printf("O vetor invertido e:\n");
    for(int i = 0; i < size; i++) {
        printf("Posicao %d: %d\n", i, vet2[i]);
    }

    printf("Verificar se tem %d em %d \n", 8, 3485858);
    printf("%d aparece %d vezes \n em %d", 8, count(3485858, 8), 3485858);
    return 0;
}
