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

    fflush(stdout); // Garante que a saída foi enviada antes do getchar
    getchar(); // Espera o ENTER
    return 0;
}

// Função para gerar eventos
int eventos(void) {
    return rand() % 5;
}

// Tabela de preços
void tabela_precos() {
    printf("Preço dos limões: 0.20€\n");
    printf("Preço do açúcar: 0.35€\n");
    printf("Preço da água: 0.10€\n");
}

// Função para mostrar o stock
void stock(int limoes, int acucar, int agua) {
    printf("\nO teu Stock: ");
    printf("\nLimões: %d", limoes);
    printf("\nAçúcar: %d", acucar);
    printf("\nÁgua: %d", agua);
}

// Função para determinar o tempo
int metereologia(void) {
    return rand() % 4 + 1;
}

// Função para calcular vendas de limonadas
int venda_limonadas(int limonadas, float chance1, float chance2) {
    float chance_total = chance1 + chance2;
    int venda_sucedida = 0;
    //vai gerar um número random entre 0 e 1 e vai comparar se é menor do que a chance de venda, se for menor a venda é realizada
    for (int i = 0; i < limonadas; i++) {
        float venda = (float)rand() / RAND_MAX;
        if (venda < chance_total) {
            venda_sucedida++;
        }
    }
    return venda_sucedida;//retorna o valor das vendas sucedidas
}

// Função para terminar o jogo(vitória)
int vitoria(char *jogador, int dia, float lucro_total) {
    system("cls");

    printf("Ganhaste\n");
    printf("\nPressione ENTER para continuar...");
    fflush(stdout); // Garante que a saída foi enviada antes do getchar
    getchar();

    FILE *fptw = fopen("Scoreboard.txt", "a+");

    system("cls");

    fprintf(fptw, "\n\nJogador: %s", jogador);
    fprintf(fptw, "\nÚltimo dia: %d", dia);
    fprintf(fptw, "\nMelhor Lucro: %.2f", lucro_total);

    // Move o ponteiro para o início do arquivo
    rewind(fptw);

    // Lê e exibe os scores dos jogadores
    char ch1;
    while ((ch1 = fgetc(fptw)) != EOF) {
        putchar(ch1);
    }

    fclose(fptw);

    printf("\nPressione ENTER para continuar...");
    fflush(stdout); // Garante que a saída foi enviada antes do getchar
    getchar();

    system("cls");

    execl("Projeto_Final", "Projeto_Final", NULL); // Substitui o processo atual pelo novo
}

// Função para terminar o jogo(derrota)
int game_over(char *jogador, int dia, float lucro_total) {
    system("cls");

    printf("Game Over\n");
    printf("\nPressione ENTER para continuar...");
    fflush(stdout); // Garante que a saída foi enviada antes do getchar
    getchar();

    FILE *fptw = fopen("Scoreboard.txt", "a+");

    system("cls");

    fprintf(fptw, "\n\nJogador: %s", jogador);
    fprintf(fptw, "\nÚltimo dia: %d", dia);
    fprintf(fptw, "\nLucro Total: %.2f", lucro_total);

    // Move o ponteiro para o início do arquivo
    rewind(fptw);

    // Lê e exibe os scores dos jogadores
    char ch1;
    while ((ch1 = fgetc(fptw)) != EOF) {
        putchar(ch1);
    }

    fclose(fptw);

    printf("\nPressione ENTER para continuar...");
    fflush(stdout); // Garante que a saída foi enviada antes do getchar
    getchar();

    system("cls");

    execl("Projeto_Final", "Projeto_Final", NULL); // Substitui o processo atual pelo novo
}

