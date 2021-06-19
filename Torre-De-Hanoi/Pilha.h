#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct pilha Pilha;

Pilha * criar();

void destruir(Pilha * p);

int tamanho(Pilha * p);

int topo(Pilha * p);

void imprimirA(Pilha * p);

void imprimirB(Pilha * p);

void imprimirC(Pilha * p);

int desempilhar(Pilha * p);

void empilhar(Pilha * p, int x);

int mover(Pilha * origem, Pilha * destino);

int inicializar(Pilha * torreA, int * quantDiscos);

void finalizar(Pilha * torreA, Pilha * torreB, Pilha * torreC);

int movimentar(Pilha * torreA, Pilha * torreB, Pilha * torreC);

void mostrarPinos(Pilha * torreA, Pilha * torreB, Pilha * torreC);

void mostrarPossibilidades(Pilha * torreA, Pilha * torreB, Pilha * torreC);

#endif // PILHA_H_INCLUDED
