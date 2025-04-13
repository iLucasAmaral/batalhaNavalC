// Código desenvolvido por: Lucas Amaral
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define vazio 0
#define afundado 1
#define barco 2
#define navio 3
#define portaViao 4
#define user 5
#define PC 6
#define nadaEncontrado 7

// Inicia as variaveis globais do jogo.
int matrizUser[5][5];        // Matriz do usuario
int matrizPC[5][5];          // Matriz do Pc (exibição para o usuario)
int matrizInt[5][5];         // Matriz onde o Pc guarda as peças jogadas no inicio do jogo
int posicaoX;                // Serve para converter uma escolha em uma posicao no eixo x
int posicaoY;                // Serve para converter uma escolha em uma posicao no eixo y
int proximaJogada;           // Quem irá jogar na próxima jogada (Pc ou Usuario)
int totalPecasUser;          // Total de peças do usuario posicionadas no inicio do jogo
int totalpecasPC;            // Total de peças do PC posicionadas no inicio do jogo
int totalTabuleiroUser = 9;  // Variavel para controle do vencedor (se 0 PC venceu)
int totalTabuleiroPC = 9;    // Variavel para controle do vencedor (se 0 Usuario venceu)
int vencedor;                // Guarda quem venceu para exibir a mensagem de vencedor.

