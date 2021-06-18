#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "matrizes.h"

int main()
{
    int op,quantLinhas,quantColun,quantLinhasB,quantColunB,**matA=NULL,**matB=NULL,**matC=NULL;
    do{
        setlocale(LC_ALL, "Portuguese");
        system("cls");
        printf("\n-----------------------------------------------------------------\n");
        printf("\n 1 - ACHAR MATRIZ OPOSTA");
        printf("\n 2 - MULTIPLICAÇÃO DE UMA MATRIZ POR UM ESCALAR");
        printf("\n 3 - SOMA ENTRE DUAS MATRIZES");
        printf("\n 4 - SUBTRAÇÃO ENTRE DUAS MATRIZES");
        printf("\n 5 - MULTIPLICAÇÃO ENTRE DUAS MATRIZES");
        printf("\n 6 - ACHAR MATRIZ TRANSPOSTA");
        printf("\n 0 - SAIR DO PROGRAMA\n");
        printf("\n-----------------------------------------------------------------\n");
        printf("\nDIGITE O NÚMERO RELACIONADO AO QUE DESEJA FAZER>>");
        scanf("%d",&op);
        getchar();
        switch(op){
        case 1:
            system("cls");
            printf("\nDIGITE O NÚMERO DE LINHAS DA MATRIZ>>");
            scanf("%d",&quantLinhas);
            printf("\nDIGITE O NÚMERO DE COLUNAS DA MATRIZ>>");
            scanf("%d",&quantColun);
            putchar('\n');
            matA = alocar(quantLinhas,quantColun);
            oposta(matA,quantLinhas,quantColun);
            liberar(matA,quantLinhas);
            getchar();
        break;
        case 2:
            system("cls");
            printf("\nDIGITE O NÚMERO DE LINHAS DA MATRIZ>>");
            scanf("%d",&quantLinhas);
            printf("\nDIGITE O NÚMERO DE COLUNAS DA MATRIZ>>");
            scanf("%d",&quantColun);
            putchar('\n');
            matA = alocar(quantLinhas,quantColun);
            multiescalar(matA,quantLinhas,quantColun);
            liberar(matA,quantLinhas);
            getchar();
        break;
        case 3:
            system("cls");
            printf("\n>>PARA REALIZAR SOMA ENTRE MATRIZES ELAS DEVEM TER A MESMA QUANTIDADE DE LINHAS E MESMA QUANTIDADE DE COLUNAS<<\n");
            printf("\nDIGITE O NÚMERO DE LINHAS DAS MATRIZES>>");
            scanf("%d",&quantLinhas);
            printf("\nDIGITE O NÚMERO DE COLUNAS DAS MATRIZES>>");
            scanf("%d",&quantColun);
            putchar('\n');
            matA = alocar(quantLinhas,quantColun);
            matB= alocar(quantLinhas,quantColun);
            somamatriz(matA,matB,quantLinhas,quantColun);
            liberar(matA,quantLinhas);
            liberar(matB,quantLinhas);
            getchar();
        break;
        case 4:
            system("cls");
            printf("\n>>PARA REALIZAR SUBTRAÇÃO ENTRE MATRIZES ELAS DEVEM TER A MESMA QUANTIDADE DE LINHAS E MESMA QUANTIDADE DE COLUNAS<<\n");
            printf("\nDIGITE O NÚMERO DE LINHAS DAS MATRIZES>>");
            scanf("%d",&quantLinhas);
            printf("\nDIGITE O NÚMERO DE COLUNAS DAS MATRIZES>>");
            scanf("%d",&quantColun);
            putchar('\n');
            matA = alocar(quantLinhas,quantColun);
            matB= alocar(quantLinhas,quantColun);
            subtmatriz(matA,matB,quantLinhas,quantColun);
            liberar(matA,quantLinhas);
            liberar(matB,quantLinhas);
            getchar();
        break;
        case 5:
            system("cls");
            printf("\n>>A QUANTIDADE DE COLUNAS DA PRIMEIRA DEVE SER IGUAL A QUANTIDADE DE LINHAS DA SEGUNDA<<\n");
            printf("\nDIGITE O NÚMERO DE LINHAS DA MATRIZ A>>");
            scanf("%d",&quantLinhas);
            printf("\nDIGITE O NÚMERO DE COLUNAS DA MATRIZ A>>");
            scanf("%d",&quantColun);
            printf("\nDIGITE O NÚMERO DE LINHAS DA MATRIZ B>>");
            scanf("%d",&quantLinhasB);
            printf("\nDIGITE O NÚMERO DE COLUNAS DA MATRIZ B>>");
            scanf("%d",&quantColunB);
             while(quantColun!=quantLinhasB){
                system("cls");
                printf("\n>>OS VALORES SÃO INVÁLIDOS PARA UMA MULTIPLICAÇÃO ENTRE MATRIZES<<\n");
                printf(">>A QUANTIDADE DE COLUNAS DA PRIMEIRA MATRIZ E A QUANTIDADE DE LINHAS DA SEGUNDA MATRIZ DEVEM SER IGUAIS<<\n");
                printf("\nDIGITE O NÚMERO DE LINHAS DA MATRIZ A>>");
                scanf("%d",&quantLinhas);
                printf("\nDIGITE O NÚMERO DE COLUNAS DA MATRIZ A>>");
                scanf("%d",&quantColun);
                printf("\nDIGITE O NÚMERO DE LINHAS DA MATRIZ B>>");
                scanf("%d",&quantLinhasB);
                printf("\nDIGITE O NÚMERO DE COLUNAS DA MATRIZ B>>");
                scanf("%d",&quantColunB);
            }
            matA = alocar(quantLinhas,quantColun);
            matB = alocar(quantLinhasB,quantColunB);
            matC = alocar(quantLinhas,quantColunB);
            multimatrizes(matA,matB,matC,quantLinhas,quantColun,quantLinhasB,quantColunB);
            liberar(matA,quantLinhas);
            liberar(matB,quantLinhas);
            liberar(matC,quantLinhas);
            getchar();
        break;
        case 6:
            system("cls");
            printf("\nDIGITE O NÚMERO DE LINHAS>>");
            scanf("%d",&quantLinhas);
            printf("\nDIGITE O NÚMERO DE COLUNAS>>");
            scanf("%d",&quantColun);
            putchar('\n');
            matrizTransposta(quantLinhas,quantColun);
            getchar();
        break;
        }
        getchar();
    }while(op!=0);

}
