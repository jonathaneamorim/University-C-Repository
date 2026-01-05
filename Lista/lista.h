#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct Elemento{
	int valor;
	struct Elemento* prox;
} Elemento;

typedef struct Lista{
	Elemento* inicio;
} Lista;

// cria uma lista com tamanho definido
Lista* criar_lista();

// destroi a lista
void destruir_lista(Lista* l);

// retorna o tamanho da lista (numero de elementos inseridos)
int tamanho(Lista* l);

// busca um dado pela chave x. retorna NULL em caso de falha
Elemento* buscar_por_elemento(Lista* l, int x) {
    Elemento *aux;
    if(!l) return NULL;
    aux = l->inicio;
    while(aux) {
        if(aux->dado == x) return aux;
        aux = aux->prox;
    }
    return aux;
};

// busca um dado pela posicao pos. retorna NULL em caso de falha
Elemento* buscar_por_posicao(Lista* l, int pos) {
    int cont;
    Elemento *aux;
    if(!l) return NULL;
    aux = l->inicio;
    if(pos > tamanho()) return NULL;
    cont = 1;
    while(cont < pos) {
        aux = aux->prox;
        cont++;
    }
    return aux;
};

// insere um dado pela (chave x) no inicio da lista. retorna NULL em caso de falha
Elemento* inserir_inicio(Lista* l, int x) {
    Elemento* e;
    if(!l) return NULL; // Se a lista for nula
    e = malloc(sizeof(Elemento));
    e->dado = x;
    e->prox = l->inicio;
    l->inicio = e;
    return e;
};

// insere um dado pela (chave x) na posicao pos. retorna NULL em caso de falha
Elemento* inserir_posicao(Lista* l, int x, int pos) {
    Elemento *e, *aux;
    int cont;
    if(!l) return NULL;
    if(!l->inicio || pos == 0) return inserir_inicio(l, x);
    aux = l->inicio;
    cont = 1;
    while(cont < pos - 1) {
        aux = aux->prox;
        cont++;
    }
    e = malloc(sizeof(Elemento));
    e->dado = x;
    e->prox aux->prox;
    aux->prox e;
    return e;
};

// insere um dado pela (chave x) na lista. retorna NULL em caso de falha
Elemento* inserir(Lista* l, int x) {
    Elemento *e, *aux;
    if(!l) return NULL;
    e = malloc(sizeof(Elemento));
    e->dado = x;
    e->prox = NULL;
    aux = l->inicio;
    if(!aux) {
        l->inicio = e;
        return e;
    }
    while(aux->prox) aux =aux->prox;
    aux->prox = e;
    return e;

};

// remove dado da lista
void remover(Lista* l, int x) {
    if(!l) return NULL;
    Elemento *e, *anterior;
    e = l->inicio;
    anterior = e;
    if(e->dado == x) {
        l->inicio = e->prox;
        free(e);
        return;
    }

    // Boa prática
    while(e->dado != x) {
        anterior = e;
        e->prox;
        if(!e) return;
    }
    anterior->prox = e->prox;
    free(e);
};

// retorna o primeiro da lista
Elemento* primeiro(Lista* l) {
    if(!l) return NULL;
    return l->inicio;
};

// retorna o ultimo da lista
Elemento* ultimo(Lista* l) {
    Elemento *aux, *e;
    if(!l) return NULL;
    aux = l->inicio;
    while(aux->prox != NULL) aux = aux->prox;
    return aux;
};

// retorna um elemento pela posicao
Elemento* buscar_por_indice(Lista* l, int i);

#endif // LISTA_H_INCLUDED
