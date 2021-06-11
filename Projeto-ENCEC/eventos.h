#ifndef EVENTOS_H_INCLUDED
#define EVENTOS_H_INCLUDED

#define D 50
#define C 30

void cabecalho();
void limparTela();
int Palestras();
int Oficinas();
int Cursos();
int Grupos();

/*-------------------------------PALESTRAS----------------------------------*/

FILE *PAL;
FILE *AUXPAL;

typedef struct{
    int codigo;
    int cargaH;
    char tema[D];
    char local[D];
    char horario[D];
    char palestrante[D];
}PALESTRA;


int removerPalestra();
void mostrarPalestras();
int verificaPalestranteCadastradoEmPalestra(int x);
void cadastrarPalestra(int x,char localteste[C],char horarioteste[C]);
int testeHorarioDisponivelParaPalestra(char localteste[C],char horarioteste[C]);

/*---------------------------------CURSOS------------------------------------*/

FILE *CURS;
FILE *AUXCURS;

typedef struct{
    int codigo;
    int cargaH;
    char tema[D];
    char local[D];
    char horario[D];
    char palestrante[D];
}CURSO;


int removerCurso();
void mostrarCursos();
int verificaPalestranteCadastradoEmCurso(int x);
void cadastrarCurso(int x,char localteste[C],char horarioteste[C]);
int testeHorarioDisponivelParaCurso(char localteste[C],char horarioteste[C]);

/*--------------------------------OFICINAS-----------------------------------*/

FILE *OFIC;
FILE *AUXOFIC;

typedef struct{
    int codigo;
    int cargaH;
    char tema[D];
    char local[D];
    char horario[D];
    char palestrante[D];
}OFICINA;


int removerOficina();
void mostrarOficinas();
int verificaPalestranteCadastradoEmOficina(int x);
void cadastrarOficina(int x,char localteste[C],char horarioteste[C]);
int testeHorarioDisponivelParaOficina(char localteste[C],char horarioteste[C]);

/*---------------------------------GRUPOS------------------------------------*/

FILE *GRUP;
FILE *AUXGRUP;

typedef struct{
    int codigo;
    int cargaH;
    char tema[D];
    char local[D];
    char horario[D];
    int quantidadeP;
    int Membros_da_mesa[5][5];
}GRUPO;


int removerGrupo();
void mostrarGrupos();
void cadastrarGrupo(char localteste[C],char horarioteste[C]);
int testeHorarioDisponivelParaGrupo(char localteste[C],char horarioteste[C]);

/*--------------------------CADASTRO-EM-PALESTRAS-----------------------------*/

FILE *CADP;
FILE *AUXCADP;

typedef struct{
    int codigo;
    char tema[D];
    char nome[D];
}CADPALESTRAS;


int verificaPalestra(int x);
void mostrarCadastradosNasPalestras();
int removerCadastroDePalestra(int cod4);
void cadastrarEmPalestra(int cod,int cod2);
void mostrarCadastradosPorPalestra(int cod3);

/*--------------------------CADASTRO-EM-GRUPOS--------------------------------*/

FILE *CADG;
FILE *AUXCADG;

typedef struct{
    int codigo;
    char tema[D];
    char nome[D];
}CADGRUPOS;


int verificaGrupo(int x);
void mostrarCadastradosNosGrupos();
int removerCadastroDeGrupo(int cod4);
void cadastrarEmGrupo(int cod,int cod2);
void mostrarCadastradosPorGrupo(int cod3);

/*--------------------------CADASTRO-EM-CURSOS--------------------------------*/

FILE *CADC;
FILE *AUXCADC;

typedef struct{
    int codigo;
    char tema[D];
    char nome[D];
}CADCURSOS;


int verificaCurso(int x);
void mostrarCadastradosNosCursos();
int removerCadastroDeCurso(int cod4);
void cadastrarEmCurso(int cod,int cod2);
void mostrarCadastradosPorCurso(int cod3);
int verificaCongressistaCadastradoEmCurso(int x);

/*--------------------------CADASTRO-EM-OFICINAS------------------------------*/

FILE *CADO;
FILE *AUXCADO;

typedef struct{
    int codigo;
    char tema[D];
    char nome[D];
}CADOFICINAS;


int verificaOficina(int x);
void mostrarCadastradosNasOficinas();
int removerCadastroDeOficina(int cod4);
void cadastrarEmOficina(int cod,int cod2);
void mostrarCadastradosPorOficina(int cod3);
int verificaCongressistaCadastradoEmOficina(int x);

/*------------------------VERIFICAR-POR-CADASTRO------------------------------*/

int verificaCongressistaCadastrado(int x);
int verificaPalestranteCadastrado(int x);

void mostrarPalestrasPorCongressista(int cod);
void mostrarOficinasPorCongressista(int cod2);
void mostrarCursosPorCongressista(int cod3);
void mostrarGruposPorCongressista(int cod4);

void mostrarPalestrasPorPalestrante(int cod);
void mostrarOficinasPorPalestrante(int cod2);
void mostrarCursosPorPalestrante(int cod3);
void mostrarGruposPorPalestrante(int cod4);


#endif // EVENTOS_H_INCLUDED
