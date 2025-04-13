// JOGO DA VELHA BY LUCAS AMARAL

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#define usuario 1
#define computador 3

// Variáveis utilizadas durante o jogo são criadas
int matriz[4][5];                // Cria a Matriz principal do jogo
short int representacaoJogador;  // Cria a representação do usuario no tabuleiro (X ou O)
short int quemComeca;            // Indica se o usuario ou o computador começa
short int totalJogadas;          // Cria o total de jogadas
short int jogadorVencedor;       // Cria o controle do jogador que venceu
short int vitoria;               // Quebra o laço de repetição de jogadas em caso de vitoria
short int empate;                // Quebra o laço de repetiçao de jogadas em caso de empate
short int escolhaValida;         // Cria a variavel de controle da escolha

void systemset()  // É utilizado para definir as configurações e os parametros inicais do jogo
{
    // Configs
    system("chcp 65001");                    // Config. do terminal é definido para portugues
    system("cls");                           // Limpa o terminal
    system("title SUPER JOGO DA VELHA !");   // Define o título da Janela
    setlocale(LC_ALL, "Portuguese_Brasil");  // Define a localicação para a utilização de acentos do português

    // Define os parametros inicias do jogo
    for (int i = 0; i < 3; i++) {  // Limpa a matriz de jogo (define tudo como 2 novamente)
        for (int j = 1; j < 4; j++) {
            matriz[i][j] = 2;
        }
    }
    // Define as posições não utilizadas da matriz para 0 (Evita jogadas acidentais do computador)
    matriz[0][0] = 0;
    matriz[1][0] = 0;
    matriz[2][0] = 0;

    // Limpa todos os valores
    representacaoJogador = 0;
    quemComeca = 0;
    totalJogadas = 0;
    jogadorVencedor = 0;
    vitoria = 0;
    empate = 0;
}

void calculoMatriz()  // Calcula o total de linhas, colunas e diagonais
{
    // Calcula os pesos das linhas
    matriz[0][4] = (matriz[0][1] * matriz[0][2] * matriz[0][3]);  // Calcula o peso da primeira linha
    matriz[1][4] = (matriz[1][1] * matriz[1][2] * matriz[1][3]);  // Calcula o peso da segunda linha
    matriz[2][4] = (matriz[2][1] * matriz[2][2] * matriz[2][3]);  // Calcula o peso da terceira linha

    // Calcula os pesos das colunas
    matriz[3][1] = (matriz[0][1] * matriz[1][1] * matriz[2][1]);  // Calcula o peso da primeira coluna
    matriz[3][2] = (matriz[0][2] * matriz[1][2] * matriz[2][2]);  // Calcula o peso da segunda coluna
    matriz[3][3] = (matriz[0][3] * matriz[1][3] * matriz[2][3]);  // Calcula o peso da terceira linha

    // Calcula os pesos das diagonais
    matriz[3][4] = (matriz[0][1] * matriz[1][2] * matriz[2][3]);  // Calcula o peso da diagonal principal
    matriz[3][0] = (matriz[0][3] * matriz[1][2] * matriz[2][1]);  // Calcula o peso da diagonal segundaria
}

int verificaVitoria() {
    for (int i = 0; i < 3; i++)  // Verifica as linhas
    {
        if (matriz[i][1] == usuario && matriz[i][2] == usuario && matriz[i][3] == usuario) {
            jogadorVencedor = usuario;  // Define "jogadorVenceder" como 1, fazendo o proximo "exibirJogo" mostre a vitória do usuário
            vitoria = 1;                // Vitoria definida para fim de jogo
            quemComeca = 0;             // Em caso de vitoria, "quemComeca" é 0
            return 1;                   // Vitoria nas linhas
        }

        if (matriz[i][1] == computador && matriz[i][2] == computador && matriz[i][3] == computador) {
            jogadorVencedor = computador;  // Define "jogadorVenceder" como 3, fazendo o proximo "exibirJogo" mostre a vitória do computador
            vitoria = 1;                   // Vitoria definida para fim de jogo
            quemComeca = 0;                // Em caso de vitoria, "quemComeca" é 0
            return 1;                      // Vitoria nas linhas
        }
    }

    for (int j = 1; j < 4; j++)  // Verifica as colunas
    {
        if (matriz[0][j] == usuario && matriz[1][j] == usuario && matriz[2][j] == usuario) {
            jogadorVencedor = usuario;  // Define "jogadorVenceder" como 1, fazendo o proximo "exibirJogo" mostre a vitória do usuário
            vitoria = 1;                // Vitoria definida para fim de jogo
            quemComeca = 0;             // Em caso de vitoria, "quemComeca" é 0
            return 1;                   // Vitoria nas colunas
        }
        if (matriz[0][j] == computador && matriz[1][j] == computador && matriz[2][j] == computador) {
            jogadorVencedor = computador;  // Define "jogadorVenceder" como 3, fazendo o proximo "exibirJogo" mostre a vitória do computador
            vitoria = 1;                   // Vitoria definida para fim de jogo
            quemComeca = 0;                // Em caso de vitoria, "quemComeca" é 0
            return 1;                      // Vitoria nas colunas
        }
    }

    if (matriz[0][1] == usuario && matriz[1][2] == usuario && matriz[2][3] == usuario)  // Verifica a diagonal principal
    {
        jogadorVencedor = usuario;  // Define "jogadorVenceder" como 1, fazendo o proximo "exibirJogo" mostre a vitória do usuário
        vitoria = 1;                // Vitoria definida para fim de jogo
        quemComeca = 0;             // Em caso de vitoria, "quemComeca" é 0
        return 1;                   // Vitoria na Diagonal Principal
    }

    if (matriz[0][1] == computador && matriz[1][2] == computador && matriz[2][3] == computador) {
        jogadorVencedor = computador;  // Define "jogadorVenceder" como 3, fazendo o proximo "exibirJogo" mostre a vitória do computador
        vitoria = 1;                   // Vitoria definida para fim de jogo
        quemComeca = 0;                // Em caso de vitoria, "quemComeca" é 0
        return 1;                      // Vitoria na Diagonal Principal
    }

    if (matriz[0][3] == usuario && matriz[1][2] == usuario && matriz[2][1] == usuario)  // Verifica a diagonal segundaria
    {
        jogadorVencedor = usuario;  // Define "jogadorVenceder" como 1, fazendo o proximo "exibirJogo" mostre a vitória do usuário
        vitoria = 1;                // Vitoria definida para fim de jogo
        quemComeca = 0;             // Em caso de vitoria, "quemComeca" é 0
        return 1;                   // Vitoria na Diagonal Segundaria
    }

    if (matriz[0][3] == computador && matriz[1][2] == computador && matriz[2][1] == computador) {
        jogadorVencedor = computador;  // Define "jogadorVenceder" como 3, fazendo o proximo "exibirJogo" mostre a vitória do computador
        vitoria = 1;                   // Vitoria definida para fim de jogo
        quemComeca = 0;                // Em caso de vitoria, "quemComeca" é 0
        return 1;                      // Vitoria na Diagonal Segundaria
    }

    return 0;  // Retorna 0 caso não tenha vitoria
}

