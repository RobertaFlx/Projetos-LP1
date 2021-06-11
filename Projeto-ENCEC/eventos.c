#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "eventos.h"
#include "cadastros.h"
#include <time.h>
#include <string.h>

int Palestras(){
    int opcao;

    system("cls");
    cabecalho();
    printf("\n\n\n\t\t    ------------------------------------------------\n");
    printf("\t\t    |                                              |\n");
    printf("\t\t    |            OPÇOES PARA O EVENTO:             |\n");
    printf("\t\t    |                                              |\n");
    printf("\t\t    |      1 - CADASTRAR PALESTRA                  |\n");
    printf("\t\t    |      2 - EDITAR PALESTRA                     |\n");
    printf("\t\t    |      3 - REMOVER PALESTRA                    |\n");
    printf("\t\t    |      4 - LISTAR TODAS AS PALESTRAS           |\n");
    printf("\t\t    |      5 - MENU DE CADASTROS NAS PALESTRAS     |\n");
    printf("\t\t    |      6 - RETORNAR A TELA ANTERIOR            |\n");
    printf("\t\t    |                                              |\n");
    printf("\t\t    ------------------------------------------------\n");
    printf("\n\t\t            OPÇÃO:");
    scanf("%d", &opcao);
    return opcao;

}

int Oficinas(){

    int opcao;

    system("cls");
    cabecalho();
    printf("\n\n\n\t\t    ------------------------------------------------\n");
    printf("\t\t    |                                              |\n");
    printf("\t\t    |            OPÇOES PARA O EVENTO:             |\n");
    printf("\t\t    |                                              |\n");
    printf("\t\t    |      1 - CADASTRAR OFICINA                   |\n");
    printf("\t\t    |      2 - EDITAR OFICINA                      |\n");
    printf("\t\t    |      3 - REMOVER OFICINA                     |\n");
    printf("\t\t    |      4 - LISTAR TODAS AS OFICINAS            |\n");
    printf("\t\t    |      5 - MENU DE CADASTROS NAS OFICINAS      |\n");
    printf("\t\t    |      6 - RETORNAR A TELA ANTERIOR            |\n");
    printf("\t\t    |                                              |\n");
    printf("\t\t    ------------------------------------------------\n");
    printf("\n\t\t            OPÇÃO:");
    scanf("%d", &opcao);
    return opcao;

}

int Cursos(){

    int opcao;

    system("cls");
    cabecalho();
    printf("\n\n\n\t\t    ------------------------------------------------\n");
    printf("\t\t    |                                              |\n");
    printf("\t\t    |            OPÇOES PARA O EVENTO:             |\n");
    printf("\t\t    |                                              |\n");
    printf("\t\t    |      1 - CADASTRAR CURSO                     |\n");
    printf("\t\t    |      2 - EDITAR CURSO                        |\n");
    printf("\t\t    |      3 - REMOVER CURSO                       |\n");
    printf("\t\t    |      4 - LISTAR TODAS OS CURSOS              |\n");
    printf("\t\t    |      5 - MENU DE CADASTROS NOS CURSOS        |\n");
    printf("\t\t    |      6 - RETORNAR A TELA ANTERIOR            |\n");
    printf("\t\t    |                                              |\n");
    printf("\t\t    ------------------------------------------------\n");
    printf("\n\t\t            OPÇÃO:");
    scanf("%d", &opcao);
    return opcao;

}

int Grupos(){

    int opcao;

    system("cls");
    cabecalho();
    printf("\n\n\n\t\t    ------------------------------------------------\n");
    printf("\t\t    |                                              |\n");
    printf("\t\t    |            OPÇOES PARA O EVENTO:             |\n");
    printf("\t\t    |                                              |\n");
    printf("\t\t    |      1 - CADASTRAR GRUPO                     |\n");
    printf("\t\t    |      2 - EDITAR GRUPO                        |\n");
    printf("\t\t    |      3 - REMOVER GRUPO                       |\n");
    printf("\t\t    |      4 - LISTAR TODAS OS GRUPOS              |\n");
    printf("\t\t    |      5 - MENU DE CADASTROS NOS GRUPOS        |\n");
    printf("\t\t    |      6 - RETORNAR A TELA ANTERIOR            |\n");
    printf("\t\t    |                                              |\n");
    printf("\t\t    ------------------------------------------------\n");
    printf("\n\t\t            OPÇÃO:");
    scanf("%d", &opcao);
    return opcao;

}

/*--------------------------------------------------------PALESTRAS--------------------------------------------------------------*/

void cadastrarPalestra(int codi, char localteste[30], char horarioteste[30]){

    int i=0;
	int opc;
	char auxPalestrante[30];

    PALESTRA cadastrar;

    if ((PAL = fopen("palestras.txt", "ab")) == NULL){
        fprintf(stderr, "Banco de dados não existe.\n");
        exit(EXIT_FAILURE);
    }
    system("cls");

        srand(time(NULL));
        cadastrar.codigo = 1+(rand()% 300);

        PALESTRANTE A;
        PALES = fopen("palestrantes.txt", "rb");

        while(fread(&A, sizeof(PALESTRANTE), 1, PALES)){
            if(A.codigo == codi){
                strcpy(auxPalestrante, A.nome);
            }
        }
        fclose(PALES);

        strcpy(cadastrar.palestrante, auxPalestrante);

        cabecalho();
        printf("\n\n\t\tTEMA: ");
        setbuf(stdin,NULL);
        gets(cadastrar.tema);

        strcpy(cadastrar.local, localteste);
        strcpy(cadastrar.horario, horarioteste);

        fwrite(&cadastrar, sizeof(PALESTRA),1,PAL);
        fclose(PAL);
        printf("\n\n\t>> CADASTRO REALIZADO <<\n");
        limparTela();

}


int removerPalestra(int x){

    int verificador = 0;

     PALESTRA remover;
     PAL = fopen("palestras.txt","rb");
     AUXPAL = fopen("palestrasaux.txt","ab");

     while(fread(&remover, sizeof(PALESTRA), 1,PAL)){

        if(remover.codigo == x){
            verificador ++;
        }

        if(remover.codigo!=x){
            fwrite(&remover, sizeof(PALESTRA),1,AUXPAL);
        }
    }

    fclose(PAL);
    fclose(AUXPAL);
    remove("palestras.txt");
    rename("palestrasaux.txt","palestras.txt");

    if(verificador == 0){
        return 0;
    }else{
        printf("\n\t>> REMOVIDO <<\n");
        limparTela();
        return 1;
    }
}

