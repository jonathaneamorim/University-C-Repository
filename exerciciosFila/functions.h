#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

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
    Fila * f = malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
};

// remove cabeca da fila
int remover(Fila* f) {
    Elemento * aux = f->fim;
    int value = aux->dado;
    if(f->fim->prox == NULL) {
        f->fim = NULL;
        return -999;
    } else {
        f->fim = f->fim->prox;
    }

    return value;
};

// destroi a fila
void destruir_fila(Fila* f) {
    while(remover() != -999);
};

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

    Elemento * aux = malloc(sizeof(Elemento));
};


// retorna o tamanho da fila (numero de elementos inseridos)
int tamanho(Fila* f);

#endif // FILA_H_INCLUDED
