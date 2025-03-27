#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//SORTEIO 6 numeros compreendidos entre 1 a 60
#define NUMERO_MAX_SORTEADO 60

//NUMEROS DO USUARIO
#define MAX_NUMEROS_APOSTA 10
#define MIN_NUMEROS_APOSTA 6

//CUSTOS dos NUMEROS APOSTADOS
#define SEIS_NUM_CUSTO 2
#define SETE_NUM_CUSTO 20
#define OITO_NUM_CUSTO 60
#define NOVE_NUM_CUSTO 120
#define DEZ_NUM_CUSTO 450

//PONTUAÇÔES DEBITAVEIS
#define QUADRA 4
#define QUINA 5
#define MEGATRO 6

//DEBITOS
#define PAGA_QUADRA 1650
#define PAGA_QUINA 15000
#define PAGA_MEGATRO 5000000

//TECLA DE SAIDA
#define ESC_TECLA 27


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