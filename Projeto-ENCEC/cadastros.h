#ifndef CADASTROS_H_INCLUDED
#define CADASTROS_H_INCLUDED

#define D 50

void cabecalho();
void limparTela();
void menu();

/*--------------------CONGRESSISTAS-----------------------*/

FILE *CONGRE;
FILE *AUXCONGRE;

typedef struct{
    int codigo;
    char nome[D];
    char cpf[D];
    char email[D];
}CONGRESSISTA;

int Congressistas();
void cadastrarCongressita();
int removerCongressista();
int editarCongressista();
void mostrarCongressistas();

/*--------------------PALESTRANTES-----------------------*/

FILE *PALES;
FILE *AUXPALES;

typedef struct{
    int codigo;
    char nome[D];
    char email[D];
    char formacao[D];
}PALESTRANTE;

int Palestrantes();
void cadastrarPalestrante();
int removerPalestrante();
int editarPalestrante();
void mostrarPalestrantes();

/*--------------------ORGANIZADORES-----------------------*/

FILE *ORGAN;
FILE *AUXORGAN;

typedef struct{
    int codigo;
    char nome[D];
    char cpf[D];
    char email[D];
}ORGANIZADOR;

int Organizadores();
void cadastrarOrganizador();
int removerOrganizador();
int editarOrganizador();
void mostrarOrganizadores();



#endif // CADASTROS_H_INCLUDED
