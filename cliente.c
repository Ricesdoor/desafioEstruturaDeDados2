#include <stdio.h>
#include <string.h>
#include "cliente.h"

Cliente *cria_cliente(const char *nome, const char *bairro, int pessoas, int criancas, double renda) {
    Cliente *cliente = malloc(sizeof(Cliente));
    if (cliente != NULL) {
        strncpy(cliente->nome, nome, 41);
        strncpy(cliente->bairro, bairro, 41);
        cliente->pessoas = pessoas;
        cliente->criancas = criancas;
        cliente->renda = renda;
    }
    return cliente;
}

const char *get_nome(Cliente *cliente) {
    return cliente->nome;
}

const char *get_bairro(Cliente *cliente) {
    return cliente->bairro;
}

int get_pessoas(Cliente *cliente) {
    return cliente->pessoas;
}

int get_criancas(Cliente *cliente) {
    return cliente->criancas;
}

double get_renda(Cliente *cliente) {
    return cliente->renda;
}
