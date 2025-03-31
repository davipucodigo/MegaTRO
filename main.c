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
int VetNumerosApostados[10] = {0,0,0,0,0,0,0,0,0,0}; // Vetor que guardará os valores apostados.
int ControleNumeroGravados = 0; // Variavel que controla o numero de valores de aposta guardados em VetNumerosApostados.
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
    printf("\n| CRÉDITO USUÁRIO: $%d                                                   ", CREDITO_USUARIO);
    printf("\n| QUANTIA DE NUMEROS APOSTADOS: %d                                       ", ControleNumeroGravados);
    printf("\n| NÚMEROS APOSTADOS: | %d | %d | %d | %d | %d | %d | %d | %d | %d | %d | ", VetNumerosApostados[0],VetNumerosApostados[1],VetNumerosApostados[2],VetNumerosApostados[3],VetNumerosApostados[4],VetNumerosApostados[5],VetNumerosApostados[6],VetNumerosApostados[7],VetNumerosApostados[8],VetNumerosApostados[9]);
    printf("\n|                                                                     |");
    printf("\n| 1) Comprar Números                                                  |");
    printf("\n| 2) Apostar                                                          |");
    printf("\n|                                                                     |");
    printf("\n| Aperte a respectiva tecla do numero no teclado. Ou ESC para sair.   |");
    printf("\n| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - |");
    printf("\nComandos >>> ");
}

void EscolhendoNumeros () {
    while(1) {
        printf("\n| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - |");
        printf("\n| Quantos Numeros deseja apostar?                                      ");
        printf("\n| 6 N° - custo $%d                                                     ", SEIS_NUM_CUSTO);
        printf("\n| 7 N° - custo $%d                                                     ", SETE_NUM_CUSTO);
        printf("\n| 8 N° - custo $%d                                                     ", OITO_NUM_CUSTO);
        printf("\n| 9 N° - custo $%d                                                     ", NOVE_NUM_CUSTO);
        printf("\n| 10 N° - custo $%d                                                    ", DEZ_NUM_CUSTO);
        printf("\n| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - |");
        printf("\nDigite a respectiva quantia que desejará apostar >> ");
        scanf("%d",&ControleNumeroGravados);
        fflush(stdin);
        //Verifica quantia de numeros apostados
        if (ControleNumeroGravados > 5 && ControleNumeroGravados < 11) {
            //Verificar credito
            switch (ControleNumeroGravados) {
                case 6:
                    if (CREDITO_USUARIO >= SEIS_NUM_CUSTO) CREDITO_USUARIO = CREDITO_USUARIO - SEIS_NUM_CUSTO;
                    else printf("\n$%d de credito quantia insuficiente!",CREDITO_USUARIO);
                break;
                case 7: 
                    if (CREDITO_USUARIO >= SETE_NUM_CUSTO) CREDITO_USUARIO = CREDITO_USUARIO - SETE_NUM_CUSTO;
                    else printf("\n$%d de credito quantia insuficiente!",CREDITO_USUARIO);   
                break;
                case 8: 
                    if (CREDITO_USUARIO >= OITO_NUM_CUSTO) CREDITO_USUARIO = CREDITO_USUARIO - OITO_NUM_CUSTO;
                    else printf("\n$%d de credito quantia insuficiente!",CREDITO_USUARIO);
                break;
                case 9: 
                    if (CREDITO_USUARIO >= NOVE_NUM_CUSTO) CREDITO_USUARIO = CREDITO_USUARIO - NOVE_NUM_CUSTO;
                    else printf("\n$%d de credito quantia insuficiente!",CREDITO_USUARIO);
                break;
                case 10: 
                    if (CREDITO_USUARIO >= DEZ_NUM_CUSTO) CREDITO_USUARIO = CREDITO_USUARIO - DEZ_NUM_CUSTO;
                    else printf("\n$%d de credito quantia insuficiente!",CREDITO_USUARIO);
                break;
            }
            break;//Fecha laço.
        }else {
            printf("\nNÚMERO DE APOSTAS INVALIDO!\n");
        }
    }
}

void GerandoNumerosApostados() {
    //... programar
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
        printf("Tecla da Tabela ASCII: %d",c);
        //Oh 10 que aparece é um caracter de controle, possivelmente ele está a aparecer por conta da quebra de linha.
        switch (c) {
            case 49:
                EscolhendoNumeros();
            break;
            case 50:
            printf("\nTeste aposta");
                //... programar
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