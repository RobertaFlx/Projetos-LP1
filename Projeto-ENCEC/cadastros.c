#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "cadastros.h"
#include <time.h>
#include <string.h>

void limparTela(){
    printf("\n\t");
    system("pause");
    system("cls");
}

void cabecalho(){
    printf("==========================================================================================\n\n");
    printf("                ENCONTRO CAMPINENSE DOS ESTUDANTES DE COMPUTAÇÃO - ENCEC\n\n");
    printf("==========================================================================================\n");
}


/*-------------------------------------------------------CONGRESSISTAS----------------------------------------------------------*/

void cadastrarCongressita(){

    int i=0;
	int opc;

    CONGRESSISTA cadastrar;

    if ((CONGRE = fopen("congressistas.txt", "ab")) == NULL){
        fprintf(stderr, "Banco de dados não existe.\n");
        exit(EXIT_FAILURE);
    }
    system("cls");

        srand(time(NULL));
        cadastrar.codigo = 1+(rand()% 300);
        cabecalho();

        printf("\n\n\t\t ---------------------------------------------------\n");
        printf("\t\t |             CADASTRO DO CONGRESSISTA            |\n");
        printf("\t\t ---------------------------------------------------\n");

        printf("\n\t\t NOME:");
        setbuf(stdin,NULL);
        gets(cadastrar.nome);

        printf("\t\t CPF:");
        setbuf(stdin,NULL);
        gets(cadastrar.cpf);

        printf("\t\t EMAIL:");
        setbuf(stdin,NULL);
        gets(cadastrar.email);
        fwrite(&cadastrar, sizeof(CONGRESSISTA),1,CONGRE);
        fclose(CONGRE);
        printf("\n\n\t>> CADASTRO REALIZADO <<\n");
        limparTela();

        cabecalho();

        printf("\n\n\n\n\n\t\t  ---------------------------------------------------\n");
        printf("\t\t  |                                                 |\n");
        printf("\t\t  |         DESEJA FAZER UM NOVO CADASTRO?          |\n");
        printf("\t\t  |                                                 |\n");
        printf("\t\t  |               1-SIM      2-NAO                  |\n");
        printf("\t\t  |                                                 |\n");
        printf("\t\t  ---------------------------------------------------\n");
        printf("\n\t\t              SELECIONE UMA OPÇÃO: ");
        scanf("%d", &opc);
        if(opc == 1){
            cadastrarCongressita();
        }
}

int editarCongressista(int x){

     int verifica = 0;

     int auxN;
     char aux[D];
     int opcao;

     system("cls");
     cabecalho();
     CONGRESSISTA editar;
     CONGRE = fopen("congressistas.txt","rb");
     AUXCONGRE = fopen("congressistasaux.txt","ab");

     while(fread(&editar, sizeof(CONGRESSISTA), 1,CONGRE)){
        if(editar.codigo==x){
            printf("\n\n\n\t\t    ---------------------------------------------\n");
            printf("\t\t    |                                           |\n");
            printf("\t\t    |            O QUE DESEJA ALTERAR?          |\n");
            printf("\t\t    |                                           |\n");
            printf("\t\t    |      1 - NOME                             |\n");
            printf("\t\t    |      2 - CPF                              |\n");
            printf("\t\t    |      3 - REMOVER                          |\n");
            printf("\t\t    |      3 - EMAIL                            |\n");
            printf("\t\t    |      4 - RETORNAR A TELA ANTERIOR         |\n");
            printf("\t\t    |                                           |\n");
            printf("\t\t    ---------------------------------------------\n");
            printf("\n\t\t            OPÇÃO:");
            scanf("%d", &opcao);

             system("cls");

                switch(opcao){
                    case 1:
                        cabecalho();
                        printf("\n\tDIGITE O NOVO NOME:");
                        setbuf(stdin,NULL);
                        gets(aux);
                        strcpy(editar.nome,aux);
                        break;
                    case 2:
                        cabecalho();
                        printf("\n\tDIGITE O NOVO CPF:");
                        setbuf(stdin,NULL);
                        gets(aux);
                        strcpy(editar.cpf,aux);
                        break;
                    case 3:
                        cabecalho();
                        printf("\n\tDIGITE O NOVO EMAIL:");
                        setbuf(stdin,NULL);
                        gets(aux);
                        strcpy(editar.email,aux);
                        break;
                    case 4:
                        break;
                }

                fwrite(&editar, sizeof(CONGRESSISTA),1,AUXCONGRE);
                verifica++;
        }else{
            fwrite(&editar, sizeof(CONGRESSISTA),1,AUXCONGRE);
        }
    }

    fclose(CONGRE);
    fclose(AUXCONGRE);
    remove("congressistas.txt");
    rename("congressistasaux.txt","congressistas.txt");

    if(verifica == 0){
        return 0;
    }else{
        printf("\n\t>> EDITADO <<\n");
        limparTela();
        return 1;
    }
}

int removerCongressista(int x){

    int verificador = 0;

     CONGRESSISTA remover;
     CONGRE = fopen("congressistas.txt","rb");
     AUXCONGRE = fopen("congressistasaux.txt","ab");

     while(fread(&remover, sizeof(CONGRESSISTA), 1,CONGRE)){

        if(remover.codigo == x){
            verificador ++;
        }

        if(remover.codigo!=x){
            fwrite(&remover, sizeof(CONGRESSISTA),1,AUXCONGRE);
        }
    }

    fclose(CONGRE);
    fclose(AUXCONGRE);
    remove("congressistas.txt");
    rename("congressistasaux.txt","congressistas.txt");

    if(verificador == 0){
        return 0;
    }else{
        printf("\n\t>> REMOVIDO <<\n");
        limparTela();
        return 1;
    }
}

void mostrarCongressistas(){
        system("cls");
        CONGRESSISTA mostrar;
        CONGRE = fopen("congressistas.txt", "rb");
        cabecalho();
        printf("\t====================CONGRESSISTAS====================\n\n");
        while (fread(&mostrar, sizeof(CONGRESSISTA), 1,CONGRE)){
            printf("\tCODIGO :%d\n", mostrar.codigo);
            printf("\tNOME :%s\n", strupr(mostrar.nome));
            printf("\tCPF :%s\n", strupr(mostrar.cpf));
            printf("\tEMAIL :%s\n\n", strupr(mostrar.email));
            printf("\t===================================================\n\n");
        }
        fclose(CONGRE);
		limparTela();
}


int Congressistas(){
    int opcao;

    system("cls");
    cabecalho();
    printf("\n\n\n\t\t    ---------------------------------------------\n");
    printf("\t\t    |                                           |\n");
    printf("\t\t    |        OPÇÕES PARA CONGRESSISTA:          |\n");
    printf("\t\t    |                                           |\n");
    printf("\t\t    |      1 - CADASTRAR                        |\n");
    printf("\t\t    |      2 - EDITAR                           |\n");
    printf("\t\t    |      3 - REMOVER                          |\n");
    printf("\t\t    |      4 - LISTAR                           |\n");
    printf("\t\t    |      5 - VERIFICAR CADASTRO EM EVENTO     |\n");
    printf("\t\t    |      6 - RETORNAR A TELA ANTERIOR         |\n");
    printf("\t\t    |                                           |\n");
    printf("\t\t    ---------------------------------------------\n");
    printf("\n\t\t            OPÇÃO:");
    scanf("%d", &opcao);
    return opcao;

}

/*-------------------------------------------------------PALESTRANTES----------------------------------------------------------*/

void cadastrarPalestrante(){

    int i=0;
	int opc;

    PALESTRANTE cadastrar;

    if ((PALES= fopen("palestrantes.txt", "ab")) == NULL){
        fprintf(stderr, "Banco de dados não existe.\n");
        exit(EXIT_FAILURE);
    }
    system("cls");

        srand(time(NULL));
        cadastrar.codigo = 1+(rand()% 300);
        cabecalho();


        printf("\n\n\t\t ---------------------------------------------------\n");
        printf("\t\t |             CADASTRO DO PALESTRANTE             |\n");
        printf("\t\t ---------------------------------------------------\n");

        printf("\n\t\t NOME:");
        setbuf(stdin,NULL);
        gets(cadastrar.nome);

        printf("\t\t EMAIL: ");
        setbuf(stdin,NULL);
        gets(cadastrar.email);

        printf("\t\t FORMACAO ACADEMICA: ");
        setbuf(stdin,NULL);
        gets(cadastrar.formacao);

        fwrite(&cadastrar, sizeof(PALESTRANTE),1,PALES);
        fclose(PALES);
        printf("\n\n\t>> CADASTRO REALIZADO <<\n");
        limparTela();

        cabecalho();

        printf("\n\n\n\n\n\t\t  ---------------------------------------------------\n");
        printf("\t\t  |                                                 |\n");
        printf("\t\t  |         DESEJA FAZER UM NOVO CADASTRO?          |\n");
        printf("\t\t  |                                                 |\n");
        printf("\t\t  |               1-SIM      2-NAO                  |\n");
        printf("\t\t  |                                                 |\n");
        printf("\t\t  ---------------------------------------------------\n");
        printf("\n\t\t              SELECIONE UMA OPÇÃO: ");
        scanf("%d", &opc);
        if(opc == 1){
            cadastrarPalestrante();
        }
}

