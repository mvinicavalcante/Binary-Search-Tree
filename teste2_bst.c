#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[]) {
    arvore a = NULL;
    a = inserir(a, 18);
    a = inserir(a, 7);
    a = inserir(a, 9);
    a = inserir(a, 10);
    a = inserir(a, 27);
    a = inserir(a, 12);
    a = inserir(a, 21);
    a = inserir(a, 30);
    a = inserir(a, 2);
    a = inserir(a, 1);

    printf("PRE-ORDER: ");
    preorder(a);
    printf("\nIN-ORDER: ");
    inorder(a);
    printf("\nPOS-ORDER: ");
    posorder(a);
    printf("\n");

    printf("SOMA: %d\n", somatorio(a));
    busca(a, 7);
    printf("\nDobra de valores (IN-ORDER): \n");
    dobrar_valores(a);
    printf("\n");

    printf("Maior valor: \n");
    maior(a);

    printf("\n");

    remover(a, 7);
    printf("PRE-ORDER apos remocao: ");
    preorder(a);

    return 0;
}