void mostrarPalestras(){
        system("cls");
        PALESTRA mostrar;
        PAL = fopen("palestras.txt", "rb");
        cabecalho();
        printf("\t=====================PALESTRAS=====================\n\n");
        while (fread(&mostrar, sizeof(PALESTRA), 1,PAL)){
            printf("\tCODIGO: %d\n", mostrar.codigo);
            printf("\tCARGA HORARIA: 1 HORA E 30 MINUTOS\n");
            printf("\tTEMA: %s\n", strupr(mostrar.tema));
            printf("\tLOCAL: %s\n", strupr(mostrar.local));
            printf("\tHORARIO: %s\n", strupr(mostrar.horario));
            printf("\tPALESTRANTE: %s\n\n", strupr(mostrar.palestrante));
            printf("\t===================================================\n\n");
        }
        fclose(PAL);
        limparTela();
}

int verificaPalestranteCadastradoEmPalestra(int x){
    int verifica = 0;
    char auxPales[30];

    PALESTRANTE A;
    PALES = fopen("palestrantes.txt","rb");

    while(fread(&A, sizeof(PALESTRANTE), 1,PALES)){
        if(A.codigo== x){
            verifica++;
            strcpy(auxPales, A.nome);// COPIAR O NOME QUE EQUIVALE AO ID
        }
    }
    fclose(PALES);

    PALESTRA B;
    PAL = fopen("palestras.txt","rb");

    while(fread(&B, sizeof(PALESTRA), 1,PAL)){
        if(strcmp(B.palestrante,auxPales)==0){// SE ACHOU O NOME NO ARQUIVO
            verifica++;
        }
    }
    fclose(PAL);

    if(verifica == 0){
        return 0;
    }
    else if(verifica == 2){
        return 2;
    }
    else{
        return 1;
    }
}


int testeHorarioDisponivelParaPalestra(char localteste[30],char horarioteste[30]){

    int verifica = 0;
    PALESTRA B;
    PAL = fopen("palestras.txt","rb");

    while(fread(&B, sizeof(PALESTRA), 1,PAL)){
        if(strcmp(B.local,localteste)==0 && strcmp(B.horario,horarioteste)==0){// SE ACHOU AMBOS CADASTRADOS NO ARQUIVO
            verifica++;
        }
    }
    fclose(PAL);

    if(verifica == 0){
        return 0;
    }
    else{
        return 1;
    }

}

/*----------------------------------------------------------CURSOS-------------------------------------------------------------*/

int removerCurso(int x){

    int verificador = 0;

     CURSO remover;
     CURS = fopen("cursos.txt","rb");
     AUXCURS = fopen("cursosaux.txt","ab");

     while(fread(&remover, sizeof(CURSO), 1,CURS)){

        if(remover.codigo == x){
            verificador ++;
        }

        if(remover.codigo!=x){
            fwrite(&remover, sizeof(CURSO),1,AUXCURS);
        }
    }

    fclose(CURS);
    fclose(AUXCURS);
    remove("cursos.txt");
    rename("cursosaux.txt","cursos.txt");

    if(verificador == 0){
        return 0;
    }else{
        printf("\n\t>> REMOVIDO <<\n");
        limparTela();
        return 1;
    }
}

void mostrarCursos(){
        system("cls");
        CURSO mostrar;
        CURS = fopen("cursos.txt", "rb");
        cabecalho();
        printf("\t======================CURSOS=======================\n\n");
        while (fread(&mostrar, sizeof(CURSO), 1,CURS)){
            printf("\tCODIGO: %d\n", mostrar.codigo);
            printf("\tCARGA HORARIA: 1 HORA\n");
            printf("\tTEMA: %s\n", strupr(mostrar.tema));
            printf("\tLOCAL: %s\n", strupr(mostrar.local));
            printf("\tHORARIO: %s\n", strupr(mostrar.horario));
            printf("\tPALESTRANTE: %s\n\n", strupr(mostrar.palestrante));
            printf("\t===================================================\n\n");
        }
        fclose(CURS);
		limparTela();
}


void cadastrarCurso(int codi, char localteste[30], char horarioteste[30]){

    int i=0;
	int opc;
	char auxPalestrante[30];

    CURSO cadastrar;

    if ((CURS = fopen("cursos.txt", "ab")) == NULL){
        fprintf(stderr, "Banco de dados não existe.\n");
        exit(EXIT_FAILURE);
    }
    system("cls");

        srand(time(NULL));
        cadastrar.codigo = 1+(rand()% 300);

        PALESTRANTE A;
        PALES = fopen("palestrantes.txt", "rb");

        while(fread(&A, sizeof(PALESTRANTE), 1, PALES)){
            if(A.codigo == codi){
                strcpy(auxPalestrante, A.nome);
            }
        }
        fclose(PALES);

        strcpy(cadastrar.palestrante, auxPalestrante);

        cabecalho();
        printf("\n\n\t\tTEMA: ");
        setbuf(stdin,NULL);
        gets(cadastrar.tema);

        strcpy(cadastrar.local, localteste);
        strcpy(cadastrar.horario, horarioteste);

        fwrite(&cadastrar, sizeof(CURSO),1,CURS);
        fclose(CURS);
        printf("\n\n\t>> CADASTRO REALIZADO <<\n");
        limparTela();

}


int verificaPalestranteCadastradoEmCurso(int x){
    int verifica = 0;
    char auxPales[30];

    PALESTRANTE A;
    PALES = fopen("palestrantes.txt","rb");

    while(fread(&A, sizeof(PALESTRANTE), 1,PALES)){
        if(A.codigo== x){
            verifica++;
            strcpy(auxPales, A.nome);// COPIAR O NOME QUE EQUIVALE AO ID
        }
    }
    fclose(PALES);

    CURSO B;
    CURS = fopen("cursos.txt","rb");

    while(fread(&B, sizeof(CURSO), 1,CURS)){
        if(strcmp(B.palestrante,auxPales)==0){// SE ACHOU O NOME NO ARQUIVO
            verifica++;
        }
    }
    fclose(CURS);

    if(verifica == 0){
        return 0;
    }
    else if(verifica == 2){
        return 2;
    }
    else{
        return 1;
    }
}


