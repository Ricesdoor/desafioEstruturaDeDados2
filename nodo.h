#ifndef NODO_H
#define NODO_H

#include "cliente.h"

typedef struct Node {
    Cliente *data;
    struct Node *next;
} Node;

Node *cria_node(Cliente *cliente);
void destroi_node(Node *node);
Cliente *get_data(Node *node);

#endif