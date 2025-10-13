#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef LIB_H
#define LIB_H
struct data {
    int dia, mes, ano;
};

typedef struct retangulo {
    float base;
    float altura;
} Retangulo;

typedef struct aluno {
    char nome[50];
    int matricula;
    float nota1, nota2;
} Aluno;

void inicializarRetangulo(Retangulo *r, float base, float altura) {
    r->altura = altura;
    r->base = base;
}

float calcularArea(Retangulo *r) {
    return r->base * r->altura;
}

float calcularPerimetro(Retangulo *r) {
    return 2 * (r->base + r->altura);
}

void inicializarAluno(Aluno *a, char nome[50], int matricula, float nota1, float nota2){
    strcpy(a->nome, nome);
    a->matricula = matricula;
    a->nota1 = nota1;
    a->nota2 = nota2;
}

float calcularMedia(Aluno *a) {
    return (a->nota1 + a->nota2) / 2;
}

void exibirAluno(Aluno *a) {
    printf("\n\n======== ALUNO ========\n");
    printf("Nome: %s\n", a->nome);
    printf("Matricula: %d\n", a->matricula);
    printf("Nota 1: %.2f\n", a->nota1);
    printf("Nota 2: %.2f\n", a->nota2);
    printf("Media: %.2f\n", calcularMedia(a));
    printf("=======================\n");
}
#endif