int testeHorarioDisponivelParaCurso(char localteste[30],char horarioteste[30]){

    int verifica = 0;
    CURSO B;
    CURS = fopen("cursos.txt","rb");

    while(fread(&B, sizeof(CURSO), 1,CURS)){
        if(strcmp(B.local,localteste)==0 && strcmp(B.horario,horarioteste)==0){// SE ACHOU AMBOS CADASTRADOS NO ARQUIVO
            verifica++;
        }
    }
    fclose(CURS);

    if(verifica == 0){
        return 0;
    }
    else{
        return 1;
    }

}

/*---------------------------------------------------------OFICINAS-------------------------------------------------------------*/


void cadastrarOficina(int codi, char localteste[30], char horarioteste[30]){

    int i=0;
	int opc;
	char auxPalestrante[30];

    OFICINA cadastrar;

    if ((OFIC = fopen("oficinas.txt", "ab")) == NULL){
        fprintf(stderr, "Banco de dados não existe.\n");
        exit(EXIT_FAILURE);
    }
    system("cls");

        srand(time(NULL));
        cadastrar.codigo = 1+(rand()% 300);

        PALESTRANTE A;
        PALES = fopen("palestrantes.txt", "rb");

        while(fread(&A, sizeof(PALESTRANTE), 1, PALES)){
            if(A.codigo == codi){
                strcpy(auxPalestrante, A.nome);
            }
        }
        fclose(PALES);

        strcpy(cadastrar.palestrante, auxPalestrante);

        cabecalho();
        printf("\n\n\t\tTEMA: ");
        setbuf(stdin,NULL);
        gets(cadastrar.tema);

        strcpy(cadastrar.local, localteste);
        strcpy(cadastrar.horario, horarioteste);

        fwrite(&cadastrar, sizeof(OFICINA),1,OFIC);
        fclose(OFIC);
        printf("\n\n\t>> CADASTRO REALIZADO <<\n");
        limparTela();

}


int removerOficina(int x){

    int verificador = 0;

     OFICINA remover;
     OFIC = fopen("oficinas.txt","rb");
     AUXOFIC = fopen("oficinasaux.txt","ab");

     while(fread(&remover, sizeof(OFICINA), 1,OFIC)){

        if(remover.codigo == x){
            verificador ++;
        }

        if(remover.codigo!=x){
            fwrite(&remover, sizeof(OFICINA),1,AUXOFIC);
        }
    }

    fclose(OFIC);
    fclose(AUXOFIC);
    remove("oficinas.txt");
    rename("oficinasaux.txt","oficinas.txt");

    if(verificador == 0){
        return 0;
    }else{
        printf("\n\t>> REMOVIDO <<\n");
        limparTela();
        return 1;
    }
}

void mostrarOficinas(){
        system("cls");
        OFICINA mostrar;
        OFIC = fopen("oficinas.txt", "rb");
        cabecalho();
        printf("\t=====================OFICINAS=====================\n\n");
        while (fread(&mostrar, sizeof(OFICINA), 1,OFIC)){
            printf("\tCODIGO: %d\n", mostrar.codigo);
            printf("\tCARGA HORARIA: 1 HORA\n");
            printf("\tTEMA: %s\n", strupr(mostrar.tema));
            printf("\tLOCAL: %s\n", strupr(mostrar.local));
            printf("\tHORARIO: %s\n", strupr(mostrar.horario));
            printf("\tPALESTRANTE: %s\n\n", strupr(mostrar.palestrante));
            printf("\t===================================================\n\n");
        }
        fclose(OFIC);
		limparTela();
}


int verificaPalestranteCadastradoEmOficina(int x){
    int verifica = 0;
    char auxPales[30];

    PALESTRANTE A;
    PALES = fopen("palestrantes.txt","rb");

    while(fread(&A, sizeof(PALESTRANTE), 1,PALES)){
        if(A.codigo== x){
            verifica++;
            strcpy(auxPales, A.nome);// COPIAR O NOME QUE EQUIVALE AO ID
        }
    }
    fclose(PALES);

    OFICINA B;
    OFIC = fopen("oficinas.txt","rb");

    while(fread(&B, sizeof(OFICINA), 1,OFIC)){
        if(strcmp(B.palestrante,auxPales)==0){// SE ACHOU O NOME NO ARQUIVO
            verifica++;
        }
    }
    fclose(OFIC);

    if(verifica == 0){
        return 0;
    }
    else if(verifica == 2){
        return 2;
    }
    else{
        return 1;
    }
}


int testeHorarioDisponivelParaOficina(char localteste[30],char horarioteste[30]){

    int verifica = 0;
    OFICINA B;
    OFIC = fopen("oficinas.txt","rb");

    while(fread(&B, sizeof(OFICINA), 1,OFIC)){
        if(strcmp(B.local,localteste)==0 && strcmp(B.horario,horarioteste)==0){// SE ACHOU AMBOS CADASTRADOS NO ARQUIVO
            verifica++;
        }
    }
    fclose(OFIC);

    if(verifica == 0){
        return 0;
    }
    else{
        return 1;
    }

}

/*---------------------------------------------------------GRUPOS---------------------------------------------------------------*/


int removerGrupo(int x){

    int verificador = 0;

     GRUPO remover;
     GRUP = fopen("grupos.txt","rb");
     AUXGRUP = fopen("gruposaux.txt","ab");

     while(fread(&remover, sizeof(GRUPO), 1,GRUP)){

        if(remover.codigo == x){
            verificador ++;
        }

        if(remover.codigo!=x){
            fwrite(&remover, sizeof(GRUPO),1,AUXGRUP);
        }
    }

    fclose(GRUP);
    fclose(AUXGRUP);
    remove("grupos.txt");
    rename("gruposaux.txt","grupos.txt");

    if(verificador == 0){
        return 0;
    }else{
        printf("\n\t>> REMOVIDO <<\n");
        limparTela();
        return 1;
    }
}

