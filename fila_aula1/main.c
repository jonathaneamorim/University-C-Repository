#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento{
    int dado;
    struct Elemento* prox;
} Elemento;

typedef struct Fila{
    Elemento* inicio;
    Elemento* fim;
}Fila;

// cria uma fila com tamanho definido
Fila* criar_fila() {
    Fila * fila = malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
};

// destroi a fila
void destruir_fila(Fila* f);

// insere na cauda da fila
void inserir(Fila* f, int x) {
    Elemento * e = malloc(sizeof(Elemento));
    e->dado = x;
    e->prox = NULL;
    if(f->inicio == NULL) {
        f->inicio = e;
        f->fim = e;
        return;
    }
    Elemento * aux = f->fim;
    aux->prox = e;
    f->fim = e;
};

// remove cabeca da fila
int remover(Fila* f);

// retorna o tamanho da fila (numero de elementos inseridos)
int tamanho(Fila* f);



int main()
{
    printf("Hello world!\n");
    return 0;
}
