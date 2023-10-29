#ifndef BST_H
#define BST_H

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} no;

typedef no* arvore;

arvore inserir (arvore raiz, int valor) ;

void preorder(arvore raiz);
void inorder(arvore raiz);
void posorder(arvore raiz);
int somatorio(arvore raiz);

#endif
