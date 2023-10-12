#ifndef CLIENTE_H
#define CLIENTE_H   

typedef struct {
    char nome[41];
    char bairro[41];
    int pessoas;
    int criancas;
    double renda;
} Cliente;

Cliente *cria_cliente(const char *nome, const char *bairro, int pessoas, int criancas, double renda);
const char *get_nome(Cliente *cliente);
const char *get_bairro(Cliente *cliente);
int get_pessoas(Cliente *cliente);
int get_criancas(Cliente *cliente);
double get_renda(Cliente *cliente);

#endif