int verificaEmpate() {
    if (totalJogadas == 8) {  // Quando chegar em 8 jogadas, a função verifica se na proxima jogada pode haver uma vitória, caso sim, ele retorna 0
        for (int i = 0; i < 3; i++) {
            for (int j = 1; j < 4; j++) {  // Verifica se na única posição livre é possível alguém vencer na proxima jogada
                if (matriz[i][j] == 2) {
                    if (quemComeca == usuario) {  // Verifica se o usuario pode ganhar na proxima jogada
                        matriz[i][j] = usuario;
                        if (!verificaVitoria()) {
                            empate = 1;        // Empate definido para fim de jogo
                            matriz[i][j] = 2;  // Desfaz a jogada
                            quemComeca = 0;    // Em caso de vitoria, "quemComeca" é 0
                            return 1;          // Retorno da função em caso de empate
                        }
                        matriz[i][j] = 2;  // Desfaz a jogada
                    }
                    if (quemComeca == computador) {  // Verifica se o computador pode ganhar na proxima jogada
                        matriz[i][j] = computador;
                        if (!verificaVitoria()) {
                            empate = 1;        // Empate definido para fim de jogo
                            matriz[i][j] = 2;  // Desfaz a jogada
                            quemComeca = 0;    // Em caso de vitoria, "quemComeca" é 0
                            return 1;          // Retorno da função em caso de empate
                        }
                    }
                }
            }
        }
    }
    return 0;  // Retorna 0 caso não tenha vitoria na proxima jogada e deixa o jogo seguir
}

char converter(int numero)  // Converte numeros para letras, para exibir a tabela de jogo ao usuario
{
    char letra;
    if (representacaoJogador == usuario) {  // Quando o usuário escolher que quer utilizar o tipo de jogador '0', faz a conversão da matriz númerica desta forma
        switch (numero) {
            case usuario:  // Onde for 1, é convertido para 'O'
                letra = 'O';
                break;        // Quebra o switch
            case computador:  // Onde for 3, é convertido para 'X'
                letra = 'X';
                break;  // Quebra o switch
            default:    // Onde for qualquer outro valor, é convertido para ' '
                letra = ' ';
                break;  // Quebra o switch
        }
    } else if (representacaoJogador == computador) {  // Se o usuario escolher 'X', o número 1 é trocado por '0'
        switch (numero) {
            case usuario:
                letra = 'X';
                break;
            case computador:
                letra = 'O';
                break;
            default:
                letra = ' ';
                break;
        }
    }
    return letra;
}

