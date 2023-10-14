#include "cliente.h"
#include "lista.h"

#define TAB_SIZE 100

typedef struct Estrutura Estrutura;

Estrutura* cria_estrutura();
void insere_cliente(Estrutura *estrutura, int tipo_busca, Cliente *cliente);
Lista* recupera_cliente(Estrutura *estrutura, int tipo_busca, int criterio_numerico, const char *criterio_string);
void destroi_estrutura(Estrutura *estrutura);