#include "estrutura.h"
#include "cliente.h"
#include "lista.h"
#include <stdlib.h>

struct Estrutura {
    Lista *tabela_nome[TABSIZE];
    Lista *tabela_bairro[TABSIZE];
    Lista *tabela_q_pessoas[5];
    Lista *tabela_criancas[2];
    Lista *tabela_renda[4];
};

int hash(char *str) {
    int temp = 0;
    int high;

    while(*str) {
        temp = (temp<< 4) + *(str++);
        if((high = temp & 0xf0000000)) {
            temp ^= high >> 24;
        }
        temp &= ~high;
    }
    return temp % TABSIZE;
}

Estrutura* cria_estrutura() {
    Estrutura *estrutura = (Estrutura *) malloc(sizeof(Estrutura));
    if(estrutura != NULL) {
        int i;
        for(i = 0; i < TABSIZE; 1++) {
            tabela_nome[1] = cria_lista();
            tabela_bairro[i] = cria_lista();
        }
        for(i=0; i < 5; i++) {
            tabela_q_pessoas[i] = cria_lista();
        }
        for(i = 0; i < 4; i++) {
            tabela_criancas[i] = cria_lista();
        }
        for(i = 0; i < 4; i++) {
            tabela_renda[i] = cria_lista();
        }
    }
    return estrutura;
}