void exibirJogo() {  // Verifica se há alguma situação de vitoria ou empate e exibe as devidas "telas", do contrário, exibe o tabuleiro de jogo com base no proximo jogador
    system("cls");
    if (!verificaVitoria() && !verificaEmpate()) {  // Se não for vitoria nem empate, exibe o tabuleiro de jogo com base no proximo jogador
        if (quemComeca == usuario)                  // Se o proximo jogador for o usuario, a moldura do jogo é verde (Cor do "usuario")
        {
            printf("\033[0;32m");
            printf("  *******************\n");
            printf("  *    ");
            printf("\033[0;37m");
            printf("%c | %c | %c", converter(matriz[0][1]), converter(matriz[0][2]), converter(matriz[0][3]));  // Mostra a matriz convertida
            printf("\033[0;32m");
            printf("    *\n");
            printf("  *    ");
            printf("\033[0;37m");
            printf("---------    ");
            printf("\033[0;32m");
            printf("*\n");
            printf("  *    ");
            printf("\033[0;37m");
            printf("%c | %c | %c", converter(matriz[1][1]), converter(matriz[1][2]), converter(matriz[1][3]));  // Mostra a matriz convertida
            printf("\033[0;32m");
            printf("    *\n");
            printf("  *    ");
            printf("\033[0;37m");
            printf("---------    ");
            printf("\033[0;32m");
            printf("*\n");
            printf("  *    ");
            printf("\033[0;37m");
            printf("%c | %c | %c", converter(matriz[2][1]), converter(matriz[2][2]), converter(matriz[2][3]));  // Mostra a matriz convertida
            printf("\033[0;32m");
            printf("    *\n");
            printf("  *******************\n");
            printf("\033[0;37m");
            printf("\n  Total de Jogadas: ");
            printf("\033[0;32m");
            printf("%d", totalJogadas);  // Mostra o valor das jogadas até o momento da exibição do tabuleiro
            printf("\033[0;37m");
            printf("\n\n\n");
        } else if (quemComeca == computador)  // Se o proximo jogador for o computador, a moldura do jogo é azul (Cor do "computador")
        {
            printf("\033[0;34m");
            printf("  *******************\n");
            printf("  *    ");
            printf("\033[0;37m");
            printf("%c | %c | %c", converter(matriz[0][1]), converter(matriz[0][2]), converter(matriz[0][3]));  // Mostra a matriz convertida
            printf("\033[0;34m");
            printf("    *\n");
            printf("  *    ");
            printf("\033[0;37m");
            printf("---------    ");
            printf("\033[0;34m");
            printf("*\n");
            printf("  *    ");
            printf("\033[0;37m");
            printf("%c | %c | %c", converter(matriz[1][1]), converter(matriz[1][2]), converter(matriz[1][3]));  // Mostra a matriz convertida
            printf("\033[0;34m");
            printf("    *\n");
            printf("  *    ");
            printf("\033[0;37m");
            printf("---------    ");
            printf("\033[0;34m");
            printf("*\n");
            printf("  *    ");
            printf("\033[0;37m");
            printf("%c | %c | %c", converter(matriz[2][1]), converter(matriz[2][2]), converter(matriz[2][3]));  // Mostra a matriz convertida
            printf("\033[0;34m");
            printf("    *\n");
            printf("  *******************\n");
            printf("\033[0;37m");
            printf("\n  Total de Jogadas: ");
            printf("\033[0;32m");
            printf("%d", totalJogadas);  // Mostra o valor das jogadas até o momento da exibição do tabuleiro
            printf("\033[0;37m");
            printf("\n\n\n");
        }
    }
    if (empate)  // Caso a situação seja de empate, exibe a mensagem de empate e o tabuleiro de jogo
    {
        printf("*****************************************\n");
        printf("*                                       *\n");
        printf("*  ");
        printf("\033[0;33m");
        printf("        O JOGO EMPATOU !!!     ");
        printf("\033[0;37m");
        printf("      *\n");
        printf("*                                       *\n");
        printf("*****************************************\n");

        printf("\033[0;33m");
        printf("  *******************\n");
        printf("  *    ");
        printf("\033[0;37m");
        printf("%c | %c | %c", converter(matriz[0][1]), converter(matriz[0][2]), converter(matriz[0][3]));  // Mostra a matriz convertida
        printf("\033[0;33m");
        printf("    *\n");
        printf("  *    ");
        printf("\033[0;37m");
        printf("---------    ");
        printf("\033[0;33m");
        printf("*\n");
        printf("  *    ");
        printf("\033[0;37m");
        printf("%c | %c | %c", converter(matriz[1][1]), converter(matriz[1][2]), converter(matriz[1][3]));  // Mostra a matriz convertida
        printf("\033[0;33m");
        printf("    *\n");
        printf("  *    ");
        printf("\033[0;37m");
        printf("---------    ");
        printf("\033[0;33m");
        printf("*\n");
        printf("  *    ");
        printf("\033[0;37m");
        printf("%c | %c | %c", converter(matriz[2][1]), converter(matriz[2][2]), converter(matriz[2][3]));  // Mostra a matriz convertida
        printf("\033[0;33m");
        printf("    *\n");
        printf("  *******************\n");
        printf("\033[0;37m");
        printf("\n  Total de Jogadas: ");
        printf("\033[0;32m");
        printf("%d", totalJogadas);  // Mostra o valor das jogadas até o momento da exibição do tabuleiro
        printf("\033[0;37m");
        printf("\n\n\n");
        system("pause");
    } else if (verificaVitoria() && jogadorVencedor == usuario) {  // Caso seja vitoria e o usuario seja quem ganhou, exibe a mensagem de vitoria do usuario
        printf("*****************************************\n");
        printf("*                                       *\n");
        printf("*  ");
        printf("\033[0;32m");
        printf("      VITÓRIA DO USUÁRIO !!!");
        printf("\033[0;37m");
        printf("         *\n");
        printf("*                                       *\n");
        printf("*****************************************\n\n");

        printf("\033[0;32m");
        printf("  *******************\n");
        printf("  *    ");
        printf("\033[0;37m");
        printf("%c | %c | %c", converter(matriz[0][1]), converter(matriz[0][2]), converter(matriz[0][3]));  // Mostra a matriz convertida
        printf("\033[0;32m");
        printf("    *\n");
        printf("  *    ");
        printf("\033[0;37m");
        printf("---------    ");
        printf("\033[0;32m");
        printf("*\n");
        printf("  *    ");
        printf("\033[0;37m");
        printf("%c | %c | %c", converter(matriz[1][1]), converter(matriz[1][2]), converter(matriz[1][3]));  // Mostra a matriz convertida
        printf("\033[0;32m");
        printf("    *\n");
        printf("  *    ");
        printf("\033[0;37m");
        printf("---------    ");
        printf("\033[0;32m");
        printf("*\n");
        printf("  *    ");
        printf("\033[0;37m");
        printf("%c | %c | %c", converter(matriz[2][1]), converter(matriz[2][2]), converter(matriz[2][3]));  // Mostra a matriz convertida
        printf("\033[0;32m");
        printf("    *\n");
        printf("  *******************\n");
        printf("\033[0;37m");
        printf("\n  Total de Jogadas: ");
        printf("\033[0;32m");
        printf("%d", totalJogadas);  // Mostra o valor das jogadas até o momento da exibição do tabuleiro
        printf("\033[0;37m");
        printf("\n\n\n");
        system("pause");
    } else if (verificaVitoria() && jogadorVencedor == computador) {  // Caso seja vitoria, mas o vencedor seja o computador, exibe a mensagem de vitoria do computador
        printf("*****************************************\n");
        printf("*                                       *\n");
        printf("*  ");
        printf("\033[0;34m");
        printf("      VITÓRIA DO COMPUTADOR !!!");
        printf("\033[0;37m");
        printf("      *\n");
        printf("*                                       *\n");
        printf("*****************************************\n");

        printf("\033[0;34m");
        printf("  *******************\n");
        printf("  *    ");
        printf("\033[0;37m");
        printf("%c | %c | %c", converter(matriz[0][1]), converter(matriz[0][2]), converter(matriz[0][3]));  // Mostra a matriz convertida
        printf("\033[0;34m");
        printf("    *\n");
        printf("  *    ");
        printf("\033[0;37m");
        printf("---------    ");
        printf("\033[0;34m");
        printf("*\n");
        printf("  *    ");
        printf("\033[0;37m");
        printf("%c | %c | %c", converter(matriz[1][1]), converter(matriz[1][2]), converter(matriz[1][3]));  // Mostra a matriz convertida
        printf("\033[0;34m");
        printf("    *\n");
        printf("  *    ");
        printf("\033[0;37m");
        printf("---------    ");
        printf("\033[0;34m");
        printf("*\n");
        printf("  *    ");
        printf("\033[0;37m");
        printf("%c | %c | %c", converter(matriz[2][1]), converter(matriz[2][2]), converter(matriz[2][3]));  // Mostra a matriz convertida
        printf("\033[0;34m");
        printf("    *\n");
        printf("  *******************\n");
        printf("\033[0;37m");
        printf("\n  Total de Jogadas: ");
        printf("\033[0;32m");
        printf("%d", totalJogadas);  // Mostra o valor das jogadas até o momento da exibição do tabuleiro
        printf("\033[0;37m");
        printf("\n\n\n");
        system("pause");
    }
}

