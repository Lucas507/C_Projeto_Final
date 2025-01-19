#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

// Função para centralizar o texto
int ecra_inicial(void) {
    char nome_jogo[] = {"Jogo da Limonada"};
    char texto[] = {"Pressione ENTER para continuar"};
    int tamanho_terminal = 120; // Tamanho do terminal
    int comprimento_nome_jogo = strlen(nome_jogo);
    int comprimento = strlen(texto);

    int espacos_titulo = (tamanho_terminal - comprimento_nome_jogo) / 2;

    // Imprimir o nome do jogo centralizado
    for (int i = 0; i < espacos_titulo; i++) {
        printf(" ");
    }
    printf("%s\n\n\n\n\n\n\n\n\n", nome_jogo);

    int espacos_texto = (tamanho_terminal - comprimento) / 2;

    // Imprimir o texto centralizado
    for (int i = 0; i < espacos_texto; i++) {
        printf(" ");
    }
    printf("%s", texto);

    getchar(); // Espera o ENTER
    return 0;
}

// Função para gerar eventos
int eventos(void) {
    return rand() % 4 + 1;
}

// Tabela de preços
void tabela_precos() {
    printf("Preço dos limões: 0.20€\n");
    printf("Preço do açúcar: 0.35€\n");
    printf("Preço da água: 0.10€\n");
}

// Função para determinar o tempo
int metereologia(void) {
    return rand() % 4 + 1;
}

// Função para calcular vendas de limonadas
int venda_limonadas(int limonadas, float chance1, float chance2) {
    int vendas_max = limonadas * (chance1 + chance2);
    if (vendas_max <= 0) return 0; // Prevenção de números negativos ou zero
    return rand() % vendas_max;
}

// Função para terminar o jogo
int game_over(char *jogador, int dia, float melhor_orcamento) {
    FILE *fptw = fopen("Scoreboard.txt", "r+");

    system("cls");

    fprintf(fptw, "Jogador: %s", jogador);
    fprintf(fptw, "\nÚltimo dia: %d", dia);
    fprintf(fptw, "Melhor Lucro: %f", melhor_orcamento);

    // Move o ponteiro para o início do arquivo
    rewind(fptw);

    // Lê e exibe os scores dos jogadores
    char ch1;
    while ((ch1 = fgetc(fptw)) != EOF) {
        putchar(ch1);
    }

    fclose(fptw);

    printf("\nPressione ENTER para continuar...");
    getchar();

    system("cls");

    execl("Projeto_Final", "Projeto_Final", NULL); // Substitui o processo atual pelo novo
}

