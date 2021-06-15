#include<stdio.h>
#include<locale.h>
#include<string.h>

void imprimiraux(char string[100][100], int quantidade){
    int i, j;

    for(i=0;i<quantidade;i++){
        printf("%s", string[i]);
    }
}

/*COMPARA UMA PALAVRA DA MATRIZAUX COM A MATRIZDICIO*/
void comparar(char matrizaux[100], int quantcaract, int quantdicio, char matrizdicio[100][100]){
    int i,j,cont=0;
    for(i=0; i<quantdicio*2; i+=2){
        for(j=0; j<quantcaract; j++){
            if(matrizaux[j] == matrizdicio[i][j]){
                cont++;
            }
            else{
                break;
            }
        }
        if(cont == strlen(matrizdicio[i]) && strlen(matrizdicio[i]) == quantcaract){
            strcpy(matrizaux,matrizdicio[i+1]);
        }
        cont=0;
    }
}

main(){
int i,j,quantpalavras,quantlinhas,lin,col,a,b,cont=0,aux,instancias,inst;

setlocale(LC_ALL, "Portuguese");
printf("------------------------------------------------------------------------------------------");
printf("\nDIGITE A QUANTIDADE DE INSTÂNCIAS QUE SERÃO EXECUTADAS>> ");
scanf("%d",&instancias);
putchar('\n');

for(inst=0;inst<instancias;inst++){
int cont=0;
char matrizdicio[100][100]={},matrizcript[100][100]={},matrizaux[100][100]={};

printf("------------------------------------------------------------------------------------------");
printf("\nDE MODO QUE 1<QUANTIDADE<100, DIGITE A QUANTIDADE DE PALAVRAS DO DICIONÁRIO>> ");
scanf("%d",&quantpalavras);
while(quantpalavras<=1||quantpalavras>100){
    printf("\n>>QUANTIDADE DE PALAVRAS INVÁLIDA<<");
    printf("\nDE MODO QUE 1<QUANTIDADE<100, DIGITE A QUANTIDADE DE PALAVRAS DO DICIONÁRIO>> ");
    scanf("%d",&quantpalavras);
}

for(lin=0;lin<quantpalavras*2;lin=lin+=2){
    printf("\nDIGITE UMA PALAVRA CRIPTOGRAFADA>> ");
    scanf("%s",matrizdicio[lin]);
    setbuf(stdin,NULL);

    printf("\nDIGITE UM SIGNIFICADO, PODENDO SER UMA FRASE DE ATÉ 30 CARACTERES>> ");
    gets(matrizdicio[lin+1]);
    while(strlen(matrizdicio[lin+1])>30){
        printf("\n>>QUANTIDADE DE CARACTERES INVÁLIDA<<");
        printf("\nDIGITE UM SIGNIFICADO, PODENDO SER UMA FRASE DE ATÉ 30 CARACTERES>> ");
        gets(matrizdicio[lin+1]);
    }
}

printf("------------------------------------------------------------------------------------------");
printf("\nDE MODO QUE 1<QUANTIDADE<100, DIGITE A QUANTIDADE DE LINHAS DA MENSAGEM CRIPTOGRAFADA>> ");
scanf("%d",&quantlinhas);
while(quantlinhas<=1||quantlinhas>100){
    printf("\n>>QUANTIDADE INVÁLIDA<<");
    printf("\nDE MODO QUE 1<QUANTIDADE<100, DIGITE A QUANTIDADE DE LINHAS DA MENSAGEM CRIPTOGRAFADA>> ");
    scanf("%d",&quantlinhas);
}

for(lin=0;lin<quantlinhas;lin++){
    setbuf(stdin,NULL);
    printf("\nDIGITE A LINHA CRIPTOGRAFADA, PODENDO TER ATÉ 60 CARACTERES>> ");
    gets(matrizcript[lin]);
    while(strlen(matrizcript[lin])>60){
        printf("\n>>QUANTIDADE DE CARACTERES INVÁLIDA<<");
        printf("\nDIGITE A LINHA CRIPTOGRAFADA, PODENDO TER ATÉ 60 CARACTERES>> ");
        gets(matrizcript[lin]);
    }
}

/*QUEBRA AS FRASES EM STRINGS DIFERENTES*/
for(lin=0;lin<quantlinhas;lin++){
    aux=0;
    for(col=0;col<=strlen(matrizcript[lin]);col++){
        if(matrizcript[lin][col]==' '){
            b=0;
            for(a=aux;a<col;a++){
                matrizaux[lin+cont][b]=matrizcript[lin][a];
                b++;
            }
            aux=col+1;
            cont++;
            strcpy(matrizaux[lin+cont], " ");
            cont++;
        }
        if(matrizcript[lin][col]=='\0'){
            b=0;

            for(a=aux;a<col;a++){
                matrizaux[lin+cont][b]=matrizcript[lin][a];
                b++;
            }
            cont++;
            strcpy(matrizaux[lin+cont], "\n");

        }
    }
}

printf("------------------------------------------------------------------------------------------");

/*COMPARA TODAS AS PALAVRAS DA MATRIZAUX COM A MATRIZDICIO*/
for(i=0; i<=cont; i+=2){
    comparar(matrizaux[i],strlen(matrizaux[i]),quantpalavras,matrizdicio);
    }
putchar('\n');
printf("A MENSAGEM DESCRIPTOGRAFADA É>> ");
putchar('\n');
putchar('\n');
imprimiraux(matrizaux,++cont);
putchar('\n');
}
}
