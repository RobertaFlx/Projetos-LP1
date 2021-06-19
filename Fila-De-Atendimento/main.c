#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

typedef struct elemento{
    int senha;
    struct elemento *proximo;

}ELEM;

typedef struct {
    ELEM *inicio;
    ELEM *fim;
}FILA;

FILA *criarFila(){

    FILA *fi = (FILA*) malloc(sizeof(FILA));

    if (fi == NULL){
        return NULL;
    } else {
        fi->inicio = NULL;
        fi->fim = NULL;
    }
}

int addElemento(FILA *fi, int Senha){
    if(fi==NULL){
        return 1;
    } else {
        ELEM *no = (ELEM*) malloc(sizeof(ELEM));
        if(no != NULL) {
            no->senha = Senha;
            no->proximo = NULL;

            if(fi->fim==NULL){
                fi->inicio=no;
            } else {
                fi->fim->proximo=no;
            }
            fi->fim=no;
            return 0;
        } else {
            return 1;
        }
    }
}

int removerElemento(FILA *fi){
    if(fi==NULL){
        return 1;
    } else{
        if(fi->inicio==NULL){
            return 1;
        } else {
            ELEM *no = fi->inicio;
            fi->inicio = fi->inicio->proximo;

            if(fi->inicio == NULL){
                fi->fim = NULL;
            }
            free(no);
            return 0;
        }
    }
}

int quantElementos(FILA *fi){
    if(fi==NULL){
        return 1;
    }
    int cont=0;
    ELEM *no = fi->inicio;
    while(no != NULL){
        cont++;
        no= no->proximo;
    }
    return cont;
}

int mostrar(FILA *fi){
    if(fi == NULL){
        return 1;
    } else {
        if(fi->fim==NULL){
            return 1;
        } else {
            ELEM *no = fi->inicio;
            return no->senha;
        }
    }
}

void liberar(FILA *fi){
    if(fi != NULL){
        ELEM *no;
        while(fi->inicio!=NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->proximo;
            free(no);
        }
        free(fi);
    }
}

void limparTela(){
    printf("\n  ");
    system("pause");
    system("cls");
}

main(){

    setlocale(LC_ALL, "Portuguese");
    FILA *filaN = criarFila();
    FILA *filaP = criarFila();

    int senhaNormal,senhaPreferencial,opcao;

 do{
    system("cls");
    printf("\n\n------------------------------------------------------------\n\n");
    printf("     OPÇÕES DO SISTEMA\n\n");
    printf("\t 1 - CRIAR SENHA PARA FILA NORMAL\n");
    printf("\t 2 - CRIAR SENHA PARA FILA PREFERENCIAL\n");
    printf("\t 3 - CHAMAR SENHAS\n");
    printf("\t 4 - SAIR DO PROGRAMA\n\n");
    printf("------------------------------------------------------------\n\n");
    printf("     ESCOLHA UMA OPÇÃO>>");
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
            senhaNormal = rand()%1000;//TODAS AS SENHAS MENORES QUE 1000, SERÃO PARA A FILA NORMAL
            addElemento(filaN, senhaNormal);
            printf("\n------------------------------------------------------------\n\n");
            printf("           >>SENHA CRIADA PARA FILA NORMAL: %d<<\n",senhaNormal);
            printf("\n------------------------------------------------------------\n");
            getchar();
            getchar();
            break;
        case 2:
            senhaPreferencial = 1000 + rand()%1000;//TODAS AS SENHAS MAIORES QUE 1000, SERÃO PARA A FILA PREFERENCIAL
            addElemento(filaP, senhaPreferencial);
            printf("\n------------------------------------------------------------\n\n");
            printf("       >>SENHA CRIADA PARA FILA PREFERENCIAL: %d<<\n",senhaPreferencial);
            printf("\n------------------------------------------------------------\n");
            getchar();
            getchar();
            break;
        case 3:
            if (quantElementos(filaP) == 0 && quantElementos(filaN) != 0){//TEM ELEMENTOS NA FILA NORMAL MAS NÃO TEM NA PREFERENCIAL
            printf("\n------------------------------------------------------------\n\n");
            printf("\t     >>CHAMANDO SENHA NORMAL: %d<<", mostrar(filaN));
            printf("\n\n------------------------------------------------------------\n");
            removerElemento(filaN);
            getchar();
            getchar();
            }
            else{
            if(quantElementos(filaP) == 0){//AS DUAS FILAS ESTÃO VAZIAS
                printf("\n------------------------------------------------------------\n\n");
                printf("\t      >>NÃO HÁ PESSOAS EM ESPERA<<");
                printf("\n\n------------------------------------------------------------\n");
                getchar();
                getchar();
            }
            else{//TEM ELEMENTOS NA LISTA PREFERENCIAL
                printf("\n------------------------------------------------------------\n\n");
                printf("\t  >>CHAMANDO SENHA PREFERENCIAL: %d<<", mostrar(filaP));
                printf("\n\n------------------------------------------------------------\n");
                removerElemento(filaP);
                getchar();
                getchar();
            }
            }
            break;
        case 4:
            break;
        default:
            printf("\n  OPÇÃO INVÁLIDA");
            limparTela();
            break;

    }
    }while(opcao != 4);

liberar(filaN);
liberar(filaP);

}
