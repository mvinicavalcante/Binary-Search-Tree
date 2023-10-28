#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

arvore inserir(arvore raiz, int valor) {
    if(raiz == NULL) {
        arvore nova = (arvore) malloc(sizeof(struct no));
        nova->valor = valor;
        nova->esq = NULL;
        nova->dir = NULL;
        return nova;
    } else {
        if(valor > raiz->valor) {
            inserir(raiz->dir, valor);
        } else {
            inserir(raiz->esq, valor);
        }
        return raiz;
    }
}
