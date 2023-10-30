#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

arvore inserir (arvore raiz, int valor){
    if(raiz == NULL) {
        arvore nova = (arvore) malloc(sizeof(struct no));
        nova->valor = valor;
        nova->esq = NULL;
        nova->dir = NULL;
        return nova;
    }
    else {
        if(valor > raiz->valor) {
            raiz->dir = inserir(raiz->dir, valor);
        } else {
            raiz->esq = inserir(raiz->esq, valor);
        }
        return raiz;
    }
}

void preorder(arvore raiz){
    if(raiz != NULL) {
        printf("[%d]", raiz->valor);
        preorder(raiz->esq);
        preorder(raiz->dir);
    }
}

void inorder(arvore raiz){
    if(raiz != NULL) {
        inorder(raiz->esq);
        printf("[%d]", raiz->valor);
        inorder(raiz->dir);
    }

}
void posorder(arvore raiz) {
    if(raiz != NULL) {
        posorder(raiz->esq);
        posorder(raiz->dir);
        printf("[%d]", raiz->valor);
    }
}

int somatorio(arvore raiz) {
    int soma = 0;
    if(raiz != NULL) {
        soma = raiz->valor + somatorio(raiz->esq) + somatorio(raiz->dir);
    }
    return soma;
}

arvore busca(arvore raiz, int valor) {
    if(raiz != NULL) {
        if(raiz->valor == valor){
            printf("Valor encontrado");
        }
        else if(valor > raiz->valor) {
            busca(raiz->dir, valor);
        } else {
            busca(raiz->esq, valor);
        }
        return raiz->valor;
    } else {
        printf("Valor nao existe");
        return raiz->valor;
    }
}
