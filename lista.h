#include "node.h"

typedef struct Lista Lista;

Lista* cria_lista();
int get_quantidade(Lista *lista);
Node* get_inicio(Lista *lista);
void insere_inicio(Lista *lista, Node *node);
void destroi_lista(Lista *lista);