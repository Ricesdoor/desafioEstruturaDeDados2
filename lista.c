#include "lista.h"
#include "node.h"
#include <stdlib.h>

struct Lista{
    Node *inicio;
    int quantidade;
};

Lista* cria_lista() {
    Lista *lista = (Lista *) malloc(sizeof(Lista));
    if(lista != NULL) {
        lista->inicio = NULL;
        lista->quantidade = 0;
    }
    return lista;
}

int get_quantidade(Lista *lista){
    return lista->quantidade;
}

Node* get_inicio(Lista *lista){
    return lista->inicio;
}

void insere_inicio(Lista *lista, Node *node){
    if (lista != NULL && node != NULL) {
        set_next(node, lista->inicio);
        lista->inicio = node;
        lista->quantidade++;
    }
}

void destroi_lista(Lista *lista) {
    while (lista != NULL) {
        Node *temp = lista->inicio;
        lista->inicio = get_next(lista->inicio);
        free(temp);
    }
    free(lista); 
}