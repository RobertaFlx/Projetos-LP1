#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Pilha.h"

int main() {

    int opcao=0,*A=NULL,*B=NULL,*C=NULL,estado = 1,quantDiscos = 0;

    do{
    system("cls");
    setlocale(LC_ALL, "Portuguese");
    printf("\n\n  ------------------------------------------------------\n\n");
    printf("    1 - VER AS REGRAS DO JOGO\n");
    printf("    2 - JOGAR TORRE DE HANÓI\n");
    printf("    3 - SAIR DO PROGRAMA\n\n");
    printf("  ------------------------------------------------------\n\n");
    printf("   DIGITE O NÚMERO RELACIONADO AO QUE DESEJA FAZER>>");
    scanf("%d",&opcao);

    switch(opcao){
    case 1:{
        system("cls");
        printf("\n\n-----------------------------------------------------------------------------------------------------------------\n\n");
        printf("   1. O OBJETIVO DO JOGO É DESLOCAR TODOS OS DISCOS DA TORRE A PARA A C.\n");
        printf("   2. PARA GANHAR, OS DISCOS NA TORRE C DEVEM ESTAR POSICIONADOS DA MESMA FORMA QUE INICIARAM NA TORRE A.\n");
        printf("   3. APENAS UM DISCO PODE SER MOVIMENTADO POR VEZ.\n");
        printf("   4. O DISCO A SER MOVIMENTADO NÃO PODE ESTAR NO MEIO OU NO FINAL DA TORRE, SEMPRE SERÁ MOVIMENTADO O TOPO.\n");
        printf("   5. UM DISCO DE NÚMERO MAIOR NUNCA PODERÁ SER COLOCADO EM CIMA DE UM DISCO DE NÚMERO MENOR QUE ELE.\n");
        printf("\n-----------------------------------------------------------------------------------------------------------------\n\n");
        system("pause");
    }
    break;
    case 2:
    {
    Pilha * A = criar();
    Pilha * B = criar();
    Pilha * C = criar();

    do{
        switch(estado){
            case 1 :
                system("cls");
                estado = inicializar(A,&quantDiscos);
                break;
            case 2 :
                system("cls");
                mostrarPinos(A,B,C);
            case 3 :
                mostrarPossibilidades(A,B,C);
            case 4 :
                estado = movimentar(A,B,C);
                break;
            case 5 :
                if(tamanho(C) == quantDiscos){
                    estado = 6;
                }
                else{
                    estado = 2;
                }
                break;
            case 6 :
                system("cls");
                mostrarPinos(A,B,C);
                finalizar(A,B,C);
                estado = 7;
                break;
        }
    }while(estado != 7);

    printf("\n PARABÉNS, VOCÊ CONSEGUIU!\n OBRIGADO POR JOGAR\n\n");
    system("pause");
    }
    break;
    }
    }while(opcao!=3);
}
