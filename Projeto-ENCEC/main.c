#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "cadastros.h"
#include "eventos.h"
#include <ctype.h>
#include <time.h>
#include <string.h>

main(){

    setlocale(LC_ALL, "Portuguese");
    system("color 4F");//VERMELHO
    system("mode con:cols=90 lines=0");

    menu();

}



