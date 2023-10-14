typedef struct Cliente Cliente;

Cliente* cria_cliente(char *nome, char *bairro, int qtd_pessoas, int criancas, double renda_bruta);
char* get_nome(Cliente *cliente);
char* get_bairro(Cliente *cliente);
int get_pessoas(Cliente *cliente);
int get_criancas(Cliente *cliente);
double get_renda(Cliente *cliente);
int get_faixa_renda(Cliente *cliente);
