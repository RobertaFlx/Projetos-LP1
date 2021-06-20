#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <locale.h>
#include "lista.h"

LISTA* criar(){
    LISTA* li = (LISTA*) malloc(sizeof(LISTA));
    if(li != NULL)
    {
        li->inicio= NULL;
    }
    return li;
}

void liberar(LISTA *li){
    if(li !=NULL){
        ELEM * aux;
        while(li->inicio!=NULL)
        {
            aux = li->inicio;
            li->inicio = li->inicio->prox;
            free(aux);
        }
        free(li);
    }
}

int quantContatos(LISTA *li){
    if(li==NULL){
        return -1;
    }
    int cont=0;
    ELEM *aux = li->inicio;
    while(aux != NULL)
    {
        cont++;
        aux= aux->prox;
    }
    return cont;
}

void inserir(LISTA *li, CONTATO a)
{
    if(li==NULL)
    {
        printf("\n >>ERRO DE ALOCACAO<<\n");
    }
    else
    {
        ELEM *novo = (ELEM*) malloc(sizeof(ELEM));
        if(novo != NULL)
        {
            novo->dados= a;
            if(li->inicio==NULL){//LISTA VAZIA
                novo->prox=NULL;
                li->inicio=novo;
            }else{//LISTA NAO VAZIA
                ELEM *aux=li->inicio;
                if(aux->dados.codigo > novo->dados.codigo){//INSERÇÃO NO INICIO
                    novo->prox=aux;
                    li->inicio=novo;
                }else{//INSERÇÃO NO MEIO OU FIM
                    ELEM *ant;
                    while((aux!=NULL)&&(aux->dados.codigo < novo->dados.codigo)){
                        ant=aux;
                        aux=aux->prox;
                    }
                    ant->prox=novo;
                    novo->prox=aux;
                }

            }
            printf("\n >>ELEMENTO INSERIDO<<\n");
            getchar();
            getchar();
        }
        else
        {
            printf("\n >>ERRO DE ALOCACAO<<\n");
        }
    }
}

void remover(LISTA *li, int cod){
    if(li==NULL)
    {
        printf("\n >>ERRO DE ALOCACAO<<\n");
    }
    else  //LISTA ALOCADA
    {
        if(li->inicio==NULL)
        {
            printf("\n >>LISTA VAZIA<<\n");
        }
        else //SE NAO ESTIVER VAZIA
        {
            ELEM *aux=li->inicio;
            if(aux->dados.codigo==cod){//SE O ELEMENTO FOR O PRIMEIRO DA LISTA
                li->inicio=aux->prox;
                free(aux);
            }else{//O ELEMENTO NAO ESTA NO INICIO DA LISTA
                ELEM *ant;
                while((aux!=NULL)&&(aux->dados.codigo != cod)){
                    ant=aux;
                    aux=aux->prox;
                }
                if(aux==NULL){
                    return;
                }
                ant->prox = aux->prox;
                free(aux);
            }
            printf("\n >>ELEMENTO REMOVIDO<<\n");
        }
    }
}

void mostrarContatos(LISTA *li)
{
    system("cls");
    cabecalho();
    if(li == NULL)
    {
        printf("\n >>ERRO DE ALOCACAO<<\n");
    }
    else //LISTA ALOCADA
    {
        if(li->inicio==NULL)  //LISTA VAZIA
        {
            printf("\n >>LISTA VAZIA<<\n");
        }else{//HÁ ELEMENTO NA LISTA
            ELEM* aux = li->inicio;
            while(aux != NULL){
                printf(" CODIGO: %d\n",aux->dados.codigo);
                printf(" NOME: %s\n",aux->dados.nome);
                printf(" TELEFONE: %s\n",aux->dados.telefone);
                printf(" GRUPO: %s\n",aux->dados.grupo);
                printf("-----------------------------------------------------------\n");
                aux = aux->prox;
            }
        }
    }
}

void addContato(CONTATO *a)
{
    int opc;
    system("cls");
    printf("\n DIGITE O CODIGO>> ");
    scanf("%d",&a->codigo);
    printf(" DIGITE NOME>> ");
    fflush(stdin);
    strupr(gets(a->nome));
    printf(" DIGITE TELEFONE>> ");
    scanf("%s",a->telefone);

    do{
        system("cls");
        char vetorgrupo[4][10]={"FAMILIA","TRABALHO","AMIGOS","COLEGAS"};
        printf("\n >>ESCOLHA UM GRUPO PARA O CONTATO<<\n");

        printf("    1 - FAMILIA\n");
        printf("    2 - TRABALHO\n");
        printf("    3 - AMIGOS\n");
        printf("    4 - COLEGAS\n\n");
        printf(" OPÇAO>>");

       scanf("%d",&opc);

        switch(opc){
            case 1:{
                strcpy(a->grupo,vetorgrupo[0]);
                break;
            }
            case 2:{
                strcpy(a->grupo,vetorgrupo[1]);
                break;
            }
            case 3:{
                strcpy(a->grupo,vetorgrupo[2]);
                break;
            }
            case 4:{
                strcpy(a->grupo,vetorgrupo[3]);
                break;
            }

        }
    }while (opc!=1 && opc!=2 && opc!=3 && opc!=4);
}

int mostrarContato(LISTA *li){

	char nomeaux[120];
	ELEM *no = li->inicio,*aux = no;
	int achou = 0;

	printf("\n DIGITE O NOME DO CONTATO PARA MOSTRAR>> ");
	setbuf(stdin,NULL);
	strupr(gets(nomeaux));
	do {
		if(!strcmp(nomeaux,no->dados.nome)) {
		   achou = 1;
		   break;
	   }
		no = no->prox;
	} while(no!=aux && no!=NULL);

	if(achou==1) {

        printf(" CODIGO: %d\n",no->dados.codigo);
        printf(" NOME: %s\n",no->dados.nome);
        printf(" TELEFONE: %s\n",no->dados.telefone);
        printf(" GRUPO: %s\n",no->dados.grupo);
        printf("-----------------------------------------------------------\n");
		putchar('\n');
		getchar();

	} else {
		puts("\n >>CONTATO NÃO ENCONTRADO<<");
		getchar();
		return 0;
	}
	return 1;
	free(aux);
}

void limparTela(){
    printf("\n\t");
    system("pause");
    system("cls");
}

void cabecalho(){
    printf("\n-----------------------------------------------------------\n");
    printf("                  LISTA DE CONTATOS");
    printf("\n-----------------------------------------------------------\n");
}
