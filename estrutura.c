#include "estrutura.h"
#include "lista.h"
#include <stdlib.h>

struct Estrutura {
    Lista* tabela_hash_nome[HASH_SIZE];
    Lista* tabela_hash_bairro[HASH_SIZE];
    Lista* tabela_hash_pessoas[HASH_SIZE];
    Lista* tabela_hash_criancas[2]; // 0 ou 1 para presença de crianças
    Lista* tabela_hash_renda[4];    // 1, 2, 3, ou 4 para faixas de renda
};

Estrutura* cria_estrutura() {
    Estrutura* estrutura = (Estrutura*)malloc(sizeof(Estrutura));
    if (estrutura == NULL) {
        exit(1);
    }

    // Inicialize as tabelas hash
    for (int i = 0; i < HASH_SIZE; i++) {
        estrutura->tabela_hash_nome[i] = cria_lista();
        estrutura->tabela_hash_bairro[i] = cria_lista();
        estrutura->tabela_hash_pessoas[i] = cria_lista();
    }

    estrutura->tabela_hash_criancas[0] = cria_lista();
    estrutura->tabela_hash_criancas[1] = cria_lista();

    estrutura->tabela_hash_renda[0] = cria_lista();
    estrutura->tabela_hash_renda[1] = cria_lista();
    estrutura->tabela_hash_renda[2] = cria_lista();
    estrutura->tabela_hash_renda[3] = cria_lista();

    return estrutura;
}

void insere_cliente(Estrutura* estrutura, Cliente* cliente) {
}

Lista* recupera_cliente(Estrutura* estrutura, int criterio, int valor, char* nome) {
}

void destroi_estrutura(Estrutura* estrutura) {
    free(estrutura);
}