int editarPalestrante(int x){

     int verifica = 0;

     int auxN;
     char aux[D];
     int opcao;

     system("cls");
     cabecalho();
     PALESTRANTE editar;
     PALES = fopen("palestrantes.txt","rb");
     AUXPALES = fopen("palestrantesaux.txt","ab");

     while(fread(&editar, sizeof(PALESTRANTE), 1,PALES)){
        if(editar.codigo==x){
            printf("\n\n\n\t\t    ---------------------------------------------\n");
            printf("\t\t    |                                           |\n");
            printf("\t\t    |            O QUE DESEJA ALTERAR?          |\n");
            printf("\t\t    |                                           |\n");
            printf("\t\t    |      1 - NOME                             |\n");
            printf("\t\t    |      2 - CPF                              |\n");
            printf("\t\t    |      3 - REMOVER                          |\n");
            printf("\t\t    |      3 - EMAIL                            |\n");
            printf("\t\t    |      4 - RETORNAR A TELA ANTERIOR         |\n");
            printf("\t\t    |                                           |\n");
            printf("\t\t    ---------------------------------------------\n");
            printf("\n\t\t            OPÇÃO:");
            scanf("%d", &opcao);
            system("cls");

                switch(opcao){
                    case 1:
                        cabecalho();
                        printf("\n\tDIGITE O NOVO NOME:");
                        setbuf(stdin,NULL);
                        gets(aux);
                        strcpy(editar.nome,aux);
                        break;
                    case 2:
                        cabecalho();
                        printf("\n\tDIGITE O NOVO EMAIL:");
                        setbuf(stdin,NULL);
                        gets(aux);
                        strcpy(editar.email,aux);
                        break;
                    case 3:
                        cabecalho();
                        printf("\n\tDIGITE A NOVA FORMACAO ACADEMICA:");
                        setbuf(stdin,NULL);
                        gets(aux);
                        strcpy(editar.formacao,aux);
                        break;
                    case 4:
                        break;
                }

                fwrite(&editar, sizeof(PALESTRANTE),1,AUXPALES);
                verifica++;
        }else{
            fwrite(&editar, sizeof(PALESTRANTE),1,AUXPALES);
        }
    }

    fclose(PALES);
    fclose(AUXPALES);
    remove("palestrantes.txt");
    rename("palestrantesaux.txt","palestrantes.txt");

    if(verifica == 0){
        return 0;
    }else{
        printf("\n\t>> EDITADO <<\n");
        limparTela();
        return 1;
    }
}

int removerPalestrante(int x){

    int verificador = 0;

     PALESTRANTE remover;
     PALES = fopen("palestrantes.txt","rb");
     AUXPALES = fopen("palestrantesaux.txt","ab");

     while(fread(&remover, sizeof(PALESTRANTE), 1,PALES)){

        if(remover.codigo == x){
            verificador ++;
        }

        if(remover.codigo!=x){
            fwrite(&remover, sizeof(PALESTRANTE),1,AUXPALES);
        }
    }

    fclose(PALES);
    fclose(AUXPALES);
    remove("palestrantes.txt");
    rename("palestrantesaux.txt","palestrantes.txt");

    if(verificador == 0){
        return 0;
    }else{
        printf("\n\t>> REMOVIDO <<\n");
        limparTela();
        return 1;
    }
}

void mostrarPalestrantes(){
        system("cls");
        PALESTRANTE mostrar;
        PALES = fopen("palestrantes.txt", "rb");
        cabecalho();
        printf("\t====================PALESTRANTES====================\n\n");
        while (fread(&mostrar, sizeof(PALESTRANTE), 1,PALES)){
            printf("\tCODIGO: %d\n", mostrar.codigo);
            printf("\tNOME: %s\n", strupr(mostrar.nome));
            printf("\tEMAIL: %s\n", strupr(mostrar.email));
            printf("\tFORMACAO ACADEMICA: %s\n", strupr(mostrar.formacao));
            printf("\t===================================================\n\n");
        }
        fclose(PALES);
		limparTela();
}


int Palestrantes(){
    int opcao;

    system("cls");
    cabecalho();
    printf("\n\n\n\t\t    ---------------------------------------------\n");
    printf("\t\t    |                                           |\n");
    printf("\t\t    |        OPÇÕES PARA PALESTRANTE:           |\n");
    printf("\t\t    |                                           |\n");
    printf("\t\t    |      1 - CADASTRAR                        |\n");
    printf("\t\t    |      2 - EDITAR                           |\n");
    printf("\t\t    |      3 - REMOVER                          |\n");
    printf("\t\t    |      4 - LISTAR                           |\n");
    printf("\t\t    |      5 - VERIFICAR CADASTRO EM EVENTO     |\n");
    printf("\t\t    |      6 - RETORNAR A TELA ANTERIOR         |\n");
    printf("\t\t    |                                           |\n");
    printf("\t\t    ---------------------------------------------\n");
    printf("\n\t\t            OPÇÃO:");
    scanf("%d", &opcao);
    return opcao;
}

/*-------------------------------------------------------ORGANIZADORES----------------------------------------------------------*/

void cadastrarOrganizador(){

    int i=0;
	int opc;

    ORGANIZADOR cadastrar;

    if ((ORGAN = fopen("organizadores.txt", "ab")) == NULL){
        fprintf(stderr, "Banco de dados não existe.\n");
        exit(EXIT_FAILURE);
    }
    system("cls");

        srand(time(NULL));
        cadastrar.codigo = 1+(rand()% 300);
        cabecalho();

        printf("\n\n\t\t ---------------------------------------------------\n");
        printf("\t\t |             CADASTRO DO ORGANIZADOR             |\n");
        printf("\t\t ---------------------------------------------------\n");

        printf("\n\t\t NOME:");
        setbuf(stdin,NULL);
        gets(cadastrar.nome);

        printf("\t\t CPF: ");
        setbuf(stdin,NULL);
        gets(cadastrar.cpf);

        printf("\t\t EMAIL: ");
        setbuf(stdin,NULL);
        gets(cadastrar.email);
        fwrite(&cadastrar, sizeof(ORGANIZADOR),1,ORGAN);
        fclose(ORGAN);
        printf("\n\n\t>> CADASTRO REALIZADO <<\n");
        limparTela();

        cabecalho();

        printf("\n\n\n\n\n\t\t  ---------------------------------------------------\n");
        printf("\t\t  |                                                 |\n");
        printf("\t\t  |         DESEJA FAZER UM NOVO CADASTRO?          |\n");
        printf("\t\t  |                                                 |\n");
        printf("\t\t  |               1-SIM      2-NAO                  |\n");
        printf("\t\t  |                                                 |\n");
        printf("\t\t  ---------------------------------------------------\n");
        printf("\n\t\t              SELECIONE UMA OPÇÃO: ");
        scanf("%d", &opc);
        if(opc == 1){
            cadastrarOrganizador();
        }
}

