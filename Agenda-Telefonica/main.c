#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <locale.h>
#include "lista.h"

main(){

    int op,cod;
    setlocale(LC_ALL, "Portuguese");
    LISTA *li = criar();

    CONTATO a;

    do{
        system("cls");
        printf("\n\n    OPÇÕES DA LISTA TELEFONICA:\n\n");
        printf("      1 - ADICIONAR NOVO CONTATO\n");
        printf("      2 - MOSTRAR TODOS OS CONTATOS\n");
        printf("      3 - MOSTRAR QUANTIDADE DE CONTATOS\n");
        printf("      4 - REMOVER CONTATO EXISTENTE\n");
        printf("      5 - MOSTRAR CONTATO A PARTIR DE NOME\n");
        printf("      6 - SAIR DO PROGRAMA\n\n");
        printf("    OPÇÃO:");
        scanf("%d", &op);


        switch(op){
            case 1:{
                addContato(&a);
                inserir(li,a);
                break;
            }
            case 2:{
                mostrarContatos(li);
                getchar();
                getchar();
                break;
            }
            case 3:{
                int quant=quantContatos(li);
                if(quant==0){
                printf("\n >>SUA LISTA DE CONTATOS ESTÁ VAZIA<<");
                }
                else{
                printf("\n >>LISTA DE CONTATOS COM %d ELEMENTO(S)<<\n",quant);
                }
                getchar();
                getchar();
                break;
            }
            case 4:{
                mostrarContatos(li);
                printf(" DIGITE O CÓDIGO DO CONTATO QUE SERÁ REMOVIDO>> ");
                scanf("%d",&cod);
                remover(li,cod);
                getchar();
                getchar();
                break;
            }
            case 5:{
                mostrarContato(li);
                break;
            }
            case 6:{
                break;
            }
            default:{
                printf("\n\t >>OPÇÃO INVÁLIDA<<\n");
                limparTela();
                break;
            }
        }
    }while(op != 6);
}
