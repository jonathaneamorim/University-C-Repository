#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento {
    int dado;
    struct Elemento* prox;
} Elemento;

typedef struct Pilha {
    struct Elemento* topo;
} Pilha;

Pilha* criar_pilha() {
    Pilha* p = malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void push(Pilha* p, int x) {
    Elemento* e = malloc(sizeof(Elemento));
    e->dado = x;
    e->prox = p->topo;
    p->topo = e;
}

int pop(Pilha* p) {
    int valor;
    Elemento* aux = p->topo;
    if(aux == NULL) {
        return -999;
    }
    p->topo = aux->prox;
    valor = aux->dado;
    free(aux);
    return valor;
}

int tamanho(Pilha* p) {
    int contador = 0;
    Elemento* aux = p->topo;
    while(aux != NULL) {
        contador++;
        aux = aux->prox;
    }
}

void ver_itens(Pilha* p) {
    Elemento* aux = p->topo;
    while(aux != NULL) {
        printf("%d", aux->dado);
        aux = aux->prox;
    }
}

void destruir_pilha(Pilha* p) {
    while(pop(p) != -999);
    free(p);
}

// 1. Faça um algoritmo que calcule a sequência de Fibonacci utilizando recursão.
// Não faça uso de laço de repetição. Tem-se que os dois primeiros elementos da sequência são 1, ou seja, fibonacci(0) = 1 e fibonacci(1) = 1.
// fibonacci = 1 1 2 3 5 8 13
void fibonacci(int anterior, int atual) {
    int prox = anterior + atual;
    if(autal > 100) return;

    if(atual == 1) {
        printf("%d\n", anterior);
        printf("%d\n", atual);
    }

    printf("%d\n", prox);
    fibonacci(atual, prox);
}

int main()
{
    fibonacci(1, 1);
    return 0;
}
