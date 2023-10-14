#include "lista.h"
#include <stdlib.h>
#include "nodo.h"

struct Lista_{
    Node *inicio;
    int quantidade;
};

Lista* cria_lista() {
    Lista *lista = (lista *) malloc(sizeof(Lista_));
    if(lista != NULL) {
        lista->inicio = NULL;
        lista->quantidade = 0;
    }
    return lista;
}