// Define os parametros inicais do jogo, configura o terminal e linguagem.
void systemSet() {
    system("title Batalha Naval - Por: Lucas Amaral");  // Define o titulo da Janela
    setlocale(LC_ALL, "Portuguese_Brasil");                         // Define a linguagem para português
    system("chcp 65001");                                           // Define o terminal para UTF-8
    system("cls");                                                  // Limpa o terminal

    for (int i = 0; i < 4; i++) {  // Inicia o jogo com todas as matrizes zeradas
        for (int j = 0; j < 4; j++) {
            matrizUser[i][j] = 0;
            matrizPC[i][j] = 0;
            matrizInt[i][j] = 0;
        }
    }
}
// Exibe uma mensagem de bem-vindo para o usuario
void bemVindo() {
    printf("\n           ***************************************");
    printf("\n           *  \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694    *");
    printf("\n           *  \U00002694 \U00002694 \U00002694 \U00002694  BATALHA  NAVAL \U00002694 \U00002694 \U00002694 \U00002694    *");
    printf("\n           *  \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694    *");
    printf("\n           ***************************************");
    printf("\n\n       \U0001F525 Seja bem-vindo ao jogo de batalha naval! \U0001F525\n\n");
    system("pause");
    system("cls");
    printf("\n           ***************************************");
    printf("\n           *  \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694    *");
    printf("\n           *  \U00002694 \U00002694 \U00002694 \U00002694  BATALHA  NAVAL \U00002694 \U00002694 \U00002694 \U00002694    *");
    printf("\n           *  \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694    *");
    printf("\n           ***************************************");
    printf("\n\n                \U0001F601 Espero que se divirta! \U0001F601\n\n");
    system("pause");
    system("cls");
    printf("\n           ***************************************");
    printf("\n           *  \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694    *");
    printf("\n           *  \U00002694 \U00002694 \U00002694 \U00002694  BATALHA  NAVAL \U00002694 \U00002694 \U00002694 \U00002694    *");
    printf("\n           *  \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694 \U00002694    *");
    printf("\n           ***************************************");
    printf("\n\n               E que não encontre nenhum bug \U0001F605\n\n");
    system("pause");
}
// Exibe o tabuleiro do jogo quando está em "batalha"
void exibirJogo() {
    system("cls");
    printf("                      \033[1;32mVOCÊ                                                            \033[1;31mOPONENTE\033[0m           \n");
    printf("           **************************                                        **************************     \n");
    printf("           * %s * %s * %s * %s * %s *                 LEGENDA                * %s * %s * %s * %s * %s *     \n", converter(matrizUser[0][0]), converter(matrizUser[0][1]), converter(matrizUser[0][2]), converter(matrizUser[0][3]), converter(matrizUser[0][4]), converter(matrizPC[0][0]), converter(matrizPC[0][1]), converter(matrizPC[0][2]), converter(matrizPC[0][3]), converter(matrizPC[0][4]));
    printf("           **************************      ****************************      **************************     \n");
    printf("           * %s * %s * %s * %s * %s *      * \U000026F5 = Barco               *      * %s * %s * %s * %s * %s *     \n", converter(matrizUser[1][0]), converter(matrizUser[1][1]), converter(matrizUser[1][2]), converter(matrizUser[1][3]), converter(matrizUser[1][4]), converter(matrizPC[1][0]), converter(matrizPC[1][1]), converter(matrizPC[1][2]), converter(matrizPC[1][3]), converter(matrizPC[1][4]));
    printf("           **************************      * \U0001F6A2 = Navio               *      **************************     \n");
    printf("           * %s * %s * %s * %s * %s *      * \U0001F6EB = Porta Aviões        *      * %s * %s * %s * %s * %s *     \n", converter(matrizUser[2][0]), converter(matrizUser[2][1]), converter(matrizUser[2][2]), converter(matrizUser[2][3]), converter(matrizUser[2][4]), converter(matrizPC[2][0]), converter(matrizPC[2][1]), converter(matrizPC[2][2]), converter(matrizPC[2][3]), converter(matrizPC[2][4]));
    printf("           **************************      * \U0000274C = Nada Encontrado     *      **************************     \n");
    printf("           * %s * %s * %s * %s * %s *      * \U0001F4A6 = Embarcação Afundada *      * %s * %s * %s * %s * %s *     \n", converter(matrizUser[3][0]), converter(matrizUser[3][1]), converter(matrizUser[3][2]), converter(matrizUser[3][3]), converter(matrizUser[3][4]), converter(matrizPC[3][0]), converter(matrizPC[3][1]), converter(matrizPC[3][2]), converter(matrizPC[3][3]), converter(matrizPC[3][4]));
    printf("           **************************      ****************************      **************************     \n");
    printf("           * %s * %s * %s * %s * %s *                                        * %s * %s * %s * %s * %s *     \n", converter(matrizUser[4][0]), converter(matrizUser[4][1]), converter(matrizUser[4][2]), converter(matrizUser[4][3]), converter(matrizUser[4][4]), converter(matrizPC[4][0]), converter(matrizPC[4][1]), converter(matrizPC[4][2]), converter(matrizPC[4][3]), converter(matrizPC[4][4]));
    printf("           **************************                                        **************************     \n");
}
// Exibe a mensagem de fim de jogo/vencedor e mostra o tabuleiro de jogo
void exibirFimDeJogo() {
    system("cls");
    printf("                     *************************************************************************\n");
    printf("                     * \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6  *\n");
    printf("                     * \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6                                  \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6  *\n");
    printf("                     * \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6             FIM DE JOGO          \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6  *\n");
    printf("                     * \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6                                  \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6  *\n");
    printf("                     * \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6 \U0001F3C6  *\n");
    printf("                     *************************************************************************\n\n");
    printf("                      \033[1;32mVOCÊ                                                            \033[1;31mOPONENTE\033[0m           \n");
    printf("           **************************                                        **************************     \n");
    printf("           * %s * %s * %s * %s * %s *                 LEGENDA                * %s * %s * %s * %s * %s *     \n", converter(matrizUser[0][0]), converter(matrizUser[0][1]), converter(matrizUser[0][2]), converter(matrizUser[0][3]), converter(matrizUser[0][4]), converter(matrizPC[0][0]), converter(matrizPC[0][1]), converter(matrizPC[0][2]), converter(matrizPC[0][3]), converter(matrizPC[0][4]));
    printf("           **************************      ****************************      **************************     \n");
    printf("           * %s * %s * %s * %s * %s *      * \U000026F5 = Barco               *      * %s * %s * %s * %s * %s *     \n", converter(matrizUser[1][0]), converter(matrizUser[1][1]), converter(matrizUser[1][2]), converter(matrizUser[1][3]), converter(matrizUser[1][4]), converter(matrizPC[1][0]), converter(matrizPC[1][1]), converter(matrizPC[1][2]), converter(matrizPC[1][3]), converter(matrizPC[1][4]));
    printf("           **************************      * \U0001F6A2 = Navio               *      **************************     \n");
    printf("           * %s * %s * %s * %s * %s *      * \U0001F6EB = Porta Aviões        *      * %s * %s * %s * %s * %s *     \n", converter(matrizUser[2][0]), converter(matrizUser[2][1]), converter(matrizUser[2][2]), converter(matrizUser[2][3]), converter(matrizUser[2][4]), converter(matrizPC[2][0]), converter(matrizPC[2][1]), converter(matrizPC[2][2]), converter(matrizPC[2][3]), converter(matrizPC[2][4]));
    printf("           **************************      * \U0000274C = Nada Encontrado     *      **************************     \n");
    printf("           * %s * %s * %s * %s * %s *      * \U0001F4A6 = Embarcação Afundada *      * %s * %s * %s * %s * %s *     \n", converter(matrizUser[3][0]), converter(matrizUser[3][1]), converter(matrizUser[3][2]), converter(matrizUser[3][3]), converter(matrizUser[3][4]), converter(matrizPC[3][0]), converter(matrizPC[3][1]), converter(matrizPC[3][2]), converter(matrizPC[3][3]), converter(matrizPC[3][4]));
    printf("           **************************      ****************************      **************************     \n");
    printf("           * %s * %s * %s * %s * %s *                                        * %s * %s * %s * %s * %s *     \n", converter(matrizUser[4][0]), converter(matrizUser[4][1]), converter(matrizUser[4][2]), converter(matrizUser[4][3]), converter(matrizUser[4][4]), converter(matrizPC[4][0]), converter(matrizPC[4][1]), converter(matrizPC[4][2]), converter(matrizPC[4][3]), converter(matrizPC[4][4]));
    printf("           **************************                                        **************************     \n");
    system("pause");
    system("cls");
    if (vencedor == user) {  // Mensagem de vitoria para o usuario
        printf("                     *************************************************************************\n");
        printf("                     * \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947  *\n");
        printf("                     * \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947                                  \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947  *\n");
        printf("                     * \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947             \033[1;32mVOCÊ VENCEU!\033[0m         \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947  *\n");
        printf("                     * \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947                                  \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947  *\n");
        printf("                     * \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947  *\n");
        printf("                     *************************************************************************\n\n");
        printf("                      \033[1;32mVOCÊ                                                            \033[1;31mOPONENTE\033[0m           \n");
        printf("           **************************                                        **************************     \n");
        printf("           * %s * %s * %s * %s * %s *                 LEGENDA                * %s * %s * %s * %s * %s *     \n", converter(matrizUser[0][0]), converter(matrizUser[0][1]), converter(matrizUser[0][2]), converter(matrizUser[0][3]), converter(matrizUser[0][4]), converter(matrizPC[0][0]), converter(matrizPC[0][1]), converter(matrizPC[0][2]), converter(matrizPC[0][3]), converter(matrizPC[0][4]));
        printf("           **************************      ****************************      **************************     \n");
        printf("           * %s * %s * %s * %s * %s *      * \U000026F5 = Barco               *      * %s * %s * %s * %s * %s *     \n", converter(matrizUser[1][0]), converter(matrizUser[1][1]), converter(matrizUser[1][2]), converter(matrizUser[1][3]), converter(matrizUser[1][4]), converter(matrizPC[1][0]), converter(matrizPC[1][1]), converter(matrizPC[1][2]), converter(matrizPC[1][3]), converter(matrizPC[1][4]));
        printf("           **************************      * \U0001F6A2 = Navio               *      **************************     \n");
        printf("           * %s * %s * %s * %s * %s *      * \U0001F6EB = Porta Aviões        *      * %s * %s * %s * %s * %s *     \n", converter(matrizUser[2][0]), converter(matrizUser[2][1]), converter(matrizUser[2][2]), converter(matrizUser[2][3]), converter(matrizUser[2][4]), converter(matrizPC[2][0]), converter(matrizPC[2][1]), converter(matrizPC[2][2]), converter(matrizPC[2][3]), converter(matrizPC[2][4]));
        printf("           **************************      * \U0000274C = Nada Encontrado     *      **************************     \n");
        printf("           * %s * %s * %s * %s * %s *      * \U0001F4A6 = Embarcação Afundada *      * %s * %s * %s * %s * %s *     \n", converter(matrizUser[3][0]), converter(matrizUser[3][1]), converter(matrizUser[3][2]), converter(matrizUser[3][3]), converter(matrizUser[3][4]), converter(matrizPC[3][0]), converter(matrizPC[3][1]), converter(matrizPC[3][2]), converter(matrizPC[3][3]), converter(matrizPC[3][4]));
        printf("           **************************      ****************************      **************************     \n");
        printf("           * %s * %s * %s * %s * %s *                                        * %s * %s * %s * %s * %s *     \n", converter(matrizUser[4][0]), converter(matrizUser[4][1]), converter(matrizUser[4][2]), converter(matrizUser[4][3]), converter(matrizUser[4][4]), converter(matrizPC[4][0]), converter(matrizPC[4][1]), converter(matrizPC[4][2]), converter(matrizPC[4][3]), converter(matrizPC[4][4]));
        printf("           **************************                                        **************************     \n");
        system("pause");
    } else if (vencedor == PC) {  // Mensagem de vitoria para o computador
        printf("                     *************************************************************************\n");
        printf("                     * \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947  *\n");
        printf("                     * \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947                                  \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947  *\n");
        printf("                     * \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947             \033[1;31mO PC VENCEU!\033[0m         \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947  *\n");
        printf("                     * \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947                                  \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947  *\n");
        printf("                     * \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947 \U0001F947  *\n");
        printf("                     *************************************************************************\n\n");
        printf("                      \033[1;32mVOCÊ                                                            \033[1;31mOPONENTE\033[0m           \n");
        printf("           **************************                                        **************************     \n");
        printf("           * %s * %s * %s * %s * %s *                 LEGENDA                * %s * %s * %s * %s * %s *     \n", converter(matrizUser[0][0]), converter(matrizUser[0][1]), converter(matrizUser[0][2]), converter(matrizUser[0][3]), converter(matrizUser[0][4]), converter(matrizPC[0][0]), converter(matrizPC[0][1]), converter(matrizPC[0][2]), converter(matrizPC[0][3]), converter(matrizPC[0][4]));
        printf("           **************************      ****************************      **************************     \n");
        printf("           * %s * %s * %s * %s * %s *      * \U000026F5 = Barco               *      * %s * %s * %s * %s * %s *     \n", converter(matrizUser[1][0]), converter(matrizUser[1][1]), converter(matrizUser[1][2]), converter(matrizUser[1][3]), converter(matrizUser[1][4]), converter(matrizPC[1][0]), converter(matrizPC[1][1]), converter(matrizPC[1][2]), converter(matrizPC[1][3]), converter(matrizPC[1][4]));
        printf("           **************************      * \U0001F6A2 = Navio               *      **************************     \n");
        printf("           * %s * %s * %s * %s * %s *      * \U0001F6EB = Porta Aviões        *      * %s * %s * %s * %s * %s *     \n", converter(matrizUser[2][0]), converter(matrizUser[2][1]), converter(matrizUser[2][2]), converter(matrizUser[2][3]), converter(matrizUser[2][4]), converter(matrizPC[2][0]), converter(matrizPC[2][1]), converter(matrizPC[2][2]), converter(matrizPC[2][3]), converter(matrizPC[2][4]));
        printf("           **************************      * \U0000274C = Nada Encontrado     *      **************************     \n");
        printf("           * %s * %s * %s * %s * %s *      * \U0001F4A6 = Embarcação Afundada *      * %s * %s * %s * %s * %s *     \n", converter(matrizUser[3][0]), converter(matrizUser[3][1]), converter(matrizUser[3][2]), converter(matrizUser[3][3]), converter(matrizUser[3][4]), converter(matrizPC[3][0]), converter(matrizPC[3][1]), converter(matrizPC[3][2]), converter(matrizPC[3][3]), converter(matrizPC[3][4]));
        printf("           **************************      ****************************      **************************     \n");
        printf("           * %s * %s * %s * %s * %s *                                        * %s * %s * %s * %s * %s *     \n", converter(matrizUser[4][0]), converter(matrizUser[4][1]), converter(matrizUser[4][2]), converter(matrizUser[4][3]), converter(matrizUser[4][4]), converter(matrizPC[4][0]), converter(matrizPC[4][1]), converter(matrizPC[4][2]), converter(matrizPC[4][3]), converter(matrizPC[4][4]));
        printf("           **************************                                        **************************     \n");
        system("pause");
    }
}
int converter(int numero) {  // Converte as matrizes númericas e retorna em emojis para exibição no jogo
    char *representacaoPeca;
    switch (numero) {
        case vazio:
            representacaoPeca = "  ";
            break;
        case afundado:
            representacaoPeca = "\U0001F4A6";
            break;
        case barco:
            representacaoPeca = "\U000026F5";
            break;
        case navio:
            representacaoPeca = "\U0001F6A2";
            break;
        case portaViao:
            representacaoPeca = "\U0001F6EB";
            break;
        case nadaEncontrado:
            representacaoPeca = "\U0000274C";
            break;
    }

    return representacaoPeca;
}
void exibeMapaJogadas() {  // Exibe para o usuario, o tabuleiro dele mesmo para que ele possa posicionar suas peças
    system("cls");
    printf("                      \033[1;32mVOCÊ \033[0m           \n");
    printf("           **************************\n");
    printf("           * %s * %s * %s * %s * %s *\n", converter(matrizUser[0][0]), converter(matrizUser[0][1]), converter(matrizUser[0][2]), converter(matrizUser[0][3]), converter(matrizUser[0][4]));
    printf("           **************************\n");
    printf("           * %s * %s * %s * %s * %s *\n", converter(matrizUser[1][0]), converter(matrizUser[1][1]), converter(matrizUser[1][2]), converter(matrizUser[1][3]), converter(matrizUser[1][4]));
    printf("           **************************\n");
    printf("           * %s * %s * %s * %s * %s *\n", converter(matrizUser[2][0]), converter(matrizUser[2][1]), converter(matrizUser[2][2]), converter(matrizUser[2][3]), converter(matrizUser[2][4]));
    printf("           **************************\n");
    printf("           * %s * %s * %s * %s * %s *\n", converter(matrizUser[3][0]), converter(matrizUser[3][1]), converter(matrizUser[3][2]), converter(matrizUser[3][3]), converter(matrizUser[3][4]));
    printf("           **************************\n");
    printf("           * %s * %s * %s * %s * %s *\n", converter(matrizUser[4][0]), converter(matrizUser[4][1]), converter(matrizUser[4][2]), converter(matrizUser[4][3]), converter(matrizUser[4][4]));
    printf("           **************************\n\n");
}
int posicaoAletoria() {  // Gera um número aleatorio entre 0 e 25 que é utilizado tanto para o computador posicionar peças quanto fazer jogadas.
    return rand() % 25;
}
int direcaoAleatoria() {  // Gera um número aleatorio entre 1(horizontal) e 2(vertical) que é utilizado para o computador definir uma direção aletoria no momento de posicionar peças
    return (rand() % 2) + 1;
}
void exibeMapaDePosicoesJogo() {  // Exibe para o usuario o mapa utilizado para escolher uma posição de jogo no tabuleiro
    printf("                                               *********************\n");
    printf("                                               * a * b * c * d * e *\n");
    printf("                                               *********************\n");
    printf("                                               * f * g * h * i * j *\n");
    printf("                                               *********************\n");
    printf("                                               * k * l * m * n * o *\n");
    printf("                                               *********************\n");
    printf("                                               * p * q * r * s * t *\n");
    printf("                                               *********************\n");
    printf("                                               * u * v * w * x * y *\n");
    printf("                                               *********************\n");
}
void exibeMapaDePosicoesIniciais() {  // Exibe para o usuario o mapa utilizado para escolher onde as peças irão ficar no tabuleiro
    char *ExibeTipoPeca;
    printf("\nPara iniciar o jogo, escolha onde você deseja posicionar suas peças, conforme a legenda abaixo:\n");
    switch (totalPecasUser) {
        case 0:
            ExibeTipoPeca = "\U000026F5 - Barco 1 (Ocupa 1 posição)";
            break;
        case 1:
            ExibeTipoPeca = "\U000026F5 - Barco 2 (Ocupa 1 posição)";
            break;
        case 2:
            ExibeTipoPeca = "\U0001F6A2 - Navio 1 (Ocupa 2 posições)";
            break;
        case 3:
            ExibeTipoPeca = "\U0001F6A2 - Navio 2 (Ocupa 2 posições)";
            break;
        case 4:
            ExibeTipoPeca = "\U0001F6EB - Porta Aviões (Ocupa 3 posições)";
            break;
    }
    printf("Escolha a orientação e posição da peça: %s\n", ExibeTipoPeca);
    printf("           *********************\n");
    printf("           * a * b * c * d * e *\n");
    printf("           *********************\n");
    printf("           * f * g * h * i * j *\n");
    printf("           *********************\n");
    printf("           * k * l * m * n * o *\n");
    printf("           *********************\n");
    printf("           * p * q * r * s * t *\n");
    printf("           *********************\n");
    printf("           * u * v * w * x * y *\n");
    printf("           *********************\n");
}
void inicioDeJogo() {              // Faz o posicionamento das peças do usuario e do computador
    int direcaoPeca;               // Guarda qual direção foi escolhida
    int direcaoNavio1;             // Guarda o valor da direção do navio 1 (usuario e PC, um de cada vez)
    int direcaoNavio2;             // Guarda o valor da direção do navio 2 (usuario e PC, um de cada vez)
    int direcaoPortaViao;          // Guarda o valor da direção do Porta Aviões (usuario e PC, um de cada vez)
    while (totalPecasUser <= 4) {  // Enquanto o usuario não tiver 5 peças posicionadas, solicita o posicionamento
        int escolhaValida = 0;     // Controle de escolhas corretas, deixando o código seguir
        system("cls");
        exibeMapaJogadas();
        exibeMapaDePosicoesIniciais();
        if (totalPecasUser <= 1) {    // Se o usuario estiver jogando os barcos (total de peças é menor ou igual a 1), não é necessario solicitar uma direção
            while (!escolhaValida) {  // Solicita a escolha da posição desejada para a peça sendo posicionada.
                char escolha;
                printf("Escolha a posicao da sua jogada: ");
                scanf("%c", &escolha);
                getchar();
                switch (escolha) {  // Converte a posição escolhida para as coordenadas de eixo x e y
                    case 'a':
                        posicaoX = 0;
                        posicaoY = 0;
                        escolhaValida = 1;
                        break;
                    case 'b':
                        posicaoX = 0;
                        posicaoY = 1;
                        escolhaValida = 1;
                        break;
                    case 'c':
                        posicaoX = 0;
                        posicaoY = 2;
                        escolhaValida = 1;
                        break;
                    case 'd':
                        posicaoX = 0;
                        posicaoY = 3;
                        escolhaValida = 1;
                        break;
                    case 'e':
                        posicaoX = 0;
                        posicaoY = 4;
                        escolhaValida = 1;
                        break;
                    case 'f':
                        posicaoX = 1;
                        posicaoY = 0;
                        escolhaValida = 1;
                        break;
                    case 'g':
                        posicaoX = 1;
                        posicaoY = 1;
                        escolhaValida = 1;
                        break;
                    case 'h':
                        posicaoX = 1;
                        posicaoY = 2;
                        escolhaValida = 1;
                        break;
                    case 'i':
                        posicaoX = 1;
                        posicaoY = 3;
                        escolhaValida = 1;
                        break;
                    case 'j':
                        escolhaValida = 1;
                        posicaoX = 1;
                        posicaoY = 4;
                        break;
                    case 'k':
                        posicaoX = 2;
                        posicaoY = 0;
                        escolhaValida = 1;
                        break;
                    case 'l':
                        posicaoX = 2;
                        posicaoY = 1;
                        escolhaValida = 1;
                        break;
                    case 'm':
                        posicaoX = 2;
                        posicaoY = 2;
                        escolhaValida = 1;
                        break;
                    case 'n':
                        posicaoX = 2;
                        posicaoY = 3;
                        escolhaValida = 1;
                        break;
                    case 'o':
                        posicaoX = 2;
                        posicaoY = 4;
                        escolhaValida = 1;
                        break;
                    case 'p':
                        posicaoX = 3;
                        posicaoY = 0;
                        escolhaValida = 1;
                        break;
                    case 'q':
                        posicaoX = 3;
                        posicaoY = 1;
                        escolhaValida = 1;
                        break;
                    case 'r':
                        posicaoX = 3;
                        posicaoY = 2;
                        escolhaValida = 1;
                        break;
                    case 's':
                        posicaoX = 3;
                        posicaoY = 3;
                        escolhaValida = 1;
                        break;
                    case 't':
                        posicaoX = 3;
                        posicaoY = 4;
                        escolhaValida = 1;
                        break;
                    case 'u':
                        posicaoX = 4;
                        posicaoY = 0;
                        escolhaValida = 1;
                        break;
                    case 'v':
                        posicaoX = 4;
                        posicaoY = 1;
                        escolhaValida = 1;
                        break;
                    case 'w':
                        posicaoX = 4;
                        posicaoY = 2;
                        escolhaValida = 1;
                        break;
                    case 'x':
                        posicaoX = 4;
                        posicaoY = 3;
                        escolhaValida = 1;
                        break;
                    case 'y':
                        posicaoX = 4;
                        posicaoY = 4;
                        escolhaValida = 1;
                        break;
                    default:  // Trata entradas invalidas do usuario
                        printf("\n\U0000274C Escolha inválida, por favor, insira a posição novamente. \U0000274C\n");
                        system("pause");
                        system("cls");
                        exibeMapaJogadas();
                        exibeMapaDePosicoesIniciais();
                }
            }
            if (matrizUser[posicaoX][posicaoY] == 0) {  // Caso o usuario tenha escolhido uma posição vazia para o barco, a jogada é feita.
                if (totalPecasUser == 0 || totalPecasUser == 1) {
                    matrizUser[posicaoX][posicaoY] = 2;
                    totalPecasUser++;
                }
            } else {  // Caso o usuario tenha escolhido uma posição ocupada, solicita uma nova posição.
                printf("\n\U0000274C A posição já está ocupada, por favor, insira a posição novamente. \U0000274C\n");
                system("pause");
                system("cls");
                exibeMapaJogadas();
                exibeMapaDePosicoesIniciais();
            }
            escolhaValida = 0;
        } else {  // Se o total de peças jogadas é > 1, então a proxima jogada vai precisar da direção.
            escolhaValida = 0;
            while (!escolhaValida) {  // Solicita a direção da peça sendo posicionada para o usuario
                printf("Você deseja jogar sua peça na horizontal ou vertical?\n");
                printf("1 - Horizontal\n2 - Vertical\n");
                printf("Resposta: ");
                scanf("%d", &direcaoPeca);
                getchar();
                switch (direcaoPeca) {
                    case 1:
                        break;
                    case 2:
                        break;
                    default:  // Trata entradas invalidas do usuario
                        printf("\n\U0000274C Escolha inválida, por favor, insira a orientação da peça novamente. \U0000274C\n");
                        system("pause");
                        system("cls");
                        exibeMapaJogadas();
                        exibeMapaDePosicoesIniciais();
                }

                switch (totalPecasUser) {  // Define o valor da direção de cada peça para verificar posteriormente se existe espaço suficiente na posição selecionada
                    case 2:
                        direcaoNavio1 = direcaoPeca;
                        break;
                    case 3:
                        direcaoNavio2 = direcaoPeca;
                        break;
                    case 4:
                        direcaoPortaViao = direcaoPeca;
                        break;
                }

                escolhaValida = 0;  // Limpa a variavel de controle das escolhas validas

                // Solicita a escolha da posição desejada para a peça sendo posicionada.
                char escolha;
                printf("Escolha a posicao da sua jogada: ");
                scanf("%c", &escolha);
                getchar();
                switch (escolha) {  // Converte a posição escolhida para as coordenadas de eixo x e y
                    case 'a':
                        posicaoX = 0;
                        posicaoY = 0;
                        escolhaValida = 1;
                        break;
                    case 'b':
                        posicaoX = 0;
                        posicaoY = 1;
                        escolhaValida = 1;
                        break;
                    case 'c':
                        posicaoX = 0;
                        posicaoY = 2;
                        escolhaValida = 1;
                        break;
                    case 'd':
                        posicaoX = 0;
                        posicaoY = 3;
                        escolhaValida = 1;
                        break;
                    case 'e':
                        posicaoX = 0;
                        posicaoY = 4;
                        escolhaValida = 1;
                        break;
                    case 'f':
                        posicaoX = 1;
                        posicaoY = 0;
                        escolhaValida = 1;
                        break;
                    case 'g':
                        posicaoX = 1;
                        posicaoY = 1;
                        escolhaValida = 1;
                        break;
                    case 'h':
                        posicaoX = 1;
                        posicaoY = 2;
                        escolhaValida = 1;
                        break;
                    case 'i':
                        posicaoX = 1;
                        posicaoY = 3;
                        escolhaValida = 1;
                        break;
                    case 'j':
                        escolhaValida = 1;
                        posicaoX = 1;
                        posicaoY = 4;
                        break;
                    case 'k':
                        posicaoX = 2;
                        posicaoY = 0;
                        escolhaValida = 1;
                        break;
                    case 'l':
                        posicaoX = 2;
                        posicaoY = 1;
                        escolhaValida = 1;
                        break;
                    case 'm':
                        posicaoX = 2;
                        posicaoY = 2;
                        escolhaValida = 1;
                        break;
                    case 'n':
                        posicaoX = 2;
                        posicaoY = 3;
                        escolhaValida = 1;
                        break;
                    case 'o':
                        posicaoX = 2;
                        posicaoY = 4;
                        escolhaValida = 1;
                        break;
                    case 'p':
                        posicaoX = 3;
                        posicaoY = 0;
                        escolhaValida = 1;
                        break;
                    case 'q':
                        posicaoX = 3;
                        posicaoY = 1;
                        escolhaValida = 1;
                        break;
                    case 'r':
                        posicaoX = 3;
                        posicaoY = 2;
                        escolhaValida = 1;
                        break;
                    case 's':
                        posicaoX = 3;
                        posicaoY = 3;
                        escolhaValida = 1;
                        break;
                    case 't':
                        posicaoX = 3;
                        posicaoY = 4;
                        escolhaValida = 1;
                        break;
                    case 'u':
                        posicaoX = 4;
                        posicaoY = 0;
                        escolhaValida = 1;
                        break;
                    case 'v':
                        posicaoX = 4;
                        posicaoY = 1;
                        escolhaValida = 1;
                        break;
                    case 'w':
                        posicaoX = 4;
                        posicaoY = 2;
                        escolhaValida = 1;
                        break;
                    case 'x':
                        posicaoX = 4;
                        posicaoY = 3;
                        escolhaValida = 1;
                        break;
                    case 'y':
                        posicaoX = 4;
                        posicaoY = 4;
                        escolhaValida = 1;
                        break;
                    default:  // Trata entradas invalidas do usuario
                        printf("\n\U0000274C Escolha inválida, por favor, insira a posição novamente. \U0000274C\n");
                        system("pause");
                        system("cls");
                        exibeMapaJogadas();
                        exibeMapaDePosicoesIniciais();
                }
            }

            if (matrizUser[posicaoX][posicaoY] == 0) {                                   // Se a posição escolhida estiver livre, as verificações continuam.
                if (totalPecasUser == 0 || totalPecasUser == 1) {                        // Se as peças sendo selecionadas tem tamanho 1 (barco1 e barco2), não é necessario verificar mais nada.
                    matrizUser[posicaoX][posicaoY] = barco;                              // Faz o posicionamento da peça
                    totalPecasUser++;                                                    // Total de peças posicionadas do usuario é somado em + 1
                } else if (totalPecasUser == 2) {                                        // Se o total de peças for 2, significa que é o Navio1 sendo posicionado
                    if (direcaoNavio1 == 1) {                                            // Se a direção do navio 1 for horizontal, é necessário verificar se a peça vai ter espaço suficiente na posição do lado
                        if (matrizUser[posicaoX][posicaoY + 1] == 0 && posicaoY != 4) {  // Se a posição escolhida + 1 posição pro lado estiver livre, e a posição não é 4 (ultima coluna do tabuleiro), faz a jogada
                            matrizUser[posicaoX][posicaoY] = navio;                      // Faz a jogada na posição escolhida
                            matrizUser[posicaoX][posicaoY + 1] = navio;                  // Faz a jogada na posição do lado
                            totalPecasUser++;                                            // Total de peças posicionadas do usuario é somado em + 1
                        } else {                                                         // Trata posições onde a peça não pode ser posicionada.
                            printf("\n\U0000274C A posição já está ocupada ou é inválida pois está no limite do tabuleiro, por favor, insira a posição novamente. \U0000274C\n");
                            system("pause");
                            system("cls");
                            exibeMapaJogadas();
                            exibeMapaDePosicoesIniciais();
                        }
                    } else if (direcaoNavio1 == 2) {                                     // Se a direção do navio 1 for vertical, é necessário verificar se a peça vai ter espaço suficiente na posição abaixo
                        if (matrizUser[posicaoX + 1][posicaoY] == 0 && posicaoX != 4) {  // Se a posição escolhida + 1 posição para baixo estiver livre, e a posição não é 4 (ultima linha do tabuleiro), faz a jogada
                            matrizUser[posicaoX][posicaoY] = navio;                      // Faz a jogada na posição escolhida
                            matrizUser[posicaoX + 1][posicaoY] = navio;                  // Faz a jogada na posição abaixo
                            totalPecasUser++;                                            // Total de peças posicionadas do usuario é somado em + 1
                        } else {                                                         // Trata posições onde a peça não pode ser posicionada.
                            printf("\n\U0000274C A posição já está ocupada ou é inválida pois está no limite do tabuleiro, por favor, insira a posição novamente. \U0000274C\n");
                            system("pause");
                            system("cls");
                            exibeMapaJogadas();
                            exibeMapaDePosicoesIniciais();
                        }
                    }
                } else if (totalPecasUser == 3) {                                        // Se o total de peças for 3, significa que é o Navio2 sendo posicionado
                    if (direcaoNavio2 == 1) {                                            // Se a direção do navio 2 for horizontal, é necessário verificar se a peça vai ter espaço suficiente na posição do lado
                        if (matrizUser[posicaoX][posicaoY + 1] == 0 && posicaoY != 4) {  // Se a posição escolhida + 1 posição pro lado estiver livre, e a posição não é 4 (ultima coluna do tabuleiro), faz a jogada
                            matrizUser[posicaoX][posicaoY] = navio;                      // Faz a jogada na posição escolhida
                            matrizUser[posicaoX][posicaoY + 1] = navio;                  // Faz a jogada na posição do lado
                            totalPecasUser++;                                            // Total de peças posicionadas do usuario é somado em + 1
                        } else {                                                         // Trata posições onde a peça não pode ser posicionada.
                            printf("\n\U0000274C A posição já está ocupada ou é inválida pois está no limite do tabuleiro, por favor, insira a posição novamente. \U0000274C\n");
                            system("pause");
                            system("cls");
                            exibeMapaJogadas();
                            exibeMapaDePosicoesIniciais();
                        }
                    } else if (direcaoNavio2 == 2) {                                     // Se a direção do navio 2 for vertical, é necessário verificar se a peça vai ter espaço suficiente na posição abaixo
                        if (matrizUser[posicaoX + 1][posicaoY] == 0 && posicaoX != 4) {  // Se a posição escolhida + 1 posição para baixo estiver livre, e a posição não é 4 (ultima linha do tabuleiro), faz a jogada
                            matrizUser[posicaoX][posicaoY] = navio;                      // Faz a jogada na posição escolhida
                            matrizUser[posicaoX + 1][posicaoY] = navio;                  // Faz a jogada na posição abaixo
                            totalPecasUser++;                                            // Total de peças posicionadas do usuario é somado em + 1
                        } else {                                                         // Trata posições onde a peça não pode ser posicionada.
                            printf("\n\U0000274C A posição já está ocupada ou é inválida pois está no limite do tabuleiro, por favor, insira a posição novamente. \U0000274C\n");
                            system("pause");
                            system("cls");
                            exibeMapaJogadas();
                            exibeMapaDePosicoesIniciais();
                        }
                    }
                } else if (totalPecasUser == 4) {                                                                                                    // Se o total de peças for 4, significa que é o Porta Aviões sendo posicionado
                    if (direcaoPortaViao == 1) {                                                                                                     // Se a direção do Porta Aviões for horizontal, é necessário verificar se a peça vai ter espaço suficiente nas posições abaixo
                        if (matrizUser[posicaoX][posicaoY + 1] == 0 && matrizUser[posicaoX][posicaoY + 2] == 0 && posicaoY != 3 && posicaoY != 4) {  // Se as posições pro lado estão livres e a coluna não é a ultima nem penultima do tabuleiro, a jogada é feita
                            matrizUser[posicaoX][posicaoY] = portaViao;                                                                              // Faz a jogada na posição escolhida
                            matrizUser[posicaoX][posicaoY + 1] = portaViao;                                                                          // Faz a jogada na posição do lado
                            matrizUser[posicaoX][posicaoY + 2] = portaViao;                                                                          // Faz a jogada 2 posições para o lado
                            totalPecasUser++;                                                                                                        // Total de peças posicionadas do usuario é somado em + 1
                        } else {                                                                                                                     // Trata posições onde a peça não pode ser posicionada.
                            printf("\n\U0000274C A posição já está ocupada ou é inválida pois está no limite do tabuleiro, por favor, insira a posição novamente. \U0000274C\n");
                            system("pause");
                            system("cls");
                            exibeMapaJogadas();
                            exibeMapaDePosicoesIniciais();
                        }
                    } else if (direcaoPortaViao == 2) {                                                                                              // Se a direção do Porta Aviões for vertical, é necessário verificar se a peça vai ter espaço suficiente na posição abaixo
                        if (matrizUser[posicaoX + 1][posicaoY] == 0 && matrizUser[posicaoX + 2][posicaoY] == 0 && posicaoX != 3 && posicaoX != 4) {  // Se as posições abaixo estão livres e a linha não é a ultima nem penultima do tabuleiro, a jogada é feita
                            matrizUser[posicaoX][posicaoY] = portaViao;                                                                              // Faz a jogada na posição escolhida
                            matrizUser[posicaoX + 1][posicaoY] = portaViao;                                                                          // Faz a jogada na posição abaixo
                            matrizUser[posicaoX + 2][posicaoY] = portaViao;                                                                          // Faz a jogada 2 posições abaixo
                            totalPecasUser++;                                                                                                        // Total de peças posicionadas do usuario é somado em + 1
                        } else {                                                                                                                     // Trata posições onde a peça não pode ser posicionada.
                            printf("\n\U0000274C A posição já está ocupada ou é inválida pois está no limite do tabuleiro, por favor, insira a posição novamente. \U0000274C\n");
                            system("pause");
                            system("cls");
                            exibeMapaJogadas();
                            exibeMapaDePosicoesIniciais();
                        }
                    }
                }
            } else {  // Caso a posição escolhida não esteja livre, trata o erro.
                printf("\n\U0000274C A posição já está ocupada, por favor, insira a posição novamente. \U0000274C\n");
                system("pause");
                system("cls");
                exibeMapaJogadas();
                exibeMapaDePosicoesIniciais();
            }
        }
    }
    while (totalpecasPC <= 4) {                // Enquanto o PC não tiver 5 peças posicionadas, continua posicionando a proxima peça
        int seedDirecao = direcaoAleatoria();  // Define a semente utilizada para definir a direção da embarcação
        switch (totalpecasPC) {                // Caso a peça sendo posicionada pelo PC seja de 2 até 4, significa que precisa de uma direção
            case 2:                            // Define a direção aleatoria do navio 1 quando estiver sendo posicionado
                direcaoNavio1 = seedDirecao;
                break;
            case 3:  // Define a direção aleatoria do navio 2 quando estiver sendo posicionado
                direcaoNavio2 = seedDirecao;
                break;
            case 4:  // Define a direção aleatoria do porta aviões quando estiver sendo posicionado
                direcaoPortaViao = seedDirecao;
                break;
        }
        int seedPosicao = posicaoAletoria();  // Define uma semente para a posição aletoria ser escolhida
        switch (seedPosicao) {                // Escolhe a posição com base na semente (de 0 até 24)
            case 0:
                posicaoX = 0;
                posicaoY = 0;
                break;
            case 1:
                posicaoX = 0;
                posicaoY = 1;
                break;
            case 2:
                posicaoX = 0;
                posicaoY = 2;
                break;
            case 3:
                posicaoX = 0;
                posicaoY = 3;
                break;
            case 4:
                posicaoX = 0;
                posicaoY = 4;
                break;
            case 5:
                posicaoX = 1;
                posicaoY = 0;
                break;
            case 6:
                posicaoX = 1;
                posicaoY = 1;
                break;
            case 7:
                posicaoX = 1;
                posicaoY = 2;
                break;
            case 8:
                posicaoX = 1;
                posicaoY = 3;
                break;
            case 9:
                posicaoX = 1;
                posicaoY = 4;
                break;
            case 10:
                posicaoX = 2;
                posicaoY = 0;
                break;
            case 11:
                posicaoX = 2;
                posicaoY = 1;
                break;
            case 12:
                posicaoX = 2;
                posicaoY = 2;
                break;
            case 13:
                posicaoX = 2;
                posicaoY = 3;
                break;
            case 14:
                posicaoX = 2;
                posicaoY = 4;
                break;
            case 15:
                posicaoX = 3;
                posicaoY = 0;
                break;
            case 16:
                posicaoX = 3;
                posicaoY = 1;
                break;
            case 17:
                posicaoX = 3;
                posicaoY = 2;
                break;
            case 18:
                posicaoX = 3;
                posicaoY = 3;
                break;
            case 19:
                posicaoX = 3;
                posicaoY = 4;
                break;
            case 20:
                posicaoX = 4;
                posicaoY = 0;
                break;
            case 21:
                posicaoX = 4;
                posicaoY = 1;
                break;
            case 22:
                posicaoX = 4;
                posicaoY = 2;
                break;
            case 23:
                posicaoX = 4;
                posicaoY = 3;
                break;
            case 24:
                posicaoX = 4;
                posicaoY = 4;
                break;
        }

        if (matrizInt[posicaoX][posicaoY] == 0) {                                                            // Testa se a posição aleatoraie está livre
            if (totalpecasPC == 0 || totalpecasPC == 1) {                                                    // Se o PC estiver posicionando o barco, não é necessario direção
                matrizInt[posicaoX][posicaoY] = barco;                                                       // Faz a jogada
                totalpecasPC++;                                                                              // Adiciona 1 no total de peças do PC
            } else if (totalpecasPC == 2) {                                                                  // Se o total de peças for 2, é necessario verificar se existe espaço suficiente para a jogada
                if (direcaoNavio1 == 1 && matrizInt[posicaoX][posicaoY + 1] == 0 && posicaoY != 4) {         // Se a direção for horizontal, a posição do lado estiver livre e não for a ultima coluna do tabuleiro, faz a jogada
                    matrizInt[posicaoX][posicaoY] = navio;                                                   // Faz a jogada
                    matrizInt[posicaoX][posicaoY + 1] = navio;                                               // Faz a jogada na posição do lado
                    totalpecasPC++;                                                                          // Adiciona 1 no total de peças do PC
                } else if (direcaoNavio1 == 2 && matrizInt[posicaoX + 1][posicaoY] == 0 && posicaoX != 4) {  // Se a direção for vertical, a posição abaixo estiver livre e não for a ultima linha do tabuleiro, faz a jogada
                    matrizInt[posicaoX][posicaoY] = navio;                                                   // Faz a jogada
                    matrizInt[posicaoX + 1][posicaoY] = navio;                                               // Faz a jogada na posição abaixo
                    totalpecasPC++;                                                                          // Adiciona 1 no total de peças do PC
                }
            } else if (totalpecasPC == 3) {                                                                 // Se o total de peças for 3, é necessario verificar se existe espaço suficiente para a jogada
                if (direcaoNavio2 == 1 && matrizInt[posicaoX][posicaoY + 1] == 0 && posicaoY != 4) {        // Se a direção for horizontal, a posição do lado estiver livre e não for a ultima coluna do tabuleiro, faz a jogada
                    matrizInt[posicaoX][posicaoY] = navio;                                                  // Faz a jogada
                    matrizInt[posicaoX][posicaoY + 1] = navio;                                              // Faz a jogada na posição do lado
                    totalpecasPC++;                                                                         // Adiciona 1 no total de peças do PC
                } else if (direcaoNavio2 = 2 && matrizInt[posicaoX + 1][posicaoY] == 0 && posicaoX != 4) {  // Se a direção for vertical, a posição abaixo estiver livre e não for a ultima linha do tabuleiro, faz a jogada
                    matrizInt[posicaoX][posicaoY] = navio;                                                  // Faz a jogada
                    matrizInt[posicaoX + 1][posicaoY] = navio;                                              // Faz a jogada na posição abaixo
                    totalpecasPC++;                                                                         // Adiciona 1 no total de peças do PC
                }
            } else if (totalpecasPC == 4) {                                                                                                                                // Se o total de peças for 4, é necessario verificar se existe espaço suficiente para a jogada
                if (direcaoPortaViao == 1 && matrizInt[posicaoX][posicaoY + 1] == 0 && matrizInt[posicaoX][posicaoY + 2] == 0 && posicaoY != 3 && posicaoY != 4) {         // Se a direção for horizontal, as posições do lado estiverem livres e não forem a ultima nem penultima coluna do tabuleiro, faz a jogada
                    matrizInt[posicaoX][posicaoY] = portaViao;                                                                                                             // Faz a jogada
                    matrizInt[posicaoX][posicaoY + 1] = portaViao;                                                                                                         // Faz a jogada na posição do lado
                    matrizInt[posicaoX][posicaoY + 2] = portaViao;                                                                                                         // Faz a jogada 2 posições pro lado
                    totalpecasPC++;                                                                                                                                        // Adiciona 1 no total de peças do PC
                } else if (direcaoPortaViao == 2 && matrizInt[posicaoX + 1][posicaoY] == 0 && matrizInt[posicaoX + 2][posicaoY] == 0 && posicaoX != 3 && posicaoY != 4) {  // Se a direção for vertical, a posição abaixo e 2 posições pra estiver livre e não for a ultima linha do tabuleiro, faz a jogada
                    matrizInt[posicaoX][posicaoY] = portaViao;                                                                                                             // Faz a jogada
                    matrizInt[posicaoX + 1][posicaoY] = portaViao;                                                                                                         // Faz a jogada na posição abaixo
                    matrizInt[posicaoX + 2][posicaoY] = portaViao;                                                                                                         // Faz a jogada 2 posições pra baixo
                    totalpecasPC++;                                                                                                                                        // Adiciona 1 no total de peças do PC
                }
            }
        }
    }
    // após o posicionamento de todas as peças, exibe uma mensagem de conclusão e termina a função, iniciando a batalha
    system("cls");
    exibeMapaJogadas();
    printf("    Muito bem! O computador também já posicionou as peças! É hora de jogar!\n");
    system("pause");
    system("cls");
}
int verificaVitoria() {                    // Verifica se alguém venceu (se um dos dois não tiverem mais embarcações = derrota)
    if (totalTabuleiroPC == 0) {           // Se o PC não tiver mais embarcações, usuario vence
        vencedor = user;                   // Guarda valor do vencedor para exibir a mensagem de vitoria
        return 1;                          // retorna 1 (alguem venceu)
    } else if (totalTabuleiroUser == 0) {  // Se o Usuario não tiver mais embarcações, PC vence
        vencedor = PC;                     // Guarda valor do vencedor para exibir a mensagem de vitoria
        return 1;                          // retorna 1 (alguem venceu)
    } else {                               // Se ninguém venceu, retorna 0
        return 0;
    }
}
void batalha() {  // Inicia o jogo
    system("cls");
    exibirJogo();
    int escolhaValida = 0;
    while (!escolhaValida) {  // Pergunta para o usuario quem irá iniciar o jogo
        printf("\n     Escolha quem irá começar o jogo:\n     1 - PC\n     2 - Você\n");
        printf("     Resposta: ");
        int quemComeca;
        scanf("%d", &quemComeca);
        getchar();
        switch (quemComeca) {  // Define quem irá fazer a proxima jogada, no caso, a primeira
            case 1:
                proximaJogada = PC;  // PC inicia
                escolhaValida = 1;   // Quebra while e continua a função
                break;
            case 2:
                proximaJogada = user;  // Usuario inicia
                escolhaValida = 1;     // Quebra while e continua a função
                break;
            default:  // Trata entradas inválidas.
                printf("Escolha inválida! Por favor, insira novamente.");
                system("pause");
                system("cls");
                exibirJogo();
        }
    }
    escolhaValida = 0;
    while (!verificaVitoria()) {    // Jogo inicia até verificaVitoria retornar 1
        if (proximaJogada == PC) {  // Caso a jogada seja do Pc
            system("cls");
            exibirJogo();  // Mostra o tabuleiro
            escolhaValida = 0;
            while (!escolhaValida) {                  // Enquanto a posição aletoria não for valida, continua tentando encontrar alguma valida
                int seedPosicao = posicaoAletoria();  // Define a posição aletoria
                switch (seedPosicao) {                // Converte a posição para as coordenadas do tabuleiro
                    case 0:
                        posicaoX = 0;
                        posicaoY = 0;
                        break;
                    case 1:
                        posicaoX = 0;
                        posicaoY = 1;
                        break;
                    case 2:
                        posicaoX = 0;
                        posicaoY = 2;
                        break;
                    case 3:
                        posicaoX = 0;
                        posicaoY = 3;
                        break;
                    case 4:
                        posicaoX = 0;
                        posicaoY = 4;
                        break;
                    case 5:
                        posicaoX = 1;
                        posicaoY = 0;
                        break;
                    case 6:
                        posicaoX = 1;
                        posicaoY = 1;
                        break;
                    case 7:
                        posicaoX = 1;
                        posicaoY = 2;
                        break;
                    case 8:
                        posicaoX = 1;
                        posicaoY = 3;
                        break;
                    case 9:
                        posicaoX = 1;
                        posicaoY = 4;
                        break;
                    case 10:
                        posicaoX = 2;
                        posicaoY = 0;
                        break;
                    case 11:
                        posicaoX = 2;
                        posicaoY = 1;
                        break;
                    case 12:
                        posicaoX = 2;
                        posicaoY = 2;
                        break;
                    case 13:
                        posicaoX = 2;
                        posicaoY = 3;
                        break;
                    case 14:
                        posicaoX = 2;
                        posicaoY = 4;
                        break;
                    case 15:
                        posicaoX = 3;
                        posicaoY = 0;
                        break;
                    case 16:
                        posicaoX = 3;
                        posicaoY = 1;
                        break;
                    case 17:
                        posicaoX = 3;
                        posicaoY = 2;
                        break;
                    case 18:
                        posicaoX = 3;
                        posicaoY = 3;
                        break;
                    case 19:
                        posicaoX = 3;
                        posicaoY = 4;
                        break;
                    case 20:
                        posicaoX = 4;
                        posicaoY = 0;
                        break;
                    case 21:
                        posicaoX = 4;
                        posicaoY = 1;
                        break;
                    case 22:
                        posicaoX = 4;
                        posicaoY = 2;
                        break;
                    case 23:
                        posicaoX = 4;
                        posicaoY = 3;
                        break;
                    case 24:
                        posicaoX = 4;
                        posicaoY = 4;
                        break;
                }
                if (matrizUser[posicaoX][posicaoY] != afundado && matrizUser[posicaoX][posicaoY] != nadaEncontrado) {  // se a posicção escolhida for valida (não tiver sido escolhida anteriormente, continua a função)
                    escolhaValida = 1;                                                                                 // Quebra o while
                }
            }
            if (matrizUser[posicaoX][posicaoY] == vazio) {        // Se a posição aletoria não tiver uma embarcação do usuario
                matrizUser[posicaoX][posicaoY] = nadaEncontrado;  // Define a posição como nada encontrado
                printf("\033[0;34m");
                printf("\nO Computador está pensando na melhor jogada");
                usleep(200000);  // Espera 2ms para executar o proximo printf
                printf("\033[0;33m");
                printf(".");
                usleep(200000);  // Espera 2ms para executar o proximo printf
                printf("\033[0;35m");
                printf(".");
                usleep(300000);  // Espera 3ms para executar o proximo printf
                printf("\033[0;36m");
                printf(".");
                usleep(200000);  // Espera 2ms para executar o proximo printf
                printf("\033[0;33m");
                printf(".");
                usleep(200000);  // Espera 2ms para executar o proximo printf
                printf("\033[0;35m");
                printf(".");
                usleep(200000);  // Espera 2ms para executar o proximo printf
                printf("\033[0;36m");
                printf(".");
                usleep(400000);  // Espera 4ms para executar o proximo printf
                printf("\033[0;37m");
                system("cls");
                exibirJogo();  // Mostra a jogada do PC
                printf("\nUfa! O computador não atingiu nenhuma embarcação aliada!\n\n");
                system("pause");
                proximaJogada = user;                       // Proxima jogada é do usuario
            } else {                                        // Se a posição aletoria tiver alguma embarcação do usuario
                matrizUser[posicaoX][posicaoY] = afundado;  // Define a posição como afundado
                printf("\033[0;34m");
                printf("\nO Computador está pensando na melhor jogada");
                usleep(200000);  // Espera 3ms para executar o proximo printf
                printf("\033[0;33m");
                printf(".");
                usleep(200000);  // Espera 3ms para executar o proximo printf
                printf("\033[0;35m");
                printf(".");
                usleep(300000);  // Espera 5ms para executar o proximo printf
                printf("\033[0;36m");
                printf(".");
                usleep(200000);  // Espera 3ms para executar o proximo printf
                printf("\033[0;33m");
                printf(".");
                usleep(200000);  // Espera 3ms para executar o proximo printf
                printf("\033[0;35m");
                printf(".");
                usleep(200000);  // Espera 5ms para executar o proximo printf
                printf("\033[0;36m");
                printf(".");
                usleep(400000);  // Espera 5ms para executar o proximo printf
                printf("\033[0;37m");
                system("cls");
                exibirJogo();          // Mostra a jogada para o usuario
                totalTabuleiroUser--;  // Subtrai 1 do total de peças do usuario (inicia com 9)
                printf("Droga! O computador atingiu uma embarcação aliada e vai atacar novamente!!\n\n");
                system("pause");
            }
        } else if (proximaJogada == user) {
            escolhaValida = 0;
            while (!escolhaValida) {
                system("cls");
                exibirJogo();
                exibeMapaDePosicoesJogo();
                char escolha;
                printf("     Escolha a posicao da sua jogada: ");
                scanf("%c", &escolha);
                getchar();
                switch (escolha) {
                    case 'a':
                        posicaoX = 0;
                        posicaoY = 0;
                        break;
                    case 'b':
                        posicaoX = 0;
                        posicaoY = 1;
                        break;
                    case 'c':
                        posicaoX = 0;
                        posicaoY = 2;
                        break;
                    case 'd':
                        posicaoX = 0;
                        posicaoY = 3;
                        break;
                    case 'e':
                        posicaoX = 0;
                        posicaoY = 4;
                        break;
                    case 'f':
                        posicaoX = 1;
                        posicaoY = 0;
                        break;
                    case 'g':
                        posicaoX = 1;
                        posicaoY = 1;
                        break;
                    case 'h':
                        posicaoX = 1;
                        posicaoY = 2;
                        break;
                    case 'i':
                        posicaoX = 1;
                        posicaoY = 3;
                        break;
                    case 'j':
                        posicaoX = 1;
                        posicaoY = 4;
                        break;
                    case 'k':
                        posicaoX = 2;
                        posicaoY = 0;
                        break;
                    case 'l':
                        posicaoX = 2;
                        posicaoY = 1;
                        break;
                    case 'm':
                        posicaoX = 2;
                        posicaoY = 2;
                        break;
                    case 'n':
                        posicaoX = 2;
                        posicaoY = 3;
                        break;
                    case 'o':
                        posicaoX = 2;
                        posicaoY = 4;
                        break;
                    case 'p':
                        posicaoX = 3;
                        posicaoY = 0;
                        break;
                    case 'q':
                        posicaoX = 3;
                        posicaoY = 1;
                        break;
                    case 'r':
                        posicaoX = 3;
                        posicaoY = 2;
                        break;
                    case 's':
                        posicaoX = 3;
                        posicaoY = 3;
                        break;
                    case 't':
                        posicaoX = 3;
                        posicaoY = 4;
                        break;
                    case 'u':
                        posicaoX = 4;
                        posicaoY = 0;
                        break;
                    case 'v':
                        posicaoX = 4;
                        posicaoY = 1;
                        break;
                    case 'w':
                        posicaoX = 4;
                        posicaoY = 2;
                        break;
                    case 'x':
                        posicaoX = 4;
                        posicaoY = 3;
                        break;
                    case 'y':
                        posicaoX = 4;
                        posicaoY = 4;
                        break;
                    default:
                        printf("\n\U0000274C Escolha inválida, por favor, insira a posição novamente. \U0000274C\n");
                        system("pause");
                        system("cls");
                        exibirJogo();
                        exibeMapaDePosicoesJogo();
                }
                if (matrizPC[posicaoX][posicaoY] == afundado || matrizPC[posicaoX][posicaoY] == nadaEncontrado) {
                    printf("\n \U0000274C Você já escolheu essa posição, por favor, insira novamente. \U0000274C\n");
                    system("pause");
                    system("cls");
                    exibirJogo();
                    exibeMapaDePosicoesJogo();
                } else if (matrizInt[posicaoX][posicaoY] == barco || matrizInt[posicaoX][posicaoY] == navio || matrizInt[posicaoX][posicaoY] == portaViao) {
                    matrizPC[posicaoX][posicaoY] = afundado;
                    proximaJogada = user;
                    totalTabuleiroPC--;
                    escolhaValida = 1;
                    printf("\nMuito bem! Você afundou uma embarcação inimiga!\nAgora jogue novamente!\n\n");
                    system("pause");
                } else if (matrizInt[posicaoX][posicaoY] == 0) {
                    matrizPC[posicaoX][posicaoY] = nadaEncontrado;
                    proximaJogada = PC;
                    escolhaValida = 1;
                    printf("\nAh, nesta posição não havia nenhuma embarcação inimiga! Que droga!\n\n");
                    system("pause");
                }
            }
        }
    }
    exibirFimDeJogo();
}
int main() {
    srand(time(NULL));
    systemSet();
    bemVindo();
    inicioDeJogo();
    batalha();

    return 0;
}