void mostrarGrupos(){
        system("cls");
        GRUPO mostrar;
        GRUP = fopen("grupos.txt", "rb");
        cabecalho();
        printf("\t======================GRUPOS======================\n\n");
        while (fread(&mostrar, sizeof(GRUPO), 1,GRUP)){
            printf("\tCODIGO: %d\n", mostrar.codigo);
            printf("\tCARGA HORARIA: 1 HORA\n");
            printf("\tTEMA: %s\n", strupr(mostrar.tema));
            printf("\tLOCAL: %s\n", strupr(mostrar.local));
            printf("\tHORARIO: %s\n", strupr(mostrar.horario));

          for(int i=0;i<mostrar.quantidadeP;i++){

            PALESTRANTE A;
            PALES = fopen("palestrantes.txt", "rb");

            while(fread(&A, sizeof(PALESTRANTE), 1, PALES)){
                if(A.codigo == mostrar.Membros_da_mesa[i][0]){
                    printf("\tPALESTRANTE: %s\n", strupr(A.nome));
                }
            }
            fclose(PALES);
        }
        printf("\t===================================================\n\n");
        }
        fclose(GRUP);
		limparTela();
}

int testeHorarioDisponivelParaGrupo(char localteste[30],char horarioteste[30]){

    int verifica = 0;
    GRUPO B;
    GRUP = fopen("grupos.txt","rb");

    while(fread(&B, sizeof(GRUPO), 1,GRUP)){
        if(strcmp(B.local,localteste)==0 && strcmp(B.horario,horarioteste)==0){// SE ACHOU AMBOS CADASTRADOS NO ARQUIVO
            verifica++;
        }
    }
    fclose(GRUP);

    if(verifica == 0){
        return 0;
    }
    else{
        return 1;
    }

}

void cadastrarGrupo(char localteste[30], char horarioteste[30]){

    int i=0;
	int opc;
	char auxPalestrante[30];

    GRUPO cadastrar;

    if ((GRUP = fopen("grupos.txt", "ab")) == NULL){
        fprintf(stderr, "Banco de dados não existe.\n");
        exit(EXIT_FAILURE);
    }
    system("cls");
    cabecalho();

    srand(time(NULL));
    cadastrar.codigo = 1+(rand()% 300);

    int qntd;
    printf("\n\n     --------------------------------------------------------------------------------\n");
    printf("     | UM GRUPO DE DISCURSSÃO DEVE TER OBRIGATORIAMENTE UM PALESTRANTE E 5 NO MÁXIMO |\n");
    printf("     -------------------------------------------------------------------------------\n");
    printf("\n     DIGITE A QUANTIDADE DE PALESTRANTES QUE DESEJA ADICIONAR AO GRUPO>>");
    scanf("%d",&qntd);
    while(qntd<1 || qntd>5){
        system("cls");
        cabecalho();
        printf("\n\n     --------------------------------------------------------------------------------\n");
        printf("     | UM GRUPO DE DISCURSSÃO DEVE TER OBRIGATORIAMENTE UM PALESTRANTE E 5 NO MÁXIMO |\n");
        printf("     -------------------------------------------------------------------------------\n");
        printf("\n     DIGITE A QUANTIDADE DE PALESTRANTES QUE DESEJA ADICIONAR AO GRUPO>>");
        scanf("%d",&qntd);
      }

    cadastrar.quantidadeP= qntd;

    for(i=0;i<qntd;i++){
      mostrarPalestrantes();
      cabecalho();
      printf("\n\n\t\tDIGITE O CODIGO DO PALESTRANTE>>");
      scanf("%d",&cadastrar.Membros_da_mesa[i][0]);
    }

    system("cls");
    cabecalho();
    printf("\n\n\t\tTEMA: ");
    setbuf(stdin,NULL);
    gets(cadastrar.tema);

    strcpy(cadastrar.local, localteste);
    strcpy(cadastrar.horario, horarioteste);

    fwrite(&cadastrar, sizeof(GRUPO),1,GRUP);
    fclose(GRUP);
    printf("\n\n\t>> CADASTRO REALIZADO <<\n");
    limparTela();

}

/*-------------------------------------------------CADASTRO-EM-PALESTRA----------------------------------------------------------*/

void cadastrarEmPalestra(int cod,int cod2){

    int i=0;
	int opc;
	char auxCongre[30];
	char auxAux[30];

    CADPALESTRAS cadastrar;

    if ((CADP = fopen("congrepalestras.txt", "ab")) == NULL){
        fprintf(stderr, "Banco de dados não existe.\n");
        exit(EXIT_FAILURE);
    }
    system("cls");

        srand(time(NULL));
        cadastrar.codigo = 1+(rand()% 300);
        cabecalho();

        CONGRESSISTA A;
        CONGRE = fopen("congressistas.txt", "rb");

        while(fread(&A, sizeof(CONGRESSISTA), 1, CONGRE)){
            if(A.codigo == cod){
                strcpy(auxCongre, A.nome);
            }
        }
        fclose(CONGRE);

        strcpy(cadastrar.nome,auxCongre);

       PALESTRA B;
       PAL = fopen("palestras.txt","rb");

        while(fread(&B, sizeof(PALESTRA), 1,PAL)){
            if(B.codigo == cod2){// SE ACHOU O TEMA NO ARQUIVO
                strcpy(auxAux,B.tema);
            }
        }
        fclose(PAL);

        strcpy(cadastrar.tema,auxAux);

        fwrite(&cadastrar, sizeof(CADPALESTRAS),1,CADP);
        fclose(CADP);
        printf("\n\n\t>> CADASTRO REALIZADO <<\n");

        limparTela();

}

void mostrarCadastradosNasPalestras(){
        system("cls");
        CADPALESTRAS mostrar;
        CADP = fopen("congrepalestras.txt", "rb");
        cabecalho();
        printf("\t===================CADASTROS=NAS=PALESTRAS===================\n\n");
        while (fread(&mostrar, sizeof(CADPALESTRAS), 1,CADP)){
            printf("\tCODIGO: %d\n", mostrar.codigo);
            printf("\tTEMA DA PALESTRA: %s\n", strupr(mostrar.tema));
            printf("\tCONGRESSISTA: %s\n", strupr(mostrar.nome));
            printf("\t===========================================================\n\n");
        }
        fclose(CADP);
		limparTela();
}

int verificaCongressistaCadastrado(int x){
    int verifica = 0;

    CONGRESSISTA A;
    CONGRE = fopen("congressistas.txt","rb");

    while(fread(&A, sizeof(CONGRESSISTA), 1,CONGRE)){
        if(A.codigo== x){
            verifica++;
        }
    }
    fclose(CONGRE);

    if(verifica == 0){
        return 0;
    }
    else{
        return 1;
    }
}

