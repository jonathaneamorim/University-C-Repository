#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento {
    int dado;
    struct Elemento* prox;
} Elemento;



typedef struct Pilha {
    Elemento* topo;
} Pilha;


Pilha* criar_pilha() {
    Pilha* p = malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
};

void push(Pilha* p, int x){
    Elemento* e = malloc(sizeof(Elemento));
    e->dado = x;
    e->prox = p->topo;
    p->topo = e;
};

int pop(Pilha* p) { // retorna um inteiro e recebe o ponteiro da pilha
    int valor; // declara um valor
    Elemento * aux = p->topo; // Cria um Elemento auxiliar pra guardar o valor do topo
    if(aux == NULL) { // Se o auxiliar for NULL (se for o fim da pilha)
        return -999; // PQ? Meu codigo de erro (o valor nao pode entrar na pilha)
    }
    p->topo = aux->prox; // Se nao for o fim da pilha, o topo da pilha, receberá o topo do auxiliar
    valor  = aux->dado;  // o valor sera o valor do auxiliar
    free(aux); // Remove o espaço de memoria do item da pilha
    return valor; // retorna o valor que foi removido
};

int tamanho(Pilha* p) {
    int contador = 0;
    Elemento* aux = p->topo;
    while(aux != NULL) {
        contador++;
        aux = aux->prox;
    }
};

void verItens(Pilha* p) {
    Elemento * aux = p->topo;
    while(aux != NULL) {
        printf("%d", aux->dado);
        aux = aux->prox;
    }
}

void destruir_pilha(Pilha* p) {
    while(pop(p) != -999);
    free(p);
};


int main()
{

    return 0;
}
