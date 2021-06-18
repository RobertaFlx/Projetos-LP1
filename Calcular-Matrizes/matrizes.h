#ifndef MATRIZES_H_INCLUDED
#define MATRIZES_H_INCLUDED

int** alocar(int quantLinhas,int quantColun);

void liberar(int **m,int quantLinhas);

void oposta(int **m, int quantLinhas,int quantColun);

void multiescalar(int **p,int quantLinhas,int quantColun);

void somamatriz(int **p,int **m, int quantLinhas,int quantColun);

void subtmatriz(int **p,int **m, int quantLinhas,int quantColun);

void multimatrizes(int **matA,int **matB,int **matC, int quantLinhasA,int quantColunA, int quantLinhasB,int quantColunB);

void matrizTransposta(int quantLinhas, int quantColun);

#endif // MATRIZES_H_INCLUDED