int verificaPalestra(int cod2){

    int verifica2 = 0;

   PALESTRA B;
   PAL = fopen("palestras.txt","rb");

    while(fread(&B, sizeof(PALESTRA), 1,PAL)){
        if(B.codigo == cod2){
            verifica2++;
        }
    }
    fclose(PAL);

    if(verifica2 == 0){
        return 0;
    }
    else{
        return 1;
    }

}

void mostrarCadastradosPorPalestra(int cod3){
        char temax[30];
        system("cls");
        char auxAux[30];

       PALESTRA B;
       PAL = fopen("palestras.txt","rb");

        while(fread(&B, sizeof(PALESTRA), 1,PAL)){
            if(B.codigo == cod3){
                strcpy(auxAux,B.tema);
            }
        }
        fclose(PAL);

        CADPALESTRAS mostrar;
        CADP = fopen("congrepalestras.txt", "rb");
        cabecalho();
        printf("\t===================CADASTRADOS=NA=PALESTRA===================\n\n");
        while (fread(&mostrar, sizeof(CADPALESTRAS), 1,CADP)){
            if(strcmp(mostrar.tema,auxAux)==0){
            printf("\tCONGRESSISTA: %s\n", strupr(mostrar.nome));
            printf("\t===========================================================\n\n");
            }

        }
        fclose(CADP);

		limparTela();
}

int removerCadastroDePalestra(int cod4){

    int verificador = 0;

     CADPALESTRAS remover;
     CADP = fopen("congrepalestras.txt","rb");
     AUXCADP = fopen("congrepalestrasaux.txt","ab");

     while(fread(&remover, sizeof(CADPALESTRAS), 1,CADP)){

        if(remover.codigo == cod4){
            verificador ++;
        }
        if(remover.codigo!=cod4){
            fwrite(&remover, sizeof(CADPALESTRAS),1,AUXCADP);
        }
    }

    fclose(CADP);
    fclose(AUXCADP);
    remove("congrepalestras.txt");
    rename("congrepalestrasaux.txt","congrepalestras.txt");

    if(verificador == 0){
        return 0;
    }else{
        printf("\n\t>> REMOVIDO <<\n");
        limparTela();
        return 1;
    }

}


/*-------------------------------------------------CADASTRO-EM-GRUPO------------------------------------------------------------*/

void cadastrarEmGrupo(int cod,int cod2){

    int i=0;
	int opc;
	char auxCongre[30];
	char auxAux[30];

    CADGRUPOS cadastrar;

    if ((CADG = fopen("congregrupos.txt", "ab")) == NULL){
        fprintf(stderr, "Banco de dados não existe.\n");
        exit(EXIT_FAILURE);
    }
    system("cls");

    srand(time(NULL));
    cadastrar.codigo = 1+(rand()% 300);
    cabecalho();

    CONGRESSISTA A;
    CONGRE = fopen("congressistas.txt", "rb");

    while(fread(&A, sizeof(CONGRESSISTA), 1, CONGRE)){
        if(A.codigo == cod){
            strcpy(auxCongre, A.nome);
        }
    }
    fclose(CONGRE);

    strcpy(cadastrar.nome,auxCongre);

   GRUPO B;
   GRUP = fopen("grupos.txt","rb");

    while(fread(&B, sizeof(GRUPO), 1,GRUP)){
        if(B.codigo == cod2){// SE ACHOU O TEMA NO ARQUIVO
            strcpy(auxAux,B.tema);
        }
    }
    fclose(GRUP);

    strcpy(cadastrar.tema,auxAux);

    fwrite(&cadastrar, sizeof(CADGRUPOS),1,CADG);
    fclose(CADG);
    printf("\n\n\t>> CADASTRO REALIZADO <<\n");

    limparTela();

}

void mostrarCadastradosNosGrupos(){
    system("cls");
    CADGRUPOS mostrar;
    CADG = fopen("congregrupos.txt", "rb");
    cabecalho();
    printf("\t===================CADASTROS=NOS=GRUPOS====================\n\n");
    while (fread(&mostrar, sizeof(CADGRUPOS), 1,CADG)){
        printf("\tCODIGO: %d\n", mostrar.codigo);
        printf("\tTEMA DO GRUPO: %s\n", strupr(mostrar.tema));
        printf("\tCONGRESSISTA: %s\n", strupr(mostrar.nome));
        printf("\t===========================================================\n\n");
    }
    fclose(CADG);
    limparTela();
}


int verificaGrupo(int cod2){

    int verifica2 = 0;

   GRUPO B;
   GRUP = fopen("grupos.txt","rb");

    while(fread(&B, sizeof(GRUPO), 1,GRUP)){
        if(B.codigo == cod2){
            verifica2++;
        }
    }
    fclose(GRUP);

    if(verifica2 == 0){
        return 0;
    }
    else{
        return 1;
    }

}

void mostrarCadastradosPorGrupo(int cod3){
    char temax[30];
    system("cls");
    char auxAux[30];

   GRUPO B;
   GRUP = fopen("grupos.txt","rb");

    while(fread(&B, sizeof(GRUPO), 1,GRUP)){
        if(B.codigo == cod3){
            strcpy(auxAux,B.tema);
        }
    }
    fclose(GRUP);

    CADGRUPOS mostrar;
    CADG = fopen("congregrupos.txt", "rb");
    cabecalho();
    printf("\t===================CADASTRADOS=NO=GRUPO=====================\n\n");
    while (fread(&mostrar, sizeof(CADGRUPOS), 1,CADG)){
        if(strcmp(mostrar.tema,auxAux)==0){
        printf("\tCONGRESSISTA: %s\n", strupr(mostrar.nome));
        printf("\t===========================================================\n\n");
        }

    }
    fclose(CADG);

    limparTela();
}

int removerCadastroDeGrupo(int cod4){

    int verificador = 0;

     CADGRUPOS remover;
     CADG = fopen("congregrupos.txt","rb");
     AUXCADG = fopen("congregruposaux.txt","ab");

     while(fread(&remover, sizeof(CADGRUPOS), 1,CADG)){

        if(remover.codigo == cod4){
            verificador ++;
        }
        if(remover.codigo!=cod4){
            fwrite(&remover, sizeof(CADGRUPOS),1,AUXCADG);
        }
    }

    fclose(CADG);
    fclose(AUXCADG);
    remove("congregrupos.txt");
    rename("congregruposaux.txt","congregrupos.txt");

    if(verificador == 0){
        return 0;
    }else{
        printf("\n\t>> REMOVIDO <<\n");
        limparTela();
        return 1;
    }
}


