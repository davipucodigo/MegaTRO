#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

#define CLEAR_SCREEN "clear"


//SORTEIO 6 numeros compreendidos entre 1 a 60
#define NUMERO_MAX_SORTEADO 60

//NUMEROS DO USUARIO
#define MAX_NUMEROS_APOSTA 10
#define MIN_NUMEROS_APOSTA 6

//NUMERO MAXIMO DE VALORES GERADOS PARA MEGA TRO, NUMEROS TRO
#define QUANTIA_NUMEROS_ALEATORIOS 6

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
int VetNumerosAposta[QUANTIA_NUMEROS_ALEATORIOS] = {0,0,0,0,0,0}; // Vetor que guardará os valores gerados pela aposta.
int VetNumerosUsuario[MAX_NUMEROS_APOSTA] = {0,0,0,0,0,0,0,0,0,0}; // Vetor que guardará os valores escolhidos pelo apostador.
int ControleNumeroGravados = 0; // Variavel que controla o numero de valores de aposta guardados em VetNumerosAposta.
char Resultado[50] = "Resultado em aguardo";
char msg[500] = " ";
int confirmaAposta = 0;
int conta_acerto = 0;

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
    printf("\n| NÚMEROS DO USUÁRIO: | %d | %d | %d | %d | %d | %d | %d | %d | %d | %d | ", VetNumerosUsuario[0], VetNumerosUsuario[1], VetNumerosUsuario[2], VetNumerosUsuario[3], VetNumerosUsuario[4], VetNumerosUsuario[5], VetNumerosUsuario[6], VetNumerosUsuario[7], VetNumerosUsuario[8], VetNumerosUsuario[9]);
    printf("\n| NÚMEROS DA TRÔ: | %d | %d | %d | %d | %d | %d | *%s ", VetNumerosAposta[0],VetNumerosAposta[1],VetNumerosAposta[2],VetNumerosAposta[3],VetNumerosAposta[4],VetNumerosAposta[5], Resultado);
    printf("\n| NÚMEROS DE ACERTOS: %d                                               ", conta_acerto);
    printf("\n|                                                                     |");
    printf("\n| 1) Comprar Números                                                  |");
    printf("\n| 2) Apostar                                                          |");
    printf("\n|                                                                     |");
    printf("\n| Aperte a respectiva tecla do numero no teclado. Ou ESC para sair.   |");
    printf("\n| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - |");
    printf("\n %s", msg);
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

void EscolhaSeusNumeros() {
    if (ControleNumeroGravados > 5 && ControleNumeroGravados < 11) {
        for (int x = 0; x < ControleNumeroGravados; x++) {
            printf("\n%d° Número: ",1+x);
            scanf("%d", &VetNumerosUsuario[x]);
            fflush(stdin);
            int iguais = 1;
            while (iguais) {
                    for (int z = 0; z < ControleNumeroGravados; z++) {
                        if (VetNumerosUsuario[x] > NUMERO_MAX_SORTEADO || VetNumerosUsuario[x] <= 0) {
                            iguais = 1;
                            printf("\n%d° Número entre 1 e 60 por favor, digite outro: ", 1+x);
                            scanf("%d", &VetNumerosUsuario[x]);
                            fflush(stdin);
                        }
                        if (VetNumerosUsuario[x] == VetNumerosUsuario[z] && x != z) {
                            iguais = 1;
                            printf("\n%d° Número Reperido digite outro: ", 1+x);
                            scanf("%d", &VetNumerosUsuario[x]);
                            fflush(stdin);
                            break;
                        }
                        else {
                            iguais = 0;
                        }
                    }
                }
            }
        }
    }

void GerandoNumerosAposta() {
    for (int x = 0; x < QUANTIA_NUMEROS_ALEATORIOS; x++) VetNumerosAposta[x] = 1+(rand()%NUMERO_MAX_SORTEADO);
    int iguais = 1;
    while (iguais) {
        for (int x = 0; x < QUANTIA_NUMEROS_ALEATORIOS; x++) {
            for (int z = 0; z < QUANTIA_NUMEROS_ALEATORIOS; z++) {
                if (VetNumerosAposta[x] == VetNumerosAposta[z] && x != z) {
                    iguais = 1;
                    VetNumerosAposta[x] = 1+(rand()%NUMERO_MAX_SORTEADO);
                    break;
                }else {
                    iguais = 0;
                }
            }
        }
        if (iguais == 0) {
            break;
        }
    }
}

void PREMIOS_TRO() {
    conta_acerto = 0;
    for (int x = 0; x < QUANTIA_NUMEROS_ALEATORIOS; x++) {
        for (int z = 0; z < MAX_NUMEROS_APOSTA; z++) {
            if (VetNumerosAposta[x] == VetNumerosUsuario[z]) {
                conta_acerto++;
            }
        }
    }  
    switch (conta_acerto) {
        case QUADRA:
            strcpy(Resultado, "QUADRA TRÔ!");
            CREDITO_USUARIO+=PAGA_QUADRA;
        break;
        case QUINA:
            strcpy(Resultado,"QUINA TRÔ!!!");
            CREDITO_USUARIO+=PAGA_QUINA;
        break;
        case MEGATRO:
            strcpy(Resultado,"MEGATRÔÔÔ!!!!!!!!");
            CREDITO_USUARIO+=PAGA_MEGATRO;
        break;
        default:
            strcpy(Resultado,"Não foi dessa vez :( ");
        break;
    }   
}

int main () {
    //CONFIGURAÇÕES:
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));

    
    char c = 48;
    //LAÇO PRINCIPAL  DO PROGRAMA:
    while (1) {
        //Menu bonito.
        Menu();
        // Sistema de comando.
        c = getc(stdin);
        //printf("Tecla da Tabela ASCII: %d",c);
        //Oh 10 que aparece é um caracter de controle, possivelmente ele está a aparecer por conta da quebra de linha.
    
        switch (c) {
            case 49:
                c = 48;
                confirmaAposta = 1;
                strcpy(msg," ");
                for (int x = 0; x < MAX_NUMEROS_APOSTA; x++) VetNumerosUsuario[x] = 0; // Zera tudo.
                EscolhendoNumeros();
                EscolhaSeusNumeros();
                strcpy(Resultado,"Resultado em aguardo");
            break;
            case 50:
                c = 48;
                if (confirmaAposta == 1) {   
                    GerandoNumerosAposta();
                    PREMIOS_TRO();
                    confirmaAposta = 0;
                }
                if (confirmaAposta == 0) strcpy(msg,"Compre mais numeros. Caso não esteja apostando é por que você não comprou numeros ou já os apostou.");
            break;
            case 10:
                system(CLEAR_SCREEN);
            break;
        }
        
        if (c == 27) {
            printf("\nSaiu!!!\n");
            break;
        }
        printf("\n\n");
    }
    
    return 0;
}