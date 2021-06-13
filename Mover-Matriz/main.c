#include <stdio.h>
#include <locale.h>
int linhas=1,colunas=1;
char matriz[20][20], aux[20][20];

void colocarauxmatriz(){
  int i,j;
    for(i=0;i<linhas;i++){
        for(j=0;j<colunas;j++){
            matriz[i][j] = aux[i][j];
        }
    }
}

void printarmatriz(){
  int i,j;
  for(i=0;i<linhas;i++){
    for(j=0;j<colunas;j++){
      printf("%c ", matriz[i][j]);
    }
    putchar('\n');
  }
}

void printaraux(){
  int i,j;
  for(i=0;i<linhas;i++){
    for(j=0;j<colunas;j++){
      printf("%c ", aux[i][j]);
    }
    putchar('\n');
  }
}

void movercima(int somavert){
  int i,j,a;
  for(a=1;a<=somavert;a++){
    for(i=0;i<=linhas;i++){
      for(j=0;j<colunas;j++){
        if(i==linhas){
          aux[linhas-1][j] = matriz[0][j];
        }else{
          aux[i][j] = matriz[i+1][j];
        }
      }
    }
    colocarauxmatriz();
  }

}

void moverbaixo(int somavert){
  int i,j,a;
  for(a=1;a<=somavert;a++){
    for(i=0;i<linhas;i++){
      for(j=0;j<colunas;j++){
        aux[i+1][j]=matriz[i][j];
        if(i==linhas-1){
          aux[0][j] = matriz[i][j];
        }else{
          aux[i+1][j] = matriz[i][j];
        }
      }
    }
    colocarauxmatriz();
  }

}

void moverdireita(int somahoriz){
  int i,j,a;
  for(a=1;a<=somahoriz;a++){
    for(i=0;i<linhas;i++){
      for(j=0;j<colunas;j++){
        if(j==colunas-1){
          aux[i][0] = matriz[i][j];
        }else{
          aux[i][j+1]=matriz[i][j];
        }
      }
    }
    colocarauxmatriz();
  }

}

void moveresquerda(int somahoriz){
int i,j,a;
  for(a=1;a<=somahoriz;a++){
    for(i=0;i<linhas;i++){
      for(j=0;j<=colunas;j++){
        if(j==colunas){
          aux[i][j-1] = matriz[i][0];
        }else{
          aux[i][j]=matriz[i][j+1];
        }
      }
    }
    colocarauxmatriz();
  }

}


main() {
    int vertical=1, horizontal=1, i, j,somavert, somahoriz;
    setlocale(LC_ALL,"Portuguese");

    while(linhas!=0 && colunas!=0){
    somavert=0;
    somahoriz=0;
    printf("DIGITE AS DUAS DIMENSOES DA MATRIZ>>");
    scanf("%d %d",&linhas,&colunas);

    /*RECEBE A MATRIZ*/
    for(i=0;i<linhas;i++){
      for(j=0;j<colunas;j++){
        printf("INSIRA UMA LETRA NA MATRIZ>>");
        setbuf(stdin,NULL);
        scanf("%c",&matriz[i][j]);
      }
    }

    /*IMPRIME A MATRIZ*/
    printarmatriz();
    putchar('\n');

    /*RECEBE AS ALTERAÇÕES*/
    while(vertical!=0 || horizontal!=0){
      printf("DIGITE ALTERAÇÕES PARA A MATRIZ>>");
      scanf("%d %d", &vertical, &horizontal);
      somavert = somavert + vertical;
      somahoriz = somahoriz + horizontal;
    }

    if(somavert>0){
      movercima(somavert);
    }
    else{
      moverbaixo(somavert*-1);
    }

    if(somahoriz>0){
      moverdireita(somahoriz);
    }
    else{
      moveresquerda(somahoriz*-1);
    }
    putchar('\n');
    printarmatriz();
    putchar('\n');
  }

}