/*-------------------------------------------------CADASTRO-EM-CURSO-------------------------------------------------------------*/

void cadastrarEmCurso(int cod,int cod2){

    int i=0;
	int opc;
	char auxCongre[30];
	char auxAux[30];

    CADCURSOS cadastrar;

    if ((CADC = fopen("congrecursos.txt", "ab")) == NULL){
        fprintf(stderr, "Banco de dados não existe.\n");
        exit(EXIT_FAILURE);
    }
    system("cls");

    srand(time(NULL));
    cadastrar.codigo = 1+(rand()% 300);
    cabecalho();

    CONGRESSISTA A;
    CONGRE = fopen("congressistas.txt", "rb");

    while(fread(&A, sizeof(CONGRESSISTA), 1, CONGRE)){
        if(A.codigo == cod){
            strcpy(auxCongre, A.nome);
        }
    }
    fclose(CONGRE);

    strcpy(cadastrar.nome,auxCongre);

   CURSO B;
   CURS = fopen("cursos.txt","rb");

    while(fread(&B, sizeof(CURSO), 1,CURS)){
        if(B.codigo == cod2){
            strcpy(auxAux,B.tema);
        }
    }
    fclose(CURS);

    strcpy(cadastrar.tema,auxAux);

    fwrite(&cadastrar, sizeof(CADCURSOS),1,CADC);
    fclose(CADC);
    printf("\n\n\t>> CADASTRO REALIZADO <<\n");

    limparTela();

}

void mostrarCadastradosNosCursos(){
    system("cls");
    CADCURSOS mostrar;
    CADC = fopen("congrecursos.txt", "rb");
    cabecalho();
    printf("\t===================CADASTROS=NOS=CURSOS====================\n\n");
    while (fread(&mostrar, sizeof(CADCURSOS), 1,CADC)){
        printf("\tCODIGO: %d\n", mostrar.codigo);
        printf("\tTEMA DO GRUPO: %s\n", strupr(mostrar.tema));
        printf("\tCONGRESSISTA: %s\n", strupr(mostrar.nome));
        printf("\t===========================================================\n\n");
    }
    fclose(CADC);
    limparTela();
}


int verificaCurso(int cod2){

    int verifica2 = 0;

    CURSO B;
    CURS = fopen("cursos.txt","rb");

    while(fread(&B, sizeof(CURSO), 1,CURS)){
        if(B.codigo == cod2){
            verifica2++;
        }
    }
    fclose(CURS);

    if(verifica2 == 0){
        return 0;
    }
    else{
        return 1;
    }

}

void mostrarCadastradosPorCurso(int cod3){

    char temax[30];
    system("cls");
    char auxAux[30];

   CURSO B;
   CURS = fopen("cursos.txt","rb");

    while(fread(&B, sizeof(CURSO), 1,CURS)){
        if(B.codigo == cod3){
            strcpy(auxAux,B.tema);
        }
    }
    fclose(CURS);

    CADCURSOS mostrar;
    CADC = fopen("congrecursos.txt", "rb");
    cabecalho();
    printf("\t====================CADASTRADOS=NO=CURSO=====================\n\n");
    while (fread(&mostrar, sizeof(CADCURSOS), 1,CADC)){
        if(strcmp(mostrar.tema,auxAux)==0){
        printf("\tCONGRESSISTA: %s\n", strupr(mostrar.nome));
        printf("\t===========================================================\n\n");
        }

    }
    fclose(CADC);
    limparTela();

}

int removerCadastroDeCurso(int cod4){

    int verificador = 0;

     CADCURSOS remover;
     CADC = fopen("congrecursos.txt","rb");
     AUXCADC = fopen("congrecursosaux.txt","ab");

     while(fread(&remover, sizeof(CADCURSOS), 1,CADC)){

        if(remover.codigo == cod4){
            verificador ++;
        }
        if(remover.codigo!=cod4){
            fwrite(&remover, sizeof(CADCURSOS),1,AUXCADC);
        }
    }

    fclose(CADC);
    fclose(AUXCADC);
    remove("congrecursos.txt");
    rename("congrecursosaux.txt","congrecursos.txt");

    if(verificador == 0){
        return 0;
    }else{
        printf("\n\t>> REMOVIDO <<\n");
        limparTela();
        return 1;
    }

}


int verificaCongressistaCadastradoEmCurso(int x){
    int verifica = 0;
    char auxPales[30];

    CONGRESSISTA A;
    CONGRE = fopen("congressistas.txt","rb");

    while(fread(&A, sizeof(CONGRESSISTA), 1,CONGRE)){
        if(A.codigo== x){
            verifica++;
            strcpy(auxPales, A.nome);// COPIAR O NOME QUE EQUIVALE AO ID
        }
    }
    fclose(CONGRE);

    CADCURSOS B;
    CADC = fopen("congrecursos.txt","rb");

    while(fread(&B, sizeof(CADCURSOS), 1,CADC)){
        if(strcmp(B.nome,auxPales)==0){// SE ACHOU O NOME NO ARQUIVO
            verifica++;
        }
    }
    fclose(CADC);

    if(verifica == 0){
        return 0;
    }
    else if(verifica == 2){
        return 2;
    }
    else{
        return 1;
    }
}


/*------------------------------------------------CADASTRO-EM-OFICINA------------------------------------------------------------*/

