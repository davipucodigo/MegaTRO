#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define CLEAR_SCREEN "clear"


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
#define TECLA_ESC 27


//VARIAVEIS
int CREDITO_USUARIO = 1000; // Inicialmente 1000.
int VetNumerosEscolhidos[10] = {0,0,0,0,0,0,0,0,0,0}; // Vetor que guardará os valores apostados.
int ControleNumeroGravados; // Variavel que controla o numero de valores de aposta guardados em VetNumerosEscolhidos.
char c = 48;

//FUNÇÔES
void Menu () {
    printf("\n ███╗   ███╗███████╗ ██████╗  █████╗     ████████╗██████╗  ██████╗  ");
    printf("\n ████╗ ████║██╔════╝██╔════╝ ██╔══██╗    ╚══██╔══╝██╔══██╗██╔═══██╗ ");
    printf("\n ██╔████╔██║█████╗  ██║  ███╗███████║       ██║   ██████╔╝██║   ██║ ");
    printf("\n ██║╚██╔╝██║██╔══╝  ██║   ██║██╔══██║       ██║   ██╔══██╗██║   ██║ ");
    printf("\n ██║ ╚═╝ ██║███████╗╚██████╔╝██║  ██║       ██║   ██║  ██║╚██████╔╝ ");
    printf("\n ╚═╝     ╚═╝╚══════╝ ╚═════╝ ╚═╝  ╚═╝       ╚═╝   ╚═╝  ╚═╝ ╚═════╝  ");
    printf("\n DAVI SANT'ANNA - TRABALHO - TURMA 4324");
    printf("\n| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - |");
    printf("\n| CRÉDITO USUÁRIO: $%d                                               ", CREDITO_USUARIO);
    printf("\n| NÚMEROS APOSTADOS: | %d | %d | %d | %d | %d | %d | %d | %d | %d | %d |        |", VetNumerosEscolhidos[0],VetNumerosEscolhidos[1],VetNumerosEscolhidos[2],VetNumerosEscolhidos[3],VetNumerosEscolhidos[4],VetNumerosEscolhidos[5],VetNumerosEscolhidos[6],VetNumerosEscolhidos[7],VetNumerosEscolhidos[8],VetNumerosEscolhidos[9]);
    printf("\n|                                                                     |");
    printf("\n| 1) Comprar Números                                                  |");
    printf("\n| 2) Apostar                                                          |");
    printf("\n|                                                                     |");
    printf("\n| Aperte a respectiva tecla do numero no teclado. Ou ESC para sair.   |");
    printf("\n| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - |");
    printf("\nComandos >>> ");
}

int main () {
    //CONFIGURAÇÕES:
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));

    //LAÇO PRINCIPAL  DO PROGRAMA:
    while (1) {
        //Menu bonito.
        //system(CLEAR_SCREEN);
        Menu();

        // Sistema de comando.
        c = getc(stdin);
        printf("\n%d",c);
        //Oh 10 que aparece é um caracter de controle, possivelmente ele está a aparecer por conta da quebra de linha.
        switch (c) {
            case 49:
            printf("\nTeste compra");
                //... A programar
            break;
            case 50:
            printf("\nTeste aposta");
                //... A programar
            break;
        }
        if (c == 27) {
            printf("Saiu!!!");
            break;
        }

        //REDEFINIÇÔES
        c = 48;
        printf("\n\n");
    }
    
    return 0;
}