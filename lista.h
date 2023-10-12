#ifndef LISTA_H
#define LISTA_H

#include "cliente.h"

typedef struct Node Node;

typedef struct {
    Node *inicio;
    Node *fim;
    int quantidade;
} Lista;

Lista *cria_lista();
void destroi_lista(Lista *lista);
Node *get_inicio(Lista *lista);
int get_quantidade(Lista *lista);
void insere_lista(Lista *lista, Cliente *cliente);

#endif
