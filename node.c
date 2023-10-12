#include "node.h"
#include <stdlib.h>

Node *cria_node(Cliente *cliente) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (node) {
        node->data = cliente;
        node->next = NULL;
    }
    return node;
}

void destroi_node(Node *node) {
    free(node);
}

Cliente *get_data(Node *node) {
    return node->data;
}
