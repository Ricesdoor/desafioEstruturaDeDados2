#include "node.h"
#include <stdlib.h>

struct Node  {
    Cliente *data;
    Node *next;
};

Node* cria_node(Cliente *cliente) {
    Node *novo = (Node *) malloc(sizeof(Node));
    if (novo != NULL) {
        novo->data = cliente;
    }
    return novo;
}

Cliente* get_data(Node *node) {
    return node->data;
}

void set_next(Node *node, Node *next) {
    node->next = next;
}

Node* get_next(Node *node) {
    return node->next;
}