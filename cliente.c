#include "cliente.h"
#include <stdlib.h>
#include <strings.h>

struct Cliente_ {
    char nome[41];
    char bairro[41];
    int q_pessoas;
    int criancas;
    double renda_bruta;
    int faixa_renda;
};

Cliente* cria_cliente(char *nome, char *bairro, int qtd_pessoas, int criancas, double renda_bruta);{
    Cliente *cliente = (Cliente *) malloc(sizeof(Cliente));
    if(cliente != NULL) {
        strcopy(cliente->nome, nome);
        strcopy(cliente->bairro, bairro);
        cliente->q_pessoas = qtd_pessoas;
        cliente->criancas = criancas;
        cliente->renda_bruta = renda_bruta;
        if(renda_bruta < 2000.0) {
            cliente->faixa_renda = 1;
        } else if (renda_bruta <= 3000.0){
            cliente->faixa_renda = 2;
        } else if (renda_bruta <= 5000.0){
            cliente->faixa_renda = 3;
        } else{
            cliente->faixa_renda = 4;
        }
    }
    return cliente;
}

char* get_nome(Cliente *cliente) {
    return cliente->nome;
}
char* get_bairro(Cliente *cliente) {
    return cliente->bairro;
}
int get_pessoas(Cliente *cliente) {
    return cliente->q_pessoas;
}
int get_criancas(Cliente *cliente) {
    return cliente->criancas;
}
double get_renda(Cliente *cliente) {
    return cliente->renda_bruta;
}
int get_faixa_renda(Cliente *cliente) {
    return cliente->faixa_renda;
}