int posicaoLivre(int linha, int coluna)  // Verifica se uma posição está livre e retorna 1 caso esteja
{
    return matriz[linha][coluna] == 2;  // Se a posição for = 2, retorna 1, caso seja outro valor, ou seja, posição ocupada, retorna 0
}

void usuarioJoga()  // Usuario faz uma jogada
{
    short int linha, coluna;  // Variaveis para mapear onde o usuario vai jogar dentro do tabuleiro
    while (1) {               // Loop infinito para solicitar uma entrada válida
        char escolha;
        printf("Escolha uma das posições abaixo:\n");
        printf("\033[0;32m");
        printf("   _____________\n\n");
        printf("\033[0;37m");
        printf("     a | b | c\n");
        printf("     ---------\n");
        printf("     d | e | f\n");
        printf("     ---------\n");
        printf("     g | h | i\n");
        printf("\033[0;32m");
        printf("   _____________\n\n");
        printf("\033[0;37m");
        printf("\n\n\n");
        printf("Jogar na Posição: ");
        scanf(" %c", &escolha);

        switch (escolha) {  // Escreve onde sera a linha e coluna da jogada, com base na resposta do usuario
            case 'a':       // Caso seja 'a', joga na primeira linha e na primeira coluna
                linha = 0;
                coluna = 1;
                break;  // Quebra o switch
            case 'b':   // Caso seja 'b', joga na primeira linha e na segunda coluna
                linha = 0;
                coluna = 2;
                break;  // Quebra o switch
            case 'c':   // Caso seja 'c', joga na primeira linha e na terceira coluna
                linha = 0;
                coluna = 3;
                break;  // Quebra o switch
            case 'd':   // Caso seja 'd', joga na segunda linha e na primeira coluna
                linha = 1;
                coluna = 1;
                break;  // Quebra o switch
            case 'e':   // Caso seja 'e', joga na segunda linha e na segunda coluna
                linha = 1;
                coluna = 2;
                break;  // Quebra o switch
            case 'f':   // Caso seja 'f', joga na segunda linha e na terceira coluna
                linha = 1;
                coluna = 3;
                break;  // Quebra o switch
            case 'g':   // Caso seja 'g', joga na terceira linha e na primeira coluna
                linha = 2;
                coluna = 1;
                break;  // Quebra o switch
            case 'h':   // Caso seja 'h', joga na terceira linha e na segunda coluna
                linha = 2;
                coluna = 2;
                break;  // Quebra o switch
            case 'i':   // Caso seja 'i', jogda na terceira linha e na terceira coluna
                linha = 2;
                coluna = 3;
                break;  // Quebra o switch
            default:    // Caso não seja nenhuma das opções exibidas, retorna um erro e limpa o buffer
                printf("\033[0;31m");
                printf("Sua escolha é inválida! ");
                printf("\033[0;37m");
                printf("Por favor, tente novamente.\n\n");
                system("pause");
                getchar();  // Limpa o buffer da entrada invalida, evitando looping
                system("cls");
                exibirJogo();  // Exibe a tabela de jogo novamente
                continue;      // Volta para o inicio do while
        }

        if (!posicaoLivre(linha, coluna)) {  // Verifica se a posição está ocupada e retorna para o usuario que a escolha não é possível
            printf("\033[0;31m");
            printf("A posição escolhida já está ocupada! ");
            printf("\033[0;37m");
            printf("Por favor, selecione outra posição.\n\n");
            system("pause");
            system("cls");
            exibirJogo();  // exibe a matriz novamente e depois volta para o inicio do switch
            continue;      // Volta para o inicio do while
        }

        break;  // Quebra o While caso a posição escolhida pelo usuario seja valida e livre
    }
    matriz[linha][coluna] = usuario;  // Faz a jogada na posição escolhida
    totalJogadas++;                   // Adiciona 1 no total de jogadas
    quemComeca = computador;          // Proxima jogada é do computador
}

