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

int maior(arvore raiz) {
    if(raiz == NULL) {
        printf("Raiz vazia");
        return -1;
    } else {
        if(raiz->dir != NULL) {
            maior(raiz->dir);
        }
        if(raiz->dir == NULL) {
            printf("%d", raiz->valor);
            return raiz->valor;
        }
    }
}

arvore remover(arvore raiz, int valor) {
    if(raiz == NULL) {
        return raiz;
    } else {
        if(valor > raiz->valor) {
            raiz->dir = remover(raiz->dir, valor);
        }
        else if(valor < raiz->valor) {
            raiz->esq = remover(raiz->esq, valor);
        }
        else {
            if(raiz->esq == NULL && raiz->dir == NULL) {
                free(raiz);
                return NULL;
            }
            if(raiz->esq != NULL && raiz->dir == NULL) {
                arvore aux = raiz->esq;
                free(raiz);
                return aux;
            }
            if(raiz->esq == NULL && raiz->dir != NULL) {
                arvore aux = raiz->dir;
                free(raiz);
                return aux;
            }
            else {
                arvore temp = maior(raiz->esq);
                raiz->valor = temp->valor;
                raiz->esq = remover(raiz->esq, temp->valor);
                return raiz;
            }
            return raiz;
        }
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
        printf("Valor nao encontrado");
        return raiz->valor;
    }
}

void dobrar_valores(arvore raiz) {
    if(raiz != NULL) {
        int multiplicacao = raiz->valor * 2;
        dobrar_valores(raiz->esq);
        printf("[%d]", multiplicacao);
        dobrar_valores(raiz->dir);
    }
}

