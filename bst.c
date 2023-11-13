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

arvore maior(arvore raiz) {
    if(raiz == NULL) {
        printf("Raiz vazia");
        return -1;
    } else {
        if(raiz->dir != NULL) {
            maior(raiz->dir);
        }
        if(raiz->dir == NULL) {
            return raiz;
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
            int maiorValorSubarvoreEsquerda = maior(raiz->esq)->valor;
            raiz->valor = maiorValorSubarvoreEsquerda;
            raiz->esq = remover(raiz->esq, maiorValorSubarvoreEsquerda);
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

void dobro(arvore raiz) {
    if(raiz != NULL) {
        int multiplicacao = raiz->valor * 2;
        dobro(raiz->esq);
        printf("[%d]", multiplicacao);
        dobro(raiz->dir);
    }
}

void reverso(arvore raiz) {
     if(raiz != NULL) {
        reverso(raiz->dir);
        printf("[%d]", raiz->valor);
        reverso(raiz->esq);
    }
}

int qtdPar(arvore raiz) {
    if (raiz == NULL) {
        return 0;
    }
    int cont = 0;
    if (raiz->valor % 2 == 0) {
        cont++;
    }
    cont += qtdPar(raiz->esq);
    cont += qtdPar(raiz->dir);
    return cont;
}

arvore pai(arvore raiz, int valor) {
    if (raiz != NULL) {
        if (raiz->valor == valor) {
            printf("Nao possui pai para o valor %d\n", raiz->valor);
            return -1;
        }

        if (raiz->dir != NULL && raiz->dir->valor == valor) {
            printf("Pai: %d\n", raiz->valor);
            return raiz;
        }

        if (raiz->esq != NULL && raiz->esq->valor == valor) {
            printf("Pai: %d\n", raiz->valor);
            return raiz;
        } else {
            if (valor > raiz->valor) {
                return pai(raiz->dir, valor);
            } else {
                return pai(raiz->esq, valor);
            }
        }
    } else {
        printf("Valor nao encontrado\n");
        return -1;
    }
}

arvore antecessor(arvore raiz, int valor) {
    if (raiz != NULL) {
        if(raiz->valor == valor) {
            printf("Nao ha antecessor para o valor");
            return raiz;
        }
        if(raiz->dir != NULL && raiz->dir->valor == valor) {
            printf("O antecessor do valor e: %d", raiz->valor);
            return raiz;
        }
        if(raiz->esq != NULL && raiz->esq->valor == valor) {
            arvore filho = raiz->esq;
            printf("O antecessor do valor e: %d", filho->esq->valor);
            return filho;
        } else {
            if(valor > raiz->valor) {
                antecessor(raiz->dir, valor);
            } else {
                antecessor(raiz->esq, valor);
            }
        }
    } else {
        printf("Valor de antec nao encontrado\n");
        return NULL;
    }
}

int somaPar(arvore raiz) {
    if (raiz != NULL) {
        if (raiz->valor % 2 == 0) {
            int soma = raiz->valor + somaPar(raiz->esq) + somaPar(raiz->dir);
            return soma;
        } else {
            int somaEsq = somaPar(raiz->esq);
            int somaDir = somaPar(raiz->dir);
            return somaEsq + somaDir;
        }
    } else {
        return 0;
    }
}

arvore podar(arvore raiz, int valor) {
    if (raiz != NULL) {
        if (raiz->valor == valor) {
            free(raiz);
            return NULL;
        } else {
            if (valor > raiz->valor) {
                raiz->dir = podar(raiz->dir, valor);
            } else {
                raiz->esq = podar(raiz->esq, valor);
            }
        }
        return raiz;
    } else {
        printf("Valor nao encontrado\n");
        return NULL;
    }
}

void descendentes(arvore raiz, int valor) {
    if (raiz != NULL) {
        if (raiz->valor == valor) {
            if (raiz->esq != NULL) {
                printf("[%d]", raiz->esq->valor);
                descendentes(raiz->esq, valor);
            }
            if (raiz->dir != NULL) {
                printf("[%d]", raiz->dir->valor);
                descendentes(raiz->dir, valor);
            }
        } else {
            descendentes(raiz->esq, valor);
            descendentes(raiz->dir, valor);
        }
    }
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int altura(arvore raiz) {
    if (raiz != NULL) {
        int alturaEsq = altura(raiz->esq);
        int alturaDir = altura(raiz->dir);
        return 1 + max(alturaEsq, alturaDir);
    } else {
        return 0;
    }
}




