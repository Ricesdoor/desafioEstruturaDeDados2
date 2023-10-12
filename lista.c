#include "lista.h"
#include <stdlib.h>
#include "node.h"

Lista *cria_lista() {
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    if (lista) {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->quantidade = 0;
    }
    return lista;
}

void destroi_lista(Lista *lista) {
    Node *atual = lista->inicio;
    while (atual != NULL) {
        Node *proximo = atual->next;
        free(atual);
        atual = proximo;
    }
    free(lista);
}

Node *get_inicio(Lista *lista) {
    return lista->inicio;
}

int get_quantidade(Lista *lista) {
    return lista->quantidade;
}

void insere_node(Lista *lista, Cliente *cliente) {
    Node *node = cria_node(cliente);
    if (!lista->inicio) {
        lista->inicio = node;
        lista->fim = node;
    } else {
        lista->fim->next = node;
        lista->fim = node;
    }
    lista->quantidade++;
}