void cadastrarEmOficina(int cod,int cod2){

    int i=0;
	int opc;
	char auxCongre[30];
	char auxAux[30];

    CADOFICINAS cadastrar;

    if ((CADO = fopen("congreoficinas.txt", "ab")) == NULL){
        fprintf(stderr, "Banco de dados não existe.\n");
        exit(EXIT_FAILURE);
    }
    system("cls");

    srand(time(NULL));
    cadastrar.codigo = 1+(rand()% 300);
    cabecalho();

    CONGRESSISTA A;
    CONGRE = fopen("congressistas.txt", "rb");

    while(fread(&A, sizeof(CONGRESSISTA), 1, CONGRE)){
        if(A.codigo == cod){
            strcpy(auxCongre, A.nome);
        }
    }
    fclose(CONGRE);

    strcpy(cadastrar.nome,auxCongre);

   OFICINA B;
   OFIC = fopen("oficinas.txt","rb");

    while(fread(&B, sizeof(OFICINA), 1,OFIC)){
        if(B.codigo == cod2){
            strcpy(auxAux,B.tema);
        }
    }
    fclose(OFIC);

    strcpy(cadastrar.tema,auxAux);

    fwrite(&cadastrar, sizeof(CADOFICINAS),1,CADO);
    fclose(CADO);
    printf("\n\n\t>> CADASTRO REALIZADO <<\n");

    limparTela();

}

void mostrarCadastradosNasOficinas(){
    system("cls");
    CADOFICINAS mostrar;
    CADO = fopen("congreoficinas.txt", "rb");
    cabecalho();
    printf("\t===================CADASTROS=NAS=OFICINAS====================\n\n");
    while (fread(&mostrar, sizeof(CADOFICINAS), 1,CADO)){
        printf("\tCODIGO: %d\n", mostrar.codigo);
        printf("\tTEMA DO GRUPO: %s\n", strupr(mostrar.tema));
        printf("\tCONGRESSISTA: %s\n", strupr(mostrar.nome));
        printf("\t===========================================================\n\n");
    }
    fclose(CADO);
    limparTela();
}


int verificaOficina(int cod2){

    int verifica2 = 0;

   CURSO B;
   CURS = fopen("oficinas.txt","rb");

    while(fread(&B, sizeof(CURSO), 1,CURS)){
        if(B.codigo == cod2){
            verifica2++;
        }
    }
    fclose(CURS);

    if(verifica2 == 0){
        return 0;
    }
    else{
        return 1;
    }

}

void mostrarCadastradosPorOficina(int cod3){

   char temax[30];
   system("cls");
   char auxAux[30];

   OFICINA B;
   OFIC = fopen("oficinas.txt","rb");

    while(fread(&B, sizeof(OFICINA), 1,OFIC)){
        if(B.codigo == cod3){
            strcpy(auxAux,B.tema);
        }
    }
    fclose(OFIC);

    CADOFICINAS mostrar;
    CADO = fopen("congreoficinas.txt", "rb");
    cabecalho();
    printf("\t===================CADASTRADOS=NA=OFICINA=====================\n\n");
    while (fread(&mostrar, sizeof(CADOFICINAS), 1,CADO)){
        if(strcmp(mostrar.tema,auxAux)==0){
        printf("\tCONGRESSISTA: %s\n", strupr(mostrar.nome));
        printf("\t===========================================================\n\n");
        }

    }
    fclose(CADO);
    limparTela();

}

int removerCadastroDeOficina(int cod4){

    int verificador = 0;

     CADOFICINAS remover;
     CADO = fopen("congreoficinas.txt","rb");
     AUXCADO = fopen("congreoficinasaux.txt","ab");

     while(fread(&remover, sizeof(CADOFICINAS), 1,CADO)){

        if(remover.codigo == cod4){
            verificador ++;
        }
        if(remover.codigo!=cod4){
            fwrite(&remover, sizeof(CADOFICINAS),1,AUXCADO);
        }
    }

    fclose(CADO);
    fclose(AUXCADO);
    remove("congreoficinas.txt");
    rename("congreoficinasaux.txt","congreoficinas.txt");

    if(verificador == 0){
        return 0;
    }else{
        printf("\n\t>> REMOVIDO <<\n");
        limparTela();
        return 1;
    }

}

int verificaCongressistaCadastradoEmOficina(int x){
    int verifica = 0;
    char auxPales[30];

    CONGRESSISTA A;
    CONGRE = fopen("congressistas.txt","rb");

    while(fread(&A, sizeof(CONGRESSISTA), 1,CONGRE)){
        if(A.codigo== x){
            verifica++;
            strcpy(auxPales, A.nome);// COPIAR O NOME QUE EQUIVALE AO ID
        }
    }
    fclose(CONGRE);

    CADOFICINAS B;
    CADO = fopen("congreoficinas.txt","rb");

    while(fread(&B, sizeof(CADOFICINAS), 1,CADO)){
        if(strcmp(B.nome,auxPales)==0){// SE ACHOU O NOME NO ARQUIVO
            verifica++;
        }
    }
    fclose(CADO);

    if(verifica == 0){
        return 0;
    }
    else if(verifica == 2){
        return 2;
    }
    else{
        return 1;
    }
}

/*------------------------------------------------VERIFICAR-POR-CADASTRO--------------------------------------------------------*/


void mostrarPalestrasPorCongressista(int cod){

   system("cls");
   char auxAux[30];

   CONGRESSISTA B;
   CONGRE = fopen("congressistas.txt","rb");

    while(fread(&B, sizeof(CONGRESSISTA), 1,CONGRE)){
        if(B.codigo == cod){
            strcpy(auxAux,B.nome);
        }
    }
    fclose(CONGRE);

    CADPALESTRAS mostrar;
    CADP = fopen("congrepalestras.txt", "rb");
    cabecalho();
    printf("\t===================PALESTRAS=CADASTRADO===================\n\n");
    while (fread(&mostrar, sizeof(CADPALESTRAS), 1,CADP)){
        if(strcmp(mostrar.nome,auxAux)==0){
        printf("\tTEMA: %s\n", strupr(mostrar.tema));
        printf("\t===========================================================\n\n");
        }

    }
    fclose(CADP);
    limparTela();

}

void mostrarOficinasPorCongressista(int cod2){

   system("cls");
   char auxAux[30];

   CONGRESSISTA B;
   CONGRE = fopen("congressistas.txt","rb");

    while(fread(&B, sizeof(CONGRESSISTA), 1,CONGRE)){
        if(B.codigo == cod2){
            strcpy(auxAux,B.nome);
        }
    }
    fclose(CONGRE);

    CADOFICINAS mostrar;
    CADO = fopen("congreoficinas.txt", "rb");
    cabecalho();
    printf("\t===================OFICINAS=CADASTRADO===================\n\n");
     while (fread(&mostrar, sizeof(CADOFICINAS), 1,CADO)){
        if(strcmp(mostrar.nome,auxAux)==0){
        printf("\tTEMA: %s\n", strupr(mostrar.tema));
        printf("\t===========================================================\n\n");
        }

    }
    fclose(CADO);
    limparTela();

}

