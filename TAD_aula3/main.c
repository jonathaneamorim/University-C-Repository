#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

int main()
{
    Retangulo retangulo;
    inicializarRetangulo(&retangulo, 2, 3);
    printf("Base: %.2f \nAltura: %.2f\n", retangulo.base, retangulo.altura);
    printf("Area: %.2f\n", calcularArea(&retangulo));
    printf("Perimetro: %.2f\n", calcularPerimetro(&retangulo));
    printf("==========");
    Aluno aluno;
    inicializarAluno(&aluno, "Jobesvaldo Silveira", 202010003454, 6.4, 5.9);
    exibirAluno(&aluno);
    return 0;
}
