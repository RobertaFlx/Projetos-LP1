#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<windows.h>
main(){
char n,x;
setlocale(LC_ALL,"portuguese");
do{
    system("cls");
    printf("\n----------------------------------------------\n\n");
    printf(" 1. SEQUÊNCIA DE FIBONACCI\n 2. SEQUÊNCIA DE TERMOS\n 3. OPERAÇÕES ARITMÉTICAS\n 4. DOBRAS\n 5. SAIR DO PROGRAMA\n");
    printf("\n----------------------------------------------\n\n");

    printf(" BEM VINDO(A),DIGITE UM NÚMERO PARA SER DIRECIONADO PARA O PROGRAMA QUE DESEJA USAR>>");
    scanf("%c",&n);

    switch(n){
    case'1':
        system("cls");
        printf(" ESSE PROGRAMA TEM COMO FUNÇÃO CALCULAR E MOSTRAR A SEQUÊNCIA FIBONACCI ATÉ O PRIMEIRO NÚMERO SUPERIOR AO NÚMERO DIGITADO\n\n");
        int num,antecessor=0,sucessor=1,soma;
        printf(" DIGITE UM NÚMERO POSITIVO>>");
        scanf("%d",&num);
        while(num<0){
            printf(" NÚMEROS NEGATIVOS NÃO FUNCIONARÃO NESTE PROGRAMA,DIGITE UM NÚMERO POSITIVO>>");
            scanf("%d",&num);
        }
        printf(" 0 1");
        while(sucessor<=num && num>0){
            soma=antecessor+sucessor;
            printf(" %d",soma);
            antecessor=sucessor;
            sucessor=soma;}
    printf("\n");
    printf("DESEJA CONTINUAR? s/n: \n");
    scanf(" %c",&n);
    if(n=='n'){
    exit(0);
    }
    break;
    case'2':
        system("cls");
        printf(" ESSE PROGRAMA TEM COMO FUNÇÃO CALCULAR E MOSTRAR A SEQUÊNCIA DE TERMOS DO NÚMERO DIGITADO ATÉ QUE O VALOR SEJA IGUAL A 1\n\n");
        int numero;
        printf(" DIGITE UM NÚMERO POSITIVO>>");
        scanf("%d",&numero);
        while(numero<0){
            printf(" NÚMEROS NEGATIVOS NÃO FUNCIONARÃO NESTE PROGRAMA,DIGITE UM NÚMERO POSITIVO>>");
            scanf("%d",&numero);
            }
        if(numero%2==0 && numero>0){
            numero=numero/2;
            printf(" %d",numero);
        }
        else{
            numero=(3*numero)+1;
            printf(" %d",numero);
        }

        while(numero!=1){
            if(numero%2==0){
                numero=numero/2;
                printf("->%d",numero);
            }
            else{
                numero=(3*numero)+1;
                printf("->%d",numero);
                }
        }
    printf("\n");
    printf(" DESEJA CONTINUAR? s/n: \n");
    scanf(" %c",&n);
    if(n=='n'){
    exit(0);
    }
    break;
    case'3':
        system("cls");
        printf(" ESSE PROGRAMA TEM COMO FUNÇÃO FAZER O CÁLCULO ENTRE DOIS NÚMEROS DIGITADOS SEJAM ELES POSITIVOS OU NEGATIVOS,INTEIROS OU COM VIRGULA.\n PERMITINDO CALCULAR A ADIÇÃO,SUBTRAÇÃO,MULTIPLICAÇÃO E DIVISÃO\n\n");
        float num1,num2;
        char x;
        printf(" FAÇA UMA OPERAÇÃO ARITMÉTICA COM DOIS NÚMEROS>>");
        scanf("%f %c %f",&num1,&x,&num2);
        switch(x){
        case'+':
            printf(" A SOMA FOI>> %.2f",num1+num2);
            break;
        case'-':
            printf(" A SUBTRAÇÃO FOI>> %.2f",num1-num2);
            break;
        case'*':
            printf(" A MULTIPLICAÇÃO FOI>> %.2f",num1*num2);
            break;
        case'/':
            printf(" A DIVISÃO FOI>> %.2f",num1/num2);
            break;
        default:
            printf(" COMANDOS INVÁLIDOS");
    }
    printf("\n");
    printf(" DESEJA CONTINUAR? s/n: \n");
    scanf(" %c",&n);
    if(n=='n'){
    exit(0);
    }
    break;
    case'4':
        system("cls");
        printf(" ESSE PROGRAMA TEM COMO FUNÇÃO CALCULAR A QUANTIDADE DE PEDAÇOS DE PAPEL RESULTANTES DE UMA TÉCNICA DE DOBRADURA\n\n");
        printf(" >>CASO O NÚMERO DIGITADO FOR NEGATIVO, VOCÊ SERÁ REDIRECIONADO AO MENU<<\n");
        int onum,potencia1,raiz,pedacos;
        setlocale(LC_ALL,"portuguese");
        printf(" DIGITE UM NÚMERO DE DOBRADURAS>>");
        scanf("%d",&onum);
        if(onum>0){
            potencia1=pow(2,onum);
            raiz=potencia1+1;
            pedacos=raiz*raiz;
            printf(" A QUANTIDADE DE PEDAÇOS RESULTANTE FOI>>%d",pedacos);
        }
        else{
            break;
        }
    printf("\n");
    printf(" DESEJA CONTINUAR? s/n: \n");
    scanf(" %c",&n);
    if(n=='n'){
    exit(0);
    }
    break;
    case'5':
        system("cls");
        exit(0);
        break;
    }
} while(1);
}
