#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include "cliente.h"

#define TABSIZE 1009

typedef struct Estrutura Estrutura;
Estrutura* cria_estrutura();
void insere_cliente(Estrutura* estrutura, Cliente* cliente);
Lista* recupera_cliente(Estrutura* estrutura, int criterio, int valor, char* nome);
void destroi_estrutura(Estrutura* estrutura);

#endif