int editarOrganizador(int x){

     int verifica = 0;

     int auxN;
     char aux[D];
     int opcao;

     system("cls");
     cabecalho();
     ORGANIZADOR editar;
     ORGAN = fopen("organizadores.txt","rb");
     AUXORGAN = fopen("organizadoresaux.txt","ab");

     while(fread(&editar, sizeof(ORGANIZADOR), 1,ORGAN)){
        if(editar.codigo==x){
            printf("\n\n\n\t\t    ---------------------------------------------\n");
            printf("\t\t    |                                           |\n");
            printf("\t\t    |            O QUE DESEJA ALTERAR?          |\n");
            printf("\t\t    |                                           |\n");
            printf("\t\t    |      1 - NOME                             |\n");
            printf("\t\t    |      2 - CPF                              |\n");
            printf("\t\t    |      3 - REMOVER                          |\n");
            printf("\t\t    |      3 - EMAIL                            |\n");
            printf("\t\t    |      4 - RETORNAR A TELA ANTERIOR         |\n");
            printf("\t\t    |                                           |\n");
            printf("\t\t    ---------------------------------------------\n");
            printf("\n\t\t            OPÇÃO:");
            scanf("%d", &opcao);
            system("cls");

                switch(opcao){
                    case 1:
                        cabecalho();
                        printf("\n\tDIGITE O NOVO NOME:");
                        setbuf(stdin,NULL);
                        gets(aux);
                        strcpy(editar.nome,aux);
                        break;
                    case 2:
                        cabecalho();
                        printf("\n\tDIGITE O NOVO CPF:");
                        setbuf(stdin,NULL);
                        gets(aux);
                        strcpy(editar.cpf,aux);
                        break;
                    case 3:
                        cabecalho();
                        printf("\n\tDIGITE O NOVO EMAIL:");
                        setbuf(stdin,NULL);
                        gets(aux);
                        strcpy(editar.email,aux);
                        break;
                    case 4:
                        break;
                }

                fwrite(&editar, sizeof(ORGANIZADOR),1,AUXORGAN);
                verifica++;
        }else{
            fwrite(&editar, sizeof(ORGANIZADOR),1,AUXORGAN);
        }
    }

    fclose(ORGAN);
    fclose(AUXORGAN);
    remove("organizadores.txt");
    rename("organizadoresaux.txt","organizadores.txt");

    if(verifica == 0){
        return 0;
    }else{
        printf("\n\t>> EDITADO <<\n");
        limparTela();
        return 1;
    }
}

int removerOrganizador(int x){

    int verificador = 0;

     ORGANIZADOR remover;
     ORGAN = fopen("organizadores.txt","rb");
     AUXORGAN = fopen("organizadoresaux.txt","ab");

     while(fread(&remover, sizeof(ORGANIZADOR), 1,ORGAN)){

        if(remover.codigo == x){
            verificador ++;
        }

        if(remover.codigo!=x){
            fwrite(&remover, sizeof(ORGANIZADOR),1,AUXORGAN);
        }
    }

    fclose(ORGAN);
    fclose(AUXORGAN);
    remove("organizadores.txt");
    rename("organizadoresaux.txt","organizadores.txt");

    if(verificador == 0){
        return 0;
    }else{
        printf("\n\t>> REMOVIDO <<\n");
        limparTela();
        return 1;
    }
}

void mostrarOrganizadores(){
        system("cls");
        ORGANIZADOR mostrar;
        ORGAN = fopen("organizadores.txt", "rb");
        cabecalho();
        printf("\t====================ORGANIZADORES====================\n\n");
        while (fread(&mostrar, sizeof(ORGANIZADOR), 1,ORGAN)){
            printf("\tCODIGO: %d\n", mostrar.codigo);
            printf("\tNOME: %s\n", strupr(mostrar.nome));
            printf("\tCPF: %s\n", strupr(mostrar.cpf));
            printf("\tEMAIL: %s\n\n", strupr(mostrar.email));
            printf("\t===================================================\n\n");
        }
        fclose(ORGAN);
		limparTela();
}


int Organizadores(){
    int opcao;

    system("cls");
    cabecalho();
    printf("\n\n\n\t\t    ---------------------------------------------\n");
    printf("\t\t    |                                           |\n");
    printf("\t\t    |        OPÇÕES PARA ORGANIZADOR:           |\n");
    printf("\t\t    |                                           |\n");
    printf("\t\t    |      1 - CADASTRAR                        |\n");
    printf("\t\t    |      2 - EDITAR                           |\n");
    printf("\t\t    |      3 - REMOVER                          |\n");
    printf("\t\t    |      4 - LISTAR                           |\n");
    printf("\t\t    |      5 - RETORNAR A TELA ANTERIOR         |\n");
    printf("\t\t    |                                           |\n");
    printf("\t\t    ---------------------------------------------\n");
    printf("\n\t\t            OPÇÃO:");
    scanf("%d", &opcao);
    return opcao;
}

/*--------------------------------------------------MENU/MAIN--------------------------------------------------------------------*/

