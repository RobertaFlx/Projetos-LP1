#include "matrizes.h"

void oposta(int **m, int quantLinhas,int quantColun){
    int i,j;
    for(i=0;i<quantLinhas;i++){
        for(j=0;j<quantColun;j++){
            printf("DIGITE PARA A MATRIZ O VALOR DE [%d][%d]>>",i,j);
            scanf("%d",&m[i][j]);
        }
    }
    printf("\n>>A MATRIZ OPOSTA<<\n");
    for(i=0;i<quantLinhas;i++){
        for(j=0;j<quantColun;j++){
           m[i][j]=m[i][j]*(-1);
           printf(" %d ",m[i][j]);
        }
        putchar('\n');
    }
}

int** alocar(int quantLinhas,int quantColun){
    int i,**m;
    m=(int**)malloc(quantLinhas*sizeof(int*));
    for(i=0;i<quantLinhas;i++){
        m[i]=(int*)calloc(quantColun,sizeof(int));
    }
    return m;
}

void liberar(int **m,int quantLinhas){
    int i;
    for(i=0;i<quantLinhas;i++){
        free(m[i]);
        }
    free(m);
}

void multiescalar(int **p,int quantLinhas,int quantColun){
    int i,j,escalar;

     for(i=0;i<quantLinhas;i++){
        for(j=0;j<quantColun;j++){
            printf("DIGITE PARA A MATRIZ O VALOR DE [%d][%d]>>",i,j);
            scanf("%d",&p[i][j]);
        }
    }

    printf("\nDIGITE O NÚMERO PELO QUAL A MATRIZ SERÁ MULTIPLICADA>>");
    scanf("%d",&escalar);

    printf("\n>>A MATRIZ MULTIPLICADA PELO ESCALAR<<\n");
    for(i=0;i<quantLinhas;i++){
        for(j=0;j<quantColun;j++){
           p[i][j]=p[i][j]*escalar;
           printf(" %d ",p[i][j]);
        }
        putchar('\n');
    }
}

void somamatriz(int **p,int **m, int quantLinhas,int quantColun){
    int i,j;
    printf("--------------------------------------------------------\n");
    for(i=0;i<quantLinhas;i++){
        for(j=0;j<quantColun;j++){
            printf("DIGITE PARA A PRIMEIRA MATRIZ O VALOR DE [%d][%d]>>",i,j);
            scanf("%d",&p[i][j]);
        }
    }
    printf("--------------------------------------------------------\n");
    for(i=0;i<quantLinhas;i++){
        for(j=0;j<quantColun;j++){
            printf("DIGITE PARA A SEGUNDA MATRIZ O VALOR DE [%d][%d]>>",i,j);
            scanf("%d",&m[i][j]);
        }
    }
    printf("--------------------------------------------------------\n");

    printf("\n>>A SOMA DAS MATRIZES<<\n\n");
    for(i=0;i<quantLinhas;i++){
        for(j=0;j<quantColun;j++){
           p[i][j]=p[i][j]+m[i][j];
           printf(" %d ",p[i][j]);
        }
        putchar('\n');
    }
}

void subtmatriz(int **p,int **m, int quantLinhas,int quantColun){
    int i,j;
    printf("--------------------------------------------------------\n");
    for(i=0;i<quantLinhas;i++){
        for(j=0;j<quantColun;j++){
            printf("DIGITE PARA A PRIMEIRA MATRIZ O VALOR DE [%d][%d]>>",i,j);
            scanf("%d",&p[i][j]);
        }
    }
    printf("--------------------------------------------------------\n");
    for(i=0;i<quantLinhas;i++){
        for(j=0;j<quantColun;j++){
            printf("DIGITE PARA A SEGUNDA MATRIZ O VALOR DE [%d][%d]>>",i,j);
            scanf("%d",&m[i][j]);
        }
    }
    printf("--------------------------------------------------------\n");

    printf("\n>>A SUBTRAÇÃO DAS MATRIZES<<\n\n");
    for(i=0;i<quantLinhas;i++){
        for(j=0;j<quantColun;j++){
           p[i][j]=p[i][j]-m[i][j];
           printf(" %d ",p[i][j]);
        }
        putchar('\n');
    }
}

void multimatrizes(int **matA,int **matB,int **matC, int quantLinhasA,int quantColunA, int quantLinhasB,int quantColunB){
    int i,j,x,aux=0;
    printf("\n-----------------------------------------------------------------\n");
    for(i=0;i<quantLinhasA;i++){
        for(j=0;j<quantColunA;j++){
            printf("DIGITE PARA A MATRIZ A O VALOR DE [%d][%d]>>",i,j);
            scanf("%d",&matA[i][j]);
        }
    }
    printf("\n-----------------------------------------------------------------\n");
    for(i=0;i<quantLinhasB;i++){
        for(j=0;j<quantColunB;j++){
            printf("DIGITE PARA A MATRIZ B O VALOR DE [%d][%d]>>",i,j);
            scanf("%d",&matB[i][j]);
        }
    }
    printf("\n-----------------------------------------------------------------\n");
      for(i=0; i<quantLinhasA; i++){
        for(j=0; j<quantColunB; j++){
             matC[i][j]=0;
             for(x=0; x<quantLinhasB; x++){
             aux += matA[i][x] * matB[x][j];
             }
             matC[i][j]=aux;
             aux=0;
             }
        }
    printf("\n\n");
     printf(">>A MATRIZ GERADA PELA MULTIPLICAÇÃO<<\n\n");
    for(i=0; i<quantLinhasA; i++){
            for(j=0; j<quantColunB; j++){
            printf(" %d ", matC[i][j]);
            }
            printf("\n\n");
        }
    printf("\n\n");

}

void matrizTransposta(int quantLinhas, int quantColun){
  int i,j,aux,tamanho,**m;

 if (quantLinhas > quantColun){
    tamanho=quantLinhas;
  }
  else{
    tamanho=quantColun;
  }

    m=(int**)malloc(tamanho*sizeof(int*));
    for(i=0;i<quantLinhas;i++){
        m[i]=(int*)calloc(tamanho,sizeof(int));
    }

  int matriz[tamanho][tamanho];

  for (i=0;i<quantLinhas;i++){
    for (j=0;j<quantColun;j++){
      printf("DIGITE O VALOR DE [%d][%d]>>",i,j);
      scanf("%d",&matriz[i][j]);
    }
  }

    for (i=0;i<tamanho;i++) {
        for (j=i+1;j<tamanho;j++) {
            aux=matriz[i][j];
            matriz[i][j]=matriz[j][i];
            matriz[j][i]=aux;
        }
    }

  printf("\n>>A MATRIZ TRANSPOSTA<<\n\n");

  for (i=0;i<quantColun;i++){
    for (j=0;j<quantLinhas;j++){
      printf(" %d ",matriz[i][j]);
    }
    putchar('\n');
  }

    for(i=0;i<quantLinhas;i++){
        free(m[i]);
        }
    free(m);
}