void mostrarCursosPorCongressista(int cod3){

   system("cls");
   char auxAux[30];

   CONGRESSISTA B;
   CONGRE = fopen("congressistas.txt","rb");

    while(fread(&B, sizeof(CONGRESSISTA), 1,CONGRE)){
        if(B.codigo == cod3){
            strcpy(auxAux,B.nome);
        }
    }
    fclose(CONGRE);

    CADCURSOS mostrar;
    CADC = fopen("congrecursos.txt", "rb");
    cabecalho();
    printf("\t=====================CURSOS=CADASTRADO===================\n\n");
     while (fread(&mostrar, sizeof(CADCURSOS), 1,CADC)){
        if(strcmp(mostrar.nome,auxAux)==0){
        printf("\tTEMA: %s\n", strupr(mostrar.tema));
        printf("\t===========================================================\n\n");
        }

    }
    fclose(CADC);
    limparTela();

}

void mostrarGruposPorCongressista(int cod4){

   system("cls");
   char auxAux[30];

   CONGRESSISTA B;
   CONGRE = fopen("congressistas.txt","rb");

    while(fread(&B, sizeof(CONGRESSISTA), 1,CONGRE)){
        if(B.codigo == cod4){
            strcpy(auxAux,B.nome);
        }
    }
    fclose(CONGRE);

    CADGRUPOS mostrar;
    CADG = fopen("congregrupos.txt", "rb");
    cabecalho();
    printf("\t=====================GRUPOS=CADASTRADO===================\n\n");
     while (fread(&mostrar, sizeof(CADGRUPOS), 1,CADG)){
        if(strcmp(mostrar.nome,auxAux)==0){
        printf("\tTEMA: %s\n", strupr(mostrar.tema));
        printf("\t===========================================================\n\n");
        }

    }
    fclose(CADG);
    limparTela();

}

int verificaPalestranteCadastrado(int x){
    int verifica = 0;

    PALESTRANTE A;
    PALES = fopen("palestrantes.txt","rb");

    while(fread(&A, sizeof(PALESTRANTE), 1,PALES)){
        if(A.codigo== x){
            verifica++;
        }
    }
    fclose(PALES);

    if(verifica == 0){
        return 0;
    }
    else{
        return 1;
    }
}

void mostrarPalestrasPorPalestrante(int cod){

    system("cls");
    char auxPales[30];

    PALESTRANTE A;
    PALES = fopen("palestrantes.txt","rb");

    while(fread(&A, sizeof(PALESTRANTE), 1,PALES)){
        if(A.codigo== cod){
            strcpy(auxPales, A.nome);
        }
    }
    fclose(PALES);

    PALESTRA mostrar;
    PAL = fopen("palestras.txt", "rb");
    cabecalho();
    printf("\t===================PALESTRAS=CADASTRADO===================\n\n");
    while (fread(&mostrar, sizeof(PALESTRA), 1,PAL)){
        if(strcmp(mostrar.palestrante,auxPales)==0){
        printf("\tTEMA: %s\n", strupr(mostrar.tema));
        printf("\tLOCAL: %s\n", strupr(mostrar.local));
        printf("\tHORARIO: %s\n", strupr(mostrar.horario));
        printf("\t===========================================================\n\n");
        }

    }
    fclose(CADP);
    limparTela();

}

void mostrarOficinasPorPalestrante(int cod2){

    system("cls");
    char auxPales[30];

    PALESTRANTE A;
    PALES = fopen("palestrantes.txt","rb");

    while(fread(&A, sizeof(PALESTRANTE), 1,PALES)){
        if(A.codigo== cod2){
            strcpy(auxPales, A.nome);
        }
    }
    fclose(PALES);

    OFICINA mostrar;
    OFIC = fopen("oficinas.txt", "rb");
    cabecalho();
    printf("\t===================OFICINAS=CADASTRADO===================\n\n");
     while (fread(&mostrar, sizeof(OFICINA), 1,OFIC)){
        if(strcmp(mostrar.palestrante,auxPales)==0){
        printf("\tTEMA: %s\n", strupr(mostrar.tema));
        printf("\tLOCAL: %s\n", strupr(mostrar.local));
        printf("\tHORARIO: %s\n", strupr(mostrar.horario));
        printf("\t===========================================================\n\n");
        }
    }
    fclose(OFIC);
    limparTela();

}

void mostrarCursosPorPalestrante(int cod3){

    system("cls");
    char auxPales[30];

    PALESTRANTE A;
    PALES = fopen("palestrantes.txt","rb");

    while(fread(&A, sizeof(PALESTRANTE), 1,PALES)){
        if(A.codigo== cod3){
            strcpy(auxPales, A.nome);
        }
    }
    fclose(PALES);

    CURSO mostrar;
    CURS = fopen("cursos.txt", "rb");
    cabecalho();
    printf("\t====================CURSOS=CADASTRADO===================\n\n");
    while (fread(&mostrar, sizeof(CURSO), 1,CURS)){
        if(strcmp(mostrar.palestrante,auxPales)==0){
        printf("\tTEMA: %s\n", strupr(mostrar.tema));
        printf("\tLOCAL: %s\n", strupr(mostrar.local));
        printf("\tHORARIO: %s\n", strupr(mostrar.horario));
        printf("\t===========================================================\n\n");
        }
    }
    fclose(CURS);
    limparTela();

}

void mostrarGruposPorPalestrante(int cod4){

    system("cls");
    char auxPales[30];

    GRUPO mostrar;
    GRUP = fopen("grupos.txt", "rb");
    cabecalho();
    printf("\t====================GRUPOS=CADASTRADO===================\n\n");
    while (fread(&mostrar, sizeof(GRUPO), 1,GRUP)){

      for(int i=0;i<mostrar.quantidadeP;i++){
          if(mostrar.Membros_da_mesa[i][0]== cod4){
                printf("\tTEMA: %s\n", strupr(mostrar.tema));
                printf("\tLOCAL: %s\n", strupr(mostrar.local));
                printf("\tHORARIO: %s\n", strupr(mostrar.horario));
                printf("\t===========================================================\n\n");
                }
            }
        }

    fclose(GRUP);
    limparTela();

}


