#include "cliente.h"

typedef struct Node Node;

Node* cria_node(Cliente *cliente);
Cliente* get_data(Node *node);
Node* get_next(Node *node);
void set_next(Node *node, Node *next);