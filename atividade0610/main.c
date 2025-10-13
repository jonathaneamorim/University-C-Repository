#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Elemento * retorna_maior(Lista * l) {
    Elemento * aux, * maior;
    if(!l || !l->inicio) return NULL;
    aux = l->inicio;
    maior = aux;
    while(aux) {
        if(aux->dado > maior->dado) maior = aux;
        aux = aux->prox;
    }
    return maior;
}

Elemento * retorna_menor(Lista * l) {
    Elemento * aux;
    Elemento * menor;
    if(!l) return NULL;
    aux = l->inicio;
    menor = aux;
    while(aux) {
        if(aux->dado < menor->dado) menor = aux;
        aux = aux->prox;
    }
    return menor;
}

int retorna_soma(Lista * l) {
    Elemento * aux;
    int soma = 0;
    if(!l) return -9999;
    aux = l->inicio;
    while(aux) {
        soma += aux->dado;
        aux = aux->prox;
    }
    return soma;
}

float retorna_media(Lista * l) {
    if(!l || !l->inicio) return -9999;
    return (float) retorna_soma(l) / tamanho(l);
}

int cont_acima_media(Lista * l) {
    Elemento * aux = l->inicio;
    int qtd = 0;
    float media = retorna_media(l);
    if(media == -9999) return -9999;
    while(aux) {
        if(aux->dado >= media) qtd++;
        aux = aux->prox;
    }
    return qtd;
}

// Tenho a lista original
// Preciso remover os repetidos
// Primeiro preciso verificar qual numero ta repetido
// Verificar se um numero aparece mais de uma vez na lista
void remove_repetidos(Lista *l) {
    Elemento * aux, * n1, * n2;

    // Verifico a lista
    if (!l || !l->inicio) {
        printf("\nLista não criada ou vazia!\n");
        return;
    }
    aux = l->inicio;

    while (aux) {
        n1 = aux;
        n2 = aux->prox;
        while (n2) {
            if (aux->dado == n2->dado) {
                n1->prox = n2->prox;
                free(n2);
                n2 = n1->prox;
            } else {
                n1 = n2;
                n2 = n2->prox;
            }
        }
        aux = aux->prox;
    }
}

int main()
{
    Lista * l = criar_lista();

    inserir(l, 2);
    inserir(l, 2);
    inserir(l, 12);
    inserir(l, 2);
    inserir(l, 21);

    printf("Primeiro printer\n");
    printer(l);

    remove_repetidos(l);
    printf("\nSegundo printer\n");
    printer(l);

    //Elemento * maior = retorna_maior(l);
    //Elemento * menor = retorna_menor(l);
    // int soma = retorna_soma(l);

    //printf("\n\nMaior: %d\n\n\n", maior->dado);
    //printf("\n\nMenor: %d\n\n\n", menor->dado);
    //printf("\n\nMenor: %d\n\n\n", soma);

    // float media = retorna_media(l);

    //printf("\n\nMedia: %.2f\n\n\n", media);
    return 0;
}