void computadorJoga() {
    printf("\033[0;34m");
    printf("\nO Computador está pensando na melhor jogada");
    usleep(300000);  // Espera 3ms para executar o proximo printf
    printf("\033[0;33m");
    printf(".");
    usleep(300000);  // Espera 3ms para executar o proximo printf
    printf("\033[0;35m");
    printf(".");
    usleep(500000);  // Espera 5ms para executar o proximo printf
    printf("\033[0;36m");
    printf(".");
    usleep(300000);  // Espera 3ms para executar o proximo printf
    printf("\033[0;33m");
    printf(".");
    usleep(300000);  // Espera 3ms para executar o proximo printf
    printf("\033[0;35m");
    printf(".");
    usleep(500000);  // Espera 5ms para executar o proximo printf
    printf("\033[0;36m");
    printf(".");
    usleep(500000);  // Espera 5ms para executar o proximo printf
    printf("\033[0;37m");

    for (int i = 0; i < 3; i++) {  // Verifica se existe alguma jogada com possibilidade de vitoria
        for (int j = 1; j < 4; j++) {
            if (posicaoLivre(i, j)) {                                      // Se a posição em teste estiver livre, continua o if
                matriz[i][j] = computador;                                 // Define a posição em teste para 3 (computador)
                if (verificaVitoria() && jogadorVencedor == computador) {  // Testa se nessa jogada o computador é vencedor e caos seja faz a jogada
                    {
                        matriz[i][j] = computador;  // Faz a jogada
                        totalJogadas++;             // Adiciona 1 no total de jogadas
                        quemComeca = usuario;       // Proxima jogada é do usuario
                        return;                     // Termina a função após a jogada
                    }
                }
                matriz[i][j] = 2;  // Desfaz a jogada de verificação caso o computador não possa vencer na proxima jogada
            }
        }
    }

    for (int i = 0; i < 3; i++) {  // Se não for possível ganhar, verifica se pode perder na proxima jogada
        for (int j = 1; j < 4; j++) {
            if (posicaoLivre(i, j)) {                                   // Se a posição em teste estiver livre, continua o if
                matriz[i][j] = usuario;                                 // Define a posição em teste para 1 (usuario)
                if (verificaVitoria() && jogadorVencedor == usuario) {  // Caso o usuario seja vitorioso nesta jogada, o computador bloqueia para não perder
                    matriz[i][j] = computador;                          // Faz a jogada
                    totalJogadas++;                                     // Adiciona 1 no total de jogadas
                    quemComeca = usuario;                               // Proxima jogada é do usuario
                    return;                                             // Termina a função após a jogada
                }
                matriz[i][j] = 2;  // Desfaz a jogada de verificação caso o computador não possa perder na proxima jogada
            }
        }
    }
    // Caso não seja possível ganhar ou perder na proxima jogada, o computador joga com base no melhor peso
    int peso[8];      // Inicia o conjunto dos pesos (0, 0, 0, 0, 0, 0, 0)
    int i, j;         // Variaveis utilizadas para identificação da posição no tabuleiro
    int valorMax;     // Guarda o maior peso do conjunto peso[8]
    int pos = 0;      // Guarda a posição correspondente ao maior peso
    calculoMatriz();  // Faz o calculo dos pesos na matriz para a definição do conjunto peso[8]

    // Define o valor de cada numero do conjunto peso[8]
    peso[0] = matriz[0][4];
    peso[1] = matriz[1][4];
    peso[2] = matriz[2][4];
    peso[3] = matriz[3][4];
    peso[4] = matriz[3][3];
    peso[5] = matriz[3][2];
    peso[6] = matriz[3][1];
    peso[7] = matriz[3][0];
    valorMax = peso[0];  // Maior peso é definido como o primeiro numero do conjunto peso[8]

    for (i = 1; i <= 7; i++) {
        if (peso[i] > valorMax) {  // Verifica o maior peso do conjunto e caso o peso[0] não seja o maior, define o peso correspondente como maior peso
            valorMax = peso[i];
            pos = i;  // Define a posição com maior peso em que a jogada será feita
        }
    }

    switch (pos) {                              // Faz a jogada com base na posição com maior peso
        case 0:                                 // Se o primeiro valor do conjunto peso[8] for o maior, faz a jogada em alguma posição livre na primeira linha
            i = 0;                              // Define a linha como 0 (primeira linha)
            for (j = 1; j <= 3; j++) {          // Verifica se alguma posição da primeira linha está livre
                if (posicaoLivre(i, j)) {       // Se a posição em teste estiver livre, continua o if
                    matriz[i][j] = computador;  // Faz a jogada
                    totalJogadas++;             // Adiciona 1 no total de jogadas
                    quemComeca = usuario;       // Proxima jogada é do usuario
                    return;                     // Termina a função após a jogada
                }
            }
            break;
        case 1:  // Se o segundo valor do conjunto peso[8] for o maior, faz a jogada em alguma posição livre na segunda linha
            i = 1;
            for (j = 1; j <= 3; j++) {
                if (posicaoLivre(i, j)) {       // Verifica se alguma posição da segunda linha está livre
                    matriz[i][j] = computador;  // Faz a jogada
                    totalJogadas++;             // Adiciona 1 no total de jogadas
                    quemComeca = usuario;       // Proxima jogada é do usuario
                    return;                     // Termina a função após a jogada
                }
            }
            break;
        case 2:  // Se o terceiro valor do conjunto peso[8] for o maior, faz a jogada em alguma posição livre na terceira linha
            i = 2;
            for (j = 1; j <= 3; j++) {
                if (posicaoLivre(i, j)) {       // Verifica se alguma posição da terceira linha está livre
                    matriz[i][j] = computador;  // Faz a jogada
                    totalJogadas++;             // Adiciona 1 no total de jogadas
                    quemComeca = usuario;       // Proxima jogada é do usuario
                    return;                     // Termina a função após a jogada
                }
            }
            break;
        case 3:                             // Se o quarto valor do conjunto peso[8] for o maior, faz a jogada em alguma posição livre na diagonal principal
            if (posicaoLivre(0, 1)) {       // Verifica se a primeira posição da diagonal principal está livre
                matriz[0][1] = computador;  // Faz a jogada
                totalJogadas++;             // Adiciona 1 no total de jogadas
                quemComeca = usuario;       // Proxima jogada é do usuario
                return;                     // Termina a função após a jogada
            }
            if (posicaoLivre(1, 2)) {       // Verifica se a segunda posição da diagonal principal está livre
                matriz[1][2] = computador;  // Faz a jogada
                totalJogadas++;             // Adiciona 1 no total de jogadas
                quemComeca = usuario;       // Proxima jogada é do usuario
                return;                     // Termina a função após a jogada
            }
            if (posicaoLivre(2, 3)) {       // Verifica se a terceira posição da diagonal principal está livre
                matriz[2][3] = computador;  // Faz a jogada
                totalJogadas++;             // Adiciona 1 no total de jogadas
                quemComeca = usuario;       // Proxima jogada é do usuario
                return;                     // Termina a função após a jogada
            }
            break;
        case 4:  // Se o quinto valor do conjunto peso[8] for o maior, faz a jogada em alguma posição livre na terceira coluna
            j = 3;
            for (i = 0; i < 2; i++) {
                if (posicaoLivre(i, j)) {       // Verifica se alguma posição da segunda coluna está livre
                    matriz[i][j] = computador;  // Faz a jogada
                    totalJogadas++;             // Adiciona 1 no total de jogadas
                    quemComeca = usuario;       // Proxima jogada é do usuario
                    return;                     // Termina a função após a jogada
                }
            }
            break;
        case 5:  // Se o sexto valor do conjunto peso[8] for o maior, faz a jogada em alguma posição livre na segunda coluna
            j = 2;
            for (i = 0; i <= 2; i++) {
                if (posicaoLivre(i, j)) {       // Verifica se alguma posição da segunda coluna está livre
                    matriz[i][j] = computador;  // Faz a jogada
                    totalJogadas++;             // Adiciona 1 no total de jogadas
                    quemComeca = usuario;       // Proxima jogada é do usuario
                    return;                     // Termina a função após a jogada
                }
            }
            break;
        case 6:  // Se o sétimo valor do conjunto peso[8] for o maior, faz a jogada em alguma posição livre na terceira coluna
            j = 1;
            for (i = 0; i <= 2; i++) {
                if (posicaoLivre(i, j)) {       // Verifica se alguma posição da primeira coluna está livre
                    matriz[i][j] = computador;  // Faz a jogada
                    totalJogadas++;             // Adiciona 1 no total de jogadas
                    quemComeca = usuario;       // Proxima jogada é do usuario
                    return;                     // Termina a função após a jogada
                }
            }
            break;
        case 7:                             // Se o oitavo valor do conjunto peso[8] for o maior, faz a jogada em alguma posição livre na diagonal segundaria
            if (posicaoLivre(0, 3)) {       // Verifica se a primeira posição da diagonal segundaria está livre
                matriz[0][3] = computador;  // Faz a jogada
                totalJogadas++;             // Adiciona 1 no total de jogadas
                quemComeca = usuario;       // Proxima jogada é do usuario
                return;                     // Termina a função após a jogada
            }
            if (posicaoLivre(1, 2)) {       // Verifica se a segunda posição da diagonal segundaria está livre
                matriz[1][2] = computador;  // Faz a jogada
                totalJogadas++;             // Adiciona 1 no total de jogadas
                quemComeca = usuario;       // Proxima jogada é do usuario
                return;                     // Termina a função após a jogada
            }
            if (posicaoLivre(2, 1)) {       // Verifica se a terceira posição da diagonal segundaria está livre
                matriz[2][1] = computador;  // Faz a jogada
                totalJogadas++;             // Adiciona 1 no total de jogadas
                quemComeca = usuario;       // Proxima jogada é do usuario
                return;                     // Termina a função após a jogada
            }
            break;
    }
}