int main(void) {
    char jogador[20];
    int limonadas, limoes = 0, agua = 0, acucar = 0, limoes_comprados = 0, agua_comprada = 0, acucar_comprado = 0, vendas, i;
    float preco, chance1 = 0.0, chance2 = 0.0, verificar_orcamento, orcamento = 20.0, melhor_orcamento = 0;
    bool fornecedor = true;

    FILE *fptr = fopen("Rules.txt", "r");
    if (!fptr) {
        printf("Erro ao abrir o arquivo Rules.txt\n");
        return 1;
    }

    ecra_inicial();

    system("chcp 65001");

    system("cls"); // Limpa a tela

    printf("Nome do jogador: ");
    scanf("%s", jogador); // Limita o nome para evitar estouro de buffer

    getchar(); // Consome o '\n' deixado no buffer

    system("cls");

    // Lê e exibe as regras do jogo
    char ch;
    while ((ch = fgetc(fptr)) != EOF) {
        putchar(ch);
    }
    fclose(fptr);

    printf("\nPressione ENTER para continuar...");
    getchar();

    system("cls");

    for (i = 1; orcamento > 0; i++) {

        // Determina o tempo e eventos do dia
        int tempo = metereologia();
        int evento = eventos();

        printf("Previsão do dia de amanhã:\n");
        switch (tempo) {
            case 1: printf("Tempo: Ensolarado\n"); chance1 = 0.5; break;
            case 2: printf("Tempo: Enublado\n"); chance1 = 0.3; break;
            case 3: printf("Tempo: Chuvoso\n"); chance1 = 0.25; break;
            case 4: printf("Tempo: Ventoso\n"); chance1 = 0.15; break;
        }
        switch (evento) {
            case 1: printf("Concerto (+50%% de chance de vendas)\n"); chance2 = 0.5; break;
            case 2: printf("Evento de jogos e animes (+50%% de chance de vendas)\n"); chance2 = 0.5; break;
            case 3: printf("Obras na rua (sem fornecedor)\n"); fornecedor = false; break;
            case 4: printf("Jogo de futebol (+25%% de chance de vendas)\n"); chance2 = 0.25; break;
        }

        printf("\nPressione ENTER para continuar...");
        getchar(); // Aguarda ENTER

        system("cls");

        printf("Dia %d\n", i);

        // Exibe a tabela de preços e permite compras
        if (fornecedor == true) {

            tabela_precos();
            printf("\nO teu Stock: ");
            printf("\nLimões: %d", limoes);
            printf("\nAçúcar: %d", acucar);
            printf("\nÁgua: %d", agua);

            printf("\nSaldo disponivel: %.2f€", orcamento);

            do {
                printf("\nQuantidade de limões a comprar: ");
                if (scanf("%d", &limoes_comprados) != 1 || limoes_comprados < 0) {
                    printf("\nIntroduza um número positivo");
                    getchar();
                    continue;
                }

                verificar_orcamento = orcamento - (limoes_comprados * 0.2);
                if (verificar_orcamento < limoes * 0.2) {
                    printf("\nSaldo insuficiente");
                    printf("\nSaldo atual: %.2f €", orcamento);
                    printf("\nCusto total: %.2f €", limoes_comprados * 0.2);
                    getchar();
                    continue;
                }

                break;
            }
            while (1);

            limoes += limoes_comprados;
            orcamento -= limoes_comprados * 0.2;

            system("cls");

            printf("Dia %d\n", i);

            tabela_precos();
            printf("\nO teu Stock: ");
            printf("\nLimões: %d", limoes);
            printf("\nAçúcar: %d", acucar);
            printf("\nÁgua: %d", agua);

            printf("\nSaldo disponivel: %.2f€", orcamento);

            do {
                printf("\nQuantidade de açúcar a comprar: ");
                if (scanf("%d", &acucar_comprado) != 1 || acucar_comprado < 0) {
                    printf("\nIntroduza um número positivo");
                    getchar();
                    continue;
                }

                verificar_orcamento = orcamento - (acucar_comprado * 0.35);
                if (verificar_orcamento < acucar_comprado * 0.35) {
                    printf("\nSaldo insuficiente");
                    printf("\nSaldo atual: %.2f €", orcamento);
                    printf("\nCusto total: %.2f €", acucar_comprado * 0.35);
                    getchar();
                    continue;
                }

                break;
            }
            while (1);

            acucar += acucar_comprado;
            orcamento -= acucar_comprado * 0.35;

            system("cls");

            printf("Dia %d\n", i);

            tabela_precos();
            printf("\nO teu Stock: ");
            printf("\nLimões: %d", limoes);
            printf("\nAçúcar: %d", acucar);
            printf("\nÁgua: %d", agua);

            printf("\nSaldo disponivel: %.2f", orcamento);

            do {
                printf("\nQuantidade de água a comprar: ");
                if (scanf("%d", &agua_comprada) != 1 || agua_comprada < 0) {
                    printf("\nIntroduza um número positivo");
                    getchar();
                    continue;
                }

                verificar_orcamento = orcamento - (agua_comprada * 0.1);
                if (verificar_orcamento < agua_comprada * 0.1) {
                    printf("\nSaldo insuficiente");
                    printf("\nSaldo atual: %.2f €", orcamento);
                    printf("\nCusto total: %.2f €", agua_comprada * 0.1);
                    getchar();
                    continue;
                }

                break;
            }
            while (1);

            agua += agua_comprada;
            orcamento -= agua_comprada * 0.1;

            system("cls");

            printf("Dia %d\n", i);

            printf("\nSaldo disponivel: %.2f €\n", orcamento);
            getchar();
        } else {
            printf("\nHoje o fornecedor não apareceu.");
            if (limoes < 0 || agua < 0 || acucar < 0)
                game_over(jogador,i,melhor_orcamento);
            else {
                printf("\nO teu Stock: ");
                printf("\nLimões: %d", limoes);
                printf("\nAçúcar: %d", acucar);
                printf("\nÁgua: %d", agua);
                fornecedor = true;
            }
        }

        printf("\nPressione ENTER para continuar...");
        getchar(); // Aguarda ENTER

        system("cls");

        printf("Dia %d\n", i);

        do {
            printf("\nQuantas limonadas queres vender? ");
            if (scanf("%d", &limonadas) != 1 || limonadas <= 0) {
                printf("Introduza um número positivo");
                getchar();
                continue;
            }

            if (limonadas > limoes || limonadas > agua || limonadas > acucar) {
                printf("\nStock insuficiente.");
                printf("\nO teu Stock: ");
                printf("\nLimões: %d", limoes);
                printf("\nAçúcar: %d", acucar);
                printf("\nÁgua: %d", agua);
                getchar();
                continue;
            }

            // Todas as condições foram atendidas, saímos do loop
            break;

        } while (1); // Loop infinito até atender as condições

        limoes -= limonadas;
        agua -= limonadas;
        acucar -= limonadas;

        printf("\nQual o preço por unidade? ");
        if (scanf("%f", &preco) != 1 || preco < 0) {
            printf("Introduza um número positivo\n");
            break;
        }

        // Calcula vendas e lucro
        vendas = venda_limonadas(limonadas, chance1, chance2);
        float lucro = vendas * (preco - (limonadas * 0.2) - (limonadas * 0.35) - (limonadas * 0.1));
        orcamento += lucro;

        printf("Foram vendidas %d limonadas.\n", vendas);
        printf("Lucro: %.2f €\n", lucro);
        printf("Saldo Total: %.2f €\n", orcamento);

        printf("\nPressione ENTER para continuar...");
        getchar(); // Limpa o buffer
        getchar(); // Aguarda ENTER

        system("cls");

        if (orcamento > melhor_orcamento)
            melhor_orcamento = orcamento;

        if (orcamento < 0.2 || orcamento < 0.35 || orcamento < 0.1) {
            printf("\nSem saldo suficiente");
            printf("\nPressione ENTER para continuar...");
            getchar(); // Aguarda ENTER
            break;
        }

    }
    game_over(jogador,i,melhor_orcamento);

    return 0;
}
