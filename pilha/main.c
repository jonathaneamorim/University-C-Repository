#include <stdio.h>
#include <stdlib.h>

// Sempre apontar por proximo valor
// O que importa na pilha é sempre o topo (fim)
// TAD (struct) de pilha
// Last-in First-out


// Item da pilha (elemento)
// Da pra fazer com uma struct só (ponteiro de ponteiro)
typedef struct Elemento {
    int dado;
    struct Elemento * prox;
} Elemento;

// Guarda somente o endereco do topo
typedef struct Pilha {
    struct Elemento * topo;
} Pilha;

Pilha* criar_pilha() { // Igual o new do java (instanciar o objeto pilha)
    Pilha * p = malloc(sizeof(Pilha)); // Alocando memoria pra pilha
    p->topo = NULL; // Settano null para o topo
    return p;
};

// Empilhar e desempilhar (push and pop)
// Push empilhar e pop desempilhar
// Aloca regiao de memria
// Coloca o valor
// Proximo aponta pro Topo
// Topo aponta pro novo cara (prato)
void push (Pilha* p, int x) {
    Elemento * e = malloc(sizeof(Elemento));
    e->dado = x;
    e->prox = p->topo;
    p->topo = e;
};

// Pq o auxiliar pode apontar pro topo? Topo do tipo elemento tambem
// Remover item da pilha
// Pra remover cria um auxiliar e aponta pro topo
// Topo aponta pro proximo
// Free no auxiliar
int pop(Pilha *p) {
    int valor;
    Elemento * aux = p->topo;
    if(aux == NULL) {
        return -999; // PQ? Meu codigo de erro (o valor nao pode entrar na pilha)
    }
    p->topo = aux->prox;
    valor  = aux->dado;
    free(aux); // Remove o espaço de memoria do item da pilha
    return valor;
};

// Destruir com recursividade
// Utilizou sumiu a pilha
void destruir_pilha(Pilha * p) {
    while(pop(p) != -999);
    free(p);
};

int tamanho(Pilha * p) {
    Elemento * aux = p->topo;
    int contador = 0;
    while(aux != NULL) {
        contador++;
        aux = aux->prox;
    }
    return contador;
}

void verItens(Pilha * p) {
    Elemento * aux = p->topo;
    while(aux != NULL) {
        printf("%d", aux->dado);
        aux = aux->prox;
    }
};


void convertToBinary(Pilha * p, int decimal) {
    while(decimal != 0){
        push(p, decimal % 2);
        decimal /= 2;
    }
}

void questaoQuatro(Pilha * r, Pilha * s){
    while(/* Pode usar assim s->topo != NULL ou */ tamanho(s) > 0) {
        int valor1, valor2, signal, result;
        valor1 = pop(r);
        valor2 = pop(r);
        signal = pop(s);
        switch(signal) {
            case '+':
                result = valor1 + valor2;
                break;
            case '-':
                result = valor1 - valor2;
                break;
            case '/':
                result = valor1 / valor2;
                break;
            case '*':
                result = valor1 * valor2;
                break;
        };

        printf("%d %c %d = %d\n", valor1, signal, valor2, result);
        push(r, result);
    }
};

int main()
{
    Pilha* p = criar_pilha();

    Pilha* r = criar_pilha();
    Pilha* s = criar_pilha();
    push(r, 2);
    push(r, 3);
    push(r, 1);
    push(s, '-');
    push(s, '+');

    questaoQuatro(r, s);
    verItens(r);
    verItens(s);

    // int decimal = 0;
    /*
    push(p, 10);
    push(p, 20);
    push(p, 30);
    verItens(p);
    printf("===================\n");
    int valor = pop(p);
    verItens(p);
    printf("===================\n");
    */

    //printf("Entre com o numero decimal: ");
    //scanf("%d", &decimal);

    //convertToBinary(p, decimal);

    // Faz assim pra nao dar merda, define o tamanho antes de usar
    // Evita usar função pra ver o tamanho das coisa monquei
    //int size = tamanho(p);

    /*
    for(int i = 0; i < size; i++) {
        printf("%d", pop(p));
    }
    */

    // verItens(p);

    return 0;
}