int main(void) {
    char jogador[20];
    int limonadas, limoes = 0, agua = 0, acucar = 0, limoes_comprados = 0, agua_comprada = 0, acucar_comprado = 0, vendas, i;
    float lucro_total, preco, custo_por_unidade = 0.2 + 0.35 + 0.1, chance1, chance2 = 0.0, verificar_orcamento, orcamento = 20.0;
    bool fornecedor = true, sem_stock = false;

    FILE *fptr = fopen("Rules.txt", "r");
    if (!fptr) {
        printf("Erro ao abrir o arquivo Rules.txt\n");
        return 1;
    }

    ecra_inicial();

    system("chcp 65001");

    system("cls"); // Limpa a tela

    printf("Nome do jogador: ");
    fflush(stdout); // Garante que a saída foi enviada antes do getchar
    scanf("%s", jogador); // Limita o nome para evitar estouro de buffer

    getchar(); // Consome o '\n' deixado no buffer

    system("cls");

    // Lê e exibe as regras do jogo
    char ch;
    while ((ch = fgetc(fptr)) != EOF) {
        putchar(ch);
    }
    fclose(fptr);

    printf("\n\nPressione ENTER para continuar...");
    fflush(stdout); // Garante que a saída foi enviada antes do getchar
    getchar();

    system("cls");

    for (i = 1; (sem_stock == false) || (orcamento > 0.35); i++) {

        if (i == 7) {
            vitoria(jogador, i, lucro_total);
        }

        int tempo = metereologia();
        int evento = eventos();

        printf("Previsão do dia de amanhã:\n");
        switch (tempo) {
            case 1: printf("Tempo: Ensolarado\n"); chance1 = 0.50; break;
            case 2: printf("Tempo: Enublado\n"); chance1 = 0.20; break;
            case 3: printf("Tempo: Chuvoso\n"); chance1 = 0.10; break;
            case 4: printf("Tempo: Ventoso\n"); chance1 = 0.15; break;
        }
        switch (evento) {
            case 1: printf("Concerto (+50%% de chance de vendas)\n"); chance2 = 0.35; break;
            case 2: printf("Evento de jogos e animes (+50%% de chance de vendas)\n"); chance2 = 0.5; break;
            case 3: printf("Obras na rua (sem fornecedor)\n"); fornecedor = false; break;
            case 4: printf("Jogo de futebol (+25%% de chance de vendas)\n"); chance2 = 0.15; break;
            default: break;
        }

        printf("\nPressione ENTER para continuar...");
        fflush(stdout);
        getchar(); // Aguarda ENTER

        system("cls");

        printf("Dia %d\n", i);

        if (fornecedor == true) {
            tabela_precos();
            stock(limoes,acucar,agua);

            printf("\nSaldo disponivel: %.2f€", orcamento);

            do {
                printf("\nQuantidade de limões a comprar: ");
                fflush(stdout);
                if (scanf("%d", &limoes_comprados) != 1 || limoes_comprados < 0) {
                    printf("\nIntroduza um número positivo");
                    fflush(stdout);
                    getchar();
                    continue;
                }

                verificar_orcamento = orcamento - (limoes_comprados * 0.2);
                if (verificar_orcamento < limoes * 0.2) {
                    printf("\nSaldo insuficiente");
                    printf("\nSaldo atual: %.2f €", orcamento);
                    printf("\nCusto total: %.2f €", limoes_comprados * 0.2);
                    fflush(stdout);
                    getchar();
                    continue;
                }

                break;
            } while (1);

            limoes += limoes_comprados;
            orcamento -= limoes_comprados * 0.2;

            system("cls");

            printf("Dia %d\n", i);

            tabela_precos();
            stock(limoes,acucar,agua);

            printf("\nSaldo disponivel: %.2f€", orcamento);

            do {
                printf("\nQuantidade de açúcar a comprar: ");
                fflush(stdout);
                if (scanf("%d", &acucar_comprado) != 1 || acucar_comprado < 0) {
                    printf("\nIntroduza um número positivo");
                    fflush(stdout);
                    getchar();
                    continue;
                }

                verificar_orcamento = orcamento - (acucar_comprado * 0.35);
                if (verificar_orcamento < acucar_comprado * 0.35) {
                    printf("\nSaldo insuficiente");
                    printf("\nSaldo atual: %.2f €", orcamento);
                    printf("\nCusto total: %.2f €", acucar_comprado * 0.35);
                    fflush(stdout);
                    getchar();
                    continue;
                }

                break;
            } while (1);

            acucar += acucar_comprado;
            orcamento -= acucar_comprado * 0.35;

            system("cls");

            printf("Dia %d\n", i);

            tabela_precos();
            stock(limoes,acucar,agua);

            printf("\nSaldo disponivel: %.2f", orcamento);

            do {
                printf("\nQuantidade de água a comprar: ");
                fflush(stdout);
                if (scanf("%d", &agua_comprada) != 1 || agua_comprada < 0) {
                    printf("\nIntroduza um número positivo");
                    fflush(stdout);
                    getchar();
                    continue;
                }

                verificar_orcamento = orcamento - (agua_comprada * 0.1);
                if (verificar_orcamento < agua_comprada * 0.1) {
                    printf("\nSaldo insuficiente");
                    printf("\nSaldo atual: %.2f €", orcamento);
                    printf("\nCusto total: %.2f €", agua_comprada * 0.1);
                    fflush(stdout);
                    getchar();
                    continue;
                }

                break;
            } while (1);

            agua += agua_comprada;
            orcamento -= agua_comprada * 0.1;

            system("cls");

            printf("Dia %d\n", i);

            printf("\nSaldo disponivel: %.2f €\n", orcamento);
            fflush(stdout);
            getchar();
        } else {
            printf("\nHoje o fornecedor não apareceu.");

            if (limoes == 0 || acucar == 0 || agua == 0) {
                printf("\nSem stock suficiente.");
                fflush(stdout);
                game_over(jogador, i, lucro_total);
            } else {
                stock(limoes,acucar,agua);
                fornecedor = true;
            }
        }

        printf("\nPressione ENTER para continuar...");
        fflush(stdout);
        getchar();

        system("cls");

        printf("Dia %d\n", i);

        do {
            printf("\nQuantas limonadas queres vender? ");
            fflush(stdout);
            if (scanf("%d", &limonadas) != 1 || limonadas <= 0) {
                printf("Introduza um número positivo");
                fflush(stdout);
                getchar();
                continue;
            }

            if (limonadas > limoes || limonadas > agua || limonadas > acucar) {
                printf("\nStock insuficiente.");
                stock(limoes,acucar,agua);
                fflush(stdout);
                getchar();
                continue;
            }

            break;

        } while (1);

        limoes -= limonadas;
        agua -= limonadas;
        acucar -= limonadas;

        printf("\nQual o preço por unidade? ");
        fflush(stdout);

        if (scanf("%f", &preco) != 1 || preco < 0) {
            printf("Introduza um número positivo\n");
            fflush(stdout);
            break;
        }

        vendas = venda_limonadas(limonadas, chance1, chance2);

        int desperdicio = limonadas - vendas;
        float lucro = ((preco - custo_por_unidade) * vendas) - (custo_por_unidade * desperdicio);
        lucro_total += lucro;
        orcamento += (vendas * preco);

        printf("\nForam vendidas %d limonadas.", vendas);
        printf("\nDesperdiçaste %d limonadas.", desperdicio);
        printf("\nLucro: %.2f €", lucro);
        printf("\nSaldo Total: %.2f €\n", orcamento);
        stock(limoes,acucar,agua);

        printf("\n\nPressione ENTER para continuar...");
        fflush(stdout);
        getchar();
        getchar();

        system("cls");

        if (limoes == 0 || acucar == 0 || agua == 0) {
            sem_stock = true;
        }
    }

    printf("\nSem saldo ou stock suficiente");
    printf("\nPressione ENTER para continuar...");
    fflush(stdout);
    getchar();

    game_over(jogador, i, lucro_total);

    return 0;
}
