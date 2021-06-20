#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct {
    char nome[31];
    int codigo;
    char telefone[31];
    char grupo[31];
}CONTATO;

typedef struct elemento{
    CONTATO dados;
    struct elemento *prox;
} ELEM;

typedef struct{
    ELEM *inicio;
}LISTA;

LISTA* criar();

void liberar(LISTA *li);

int quantContatos(LISTA *li);

void inserir(LISTA *li, CONTATO a);

void remover(LISTA *li, int cod);

void mostrarContatos(LISTA *li);

void addContato(CONTATO *a);

int mostrarContato(LISTA *li);

void limparTela();

void cabecalho();

#endif // LISTA_H_INCLUDED
