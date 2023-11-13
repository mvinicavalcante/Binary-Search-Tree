#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

void imprimirMenu() {
    printf("\nOpcoes disponiveis:\n");
    printf("1. Inserir elemento\n");
    printf("2. Exibir arvore preorder\n");
    printf("3. Exibir arvore inorder\n");
    printf("4. Exibir arvore posorder\n");
    printf("5. Exibir arvore reverso\n");
    printf("6. Exibir a quantidade de elementos pares da arvore\n");
    printf("7. Exibir antecessor de um elemento da arvore\n");
    printf("8. Exibir pai de um elemento da arvore\n");
    printf("9. Remover elemento da arvore\n");
    printf("10. Exibir a soma de elementos pares da arvore\n");
    printf("11. Podar os elementos e seus respectivos filhos\n");
    printf("12. Exibe a arvore com o valor de seus elementos duplicados\n");
    printf("13. Busca um elemento na arvore\n");
    printf("14. Mostrar os descendentes de um elemento\n");
    printf("15. Mostrar a altura de uma arvore\n");
    printf("99. Sair\n");
}

int main() {
    arvore raiz = NULL;

    int escolha;
    int valor;

    do {
        imprimirMenu();
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                raiz = inserir(raiz, valor);
                break;
            case 2:
                printf("Exibir arvore preorder: ");
                preorder(raiz);
                printf("\n");
                break;
            case 3:
                printf("Exibir arvore inorder: ");
                inorder(raiz);
                printf("\n");
                break;
            case 4:
                printf("Exibir arvore posorder: ");
                posorder(raiz);
                printf("\n");
                break;
            case 5:
                printf("Exibir arvore reverso: ");
                reverso(raiz);
                printf("\n");
                break;
            case 6:
                printf("Exibir quantidade par de numeros na arvore: ");
                qtdPar(raiz);
                printf("\n");
                break;
            case 7:
                printf("Exibir o antecessor de um elemento na arvore: ");
                scanf("%d", &valor);
                antecessor(raiz, valor);
                printf("\n");
                break;
            case 8:
                printf("Exibir o pai de um elemento na arvore: ");
                scanf("%d", &valor);
                antecessor(raiz, valor);
                printf("\n");
                break;
            case 9:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                raiz = remover(raiz, valor);
                printf("\n");
                break;
            case 10:
                printf("Exibe a soma de numeros pares da arvore: ");
                somaPar(raiz);
                printf("\n");
                break;
            case 11:
                printf("Poda os descendentes de um elemento da arvore: ");
                somaPar(raiz);
                printf("\n");
                break;
            case 12:
                printf("Exibe o dobro dos elementos contidos na arvore: ");
                dobro(raiz);
                printf("\n");
                break;
            case 13:
                printf("Busca por um elemento da arvore: ");
                scanf("%d", &valor);
                busca(raiz, valor);
                printf("\n");
                break;
            case 14:
                printf("Mostra os descendentes de um elemento da arvore: ");
                scanf("%d", &valor);
                descendentes(raiz, valor);
                printf("\n");
                break;
            case 15:
                printf("Altura da arvore: %d\n", altura(raiz));
                break;
            case 99:
                printf("Saindo do programa. Limpando memória...\n");
                exit(0);
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (1);

    return 0;
}
