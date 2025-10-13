#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento{
	int dado;
	struct Elemento* prox;
} Elemento;

typedef struct Lista{
	Elemento* inicio;
} Lista;

Lista * criar_lista() {
    Lista * l = malloc(sizeof(Lista));
    l->inicio = NULL;
    return l;
};

void destruir_lista(Lista* l);

int tamanho(Lista* l) {
    Elemento *aux = l->inicio;
    int cont = 0;
    if(!aux) return cont;
    while(!aux) {
        aux = aux->prox;
        cont++;
    };
    return cont;
};

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

Elemento* buscar_por_posicao(Lista* l, int pos) {
    int cont;
    Elemento *aux;
    if(!l) return NULL;
    aux = l->inicio;
    if(pos > tamanho(l)) return NULL;
    cont = 1;
    while(cont < pos) {
        aux = aux->prox;
        cont++;
    }
    return aux;
};

Elemento* inserir_inicio(Lista* l, int x) {
    Elemento* e;
    if(!l) return NULL; // Se a lista for nula
    e = malloc(sizeof(Elemento));
    e->dado = x;
    e->prox = l->inicio;
    l->inicio = e;
    return e;
};

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
    e->prox = aux->prox;
    aux->prox = e;
    return e;
};

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
    while(aux->prox) aux = aux->prox;
    aux->prox = e;
    return e;

};

void remover(Lista* l, int x) {
    Elemento *e, *anterior;
    if(!l) return;
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
        e = e->prox;
        if(!e) return;
    }
    anterior->prox = e->prox;
    free(e);
};

Elemento* primeiro(Lista* l) {
    if(!l) return NULL;
    return l->inicio;
};

Elemento* ultimo(Lista* l) {
    Elemento *aux;
    if(!l) return NULL;
    aux = l->inicio;
    while(aux->prox) aux = aux->prox;
    return aux;
};

void printer(Lista* l) {
    Elemento* aux;
    if(!l) {
        printf("Lista não iniciada!");
        return;
    }
    int cont = 1;
    aux = l->inicio;
    while(aux) {
        printf("Valor: %d | Posicao: %d\n", aux->dado, cont);
        aux = aux->prox;
        cont++;
    }
}

int main()
{
    Lista * l = criar_lista();
    inserir(l, 1);
    inserir(l, 2);
    inserir(l, 3);
    inserir(l, 4);
    inserir(l, 5);
    remover(l, 3);
    inserir_posicao(l, 6, 2);
    inserir(l, 7);
    inserir_inicio(l, 8);
    printer(l);

    /*
        Valor: 8 | Posicao: 1
        Valor: 1 | Posicao: 2
        Valor: 6 | Posicao: 3
        Valor: 2 | Posicao: 4
        Valor: 4 | Posicao: 5
        Valor: 5 | Posicao: 6
        Valor: 7 | Posicao: 7
    */

    return 0;
}
