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
    printf(" 1. SEQU�NCIA DE FIBONACCI\n 2. SEQU�NCIA DE TERMOS\n 3. OPERA��ES ARITM�TICAS\n 4. DOBRAS\n 5. SAIR DO PROGRAMA\n");
    printf("\n----------------------------------------------\n\n");

    printf(" BEM VINDO(A),DIGITE UM N�MERO PARA SER DIRECIONADO PARA O PROGRAMA QUE DESEJA USAR>>");
    scanf("%c",&n);

    switch(n){
    case'1':
        system("cls");
        printf(" ESSE PROGRAMA TEM COMO FUN��O CALCULAR E MOSTRAR A SEQU�NCIA FIBONACCI AT� O PRIMEIRO N�MERO SUPERIOR AO N�MERO DIGITADO\n\n");
        int num,antecessor=0,sucessor=1,soma;
        printf(" DIGITE UM N�MERO POSITIVO>>");
        scanf("%d",&num);
        while(num<0){
            printf(" N�MEROS NEGATIVOS N�O FUNCIONAR�O NESTE PROGRAMA,DIGITE UM N�MERO POSITIVO>>");
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
        printf(" ESSE PROGRAMA TEM COMO FUN��O CALCULAR E MOSTRAR A SEQU�NCIA DE TERMOS DO N�MERO DIGITADO AT� QUE O VALOR SEJA IGUAL A 1\n\n");
        int numero;
        printf(" DIGITE UM N�MERO POSITIVO>>");
        scanf("%d",&numero);
        while(numero<0){
            printf(" N�MEROS NEGATIVOS N�O FUNCIONAR�O NESTE PROGRAMA,DIGITE UM N�MERO POSITIVO>>");
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
        printf(" ESSE PROGRAMA TEM COMO FUN��O FAZER O C�LCULO ENTRE DOIS N�MEROS DIGITADOS SEJAM ELES POSITIVOS OU NEGATIVOS,INTEIROS OU COM VIRGULA.\n PERMITINDO CALCULAR A ADI��O,SUBTRA��O,MULTIPLICA��O E DIVIS�O\n\n");
        float num1,num2;
        char x;
        printf(" FA�A UMA OPERA��O ARITM�TICA COM DOIS N�MEROS>>");
        scanf("%f %c %f",&num1,&x,&num2);
        switch(x){
        case'+':
            printf(" A SOMA FOI>> %.2f",num1+num2);
            break;
        case'-':
            printf(" A SUBTRA��O FOI>> %.2f",num1-num2);
            break;
        case'*':
            printf(" A MULTIPLICA��O FOI>> %.2f",num1*num2);
            break;
        case'/':
            printf(" A DIVIS�O FOI>> %.2f",num1/num2);
            break;
        default:
            printf(" COMANDOS INV�LIDOS");
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
        printf(" ESSE PROGRAMA TEM COMO FUN��O CALCULAR A QUANTIDADE DE PEDA�OS DE PAPEL RESULTANTES DE UMA T�CNICA DE DOBRADURA\n\n");
        printf(" >>CASO O N�MERO DIGITADO FOR NEGATIVO, VOC� SER� REDIRECIONADO AO MENU<<\n");
        int onum,potencia1,raiz,pedacos;
        setlocale(LC_ALL,"portuguese");
        printf(" DIGITE UM N�MERO DE DOBRADURAS>>");
        scanf("%d",&onum);
        if(onum>0){
            potencia1=pow(2,onum);
            raiz=potencia1+1;
            pedacos=raiz*raiz;
            printf(" A QUANTIDADE DE PEDA�OS RESULTANTE FOI>>%d",pedacos);
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