void iniciaJogo()  // Inicia o jogo
{
    char escolhaTipoJogador;  // Cria a variavel resposavel por guardar o valor do tipo de jogador (x ou o)
    escolhaValida = 0;        // Limpa o valor de 'escolhaValida'
    while (!escolhaValida) {  // Faz um loop até que uma escolha válida seja feita
        printf("*****************************************\n");
        printf("*                                       *\n");
        printf("*  ");
        printf("\033[0;31m");
        printf("BEM-VINDO AO SUPER JOGO DA VELHA !!");
        printf("\033[0;37m");
        printf("  *\n");
        printf("*                                       *\n");
        printf("*****************************************\n");
        printf("Por favor, selecione um tipo de Jogador ( ");
        printf("\033[0;32m");
        printf("O");
        printf("\033[0;37m");
        printf(" ou ");
        printf("\033[0;31m");
        printf("X");
        printf("\033[0;37m");
        printf(" ): ");
        scanf(" %c", &escolhaTipoJogador);  // Solicita a entrada do tipo de jogador e guarda na variavel 'escolhaTipoJogador'
        switch (escolhaTipoJogador) {       // Define a variavel 'representacaoJogador', convertendo posteriormente no tabuleiro para a escolha do usuário
            case 'X':
                representacaoJogador = computador;  // representacaoJogador é definido para '3'
                escolhaValida = 1;                  // Define a escolha valida como '1', para quebrar o While
                break;
            case 'x':
                representacaoJogador = computador;  // representacaoJogador é definido para '3'
                escolhaValida = 1;                  // Define a escolha valida como '1', para quebrar o While
                break;
            case 'O':
                representacaoJogador = usuario;  // representacaoJogador é definido para '1'
                escolhaValida = 1;               // Define a escolha valida como '1', para quebrar o While
                break;
            case 'o':
                representacaoJogador = usuario;  // representacaoJogador é definido para '1'
                escolhaValida = 1;               // Define a escolha valida como '1', para quebrar o While
                break;
            default: {  // Exibe a mensagem de erro caso a entrada não seja x ou o
                printf("\033[0;31m");
                printf("\nOpção inválida! ");
                printf("\033[0;37m");
                printf("Por favor, insira novamente.\n\n");
                system("pause");
                getchar();  // Limpa o buffer da entrada invalida, evitando looping
            }
                system("cls");
        }
    }

    system("cls");
    int escolhaQuemComeca;    // Cria a variavel responsavel por guardar o valor de quem irá iniciar o jogo
    escolhaValida = 0;        // Limpa o valor de 'escolhaValida'
    while (!escolhaValida) {  // Faz um loop até que uma escolha válida seja feita
        printf("*****************************************\n");
        printf("*                                       *\n");
        printf("*  ");
        printf("\033[0;31m");
        printf("BEM-VINDO AO SUPER JOGO DA VELHA !!");
        printf("\033[0;37m");
        printf("  *\n");
        printf("*                                       *\n");
        printf("*****************************************\n");
        printf("Por favor, selecione quem irá começar o jogo:\n");
        printf("\033[0;32m");
        printf("1 - Usuário Inicia.\n");
        printf("\033[0;34m");
        printf("2 - Computador Inicia.\n");
        printf("\033[0;37m");
        printf("Resposta: ");
        scanf(" %d", &escolhaQuemComeca);  // Solicita a entrada do tipo de jogador e guarda na variavel 'escolhaTipoJogador'
        switch (escolhaQuemComeca) {       // Define a variavel 'escolhaQuemComeca', convertendo posteriormente no tabuleiro para a escolha do usuário
            case 1:
                quemComeca = usuario;  // Usuario irá iniciar o jogo
                escolhaValida = 1;     // Define a escolha valida como '1', para quebrar o While
                break;
            case 2:
                quemComeca = computador;  // Computador irá iniciar o jogo
                escolhaValida = 1;        // Define a escolha valida como '1', para quebrar o While
                break;
            default: {  // Exibe a mensagem de erro caso a entrada não seja 1 ou 2
                printf("\033[0;31m");
                printf("\nOpção inválida! ");
                printf("\033[0;37m");
                printf("Por favor, insira novamente.\n\n");
                system("pause");
                getchar();  // Limpa o buffer da entrada invalida, evitando looping
            }
                system("cls");
        }
    }
}

