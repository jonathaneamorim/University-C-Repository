#include <stdio.h>
#include <stdlib.h>
#include <hashtable.h>

int inserir_arvore(Arvore * arv, int chave) {
    no_arvore * no, * aux;
    int flag = 0;
    if(arv == NULL) {
        return -999;
    }
    no = malloc(sizeof(no_arvore));
    no->chave = chave;
    no->esq = NULL;
    no->dir = NULL;

    if(arv->raiz == NULL) {
        arv->raiz = no;
        return 1;
    }

    aux = arv->raiz;

    while(flag == 0) {
        if(aux->chave > chave) {
            if(aux->esq == NULL) {
                aux->esq = no;
                flag = 1;
            } else {
                aux = aux->esq;
            }
        } else {
            if(aux->dir == NULL) {
                aux->dir = no;
            } else {
                aux = aux->dir;
            }
        }
    }
}



int main()
{
    printf("Hello world!\n");
    return 0;
}
