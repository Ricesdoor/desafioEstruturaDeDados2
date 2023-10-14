#include "estrutura.h"
#include "lista.h"
#include "node.h"
#include <stdlib.h>
#include <string.h>

struct Estrutura {
    Lista *tabela_nome[TAB_SIZE];
    Lista *tabela_bairro[TAB_SIZE];
    Lista *tabela_q_pessoas[5];
    Lista *tabela_criancas[2];
    Lista *tabela_renda[4];
};

int hash(const char *str) {
    int temp = 0;
    int high;

    while(*str) {
        temp = (temp << 4) + *(str++);
        if((high = temp & 0xf0000000)) {
            temp ^= high >> 24;
        }
        temp &= ~high;
    }
    return temp % TAB_SIZE;
}

Estrutura* cria_estrutura() {
    Estrutura *estrutura = (Estrutura *) malloc(sizeof(Estrutura));
    if(estrutura != NULL) {
        int i;
        for(i = 0; i < TAB_SIZE; i++) {
            estrutura->tabela_nome[i] = cria_lista();
            estrutura->tabela_bairro[i] = cria_lista();
        }
        for(i=0; i < 5; i++) {
            estrutura->tabela_q_pessoas[i] = cria_lista();
        }
        for(i = 0; i < 2; i++) {
            estrutura->tabela_criancas[i] = cria_lista();
        }
        for(i = 0; i < 4; i++) {
            estrutura->tabela_renda[i] = cria_lista();
        }
    }
    return estrutura;
}

void insere_cliente(Estrutura *estrutura, int tipo_busca, Cliente *cliente){
    if (estrutura == NULL || cliente == NULL) {
        return;
    }

    switch (tipo_busca){
        case 1:
            {
                char *nome = get_nome(cliente);
                int hash_value = hash(nome);
                int index = hash_value % TAB_SIZE;
                Lista *lista = estrutura->tabela_nome[index];
                Node *node = cria_node(cliente);
                insere_inicio(lista, node);
            }
            break;

        case 2:
            {
                char *bairro = get_bairro(cliente);
                int hash_value = hash(bairro);
                int index = hash_value % TAB_SIZE;
                Lista *lista = estrutura->tabela_bairro[index];
                Node *node = cria_node(cliente);
                insere_inicio(lista, node);
            }
            break;

        case 3:
            {
                int qtd_pessoas = get_pessoas(cliente);
                if (qtd_pessoas >= 1 && qtd_pessoas <= 5) {
                    Lista *lista = estrutura->tabela_q_pessoas[qtd_pessoas - 1];
                    Node *node = cria_node(cliente);
                    insere_inicio(lista, node);
                }
            }
            break;

        case 4:
            {
                int criancas = get_criancas(cliente);
                Lista *lista = estrutura->tabela_criancas[criancas];
                Node *node = cria_node(cliente);
                insere_inicio(lista, node);
            }
            break;

        case 5:
            {
                int faixa_renda = get_faixa_renda(cliente);
                Lista *lista = estrutura->tabela_renda[faixa_renda - 1];
                Node *node = cria_node(cliente);
                insere_inicio(lista, node);
            }
            break;
    }   
}

Lista* recupera_cliente(Estrutura *estrutura, int tipo_busca, int criterio_numerico, const char *criterio_string) {
    Lista *resultados = cria_lista();

    if (estrutura == NULL) {
        return resultados;
    }

    int index;
    switch (tipo_busca) {
        case 1: 
            if (criterio_string == NULL) {
                return resultados; // Não há critério para buscar
            }
            index = hash(criterio_string) % TAB_SIZE;
            Lista *lista = estrutura->tabela_nome[index];
            Node *cursor = get_inicio(lista);
            while (cursor != NULL) {
                Cliente *cliente = (Cliente *)get_data(cursor);
                if (strcmp(criterio_string, get_nome(cliente)) == 0) {
                    Node *result_node = cria_node(cliente);
                    insere_inicio(resultados, result_node);
                }
                cursor = get_next(cursor);
            }
            break;

        case 2:
            if (criterio_string == NULL) {
                return resultados; // Não há critério para buscar
            }
            index = hash(criterio_string) % TAB_SIZE;
            lista = estrutura->tabela_bairro[index];
            cursor = get_inicio(lista);
            while (cursor != NULL) {
                Cliente *cliente = (Cliente *)get_data(cursor);
                if (strcmp(criterio_string, get_bairro(cliente)) == 0) {
                    Node *result_node = cria_node(cliente);
                    insere_inicio(resultados, result_node);
                }
                cursor = get_next(cursor);
            }
            break;

        case 3:
            if (criterio_numerico < 1 || criterio_numerico > 5) {
                return resultados; // Critério numérico inválido
            }
            Lista *qtd_pessoas_lista = estrutura->tabela_q_pessoas[criterio_numerico - 1];
            Node *qtd_pessoas_cursor = get_inicio(qtd_pessoas_lista);
            while (qtd_pessoas_cursor != NULL) {
                Cliente *cliente = (Cliente *)get_data(qtd_pessoas_cursor);
                Node *result_node = cria_node(cliente);
                insere_inicio(resultados, result_node);
                qtd_pessoas_cursor = get_next(qtd_pessoas_cursor);
            }
            break;

        case 4:
            if (criterio_numerico < 0 || criterio_numerico > 1) {
                return resultados; // Critério numérico inválido
            }
            Lista *criancas_lista = estrutura->tabela_criancas[criterio_numerico];
            Node *criancas_cursor = get_inicio(criancas_lista);
            while (criancas_cursor != NULL) {
                Cliente *cliente = (Cliente *)get_data(criancas_cursor);
                Node *result_node = cria_node(cliente);
                insere_inicio(resultados, result_node);
                criancas_cursor = get_next(criancas_cursor);
            }
            break;

        case 5:
            if (criterio_numerico < 1 || criterio_numerico > 4) {
                return resultados; // Critério numérico inválido
            }
            Lista *renda_lista = estrutura->tabela_renda[criterio_numerico - 1];
            Node *renda_cursor = get_inicio(renda_lista);
            while (renda_cursor != NULL) {
                Cliente *cliente = (Cliente *)get_data(renda_cursor);
                Node *result_node = cria_node(cliente);
                insere_inicio(resultados, result_node);
                renda_cursor = get_next(renda_cursor);
            }
            break;
    }

    return resultados;
}

void destroi_estrutura(Estrutura *estrutura) {
    if (estrutura == NULL) {
        return;
    }

    int i;
    for (i = 0; i < TAB_SIZE; i++) {
        destroi_lista(estrutura->tabela_nome[i]);
        destroi_lista(estrutura->tabela_bairro[i]);
    }
    for (i = 0; i < 5; i++) {
        destroi_lista(estrutura->tabela_q_pessoas[i]);
    }
    for (i = 0; i < 2; i++) {
        destroi_lista(estrutura->tabela_criancas[i]);
    }
    for (i = 0; i < 4; i++) {
        destroi_lista(estrutura->tabela_renda[i]);
    }

    free(estrutura);
}