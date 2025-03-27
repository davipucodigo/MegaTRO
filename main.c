#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void Menu () {
    printf("\n ███╗   ███╗███████╗ ██████╗  █████╗     ████████╗██████╗  ██████╗  ");
    printf("\n ████╗ ████║██╔════╝██╔════╝ ██╔══██╗    ╚══██╔══╝██╔══██╗██╔═══██╗ ");
    printf("\n ██╔████╔██║█████╗  ██║  ███╗███████║       ██║   ██████╔╝██║   ██║ ");
    printf("\n ██║╚██╔╝██║██╔══╝  ██║   ██║██╔══██║       ██║   ██╔══██╗██║   ██║ ");
    printf("\n ██║ ╚═╝ ██║███████╗╚██████╔╝██║  ██║       ██║   ██║  ██║╚██████╔╝ ");
    printf("\n ╚═╝     ╚═╝╚══════╝ ╚═════╝ ╚═╝  ╚═╝       ╚═╝   ╚═╝  ╚═╝ ╚═════╝  ");
    printf("\n DAVI SANT'ANNA - TRABALHO - TURMA 4324 \n");
}


int main () {
    //CONFIGURAÇÕES:
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));

    //MENU:
    Menu();
    return 0;
}