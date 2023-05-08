#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó da árvore
struct No {
    int valor;
    struct No* esq;
    struct No* dir;
};

// Função para criar um novo nó com um determinado valor
struct No* novo_no(int valor) {
    struct No* no = (struct No*)malloc(sizeof(struct No));
    no->valor = valor;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

// Função para imprimir somente os nós folhas de uma árvore binária
void imprimir_nos_folhas(struct No* no) {
    // Caso base: nó nulo, retorna
    if (no == NULL)
        return;
    // Se o nó não tem filhos, é uma folha e imprime seu valor
    if (no->esq == NULL && no->dir == NULL)
        printf("%d ", no->valor);
    // Caso contrário, chama a função recursivamente nas subárvores esquerda e direita
    else {
        imprimir_nos_folhas(no->esq);
        imprimir_nos_folhas(no->dir);
    }
}

int main() {
    struct No* raiz = novo_no(1);
    raiz->esq = novo_no(2);
    raiz->dir = novo_no(3);
    raiz->esq->esq = novo_no(4);
    raiz->esq->dir = novo_no(5);
    raiz->dir->esq = novo_no(6);
    raiz->dir->dir = novo_no(7);

    printf("Nos folhas da arvore: ");
    imprimir_nos_folhas(raiz); // Saída: Nos folhas da arvore: 4 5 6 7

    return 0;
}
