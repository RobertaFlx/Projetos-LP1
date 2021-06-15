#include<stdio.h>
#include<string.h>
#include<locale.h>

float calcularmedia(float nota1, float nota2, float nota3, float nota4, float media){
    media=(nota1+nota2+nota3+nota4)/4;
    return media;
}

char *alunosituacao(char nome[16]){
    float nota1,nota2,nota3,nota4,media;
    char *situacao[]= {"APROVADO\n","REPROVADO\n"};

    printf("DIGITE NOTA 1 DE %s>>",nome);
    scanf("%f",&nota1);
    while(nota1<0 || nota1>10){
        printf(">>NOTA INVÁLIDA<<\n");
        printf("DIGITE NOTA 1 DE %s>>",nome);
        scanf("%f",&nota1);
    }
    printf("DIGITE NOTA 2 DE %s>>",nome);
    scanf("%f",&nota2);
    while(nota2<0 || nota2>10){
        printf(">>NOTA INVÁLIDA<<\n");
        printf("DIGITE NOTA 2 DE %s>>",nome);
        scanf("%f",&nota2);
    }
    printf("DIGITE NOTA 3 DE %s>>",nome);
    scanf("%f",&nota3);
    while(nota3<0 || nota3>10){
        printf(">>NOTA INVÁLIDA<<\n");
        printf("DIGITE NOTA 3 DE %s>>",nome);
        scanf("%f",&nota3);
    }
    printf("DIGITE NOTA 4 DE %s>>",nome);
    scanf("%f",&nota4);
    while(nota4<0 || nota4>10){
        printf(">>NOTA INVÁLIDA<<\n");
        printf("DIGITE NOTA 4 DE %s>>",nome);
        scanf("%f",&nota4);
    }
    printf("\n>>MEDIA DE %s %.2f\n",nome,calcularmedia(nota1,nota2,nota3,nota4,media));

    if (calcularmedia(nota1,nota2,nota3,nota4,media)>=7){
        return situacao[0];
    }
    else{
        return situacao[1];
    }
}

void nomealunos(char nome[20][2][16]){
    int i,j;
    char aux[16];

    for(i=0;i<20;i++){
        printf("\nDIGITE O NOME DO ALUNO>>");
        setbuf(stdin,NULL);
        strupr(gets(nome[i][0]));
        while(strlen(nome[i][0])>15){
            printf("\n>>QUANTIDADE DE CARACTERES INVÁLIDA<<");
            printf("\nDIGITE NOVAMENTE O NOME DO ALUNO>>");
            setbuf(stdin,NULL);
            strupr(gets(nome[i][0]));
        }

        strcpy(aux,alunosituacao(nome[i]));
        strcpy(nome[i][1],aux);
    }
}

void mostrar(char nome[20][2][16]){
    int i;
    for(i=0;i<20;i++){
        printf("%s %s",nome[i][0],nome[i][1]);
    }
}

main(){
char nome[20][2][16],*vetor;
vetor= nome;
setlocale(LC_ALL, "Portuguese");

printf("-----------------------------------------------");
printf("\n        >>INSIRA OS DADOS DOS ALUNOS<<\n");
printf("-----------------------------------------------\n");
printf("\n>>TODO NOME DIGITADO DEVE ATÉ 15 CARACTERES<<\n");
printf("\n>>TODO NOTA ATRIBUIDA DEVE SER DE 0 ATÉ 10<<\n");
nomealunos(nome);

printf("-----------------------------------------------");
printf("\n             >>SITUAÇÃO FINAL<<\n");
printf("-----------------------------------------------\n");

mostrar(nome);

}
