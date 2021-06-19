#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "pilha.h"
#define TAM_MAX 8

struct pilha{
	int discos[TAM_MAX];
	int tp;
};

Pilha * criar(){
	Pilha * p = (Pilha *)calloc(1,sizeof(Pilha));
	p->tp = 0;
	return p;
}

void liberar(Pilha * p){
	if (p != NULL){
		free(p);
	}
}

int desempilhar(Pilha * p){
	return p->discos[--p->tp];
}

void empilhar(Pilha * p, int x){
	p->discos[p->tp++] = x;
}

int tamanho(Pilha * p){
	return p->tp;
}

int topo(Pilha * p){
	if (p->tp == 0){
		return -1;
	}
	return p->discos[p->tp-1];
}

void imprimirA(Pilha * p) {
	int i;
	for(i=(p->tp)-1; i>=0; i--){
		printf("\t\t  %d\n", p->discos[i]);
	}
	putchar('\n');
}

void imprimirB(Pilha * p) {
	int i;
	for(i=(p->tp)-1; i>=0; i--){
		printf("\t\t\t  %d\n", p->discos[i]);
	}
	putchar('\n');
}

void imprimirC(Pilha * p) {
	int i;
	for(i=(p->tp)-1; i>=0; i--){
		printf("\t\t\t\t  %d\n", p->discos[i]);
	}
	putchar('\n');
}

int inicializar(Pilha * torreA, int * quantDiscos){
    printf("\n\n\t>>SÃO DISPONIBILIZADOS DE 3 ATÉ 8 DISCOS<<");
    printf("\n\n\tCOM QUANTOS DISCOS DESEJA JOGAR?>>");
    fflush(stdin);
    scanf("%d", quantDiscos);
    if(*quantDiscos < 3 || *quantDiscos > 8){
        return 1;
    }
    int aux = *quantDiscos;
    while(aux > 0 && aux <= 8){
        empilhar(torreA, aux);
        aux = aux - 1;
    }
    return 2;
}
void finalizar(Pilha * torreA, Pilha * torreB, Pilha * torreC){
    liberar(torreA);
    liberar(torreB);
    liberar(torreC);
}

int movimentar(Pilha * torreA, Pilha * torreB, Pilha * torreC){
    printf(" DIGITE O NÚMERO RELACIONANDO AO MOVIMENTO>>");
    fflush(stdin);
    int movimento;
    scanf("%d", &movimento);
    switch(movimento){
        case 1:
            if(mover(torreA, torreB) == 0)
                return 4;
            break;
        case 2:
            if(mover(torreA, torreC) == 0)
                return 4;
            break;
         case 3:
            if(mover(torreB, torreA) == 0)
                return 4;
            break;
        case 4:
            if(mover(torreB, torreC) == 0)
                return 4;
            break;
        case 5:
            if(mover(torreC, torreA) == 0)
                return 4;
            break;
        case 6:
            if(mover(torreC, torreB) == 0)
                return 4;
            break;
        default:
            printf(" \n>>MOVIMENTO INVÁLIDO<<\n");
            return 4;
            break;
    }
    return 5;
}

int mover(Pilha * origem, Pilha * destino){
    if(tamanho(origem) > 0 && (tamanho(destino) <= 0 || topo(origem) < topo(destino))){
        empilhar(destino,desempilhar(origem));
        return 1;
    }
    else {
        printf("\n >>NÃO É POSSIVEL FAZER ESSE MOVIMENTO<<\n");
        return 0;
    }
}

void mostrarPinos(Pilha * torreA, Pilha * torreB, Pilha * torreC){
    printf("\n--------------------------------------------------------\n");
    imprimirA(torreA);
    printf("\t\t..A..\n");
    imprimirB(torreB);
    printf("\t\t\t..B..\n");
    imprimirC(torreC);
    printf("\t\t\t\t..C..\n");
    printf("--------------------------------------------------------\n");

}

void mostrarPossibilidades(Pilha * torreA, Pilha * torreB, Pilha * torreC){
    printf("\n               >>MOVIMENTOS POSSIVEIS<<\n\n");
    if((topo(torreA) < topo(torreB) || tamanho(torreB) == 0) && tamanho(torreA) > 0){
            printf(" 1 - MOVIMENTAR TOPO DA TORRE A PARA TOPO DA TORRE B\n");
    }
    if((topo(torreA) < topo(torreC) || tamanho(torreC) == 0) && tamanho(torreA) > 0){
            printf(" 2 - MOVIMENTAR TOPO DA TORRE A PARA TOPO DA TORRE C\n");
    }
    if((topo(torreB) < topo(torreA) || tamanho(torreA) == 0) && tamanho(torreB) > 0){
            printf(" 3 - MOVIMENTAR TOPO DA TORRE B PARA TOPO DA TORRE A\n");
    }
    if((topo(torreB) < topo(torreC) || tamanho(torreC) == 0) && tamanho(torreB) > 0){
            printf(" 4 - MOVIMENTAR TOPO DA TORRE B PARA TOPO DA TORRE C\n");
    }
    if((topo(torreC) < topo(torreA) || tamanho(torreA) == 0) && tamanho(torreC) > 0){
            printf(" 5 - MOVIMENTAR TOPO DA TORRE C PARA TOPO DA TORRE A\n");
    }
    if((topo(torreC) < topo(torreB) || tamanho(torreB) == 0) && tamanho(torreC) > 0){
            printf(" 6 - MOVIMENTAR TOPO DA TORRE C PARA TOPO DA TORRE B\n");
    }
    putchar('\n');
}
