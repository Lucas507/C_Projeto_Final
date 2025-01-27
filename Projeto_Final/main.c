#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

// Função para limpar o buffer de entrada
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para mostrar o ecra inicial e centrar o texto
int ecra_inicial(void) {
    char nome_jogo[] = {"Jogo da Limonada"};
    char texto[] = {"Pressione ENTER para continuar"};
    int tamanho_terminal = 120;
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
int eventos() {
    return rand() % 5;
}

// Tabela de preços
void tabela_precos(char *nome_limoes, float preco_limoes, char *nome_acucar, float preco_acucar, char *nome_agua, float preco_agua) {
    printf("Preço dos %s: %.2f€\n", nome_limoes, preco_limoes);
    printf("Preço do %s: %.2f€\n", nome_acucar, preco_acucar);
    printf("Preço da %s: %.2f€\n", nome_agua, preco_agua);
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
    return rand() % 4 + 1;//escolhe um número random de 1 a 4
}

// Função para calcular vendas de limonadas
int venda_limonadas(int limonadas, float chance1, float chance2, float preco) {
    float chance_total = chance1 + chance2;
    int venda_sucedida = 0;

    if (preco > 1.2) {
        printf("Ninguém comprou nenhuma limonada. Os clientes reclamaram que o preço é demasiado caro");
        fflush(stdout); // Garante que o texto é mostrado imediatamente
        printf("\n\nPressione ENTER para continuar...");
        limpar_buffer();
        getchar(); // Aguarda o ENTER
        system("cls"); // Limpa a tela após o ENTER
        return venda_sucedida;//retorna o valor das vendas sucedidas
    }

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
    getchar();

    FILE *fptw = fopen("Scoreboard.txt", "a+");

    if (!fptw) {
        printf("Erro ao abrir o arquivo Scoreboard.txt\n");
        return 1;
    }

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

// Função para terminar o jogo(derrota)
int game_over(char *jogador, int dia, float lucro_total) {
    system("cls");

    printf("Game Over\n");
    printf("\nPressione ENTER para continuar...");
    fflush(stdout); // Garante que a saída foi enviada antes do getchar
    getchar();

    FILE *fptw = fopen("Scoreboard.txt", "a+");

    if (!fptw) {
        printf("Erro ao abrir o arquivo Scoreboard.txt\n");
        return 1;
    }

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

//Estrutura para criar os produtos necessarios para fazer uma bebida
struct Produtos {
    char nome_produto[20];
    float preco;
    int quantidade;
};

void loja_extras() {
    puts("----- Loja de Extras -----");
    puts("Chegaste ao 2º dia com o teu negócio, é hora de o expandires, para aumentares a visita e clientes e os teus lucros...");
    printf("1. Sumo de Laranja (+10%% de lucro) - 25€\n");
    printf("2. Sumo de Ananás e Coco (+30%% de lucro) - 35€\n");
    printf("3. Começar a fazer marketing digital (+50%% de clientes) - 50€\n");
    printf("4. Não comprar nada!\n");
    printf("Por favor, escolhe uma opção acima (1-4): ");
}

int main(void) {
    struct Produtos limoes, agua, acucar, coco, ananas, laranja;
    strcpy(limoes.nome_produto, "Limões");//Utilizamos o strcpy para passar o valor para limoes.nome_produto
    limoes.preco = 0.2;
    limoes.quantidade = 0;
    strcpy(acucar.nome_produto, "Açúcar");//Utilizamos o strcpy para passar o valor para acucar.nome_produto
    acucar.preco = 0.35;
    acucar.quantidade = 0;
    strcpy(agua.nome_produto, "Água");//Utilizamos o strcpy para passar o valor para agua.nome_produto
    agua.preco = 0.1;
    agua.quantidade = 0;
    char jogador[20];
    int limonadas, limoes_comprados = 0, agua_comprada = 0, acucar_comprado = 0, vendas = 0, i;
    float lucro = 0, lucro_total = 0, preco, custo_por_unidade = 0.2 + 0.35 + 0.1, chance1 = 0, chance2 = 0, verificar_orcamento, orcamento = 20;
    bool fornecedor = true, sem_stock = false;
    int escolha;
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    FILE *fptr = fopen("Rules.txt", "r");
    if (!fptr) {
        printf("Erro ao abrir o arquivo Rules.txt\n");
        return 1;
    }

    ecra_inicial();

    system("chcp 65001");

    system("cls"); // Limpa a tela

    printf("Nome do jogador: ");
    fgets(jogador, 19, stdin); // Limita o nome para evitar estouro de buffer

    system("cls");

    // Lê e exibe as regras do jogo
    char ch;
    while ((ch = fgetc(fptr)) != EOF) {
        putchar(ch);
    }
    fclose(fptr);

    printf("\n\nPressione ENTER para continuar...");
    getchar();

    for (i = 1; (sem_stock == false) || (orcamento > 0.35); i++) {

        if (i >= 2) {
            do{
                system("cls");
                loja_extras();
                scanf("%d", &escolha);
                limpar_buffer();

                switch (escolha) {
                    case 1:
                        if (orcamento >= 25) {
                            orcamento -= 25;
                            lucro += 0.1;
                            printf("Compraste sumo de laranja! O teu novo saldo é %.2f€\n", orcamento);
                            getchar();
                        } else if (orcamento <= 25) {
                            printf("Saldo insuficiente para comprar Sumo de Laranja.\n");
                            getchar();
                        }
                        break;

                    case 2:
                        if (orcamento >= 35) {
                            orcamento -= 35;
                            lucro += 0.3;
                            printf("Compraste sumo de ananás e coco! O teu novo saldo é %.2f€\n", orcamento);
                            getchar();
                        } else if (orcamento <= 35) {
                            printf("Saldo insuficiente para comprar Sumo de Ananás e Coco.\n");
                            getchar();
                        }
                        break;

                    case 3:
                        if (orcamento >= 50) {
                            orcamento -= 50;
                            chance2 += chance2 + 0.50;
                            printf("Começaste a fazer marketing digital! O teu novo saldo é %.2f€\n", orcamento);
                            getchar();
                        } else if (orcamento <= 50) {
                            printf("Saldo insuficiente para começar a fazer marketing digital.\n");
                            getchar();
                        }
                        break;

                    case 4:
                        printf("Escolheste não comprar nada!");
                        getchar();
                        break;

                    default:
                        printf("Opção inválida. Por favor, tenta novamente");
                        getchar();
                        break;
                }
            }while (escolha != 1 && escolha != 2 && escolha != 3 && escolha != 4);
        }

        system("cls");

        if (i == 7) {
            vitoria(jogador, i, lucro_total);
        }

        int tempo = metereologia();
        int evento = eventos();

        printf("Previsão do dia de amanhã:\n");
        switch (tempo) {
            case 1: printf("Tempo: Ensolarado\n"); chance1 = 0.50; break;
            case 2: printf("Tempo: Nublado\n"); chance1 = 0.20; break;
            case 3: printf("Tempo: Chuvoso\n"); chance1 = 0.10; break;
            case 4: printf("Tempo: Ventoso\n"); chance1 = 0.15; break;
        }

        //Verifica se é o 1º dia, se for é retirado o evento de obras na rua para não causar game over
        if (i == 1) {
            switch (evento) {
                case 1: printf("Concerto de música (+35%% de chance de vendas)\n"); chance2 = 0.35; break;
                case 2: printf("Evento de jogos e animes (+50%% de chance de vendas)\n"); chance2 = 0.5; break;
                case 3: printf("Jogo de futebol (+25%% de chance de vendas)\n"); chance2 = 0.15; break;
                default: break;
            }
        }
        else {
            switch (evento) {
                case 1: printf("Concerto de música (+50%% de chance de vendas)\n"); chance2 = 0.35; break;
                case 2: printf("Evento de jogos e animes (+50%% de chance de vendas)\n"); chance2 = 0.5; break;
                case 3: printf("Obras na rua (sem fornecedor)\n"); fornecedor = false; break;
                case 4: printf("Jogo de futebol (+25%% de chance de vendas)\n"); chance2 = 0.15; break;
                default: break;
            }
        }

        printf("\nPressione ENTER para continuar...");
        getchar(); // Aguarda ENTER

        system("cls");

        printf("Dia %d\n", i);

        if (fornecedor == true) {
            tabela_precos(limoes.nome_produto, limoes.preco, acucar.nome_produto, acucar.preco, agua.nome_produto, agua.preco);
            stock(limoes.quantidade,acucar.quantidade,agua.quantidade);

            printf("\nSaldo disponivel: %.2f€", orcamento);

            do {
                printf("\nQuantidade de limões a comprar: ");
                if (scanf("%d", &limoes_comprados) != 1 || limoes_comprados < 0) {
                    printf("\nIntroduza um número positivo");
                    limpar_buffer();
                    getchar();
                    continue;
                }

                verificar_orcamento = orcamento - (limoes_comprados * 0.2);
                if (verificar_orcamento < limoes_comprados * limoes.preco) {
                    printf("\nSaldo insuficiente");
                    printf("\nSaldo atual: %.2f €", orcamento);
                    printf("\nCusto total: %.2f €", limoes_comprados * 0.2);
                    getchar();
                    continue;
                }

                break;
            } while (1);

            limoes.quantidade += limoes_comprados;
            orcamento -= limoes_comprados * 0.2;

            system("cls");

            printf("Dia %d\n", i);

            tabela_precos(limoes.nome_produto, limoes.preco, acucar.nome_produto, acucar.preco, agua.nome_produto, agua.preco);
            stock(limoes.quantidade,acucar.quantidade,agua.quantidade);

            printf("\nSaldo disponivel: %.2f€", orcamento);

            do {
                printf("\nQuantidade de açúcar a comprar: ");
                if (scanf("%d", &acucar_comprado) != 1 || acucar_comprado < 0) {
                    printf("\nIntroduza um número positivo");
                    limpar_buffer();
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
            } while (1);

            acucar.quantidade += acucar_comprado;
            orcamento -= acucar_comprado * 0.35;

            system("cls");

            printf("Dia %d\n", i);

            tabela_precos(limoes.nome_produto, limoes.preco, acucar.nome_produto, acucar.preco, agua.nome_produto, agua.preco);
            stock(limoes.quantidade,acucar.quantidade,agua.quantidade);

            printf("\nSaldo disponivel: %.2f", orcamento);

            do {
                printf("\nQuantidade de água a comprar: ");
                if (scanf("%d", &agua_comprada) != 1 || agua_comprada < 0) {
                    printf("\nIntroduza um número positivo");
                    limpar_buffer();
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
            } while (1);

            agua.quantidade += agua_comprada;
            orcamento -= agua_comprada * 0.1;

            system("cls");

            printf("Dia %d\n", i);

            printf("\nSaldo disponivel: %.2f €\n", orcamento);
            getchar();
        } else {
            printf("\nHoje o fornecedor não apareceu.");

            if (limoes.quantidade == 0 || acucar.quantidade == 0 || agua.quantidade == 0) {
                printf("\nSem stock suficiente.");
                getchar();
                game_over(jogador, i, lucro_total);
            } else {
                stock(limoes.quantidade,acucar.quantidade,agua.quantidade);
                fornecedor = true;
            }
        }

        printf("\nPressione ENTER para continuar...");
        getchar();

        system("cls");

        printf("Dia %d\n", i);

        do {
            printf("\nQuantas limonadas queres vender? ");
            if (scanf("%d", &limonadas) != 1 || limonadas <= 0) {
                printf("Introduza um número positivo");
                limpar_buffer();
                getchar();
                continue;
            }

            if (limonadas > limoes.quantidade || limonadas > agua.quantidade || limonadas > acucar.quantidade) {
                printf("\nStock insuficiente.");
                stock(limoes.quantidade,acucar.quantidade,agua.quantidade);
                getchar();
                continue;
            }

            break;

        } while (1);

        limoes.quantidade -= limonadas;
        agua.quantidade -= limonadas;
        acucar.quantidade -= limonadas;

        do {
            printf("\nQual o preço por unidade? ");

            if (scanf("%f", &preco) != 1 || preco < 0) {
                printf("Introduza um número positivo\n");
                limpar_buffer();
                getchar();
                continue;
            }

            break;
        }
        while (1);

        vendas = venda_limonadas(limonadas, chance1, chance2, preco);

        int desperdicio = limonadas - vendas;
        lucro = ((preco - custo_por_unidade) * vendas) - (custo_por_unidade * desperdicio);
        lucro_total += lucro;
        orcamento += (vendas * preco);

        printf("\nForam vendidas %d limonadas.", vendas);
        printf("\nDesperdiçaste %d limonadas.", desperdicio);
        printf("\nLucro: %.2f €", lucro);
        printf("\nSaldo Total: %.2f €\n", orcamento);
        stock(limoes.quantidade,acucar.quantidade,agua.quantidade);

        printf("\n\nPressione ENTER para continuar...");
        limpar_buffer();
        getchar();

        system("cls");

        //verifica se tem stock
        if (limoes.quantidade == 0 || acucar.quantidade == 0 || agua.quantidade == 0) {
            sem_stock = true;
        }
    }

    printf("\nSem saldo e stock suficiente");
    printf("\nPressione ENTER para continuar...");
    getchar();

    game_over(jogador, i, lucro_total);


    return 0;
}