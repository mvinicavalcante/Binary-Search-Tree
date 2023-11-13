#ifndef BST_H
#define BST_H

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} no;
typedef no* arvore;

arvore inserir (arvore raiz, int valor);

void preorder(arvore raiz);

void inorder(arvore raiz);

void posorder(arvore raiz);

void reverso(arvore raiz);

int qtdPar(arvore raiz);

arvore antecessor(arvore raiz, int valor);

arvore pai(arvore raiz, int valor);

arvore remover (arvore raiz, int valor);

int somaPar(arvore raiz);

arvore podar (arvore raiz, int valor);

void dobro(arvore raiz);

arvore busca(arvore raiz, int valor);

void descendentes(arvore raiz, int valor);

int altura(arvore raiz);

#endif