void jogadas() {                                        // Faz as jogadas até o jogo acabar
    while (quemComeca != 0) {                           // Se quem começa não for 0, o jogo continua
        if (!verificaVitoria()) {                       // Se não tiver vitoria, o jogo continua
            if (!verificaEmpate()) {                    // Se não tiver empate o jogo continua
                if (quemComeca == usuario) {            // Se 'quemComeça' for o usuario, chama a função 'usuarioJoga'
                    exibirJogo();                       // Exibe o tabuleiro
                    usuarioJoga();                      // Exibe o tabuleiro de jogada e computa a jogada do usuario
                } else if (quemComeca == computador) {  // Se 'quemComeça' for o computador, chama a função 'computadorJoga'
                    exibirJogo();                       // Exibe o tabuleiro
                    computadorJoga();                   // Computador faz a jogada
                }
            }
        }
    }
    exibirJogo();  // Caso o While seja quebrado, apenas exibe o tabuleiro (Fim de jogo)
}

void jogarNovamente() {  // Ao fim do jogo, pergunta se o usuario deseja jogar novamente
    system("cls");
    escolhaValida = 0;              // Limpa o valor de 'escolhaValida'
    int escolhaJogarNovamente = 0;  // Cria a variavel responsavel por guardar a opção escolhida pelo usuario
    while (!escolhaValida) {        // Faz um loop até que uma escolha válida seja feita
        printf("\033[0;31m");

        printf("**************************************************************\n");
        printf("*                                                            *\n");
        printf("*                     ");
        printf("\033[0;37m");
        printf("O JOGO TERMINOU!");
        printf("\033[0;31m");
        printf("                       *\n");
        printf("*                                                            *\n");
        printf("**************************************************************\n\n");
        printf("\033[0;37m");
        printf("Você quer jogar novamente?\n\n");
        printf("\033[0;32m");
        printf("1 - Jogar Novamente\n");
        printf("\033[0;31m");
        printf("2 - Sair\n\n");
        printf("\033[0;37m");
        printf("Resposta: ");
        scanf(" %d", &escolhaJogarNovamente);  // Solicita a entrada e guarda o valor na variavel 'escolhaJogarNovamente'
        switch (escolhaJogarNovamente) {       // Swith responsavel por quebrar o While
            case 1:
                escolhaJogarNovamente = 1;  // Faz o jogo reiniciar
                escolhaValida = 1;          // Quebra o While
                break;
            case 2:
                escolhaJogarNovamente = 0;  // Faz o jogo acabar
                escolhaValida = 1;          // Quebra o While
                break;
            default: {  // Exibe a mensagem de erro caso a entrada do usuario seja invalida
                printf("\033[0;31m");
                printf("\nOpção inválida! ");
                printf("\033[0;37m");
                printf("Por favor, insira novamente.\n\n");
                system("pause");
                getchar();  // Limpa o buffer da entrada invalida, evitando looping
            }
                system("cls");
        }
    }
    if (escolhaJogarNovamente == 1) {  // Se a escolha do usuario for jogar novamente, inicia o jogo mais uma vez
        systemset();                   // Limpa todas as variaveis globais, além de configurar o terminal
        iniciaJogo();                  // Inicia o jogo
        jogadas();                     // Faz as jogadas
        jogarNovamente();              // Ao fim do jogo, pergunta se o usuario quer jogar mais uma vez
    }
}

int main() {      // Inicia o jogo pela primeira vez
    systemset();  // Faz a configuração do terminal e define o valor das variaveis globais / tabuleiro
    printf("      ATENÇÃO: JOGO FEITO POR LUCAS AMARAL !!\n\n");
    system("pause");
    system("cls");
    iniciaJogo();      // Inicia o jogo
    jogadas();         // Faz as jogadas
    jogarNovamente();  // Ao fim do jogo, pergunta se o usuario quer jogar mais uma vez
    return 0;          // Retorna 0 ao fim do jogo
}