void menu(){

    int aux=0,aux2=0,aux3=0,aux4=0,aux5=0, id=0, op,op2,op3, verifica;

    do{

        system("cls");
        cabecalho();
        printf("\n\n\n\t\t    ---------------------------------------------\n");
        printf("\t\t    |                                           |\n");
        printf("\t\t    |           OPÇÕES DO SISTEMA:              |\n");
        printf("\t\t    |                                           |\n");
        printf("\t\t    |       1 - MENU DOS CONGRESSISTAS          |\n");
        printf("\t\t    |       2 - MENU DOS PALESTRANTES           |\n");
        printf("\t\t    |       3 - MENU DOS ORGANIZADORES          |\n");
        printf("\t\t    |       4 - MENU DOS EVENTOS                |\n");
        printf("\t\t    |       5 - SAIR DO PROGRAMA                |\n");
        printf("\t\t    |                                           |\n");
        printf("\t\t    ---------------------------------------------\n");
        printf("\n\t\t            OPÇÃO:");
        scanf("%d", &op);

        switch(op){
            case 1:{
                do{
                aux = Congressistas();
                switch(aux){
                    case 1:
                        cadastrarCongressita();
                        break;
                    case 2:
                        mostrarCongressistas();
                        cabecalho();
                        printf("\n\tDIGITE O CÓDIGO DO CONGRESSITA QUE DESEJA ALTERAR>>");
                        scanf("%d", &id);
                        verifica = editarCongressista(id);
                        if(verifica == 0){
                            printf("\t>> CODIGO NÃO ENCONTRADO <<\n");
                            limparTela();
                        }
                        break;
                    case 3:
                        mostrarCongressistas();
                        cabecalho();
                        printf("\n\tDIGITE O CÓDIGO DO CONGRESSITA QUE DESEJA REMOVER>>");
                        scanf("%d", &id);
                        verifica = removerCongressista(id);
                        if(verifica == 0){
                            printf("\t>> CODIGO NÃO ENCONTRADO <<\n");
                            limparTela();
                        }
                        break;
                    case 4:
                        mostrarCongressistas();
                        break;
                    case 5:
             do{
                int cod,cod2,cod3,cod4;

                system("cls");
                cabecalho();
                printf("\n\n\n\t\t  --------------------------------------------------\n");
                printf("\t\t  |                                                |\n");
                printf("\t\t  |             OPÇÕES DO SISTEMA:                 |\n");
                printf("\t\t  |                                                |\n");
                printf("\t\t  |     1 - VERIFICAR CADASTRO EM PALESTRAS        |\n");
                printf("\t\t  |     2 - VERIFICAR CADASTRO EM OFICINAS         |\n");
                printf("\t\t  |     3 - VERIFICAR CADASTRO EM CURSOS           |\n");
                printf("\t\t  |     4 - VERIFICAR CADASTRO EM GRUPOS           |\n");
                printf("\t\t  |     5 - RETORNAR A TELA ANTERIOR               |\n");
                printf("\t\t  |                                                |\n");
                printf("\t\t  --------------------------------------------------\n");
                printf("\n\t\t           OPÇÃO:");
                scanf("%d", &op3);

                switch(op3){
                    case 1:
                        mostrarCongressistas();
                        cabecalho();
                        printf("\tDIGITE O CODIGO DO CONGRESSITA>>");
                        setbuf(stdin,NULL);
                        scanf("%d",&cod);
                        int verifica = verificaCongressistaCadastrado(cod);
                        if(verifica == 0){
                            printf("\n\t>> CONGRESSITA NÃO ENCONTRADO, RETORNANDO A TELA PRINCIPAL <<\n");
                            limparTela();
                        }
                        else{
                            mostrarPalestrasPorCongressista(cod);
                        }
                        break;
                    case 2:
                        mostrarCongressistas();
                        cabecalho();
                        printf("\tDIGITE O CODIGO DO CONGRESSITA>>");
                        setbuf(stdin,NULL);
                        scanf("%d",&cod2);
                        int verifica2 = verificaCongressistaCadastrado(cod2);
                        if(verifica2 == 0){
                            printf("\n\t>> CONGRESSITA NÃO ENCONTRADO, RETORNANDO A TELA PRINCIPAL <<\n");
                            limparTela();
                        }
                        else{
                            mostrarOficinasPorCongressista(cod2);
                        }
                        break;
                    case 3:
                        mostrarCongressistas();
                        cabecalho();
                        printf("\tDIGITE O CODIGO DO CONGRESSITA>>");
                        setbuf(stdin,NULL);
                        scanf("%d",&cod3);
                        int verifica3 = verificaCongressistaCadastrado(cod3);
                        if(verifica3 == 0){
                            printf("\n\t>> CONGRESSITA NÃO ENCONTRADO, RETORNANDO A TELA PRINCIPAL <<\n");
                            limparTela();
                        }
                        else{
                            mostrarCursosPorCongressista(cod3);
                        }
                        break;

                    case 4:
                        mostrarCongressistas();
                        cabecalho();
                        printf("\tDIGITE O CODIGO DO CONGRESSITA>>");
                        setbuf(stdin,NULL);
                        scanf("%d",&cod4);
                        int verifica4 = verificaCongressistaCadastrado(cod4);
                        if(verifica4 == 0){
                            printf("\n\t>> CONGRESSITA NÃO ENCONTRADO, RETORNANDO A TELA PRINCIPAL <<\n");
                            limparTela();
                        }
                        else{
                            mostrarGruposPorCongressista(cod4);
                        }
                        break;
                    case 5:
                        break;
                    default:
                        printf("\n\t>> OPÇÃO INVALIDA <<\n");
                        limparTela();
                        break;
                }
              }while(op3!=5);

                        break;
                    case 6:
                        break;
                    default:
                        printf("\n\t>> OPÇÃO INVALIDA <<\n");
                        limparTela();
                        break;
                }
                }while(aux!=6);
                break;
            }

              case 2:{
                do{
                aux = Palestrantes();
                switch(aux){
                    case 1:
                        cadastrarPalestrante();
                        break;
                    case 2:
                        mostrarPalestrantes();
                        cabecalho();
                        printf("\n\tDIGITE O CÓDIGO DO PALESTRANTE QUE DESEJA ALTERAR>>");
                        scanf("%d", &id);
                        verifica = editarPalestrante(id);
                        if(verifica == 0){
                            printf("\t>> CODIGO NÃO ENCONTRADO <<\n");
                            limparTela();
                        }
                        break;
                    case 3:
                        mostrarPalestrantes();
                        cabecalho();
                        printf("\n\tDIGITE O CÓDIGO DO PALESTRANTE QUE DESEJA REMOVER>>");
                        scanf("%d", &id);
                        verifica = removerPalestrante(id);
                        if(verifica == 0){
                            printf("\t>> CODIGO NÃO ENCONTRADO <<\n");
                            limparTela();
                        }
                        break;

                    case 4:
                        mostrarPalestrantes();
                        break;
                    case 5:


            do{
                int cod,cod2,cod3,cod4;

                system("cls");
                cabecalho();
                printf("\n\n\n\t\t  --------------------------------------------------\n");
                printf("\t\t  |                                                |\n");
                printf("\t\t  |             OPÇOES DO SISTEMA:                 |\n");
                printf("\t\t  |                                                |\n");
                printf("\t\t  |     1 - VERIFICAR CADASTRO EM PALESTRAS        |\n");
                printf("\t\t  |     2 - VERIFICAR CADASTRO EM OFICINAS         |\n");
                printf("\t\t  |     3 - VERIFICAR CADASTRO EM CURSOS           |\n");
                printf("\t\t  |     4 - VERIFICAR CADASTRO EM GRUPOS           |\n");
                printf("\t\t  |     5 - RETORNAR A TELA ANTERIOR               |\n");
                printf("\t\t  |                                                |\n");
                printf("\t\t  --------------------------------------------------\n");
                printf("\n\t\t           OPÇÃO:");
                scanf("%d", &op3);

                switch(op3){
                    case 1:
                        mostrarPalestrantes();
                        cabecalho();
                        printf("\tDIGITE O CODIGO DO PALESTRANTE>>");
                        setbuf(stdin,NULL);
                        scanf("%d",&cod);
                        int verifica = verificaPalestranteCadastrado(cod);
                        if(verifica == 0){
                            printf("\n\t>> PALESTRANTE NÃO ENCONTRADO, RETORNANDO A TELA PRINCIPAL <<\n");
                            limparTela();
                        }
                        else{
                            mostrarPalestrasPorPalestrante(cod);
                        }
                        break;
                    case 2:
                        mostrarPalestrantes();
                        cabecalho();
                        printf("\tDIGITE O CODIGO DO PALESTRANTE>>");
                        setbuf(stdin,NULL);
                        scanf("%d",&cod2);
                        int verifica2 = verificaPalestranteCadastrado(cod2);
                        if(verifica2 == 0){
                            printf("\n\t>> PALESTRANTE NÃO ENCONTRADO, RETORNANDO A TELA PRINCIPAL <<\n");
                            limparTela();
                        }
                        else{
                            mostrarOficinasPorPalestrante(cod2);
                        }
                        break;
                    case 3:
                        mostrarPalestrantes();
                        cabecalho();
                        printf("\tDIGITE O CODIGO DO PALESTRANTE>>");
                        setbuf(stdin,NULL);
                        scanf("%d",&cod3);
                        int verifica3 = verificaPalestranteCadastrado(cod3);
                        if(verifica3 == 0){
                            printf("\n\t>> PALESTRANTE NÃO ENCONTRADO, RETORNANDO A TELA PRINCIPAL <<\n");
                            limparTela();
                        }
                        else{
                            mostrarCursosPorPalestrante(cod3);
                        }
                        break;

                    case 4:
                        mostrarPalestrantes();
                        cabecalho();
                        printf("\tDIGITE O CODIGO DO PALESTRANTE>>");
                        setbuf(stdin,NULL);
                        scanf("%d",&cod4);
                        int verifica4 = verificaPalestranteCadastrado(cod4);
                        if(verifica4 == 0){
                            printf("\n\t>> PALESTRANTE NÃO ENCONTRADO, RETORNANDO A TELA PRINCIPAL <<\n");
                            limparTela();
                        }
                        else{
                            mostrarGruposPorPalestrante(cod4);
                        }
                        break;
                    case 5:
                        break;
                    default:
                        printf("\n\t>> OPÇÃO INVALIDA <<\n");
                        limparTela();
                        break;
                }
              }while(op3!=5);

                        break;
                    case 6:
                        break;
                    default:
                        printf("\n\t>> OPÇÃO INVALIDA <<\n");
                        limparTela();
                        break;
                }
              }while(aux!=6);
                break;
            }

               case 3:{
                do{
                aux = Organizadores();
                switch(aux){
                    case 1:
                        cadastrarOrganizador();
                        break;
                    case 2:
                        mostrarOrganizadores();
                        cabecalho();
                        printf("\n\tDIGITE O CÓDIGO DO ORGANIZADOR QUE DESEJA ALTERAR>>");
                        scanf("%d", &id);
                        verifica = editarOrganizador(id);
                        if(verifica == 0){
                            printf("\t>> CODIGO NÃO ENCONTRADO <<\n");
                            limparTela();
                        }
                        break;
                    case 3:
                        mostrarOrganizadores();
                        cabecalho();
                        printf("\n\tDIGITE O CÓDIGO DO ORGANIZADOR QUE DESEJA REMOVER>>");
                        scanf("%d", &id);
                        verifica = removerOrganizador(id);
                        if(verifica == 0){
                            printf("\t>> CODIGO NÃO ENCONTRADO <<\n");
                            limparTela();
                        }
                        break;
                    case 4:
                        mostrarOrganizadores();
                        break;
                    case 5:
                        break;
                    default:
                        printf("\n\t>> OPÇÃO INVALIDA <<\n");
                        limparTela();
                        break;
                }
                }while(aux != 5);
                break;
               }
            case 4:{

    do{
        system("cls");
        cabecalho();
        printf("\n\n\n\t\t    -----------------------------------------------\n");
        printf("\t\t    |                                             |\n");
        printf("\t\t    |             OPÇÕES DO SISTEMA:              |\n");
        printf("\t\t    |                                             |\n");
        printf("\t\t    |      1 - PAGINA DAS PALESTRAS               |\n");
        printf("\t\t    |      2 - PAGINA DAS OFICINAS                |\n");
        printf("\t\t    |      3 - PAGINA DOS CURSOS                  |\n");
        printf("\t\t    |      4 - PAGINA DOS GRUPOS DE DISCURSSAO    |\n");
        printf("\t\t    |      5 - RETORNAR A TELA ANTERIOR           |\n");
        printf("\t\t    |                                             |\n");
        printf("\t\t    -----------------------------------------------\n");
        printf("\n\t\t            OPÇÃO:");
        scanf("%d", &op2);

        switch(op2){
            case 1:{
                do{
                aux2 = Palestras();
                char nomeA[30];
                char horarioteste[30];
                char localteste[30];
                int codi;
                switch(aux2){
                    case 1:
                        mostrarPalestrantes();
                        cabecalho();
                        printf("\n\n\tDIGITE O CODIGO DO PALESTRANTE>>");
                        setbuf(stdin,NULL);
                        scanf("%d",&codi);
                        verifica = verificaPalestranteCadastradoEmPalestra(codi);
                        if(verifica == 0){
                            printf("\n\t>> PALESTRANTE NÃO ENCONTRADO, RETORNANDO A TELA PRINCIPAL <<\n");
                            limparTela();
                        }
                        else if(verifica == 2){
                            printf("\n\t>> O PALESTRANTE JA ESTA CADASTRADO EM UMA PALESTRA <<\n");
                            limparTela();
                        }
                        else{
                        int locais;

                        do{
                        limparTela();
                        cabecalho();

                        printf("\n\n\n\t\t    ------------------------------------------------\n");
                        printf("\t\t    |                                              |\n");
                        printf("\t\t    |         ESCOLHA LOCAL PARA CADASTRO          |\n");
                        printf("\t\t    |                                              |\n");
                        printf("\t\t    |     1 - AUDITORIO 1(CAP.MAX.150 PESSOAS)     |\n");
                        printf("\t\t    |     2 - AUDITORIO 2(CAP.MAX.100 PESSOAS)     |\n");
                        printf("\t\t    |     3 - AUDITORIO 3(CAP.MAX.50 PESSOAS)      |\n");
                        printf("\t\t    |     4 - SALA 1(CAP.MAX.50 PESSOAS)           |\n");
                        printf("\t\t    |     5 - SALA 2(CAP.MAX.50 PESSOAS)           |\n");
                        printf("\t\t    |                                              |\n");
                        printf("\t\t    ------------------------------------------------\n");
                        printf("\n\t\t            OPÇÃO:");

                        scanf("%d",&locais);
                        char vetorLocal[5][12]={"AUDITORIO 1","AUDITORIO 2","AUDITORIO 3","SALA 1","SALA 2"};


                        switch(locais){
                                    case 1:
                                        strcpy(localteste,vetorLocal[0]);
                                        break;
                                    case 2:
                                        strcpy(localteste,vetorLocal[1]);
                                        break;
                                    case 3:
                                        strcpy(localteste,vetorLocal[2]);
                                        break;
                                    case 4:
                                        strcpy(localteste,vetorLocal[3]);
                                        break;
                                    case 5:
                                        strcpy(localteste,vetorLocal[4]);
                                        break;
                                }
                        }while(locais!=1 && locais!=2 && locais!=3 && locais!=4 && locais!=5);

                        int horarios;

                        do{
                        limparTela();
                        cabecalho();

                        printf("\n\n\n\t\t    ------------------------------------------------\n");
                        printf("\t\t    |                                              |\n");
                        printf("\t\t    |        ESCOLHA HORARIO PARA CADASTRO         |\n");
                        printf("\t\t    |                                              |\n");
                        printf("\t\t    |        1 - 07:00H-08:30H/DIA 14              |\n");
                        printf("\t\t    |        2 - 08:30H-10:00H/DIA 14              |\n");
                        printf("\t\t    |        3 - 10:00H-11:30H/DIA 14              |\n");
                        printf("\t\t    |        4 - 07:00H-08:30H/DIA 15              |\n");
                        printf("\t\t    |        5 - 08:30H-10:00H/DIA 15              |\n");
                        printf("\t\t    |        6 - 10:00H-11:30H/DIA 15              |\n");
                        printf("\t\t    |                                              |\n");
                        printf("\t\t    ------------------------------------------------\n");
                        printf("\n\t\t            OPÇÃO:");

                        scanf("%d",&horarios);
                        char vetorHorario[6][25]={"07:00H-08:30H/DIA 14","08:30H-10:00H/DIA 14","10:00H-11:30H/DIA 14","07:00H-08:30H/DIA 15","08:30H-10:00H/DIA 15","10:00H-11:30H/DIA 15"};


                        switch(horarios){
                                    case 1:
                                        strcpy(horarioteste,vetorHorario[0]);
                                        break;
                                    case 2:
                                        strcpy(horarioteste,vetorHorario[1]);
                                        break;
                                    case 3:
                                        strcpy(horarioteste,vetorHorario[2]);
                                        break;
                                    case 4:
                                        strcpy(horarioteste,vetorHorario[3]);
                                        break;
                                    case 5:
                                        strcpy(horarioteste,vetorHorario[4]);
                                        break;
                                    case 6:
                                        strcpy(horarioteste,vetorHorario[5]);
                                        break;
                                }
                        }while(horarios!=1 && horarios!=2 && horarios!=3 && horarios!=4 && horarios!=5 && horarios!=6);

                        int verifica = testeHorarioDisponivelParaPalestra(localteste,horarioteste);

                        if(verifica == 0){
                            cadastrarPalestra(codi,localteste,horarioteste);
                        }
                        else {
                            printf("\n\t>> HORARIOS INDISPONIVEIS <<\n");
                            limparTela();
                        }

                        }
                        break;
                    case 2:
                       /*FUNCAO DE EDITAR*/
                        break;
                    case 3:
                        mostrarPalestras();
                        cabecalho();
                        printf("\n\n\tDIGITE O CÓDIGO DA PALESTRA QUE DESEJA REMOVER>>");
                        scanf("%d", &id);
                        verifica = removerPalestra(id);
                        if(verifica == 0){
                            printf("\t>> CODIGO NAO ENCONTRADO <<\n");
                            limparTela();
                        }
                        break;
                    case 4:
                        mostrarPalestras();
                        break;
                    case 5:

                do{
                    int cod,cod2,cod3,cod4;

                    system("cls");
                    cabecalho();
                    printf("\n\n\n\t\t  --------------------------------------------------\n");
                    printf("\t\t  |                                                |\n");
                    printf("\t\t  |             OPÇOES DO SISTEMA:                 |\n");
                    printf("\t\t  |                                                |\n");
                    printf("\t\t  |     1 - CADASTRAR CONGRESSISTA EM PALESTRA     |\n");
                    printf("\t\t  |     2 - MOSTRAR CONGRESSISTAS CADASTRADOS      |\n");
                    printf("\t\t  |     3 - MOSTRAR CONGRESSISTAS POR PALESTRA     |\n");
                    printf("\t\t  |     4 - CANCELAR CADASTRO DE CONGRESSISTA      |\n");
                    printf("\t\t  |     5 - RETORNAR A TELA ANTERIOR               |\n");
                    printf("\t\t  |                                                |\n");
                    printf("\t\t  --------------------------------------------------\n");
                    printf("\n\t\t           OPÇÃO:");
                    scanf("%d", &op3);


                    switch(op3){
                    case 1:

                        mostrarCongressistas();
                        cabecalho();
                        printf("\n\n\tDIGITE O CODIGO DO CONGRESSITA>>");
                        setbuf(stdin,NULL);
                        scanf("%d",&cod);
                        int verifica = verificaCongressistaCadastrado(cod);
                        if(verifica == 0){
                            printf("\n\t>> CONGRESSITA NÃO ENCONTRADO, RETORNANDO A TELA PRINCIPAL <<\n");
                            limparTela();
                        }

                        else{
                        mostrarPalestras();
                        cabecalho();
                        printf("\n\n\tDIGITE O CODIGO DA PALESTRA>>");
                        setbuf(stdin,NULL);
                        scanf("%d",&cod2);
                        int verifica = verificaPalestra(cod2);
                        if(verifica == 0){
                            printf("\n\t>> PALESTRA NÃO ENCONTRADA, RETORNANDO A TELA PRINCIPAL <<\n");
                            limparTela();
                        }
                        else{
                        cadastrarEmPalestra(cod,cod2);
                        }
                        }
                        break;
                    case 2:
                        mostrarCadastradosNasPalestras();
                        break;
                    case 3:
                        mostrarPalestras();
                        cabecalho();
                        printf("\n\n\tDIGITE O CODIGO DA PALESTRA>>");
                        setbuf(stdin,NULL);
                        scanf("%d",&cod3);
                        int verifica3 = verificaPalestra(cod3);
                        if(verifica3 == 0){
                            printf("\n\t>> PALESTRA NÃO ENCONTRADA, RETORNANDO A TELA PRINCIPAL <<\n");
                            limparTela();
                        }
                        else{
                            mostrarCadastradosPorPalestra(cod3);
                        }
                        break;
                    case 4:
                        mostrarCadastradosNasPalestras();
                        cabecalho();
                        printf("\n\n\tDIGITE O CODIGO DO CADASTRADO QUE DESEJA REMOVER>>");
                        setbuf(stdin,NULL);
                        scanf("%d",&cod4);

                        int verifica4 = removerCadastroDePalestra(cod4);
                        if(verifica4 == 0){
                            printf("\n\t>> CODIGO NAO ENCONTRADO <<\n");
                            limparTela();
                        }

                        break;
                    case 5:
                        break;
                    default:
                        printf("\n\t>> OPÇÃO INVALIDA <<\n");
                        limparTela();
                        break;
                    }

                }while(op3!=5);

                        break;
                    case 6:
                        break;
                    default:
                        printf("\n\t>> OPÇÃO INVALIDA <<\n");
                        limparTela();
                        break;
                }
                }while(aux2!=6);
                break;
            }

             case 3:{
                do{
                aux3 = Cursos();
                char nomeA[30];
                char horarioteste[30];
                char localteste[30];
                int codi;
                switch(aux3){
                    case 1:
                        mostrarPalestrantes();
                        cabecalho();
                        printf("\n\n\tDIGITE O CODIGO DO PALESTRANTE>>");
                        setbuf(stdin,NULL);
                        scanf("%d",&codi);
                        verifica = verificaPalestranteCadastradoEmCurso(codi);
                        if(verifica == 0){
                            printf("\n\t>> PALESTRANTE NÃO ENCONTRADO, RETORNANDO A TELA PRINCIPAL <<\n");
                            limparTela();
                        }
                        else if(verifica == 2){
                            printf("\n\t>> O PALESTRANTE JA ESTA CADASTRADO EM UM CURSO <<\n");
                            limparTela();
                        }
                        else{
                        int locais;

                        do{
                        limparTela();
                        cabecalho();
                        printf("\n\n\n\n\n\t\t    ------------------------------------------------\n");
                        printf("\t\t    |                                              |\n");
                        printf("\t\t    |         ESCOLHA LOCAL PARA CADASTRO          |\n");
                        printf("\t\t    |                                              |\n");
                        printf("\t\t    |     1 - AUDITORIO 3(CAP.MAX.50 PESSOAS)      |\n");
                        printf("\t\t    |     2 - SALA 1(CAP.MAX.50 PESSOAS)           |\n");
                        printf("\t\t    |     3 - SALA 2(CAP.MAX.50 PESSOAS)           |\n");
                        printf("\t\t    |                                              |\n");
                        printf("\t\t    ------------------------------------------------\n");
                        printf("\n\t\t            OPÇÃO:");

                        scanf("%d",&locais);
                        char vetorLocal[3][12]={"AUDITORIO 3","SALA 1","SALA 2"};


                        switch(locais){
                                    case 1:
                                        strcpy(localteste,vetorLocal[0]);
                                        break;
                                    case 2:
                                        strcpy(localteste,vetorLocal[1]);
                                        break;
                                    case 3:
                                        strcpy(localteste,vetorLocal[2]);
                                        break;

                                }
                        }while(locais!=1 && locais!=2 && locais!=3);

                        int horarios;


                        do{
                        limparTela();
                        cabecalho();

                        printf("\n\n\n\n\t\t    ------------------------------------------------\n");
                        printf("\t\t    |                                              |\n");
                        printf("\t\t    |        ESCOLHA HORARIO PARA CADASTRO         |\n");
                        printf("\t\t    |                                              |\n");
                        printf("\t\t    |        1 - 12:00H-13:00H/DIA 14              |\n");
                        printf("\t\t    |        2 - 13:00H-14:00H/DIA 14              |\n");
                        printf("\t\t    |        3 - 14:00H-15:00H/DIA 14              |\n");
                        printf("\t\t    |        4 - 15:00H-16:00H/DIA 14              |\n");
                        printf("\t\t    |                                              |\n");
                        printf("\t\t    ------------------------------------------------\n");
                        printf("\n\t\t            OPÇÃO:");

                        scanf("%d",&horarios);
                        char vetorHorario[4][25]={"12:00H-13:00H/DIA 14","13:00H-14:00H/DIA 14","14:00H-15:00H/DIA 14","15:00H-16:00H/DIA 14"};

                        switch(horarios){
                                    case 1:
                                        strcpy(horarioteste,vetorHorario[0]);
                                        break;
                                    case 2:
                                        strcpy(horarioteste,vetorHorario[1]);
                                        break;
                                    case 3:
                                        strcpy(horarioteste,vetorHorario[2]);
                                        break;
                                    case 4:
                                        strcpy(horarioteste,vetorHorario[3]);
                                        break;

                                }
                        }while(horarios!=1 && horarios!=2 && horarios!=3 && horarios!=4 );

                        int verifica = testeHorarioDisponivelParaCurso(localteste,horarioteste);

                        if(verifica == 0){
                            cadastrarCurso(codi,localteste,horarioteste);
                        }
                        else {
                            printf("\n\t>> HORARIOS INDISPONIVEIS <<\n");
                            limparTela();
                        }

                        }
                        break;
                    case 2:
                        /*FUNCAO DE EDITAR*/
                        break;
                    case 3:
                        mostrarCursos();
                        cabecalho();
                        printf("\n\n\tDIGITE O CÓDIGO DO CURSO QUE DESEJA REMOVER>>");
                        scanf("%d", &id);
                        verifica = removerCurso(id);
                        if(verifica == 0){
                            printf("\t>> CODIGO NÃO ENCONTRADO <<\n");
                            limparTela();
                        }
                        break;
                    case 4:
                        mostrarCursos();
                        break;
                    case 5:

                do{
                    int cod;
                    int cod2;
                    int cod3;
                    int cod4;

                    system("cls");
                    cabecalho();
                    printf("\n\n\n\t\t  --------------------------------------------------\n");
                    printf("\t\t  |                                                |\n");
                    printf("\t\t  |             OPÇOES DO SISTEMA:                 |\n");
                    printf("\t\t  |                                                |\n");
                    printf("\t\t  |     1 - CADASTRAR CONGRESSISTA EM CURSO        |\n");
                    printf("\t\t  |     2 - MOSTRAR CONGRESSISTAS CADASTRADOS      |\n");
                    printf("\t\t  |     3 - MOSTRAR CONGRESSISTAS POR CURSO        |\n");
                    printf("\t\t  |     4 - CANCELAR CADASTRO DE CONGRESSISTA      |\n");
                    printf("\t\t  |     5 - RETORNAR A TELA ANTERIOR               |\n");
                    printf("\t\t  |                                                |\n");
                    printf("\t\t  --------------------------------------------------\n");
                    printf("\n\t\t           OPÇÃO:");
                    scanf("%d", &op3);

                    switch(op3){
                    case 1:

                        mostrarCongressistas();
                        cabecalho();
                        printf("\n\n\tDIGITE O CODIGO DO CONGRESSITA>>");
                        setbuf(stdin,NULL);
                        scanf("%d",&cod);
                        int verifica = verificaCongressistaCadastradoEmCurso(cod);
                        if(verifica == 0){
                            printf("\n\t>> CONGRESSITA NÃO ENCONTRADO, RETORNANDO A TELA PRINCIPAL <<\n");
                            limparTela();
                        }
                        else if(verifica == 2){
                            printf("\n\t>> O CONGRESSISTA JA ESTA CADASTRADO EM UM CURSO <<\n");
                            limparTela();
                        }
                        else{
                        mostrarCursos();
                        cabecalho();
                        printf("\n\n\tDIGITE O CODIGO DO CURSO>>");
                        setbuf(stdin,NULL);
                        scanf("%d",&cod2);
                        int verifica = verificaCurso(cod2);
                        if(verifica == 0){
                            printf("\n\t>> CURSO NÃO ENCONTRADO, RETORNANDO A TELA PRINCIPAL <<\n");
                            limparTela();
                        }
                        else{
                        cadastrarEmCurso(cod,cod2);
                        }
                        }
                        break;
                    case 2:
                        mostrarCadastradosNosCursos();
                        break;
                    case 3:
                        mostrarCursos();
                        cabecalho();
                        printf("\n\n\tDIGITE O CODIGO DO CURSO>>");
                        setbuf(stdin,NULL);
                        scanf("%d",&cod3);
                        int verifica3 = verificaCurso(cod3);
                        if(verifica3 == 0){
                            printf("\n\t>> CURSO NÃO ENCONTRADO, RETORNANDO A TELA PRINCIPAL <<\n");
                            limparTela();
                        }
                        else{
                            mostrarCadastradosPorCurso(cod3);
                        }
                        break;
                    case 4:
                        mostrarCadastradosNosCursos();
                        cabecalho();
                        printf("\n\n\tDIGITE O CODIGO DO CADASTRADO QUE DESEJA REMOVER>>");
                        setbuf(stdin,NULL);
                        scanf("%d",&cod4);

                        int verifica4 = removerCadastroDeCurso(cod4);
                        if(verifica4 == 0){
                            printf("\n\t>> CODIGO NÃO ENCONTRADO <<\n");
                            limparTela();
                        }
                        break;
                    case 5:
                        break;
                    default:
                        printf("\n\t>> OPÇÃO INVALIDA <<\n");
                        limparTela();
                        break;
                    }

                }while(op3!=5);

                        break;
                    case 6:
                        break;
                    default:
                        printf("\n\t>> OPÇÃO INVALIDA <<\n");
                        limparTela();
                        break;
                }
                }while(aux3!=6);
                break;
            }

            case 2:{
                do{
                aux4 = Oficinas();
                char nomeA[30];
                char horarioteste[30];
                char localteste[30];
                int codi;
                switch(aux4){
                    case 1:
                        mostrarPalestrantes();
                        cabecalho();
                        printf("\n\n\tDIGITE O CODIGO DO PALESTRANTE>>");
                        setbuf(stdin,NULL);
                        scanf("%d",&codi);
                        verifica = verificaPalestranteCadastradoEmOficina(codi);
                        if(verifica == 0){
                            printf("\n\t>> PALESTRANTE NÃO ENCONTRADO, RETORNANDO A TELA PRINCIPAL <<\n");
                            limparTela();
                        }
                        else if(verifica == 2){
                            printf("\n\t>> O PALESTRANTE JA ESTA CADASTRADO EM UMA OFICINA <<\n");
                            limparTela();
                        }
                        else{
                        int locais;

                        do{
                        limparTela();
                        cabecalho();

                        printf("\n\n\n\n\n\t\t    ------------------------------------------------\n");
                        printf("\t\t    |                                              |\n");
                        printf("\t\t    |        ESCOLHA LOCAL PARA CADASTRO           |\n");
                        printf("\t\t    |                                              |\n");
                        printf("\t\t    |     1 - SALA 3(CAP.MAX.30 PESSOAS)           |\n");
                        printf("\t\t    |     2 - LABORATORIO 1(CAP.MAX.20 PESSOAS)    |\n");
                        printf("\t\t    |     3 - LABORATORIO 2(CAP.MAX.20 PESSOAS)    |\n");
                        printf("\t\t    |                                              |\n");
                        printf("\t\t    ------------------------------------------------\n");
                        printf("\n\t\t            OPÇÃO:");

                        scanf("%d",&locais);
                        char vetorLocal[3][25]={"SALA 3","LABORATORIO 1","LABORATORIO 2"};


                        switch(locais){
                                    case 1:
                                        strcpy(localteste,vetorLocal[0]);
                                        break;
                                    case 2:
                                        strcpy(localteste,vetorLocal[1]);
                                        break;
                                    case 3:
                                        strcpy(localteste,vetorLocal[2]);
                                        break;

                                }
                        }while(locais!=1 && locais!=2 && locais!=3);

                        int horarios;

                        do{
                        limparTela();
                        cabecalho();

                        printf("\n\n\n\n\t\t    ------------------------------------------------\n");
                        printf("\t\t    |                                              |\n");
                        printf("\t\t    |        ESCOLHA HORARIO PARA CADASTRO         |\n");
                        printf("\t\t    |                                              |\n");
                        printf("\t\t    |        1 - 16:00H-17:00H/DIA 14              |\n");
                        printf("\t\t    |        2 - 17:00H-18:00H/DIA 14              |\n");
                        printf("\t\t    |        3 - 16:00H-17:00H/DIA 15              |\n");
                        printf("\t\t    |        4 - 17:00H-18:00H/DIA 15              |\n");
                        printf("\t\t    |                                              |\n");
                        printf("\t\t    ------------------------------------------------\n");
                        printf("\n\t\t            OPÇÃO:");

                        scanf("%d",&horarios);
                        char vetorHorario[4][25]={"16:00H-17:00H/DIA 14","17:00H-18:00H/DIA 14","16:00H-17:00H/DIA 15","17:00H-18:00H/DIA 15"};

                        switch(horarios){
                                    case 1:
                                        strcpy(horarioteste,vetorHorario[0]);
                                        break;
                                    case 2:
                                        strcpy(horarioteste,vetorHorario[1]);
                                        break;
                                    case 3:
                                        strcpy(horarioteste,vetorHorario[2]);
                                        break;
                                    case 4:
                                        strcpy(horarioteste,vetorHorario[3]);
                                        break;

                                }
                        }while(horarios!=1 && horarios!=2 && horarios!=3 && horarios!=4 );

                        int verifica = testeHorarioDisponivelParaOficina(localteste,horarioteste);

                        if(verifica == 0){
                            cadastrarOficina(codi,localteste,horarioteste);
                        }
                        else {
                            printf("\n\t>> HORARIOS INDISPONIVEIS <<\n");
                            limparTela();
                        }

                        }
                        break;
                    case 2:
                        /*FUNCAO DE EDITAR*/
                        break;
                    case 3:
                        mostrarOficinas();
                        cabecalho();
                        printf("\n\n\tDIGITE O CÓDIGO DA OFICINA QUE DESEJA REMOVER>>");
                        scanf("%d", &id);
                        verifica = removerOficina(id);
                        if(verifica == 0){
                            printf("\t>> CODIGO NÃO ENCONTRADO <<\n");
                            limparTela();
                        }
                        break;
                    case 4:
                        mostrarOficinas();
                        break;
                    case 5:

                do{
                    int cod,cod2,cod3,cod4;

                    system("cls");
                    cabecalho();
                    printf("\n\n\n\t\t  --------------------------------------------------\n");
                    printf("\t\t  |                                                |\n");
                    printf("\t\t  |             OPÇOES DO SISTEMA:                 |\n");
                    printf("\t\t  |                                                |\n");
                    printf("\t\t  |     1 - CADASTRAR CONGRESSISTA EM OFICINA      |\n");
                    printf("\t\t  |     2 - MOSTRAR CONGRESSISTAS CADASTRADOS      |\n");
                    printf("\t\t  |     3 - MOSTRAR CONGRESSISTAS POR OFICINA      |\n");
                    printf("\t\t  |     4 - CANCELAR CADASTRO DE CONGRESSISTA      |\n");
                    printf("\t\t  |     5 - RETORNAR A TELA ANTERIOR               |\n");
                    printf("\t\t  |                                                |\n");
                    printf("\t\t  --------------------------------------------------\n");
                    printf("\n\t\t           OPÇÃO:");
                    scanf("%d", &op3);

                    switch(op3){
                    case 1:

                        mostrarCongressistas();
                        cabecalho();
                        printf("\n\n\tDIGITE O CODIGO DO CONGRESSITA>>");
                        setbuf(stdin,NULL);
                        scanf("%d",&cod);
                        int verifica = verificaCongressistaCadastradoEmOficina(cod);
                        if(verifica == 0){
                            printf("\n\t>> CONGRESSITA NÃO ENCONTRADO, RETORNANDO A TELA PRINCIPAL <<\n");
                            limparTela();
                        }
                        else if(verifica == 2){
                            printf("\n\t>> O CONGRESSISTA JA ESTA CADASTRADO EM UMA OFICINA <<\n");
                            limparTela();
                        }

                        else{
                        mostrarOficinas();
                        cabecalho();
                        printf("\n\n\tDIGITE O CODIGO DA OFICINA>>");
                        setbuf(stdin,NULL);
                        scanf("%d",&cod2);
                        int verifica = verificaOficina(cod2);
                        if(verifica == 0){
                            printf("\n\t>> OFICINA NÃO ENCONTRADA, RETORNANDO A TELA PRINCIPAL <<\n");
                            limparTela();
                        }
                        else{
                        cadastrarEmOficina(cod,cod2);
                        }
                        }
                        break;
                    case 2:
                        mostrarCadastradosNasOficinas();
                        break;
                    case 3:
                        mostrarOficinas();
                        cabecalho();
                        printf("\n\n\tDIGITE O CODIGO DA OFICINA>>");
                        setbuf(stdin,NULL);
                        scanf("%d",&cod3);
                        int verifica3 = verificaOficina(cod3);
                        if(verifica3 == 0){
                            printf("\n\t>> OFICINA NÃO ENCONTRADA, RETORNANDO A TELA PRINCIPAL <<\n");
                            limparTela();
                        }
                        else{
                            mostrarCadastradosPorOficina(cod3);
                        }
                        break;
                    case 4:
                        mostrarCadastradosNasOficinas();
                        cabecalho();
                        printf("\n\n\tDIGITE O CODIGO DO CADASTRADO QUE DESEJA REMOVER>>");
                        setbuf(stdin,NULL);
                        scanf("%d",&cod4);

                        int verifica4 = removerCadastroDeOficina(cod4);
                        if(verifica4 == 0){
                            printf("\n\t>> CODIGO NÃO ENCONTRADO <<\n");
                            limparTela();
                        }

                        break;
                    case 5:
                        break;
                    default:
                        printf("\n\t>> OPÇÃO INVALIDA <<\n");
                        limparTela();
                        break;
                    }
                }while(op3!=5);

                        break;
                    case 6:
                        break;
                    default:
                        printf("\n\t>> OPÇÃO INVALIDA <<\n");
                        limparTela();
                        break;
                }
                }while(aux4!=6);
                break;
            }

             case 4:{
                do{
                aux5 = Grupos();
                int locais;
                char horarioteste[30];
                char localteste[30];
                int codi;
                switch(aux5){
                    case 1:
                        do{
                        system("cls");
                        cabecalho();

                        printf("\n\n\n\n\n\t\t    ------------------------------------------------\n");
                        printf("\t\t    |                                              |\n");
                        printf("\t\t    |        ESCOLHA LOCAL PARA CADASTRO           |\n");
                        printf("\t\t    |                                              |\n");
                        printf("\t\t    |     1 - AUDITORIO 3(CAP.MAX.50 PESSOAS)      |\n");
                        printf("\t\t    |     2 - SALA 1(CAP.MAX.50 PESSOAS)           |\n");
                        printf("\t\t    |     3 - SALA 2(CAP.MAX.50 PESSOAS)           |\n");
                        printf("\t\t    |                                              |\n");
                        printf("\t\t    ------------------------------------------------\n");
                        printf("\n\t\t            OPÇÃO:");

                        scanf("%d",&locais);
                        char vetorLocal[3][12]={"AUDITORIO 3","SALA 1","SALA 2"};


                        switch(locais){
                                    case 1:
                                        strcpy(localteste,vetorLocal[0]);
                                        break;
                                    case 2:
                                        strcpy(localteste,vetorLocal[1]);
                                        break;
                                    case 3:
                                        strcpy(localteste,vetorLocal[2]);
                                        break;

                                }
                        }while(locais!=1 && locais!=2 && locais!=3);

                        int horarios;

                        do{
                        limparTela();
                        cabecalho();

                        printf("\n\n\n\n\t\t    ------------------------------------------------\n");
                        printf("\t\t    |                                              |\n");
                        printf("\t\t    |        ESCOLHA HORARIO PARA CADASTRO         |\n");
                        printf("\t\t    |                                              |\n");
                        printf("\t\t    |        1 - 12:00H-13:00H/DIA 15              |\n");
                        printf("\t\t    |        2 - 13:00H-14:00H/DIA 15              |\n");
                        printf("\t\t    |        3 - 14:00H-15:00H/DIA 15              |\n");
                        printf("\t\t    |        4 - 15:00H-16:00H/DIA 15              |\n");
                        printf("\t\t    |                                              |\n");
                        printf("\t\t    ------------------------------------------------\n");
                        printf("\n\t\t            OPÇÃO:");

                        scanf("%d",&horarios);
                        char vetorHorario[4][25]={"12:00H-13:00H/DIA 15","13:00H-14:00H/DIA 15","14:00H-15:00H/DIA 15","15:00H-16:00H/DIA 15"};


                        switch(horarios){
                                    case 1:
                                        strcpy(horarioteste,vetorHorario[0]);
                                        break;
                                    case 2:
                                        strcpy(horarioteste,vetorHorario[1]);
                                        break;
                                    case 3:
                                        strcpy(horarioteste,vetorHorario[2]);
                                        break;
                                    case 4:
                                        strcpy(horarioteste,vetorHorario[3]);
                                        break;

                                }
                        }while(horarios!=1 && horarios!=2 && horarios!=3 && horarios!=4 );

                        int verifica = testeHorarioDisponivelParaGrupo(localteste,horarioteste);

                        if(verifica == 0){
                            cadastrarGrupo(localteste,horarioteste);
                        }
                        else {
                            printf("\n\t>> HORARIOS INDISPONIVEIS <<\n");
                            limparTela();
                        }

                        break;
                    case 2:
                        /*FUNCAO DE EDITAR*/
                        break;
                    case 3:
                        mostrarGrupos();
                        cabecalho();
                        printf("\n\n\tDIGITE O CÓDIGO DO GRUPO QUE DESEJA REMOVER>>");
                        scanf("%d", &id);
                        verifica = removerGrupo(id);
                        if(verifica == 0){
                            printf("\t>> CODIGO NÃO ENCONTRADO <<\n");
                            limparTela();
                        }
                        break;
                    case 4:
                        mostrarGrupos();
                        break;
                    case 5:

                    do{
                    int cod,cod2,cod3,cod4;

                    system("cls");
                    cabecalho();
                    printf("\n\n\n\t\t  --------------------------------------------------\n");
                    printf("\t\t  |                                                |\n");
                    printf("\t\t  |             OPÇOES DO SISTEMA:                 |\n");
                    printf("\t\t  |                                                |\n");
                    printf("\t\t  |     1 - CADASTRAR CONGRESSISTA EM GRUPO        |\n");
                    printf("\t\t  |     2 - MOSTRAR CONGRESSISTAS CADASTRADOS      |\n");
                    printf("\t\t  |     3 - MOSTRAR CONGRESSISTAS POR GRUPO        |\n");
                    printf("\t\t  |     4 - CANCELAR CADASTRO DE CONGRESSISTA      |\n");
                    printf("\t\t  |     5 - RETORNAR A TELA ANTERIOR               |\n");
                    printf("\t\t  |                                                |\n");
                    printf("\t\t  --------------------------------------------------\n");
                    printf("\n\t\t           OPÇÃO:");
                    scanf("%d", &op3);


                    switch(op3){
                    case 1:

                        mostrarCongressistas();
                        cabecalho();
                        printf("\n\n\tDIGITE O CODIGO DO CONGRESSITA>>");
                        setbuf(stdin,NULL);
                        scanf("%d",&cod);
                        int verifica = verificaCongressistaCadastrado(cod);
                        if(verifica == 0){
                            printf("\n\t>> CONGRESSITA NÃO ENCONTRADO, RETORNANDO A TELA PRINCIPAL <<\n");
                            limparTela();
                        }

                        else{
                        mostrarGrupos();
                        cabecalho();
                        printf("\n\n\tDIGITE O CODIGO DO GRUPO>>");
                        setbuf(stdin,NULL);
                        scanf("%d",&cod2);
                        int verifica = verificaGrupo(cod2);
                        if(verifica == 0){
                            printf("\n\t>> GRUPO NÃO ENCONTRADO, RETORNANDO A TELA PRINCIPAL <<\n");
                            limparTela();
                        }
                        else{
                        cadastrarEmGrupo(cod,cod2);
                        }
                        }
                        break;
                    case 2:
                        mostrarCadastradosNosGrupos();
                        break;
                    case 3:
                        mostrarGrupos();
                        cabecalho();
                        printf("\n\n\tDIGITE O CODIGO DO GRUPO>>");
                        setbuf(stdin,NULL);
                        scanf("%d",&cod3);
                        int verifica3 = verificaGrupo(cod3);
                        if(verifica3 == 0){
                            printf("\n\t>> GRUPO NÃO ENCONTRADO, RETORNANDO A TELA PRINCIPAL <<\n");
                            limparTela();
                        }
                        else{
                            mostrarCadastradosPorGrupo(cod3);
                        }
                        break;
                    case 4:
                        mostrarCadastradosNosGrupos();
                        cabecalho();
                        printf("\n\n\tDIGITE O CODIGO DO CADASTRADO QUE DESEJA REMOVER>>");
                        setbuf(stdin,NULL);
                        scanf("%d",&cod4);

                        int verifica4 = removerCadastroDeGrupo(cod4);
                        if(verifica4 == 0){
                            printf("\n\t>> CODIGO NÃO ENCONTRADO <<\n");
                            limparTela();
                        }

                        break;
                    case 5:
                        break;
                    default:
                        printf("\n\t>> OPÇÃO INVALIDA <<\n");
                        limparTela();
                        break;
                    }

                }while(op3!=5);

                        break;
                    case 6:
                        break;
                    default:
                        printf("\n\t>> OPÇÃO INVALIDA <<\n");
                        limparTela();
                        break;
                }
                }while(aux5!=6);
                break;
            }
            }
                }while(op2!=5);
                break;
            }
            case 5:{
                break;
            }
            default:{
                printf("\n\t>> OPÇÃO INVALIDA <<\n");
                limparTela();
                break;
            }
        }
    }while(op != 5);


}

