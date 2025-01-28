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
void tabela_precos(char *nome_limoes, float preco_limoes, char *nome_acucar, float preco_acucar, char *nome_agua, float preco_agua, char *nome_laranja, float preco_laranja, char *nome_ananas, float preco_ananas, char *nome_coco, float preco_coco, bool laranja_comprado, bool ananas_comprado, bool coco_comprado) {
    printf("Preço dos %s: %.2f€\n", nome_limoes, preco_limoes);
    printf("Preço do %s: %.2f€\n", nome_acucar, preco_acucar);
    printf("Preço da %s: %.2f€\n", nome_agua, preco_agua);
    if (laranja_comprado == true) {
        printf("Preço do %s: %.2f€\n", nome_laranja, preco_laranja);
    }
    if (coco_comprado == true) {
        printf("Preço da %s: %.2f€\n", nome_ananas, preco_ananas);
        printf("Preço do %s: %.2f€\n", nome_coco, preco_coco);
    }
}

// Função para mostrar o stock
void stock(int limoes, int acucar, int agua, int laranja, int ananas, int coco, bool laranja_comprado, bool ananas_comprado, bool coco_comprado) {
    printf("\nO teu Stock: ");
    printf("\nLimões: %d", limoes);
    printf("\nAçúcar: %d", acucar);
    printf("\nÁgua: %d", agua);
    if (laranja_comprado == true) {
        printf("\nLaranja: %d", laranja);
    }
    if (ananas_comprado == true) {
        printf("\nAnanás: %d", ananas);
        printf("\nCoco: %d", coco);
    }
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

// Função para calcular vendas de sumos de laranja
int venda_sumo_laranja(int sumo_laranja, float chance1, float chance2, float preco) {
    float chance_total = chance1 + chance2;
    int venda_sucedida = 0;

    if (preco > 2) {
        printf("Ninguém comprou nenhum sumo de laranja. Os clientes reclamaram que o preço é demasiado caro");
        printf("\n\nPressione ENTER para continuar...");
        limpar_buffer();
        getchar(); // Aguarda o ENTER
        system("cls"); // Limpa a tela após o ENTER
        return venda_sucedida;//retorna o valor das vendas sucedidas
    }

    //vai gerar um número random entre 0 e 1 e vai comparar se é menor do que a chance de venda, se for menor a venda é realizada
    for (int i = 0; i < sumo_laranja; i++) {
        float venda = (float)rand() / RAND_MAX;
        if (venda < chance_total) {
            venda_sucedida++;
        }
    }
    return venda_sucedida;//retorna o valor das vendas sucedidas
}

// Função para calcular vendas de sumos de ananas e coco
int venda_ananas_coco(int sumo_ananas, float chance1, float chance2, float preco) {
    float chance_total = chance1 + chance2;
    int venda_sucedida = 0;

    if (preco > 2.50) {
        printf("Ninguém comprou nenhum sumo de laranja. Os clientes reclamaram que o preço é demasiado caro");
        printf("\n\nPressione ENTER para continuar...");
        limpar_buffer();
        getchar(); // Aguarda o ENTER
        system("cls"); // Limpa a tela após o ENTER
        return venda_sucedida;//retorna o valor das vendas sucedidas
    }

    //vai gerar um número random entre 0 e 1 e vai comparar se é menor do que a chance de venda, se for menor a venda é realizada
    for (int i = 0; i < sumo_ananas; i++) {
        float venda = (float)rand() / RAND_MAX;
        if (venda < chance_total) {
            venda_sucedida++;
        }
    }
    return venda_sucedida;//retorna o valor das vendas sucedidas
}

// Função para ganhar o jogo(vitória)
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

void loja_extras(bool laranja, bool ananas_coco, bool marketing) {
    if (laranja == true && ananas_coco == true && marketing == true) {
        puts("----- Loja de Extras -----");
        puts("Chegaste ao 2º dia com o teu negócio, é hora de o expandires, para aumentares a visita e clientes e os teus lucros...");
        printf("1. Sumo de Laranja - Comprado\n");
        printf("2. Sumo de Ananás e Coco (+30%% de lucro) - Comprado\n");
        printf("3. Começar a fazer marketing digital (+50%% de clientes) - Comprado\n");
        printf("4. Não comprar nada!\n");
        printf("Por favor, escolhe uma opção acima (1-4): ");
    }
    else if (laranja == true && ananas_coco == true) {
        puts("----- Loja de Extras -----");
        puts("Chegaste ao 2º dia com o teu negócio, é hora de o expandires, para aumentares a visita e clientes e os teus lucros...");
        printf("1. Sumo de Laranja (+10%% de lucro) - Comprado\n");
        printf("2. Sumo de Ananás e Coco - Comprado\n");
        printf("3. Começar a fazer marketing digital (+50%% de clientes) - 50€\n");
        printf("4. Não comprar nada!\n");
        printf("Por favor, escolhe uma opção acima (1-4): ");
    }
    else if (laranja == true && marketing == true) {
        puts("----- Loja de Extras -----");
        puts("Chegaste ao 2º dia com o teu negócio, é hora de o expandires, para aumentares a visita e clientes e os teus lucros...");
        printf("1. Sumo de Laranja (+10%% de lucro) - Comprado\n");
        printf("2. Sumo de Ananás e Coco - 25€\n");
        printf("3. Começar a fazer marketing digital (+50%% de clientes) - Comprado\n");
        printf("4. Não comprar nada!\n");
        printf("Por favor, escolhe uma opção acima (1-4): ");
    }
    else if (marketing == true && ananas_coco == true) {
        puts("----- Loja de Extras -----");
        puts("É hora de o expandires, para aumentares a visita e clientes e os teus lucros...");
        printf("1. Sumo de Laranja (+10%% de lucro) - 15€\n");
        printf("2. Sumo de Ananás e Coco - Comprado\n");
        printf("3. Começar a fazer marketing digital (+50%% de clientes) - 50€\n");
        printf("4. Não comprar nada!\n");
        printf("Por favor, escolhe uma opção acima (1-4): ");
    }
    else if (laranja == true) {
        puts("----- Loja de Extras -----");
        puts("É hora de o expandires, para aumentares a visita e clientes e os teus lucros...");
        printf("1. Sumo de Laranja - Comprado\n");
        printf("2. Sumo de Ananás e Coco - 25€\n");
        printf("3. Começar a fazer marketing digital (+50%% de clientes) - 50€\n");
        printf("4. Não comprar nada!\n");
        printf("Por favor, escolhe uma opção acima (1-4): ");
    }
    else if (ananas_coco == true) {
        puts("----- Loja de Extras -----");
        puts("Chegaste ao 2º dia com o teu negócio, é hora de o expandires, para aumentares a visita e clientes e os teus lucros...");
        printf("1. Sumo de Laranja (+10%% de lucro) - 15€\n");
        printf("2. Sumo de Ananás e Coco (+30%% de lucro) - Comprado\n");
        printf("3. Começar a fazer marketing digital (+50%% de clientes) - 50€\n");
        printf("4. Não comprar nada!\n");
        printf("Por favor, escolhe uma opção acima (1-4): ");
    }
    else {
        puts("----- Loja de Extras -----");
        puts("Chegaste ao 2º dia com o teu negócio, é hora de o expandires, para aumentares a visita e clientes e os teus lucros...");
        printf("1. Sumo de Laranja (+10%% de lucro) - 15€\n");
        printf("2. Sumo de Ananás e Coco (+30%% de lucro) - 25€\n");
        printf("3. Começar a fazer marketing digital (+50%% de clientes) - 50€\n");
        printf("4. Não comprar nada!\n");
        printf("Por favor, escolhe uma opção acima (1-4): ");
    }
}

//Estrutura para criar os produtos necessarios para fazer uma bebida
struct Produtos {
    char nome_produto[20];
    float preco;
    int quantidade;
    bool comprado;
};

//Estrutura para criar os produtos necessarios para fazer uma bebida
struct Bebidas {
    char nome_bebida[20];
    float preco;
    int quantidade;
};

int main(void) {
    struct Produtos limoes, agua, acucar, coco, ananas, laranja;
    struct Bebidas limonada, sumo_laranja, ananas_coco;
    strcpy(limoes.nome_produto, "Limões");//Utilizamos o strcpy para passar o valor para limoes.nome_produto
    limoes.preco = 0.2;
    limoes.quantidade = 0;
    strcpy(acucar.nome_produto, "Açúcar");//Utilizamos o strcpy para passar o valor para acucar.nome_produto
    acucar.preco = 0.35;
    acucar.quantidade = 0;
    strcpy(agua.nome_produto, "Água");//Utilizamos o strcpy para passar o valor para agua.nome_produto
    agua.preco = 0.1;
    agua.quantidade = 0;
    strcpy(laranja.nome_produto, "Laranja");//Utilizamos o strcpy para passar o valor para agua.nome_produto
    laranja.preco = 0.2;
    laranja.quantidade = 0;
    laranja.comprado = false;
    strcpy(coco.nome_produto, "Coco");//Utilizamos o strcpy para passar o valor para agua.nome_produto
    coco.preco = 0.25;
    coco.quantidade = 0;
    coco.comprado = false;
    strcpy(ananas.nome_produto, "Ananás");//Utilizamos o strcpy para passar o valor para agua.nome_produto
    ananas.preco = 0.30;
    ananas.quantidade = 0;
    ananas.comprado = false;
    strcpy(limonada.nome_bebida, "Limonada");//Utilizamos o strcpy para passar o valor para agua.nome_produto
    limonada.quantidade = 0;
    strcpy(limonada.nome_bebida, "Sumo de laranja");//Utilizamos o strcpy para passar o valor para agua.nome_produto
    sumo_laranja.quantidade = 0;
    strcpy(limonada.nome_bebida, "Sumo de Ananás e Coco");//Utilizamos o strcpy para passar o valor para agua.nome_produto
    ananas_coco.quantidade = 0;
    char jogador[20];
    int limoes_comprados = 0, agua_comprada = 0, acucar_comprado = 0, vendas_limonada = 0, vendas_sumo_laranja = 0, vendas_ananas_coco = 0, laranjas_compradas, cocos_comprados, ananas_comprados, i;
    float lucro_do_dia = 0, lucro_limonada = 0, lucro_laranja = 0, lucro_coco_ananas = 0, lucro_total = 0, custo_por_unidade_limonada = limoes.preco + agua.preco + acucar.preco, custo_por_unidade_ananas = ananas.preco + coco.preco, chance1 = 0, chance2 = 0, verificar_orcamento, orcamento = 20;
    bool fornecedor = true, sem_stock = false, marketing = false;
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
                loja_extras(laranja.comprado, coco.comprado, marketing);
                scanf("%d", &escolha);
                limpar_buffer();

                switch (escolha) {
                    case 1:
                        if (laranja.comprado == true) {
                            printf("Já adquiriste sumo de laranja para o teu negócio.\n");
                            getchar();
                            continue;
                        }
                        if (orcamento <= 15) {
                            printf("Saldo insuficiente para comprar Sumo de Laranja.\n");
                            getchar();
                            continue;
                        }
                        if (orcamento >= 15) {
                            orcamento -= 15;
                            printf("Compraste sumo de laranja! O teu novo saldo é %.2f€\n", orcamento);
                            getchar();
                            laranja.comprado = true;
                        }
                        break;

                    case 2:
                        if (ananas.comprado == true) {
                            printf("Já adquiriste sumo de ananás e coco para o teu negócio.\n");
                            getchar();
                            continue;
                        }
                        if (orcamento <= 25) {
                            printf("Saldo insuficiente para comprar Sumo de Ananás e Coco.\n");
                            getchar();
                            continue;
                        }
                        if (orcamento >= 25) {
                            orcamento -= 25;
                            printf("Compraste sumo de ananás e coco! O teu novo saldo é %.2f€\n", orcamento);
                            getchar();
                            ananas.comprado = true;
                            coco.comprado = true;
                        }
                        break;

                    case 3:
                        if (marketing == true) {
                            printf("Já começaste a fazer marketing digital.\n");
                            getchar();
                            continue;
                        }
                        if (orcamento <= 50) {
                            printf("Saldo insuficiente para começar a fazer marketing digital.\n");
                            getchar();
                            continue;
                        }
                        if (orcamento >= 50) {
                            orcamento -= 50;
                            chance2 += chance2 + 0.50;
                            printf("Começaste a fazer marketing digital! O teu novo saldo é %.2f€\n", orcamento);
                            getchar();
                            marketing = true;
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

                break;
            }while (1);
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
            tabela_precos(limoes.nome_produto, limoes.preco, acucar.nome_produto, acucar.preco, agua.nome_produto, agua.preco, laranja.nome_produto, laranja.preco, ananas.nome_produto, ananas.preco, coco.nome_produto, coco.preco, laranja.comprado, ananas.comprado, coco.comprado);
            stock(limoes.quantidade,acucar.quantidade,agua.quantidade, laranja.quantidade, ananas.quantidade, coco.quantidade, laranja.comprado, ananas.comprado, coco.comprado);

            printf("\nSaldo disponivel: %.2f€", orcamento);


            do {
                printf("\nQuantidade de limões a comprar: ");
                if (scanf("%d", &limoes_comprados) != 1 || limoes_comprados < 0) {
                    printf("\nIntroduza um número positivo");
                    limpar_buffer();
                    getchar();
                    continue;
                }

                verificar_orcamento = orcamento - (limoes_comprados * limoes.preco);
                if (verificar_orcamento < limoes_comprados * limoes.preco) {
                    printf("\nSaldo insuficiente");
                    printf("\nSaldo atual: %.2f €", orcamento);
                    printf("\nCusto total: %.2f €", limoes_comprados * limoes.preco);
                    getchar();
                    continue;
                }

                break;
            } while (1);

            limoes.quantidade += limoes_comprados;
            orcamento -= limoes_comprados * limoes.preco;

            system("cls");

            printf("Dia %d\n", i);
            tabela_precos(limoes.nome_produto, limoes.preco, acucar.nome_produto, acucar.preco, agua.nome_produto, agua.preco, laranja.nome_produto, laranja.preco, ananas.nome_produto, ananas.preco, coco.nome_produto, coco.preco, laranja.comprado, ananas.comprado, coco.comprado);
            stock(limoes.quantidade,acucar.quantidade,agua.quantidade, laranja.quantidade, ananas.quantidade, coco.quantidade, laranja.comprado, ananas.comprado, coco.comprado);

            printf("\nSaldo disponivel: %.2f€", orcamento);

            do {
                printf("\nQuantidade de açúcar a comprar: ");
                if (scanf("%d", &acucar_comprado) != 1 || acucar_comprado < 0) {
                    printf("\nIntroduza um número positivo");
                    limpar_buffer();
                    getchar();
                    continue;
                }

                verificar_orcamento = orcamento - (acucar_comprado * acucar.preco);
                if (verificar_orcamento < acucar_comprado * acucar.preco) {
                    printf("\nSaldo insuficiente");
                    printf("\nSaldo atual: %.2f €", orcamento);
                    printf("\nCusto total: %.2f €", acucar_comprado * acucar.preco);
                    getchar();
                    continue;
                }

                break;
            } while (1);

            acucar.quantidade += acucar_comprado;
            orcamento -= acucar_comprado * acucar.preco;

            system("cls");

            printf("Dia %d\n", i);
            tabela_precos(limoes.nome_produto, limoes.preco, acucar.nome_produto, acucar.preco, agua.nome_produto, agua.preco, laranja.nome_produto, laranja.preco, ananas.nome_produto, ananas.preco, coco.nome_produto, coco.preco, laranja.comprado, ananas.comprado, coco.comprado);
            stock(limoes.quantidade,acucar.quantidade,agua.quantidade, laranja.quantidade, ananas.quantidade, coco.quantidade, laranja.comprado, ananas.comprado, coco.comprado);

            printf("\nSaldo disponivel: %.2f", orcamento);

            do {
                printf("\nQuantidade de água a comprar: ");
                if (scanf("%d", &agua_comprada) != 1 || agua_comprada < 0) {
                    printf("\nIntroduza um número positivo");
                    limpar_buffer();
                    getchar();
                    continue;
                }

                verificar_orcamento = orcamento - (agua_comprada * agua.preco);
                if (verificar_orcamento < agua_comprada * agua.preco) {
                    printf("\nSaldo insuficiente");
                    printf("\nSaldo atual: %.2f €", orcamento);
                    printf("\nCusto total: %.2f €", agua_comprada * agua.preco);
                    getchar();
                    continue;
                }

                break;
            } while (1);

            agua.quantidade += agua_comprada;
            orcamento -= agua_comprada * agua.preco;

            if (laranja.comprado == true) {
                system("cls");

                printf("Dia %d\n", i);
                tabela_precos(limoes.nome_produto, limoes.preco, acucar.nome_produto, acucar.preco, agua.nome_produto, agua.preco, laranja.nome_produto, laranja.preco, ananas.nome_produto, ananas.preco, coco.nome_produto, coco.preco, laranja.comprado, ananas.comprado, coco.comprado);
                stock(limoes.quantidade,acucar.quantidade,agua.quantidade, laranja.quantidade, ananas.quantidade, coco.quantidade, laranja.comprado, ananas.comprado, coco.comprado);

                printf("\nSaldo disponivel: %.2f", orcamento);

                do {
                    printf("\nQuantidade de laranjas a comprar: ");
                    if (scanf("%d", &laranjas_compradas) != 1 || laranjas_compradas < 0) {
                        printf("\nIntroduza um número positivo");
                        limpar_buffer();
                        getchar();
                        continue;
                    }

                    verificar_orcamento = orcamento - (laranjas_compradas * laranja.preco);
                    if (verificar_orcamento < laranjas_compradas * laranja.preco) {
                        printf("\nSaldo insuficiente");
                        printf("\nSaldo atual: %.2f €", orcamento);
                        printf("\nCusto total: %.2f €", laranjas_compradas * laranja.preco);
                        getchar();
                        continue;
                    }

                    break;
                } while (1);

                laranja.quantidade += laranjas_compradas;
                orcamento -= laranjas_compradas * laranja.preco;
            }

            if (ananas.comprado == true) {
                system("cls");

                printf("Dia %d\n", i);
                tabela_precos(limoes.nome_produto, limoes.preco, acucar.nome_produto, acucar.preco, agua.nome_produto, agua.preco, laranja.nome_produto, laranja.preco, ananas.nome_produto, ananas.preco, coco.nome_produto, coco.preco, laranja.comprado, ananas.comprado, coco.comprado);
                stock(limoes.quantidade,acucar.quantidade,agua.quantidade, laranja.quantidade, ananas.quantidade, coco.quantidade, laranja.comprado, ananas.comprado, coco.comprado);

                printf("\nSaldo disponivel: %.2f", orcamento);

                do {
                    printf("\nQuantidade de ananás a comprar: ");
                    if (scanf("%d", &ananas_comprados) != 1 || ananas_comprados < 0) {
                        printf("\nIntroduza um número positivo");
                        limpar_buffer();
                        getchar();
                        continue;
                    }

                    verificar_orcamento = orcamento - (ananas_comprados * ananas.preco);
                    if (verificar_orcamento < ananas_comprados * ananas.preco) {
                        printf("\nSaldo insuficiente");
                        printf("\nSaldo atual: %.2f €", orcamento);
                        printf("\nCusto total: %.2f €", ananas_comprados * ananas.preco);
                        getchar();
                        continue;
                    }

                    break;
                } while (1);

                ananas.quantidade += ananas_comprados;
                orcamento -= ananas_comprados * ananas.preco;

                system("cls");

                printf("Dia %d\n", i);
                tabela_precos(limoes.nome_produto, limoes.preco, acucar.nome_produto, acucar.preco, agua.nome_produto, agua.preco, laranja.nome_produto, laranja.preco, ananas.nome_produto, ananas.preco, coco.nome_produto, coco.preco, laranja.comprado, ananas.comprado, coco.comprado);
                stock(limoes.quantidade,acucar.quantidade,agua.quantidade, laranja.quantidade, ananas.quantidade, coco.quantidade, laranja.comprado, ananas.comprado, coco.comprado);

                printf("\nSaldo disponivel: %.2f", orcamento);

                do {
                    printf("\nQuantidade de coco a comprar: ");
                    if (scanf("%d", &cocos_comprados) != 1 || cocos_comprados < 0) {
                        printf("\nIntroduza um número positivo");
                        limpar_buffer();
                        getchar();
                        continue;
                    }

                    verificar_orcamento = orcamento - (cocos_comprados * coco.preco);
                    if (verificar_orcamento < cocos_comprados * coco.preco) {
                        printf("\nSaldo insuficiente");
                        printf("\nSaldo atual: %.2f €", orcamento);
                        printf("\nCusto total: %.2f €", cocos_comprados * coco.preco);
                        getchar();
                        continue;
                    }

                    break;
                } while (1);

                coco.quantidade += cocos_comprados;
                orcamento -= cocos_comprados * coco.preco;
            }

            system("cls");

            printf("Dia %d\n", i);

            printf("\nSaldo disponivel: %.2f €\n", orcamento);
            getchar();
        } else {
            printf("\nHoje o fornecedor não apareceu.");

            if (limoes.quantidade == 0 || acucar.quantidade == 0 || agua.quantidade == 0 || laranja.quantidade == 0 || ananas.quantidade == 0 || coco.quantidade == 0) {
                printf("\nSem stock suficiente.");
                getchar();
                game_over(jogador, i, lucro_total);
            } else {
                stock(limoes.quantidade,acucar.quantidade,agua.quantidade, laranja.quantidade, ananas.quantidade, coco.quantidade, laranja.comprado, ananas.comprado, coco.comprado);
                fornecedor = true;
            }
        }

        printf("\nPressione ENTER para continuar...");
        getchar();

        system("cls");

        printf("Dia %d\n", i);

        //venda de limonadas
        do {
            printf("\nQuantas limonadas queres vender? ");
            if (scanf("%d", &limonada.quantidade) != 1 || limonada.quantidade <= 0) {
                printf("Introduza um número positivo");
                limpar_buffer();
                getchar();
                continue;
            }

            if (limonada.quantidade > limoes.quantidade || limonada.quantidade > agua.quantidade || limonada.quantidade > acucar.quantidade) {
                printf("\nStock insuficiente.");
                stock(limoes.quantidade,acucar.quantidade,agua.quantidade, laranja.quantidade, ananas.quantidade, coco.quantidade, laranja.comprado, ananas.comprado, coco.comprado);
                getchar();
                continue;
            }

            break;

        } while (1);

        limoes.quantidade -= limonada.quantidade;
        agua.quantidade -= limonada.quantidade;
        acucar.quantidade -= limonada.quantidade;

        do {
            printf("\nQual o preço por unidade? ");

            if (scanf("%f", &limonada.preco) != 1 || limonada.preco < 0) {
                printf("Introduza um número positivo\n");
                limpar_buffer();
                getchar();
                continue;
            }

            break;
        }
        while (1);

        vendas_limonada = venda_limonadas(limonada.quantidade, chance1, chance2, limonada.preco);
        orcamento += (vendas_limonada * limonada.preco);

        printf("Dia %d\n", i);
        //venda sumo de laranja
        if (laranja.comprado == true && laranja.quantidade > 0) {
            do {
                system("cls");
                printf("\nQuantos sumos de laranja queres vender? ");
                if (scanf("%d", &sumo_laranja.quantidade) != 1 || sumo_laranja.quantidade <= 0) {
                    printf("Introduza um número positivo");
                    limpar_buffer();
                    getchar();
                    continue;
                }

                if (sumo_laranja.quantidade > laranja.quantidade) {
                    printf("\nStock insuficiente.");
                    stock(limoes.quantidade,acucar.quantidade,agua.quantidade, laranja.quantidade, ananas.quantidade, coco.quantidade, laranja.comprado, ananas.comprado, coco.comprado);
                    getchar();
                    continue;
                }

                break;

            } while (1);

            laranja.quantidade -= sumo_laranja.quantidade;

            do {
                printf("\nQual o preço por unidade? ");

                if (scanf("%f", &sumo_laranja.preco) != 1 || sumo_laranja.preco < 0) {
                    printf("Introduza um número positivo\n");
                    limpar_buffer();
                    getchar();
                    continue;
                }

                break;
            }
            while (1);

            vendas_sumo_laranja = venda_sumo_laranja(sumo_laranja.quantidade, chance1, chance2, sumo_laranja.preco);
            orcamento += (vendas_sumo_laranja * laranja.preco);
        }

        //venda de sumo de ananas e coco
        if ((ananas.comprado == true && ananas.quantidade > 0) && (coco.comprado == true && coco.quantidade > 0)) {
            do {
                system("cls");
                printf("\nQuantos sumos de ananás e coco queres vender? ");
                if (scanf("%d", &ananas_coco.quantidade) != 1 || ananas_coco.quantidade <= 0) {
                    printf("Introduza um número positivo");
                    limpar_buffer();
                    getchar();
                    continue;
                }

                if (ananas_coco.quantidade > ananas.quantidade || ananas_coco.quantidade > coco.quantidade) {
                    printf("\nStock insuficiente.");
                    stock(limoes.quantidade,acucar.quantidade,agua.quantidade, laranja.quantidade, ananas.quantidade, coco.quantidade, laranja.comprado, ananas.comprado, coco.comprado);
                    getchar();
                    continue;
                }

                break;

            } while (1);

            ananas.quantidade -= ananas_coco.quantidade;
            coco.quantidade -= ananas_coco.quantidade;

            do {
                printf("\nQual o preço por unidade? ");

                if (scanf("%f", &ananas_coco.preco) != 1 || ananas_coco.preco < 0) {
                    printf("Introduza um número positivo\n");
                    limpar_buffer();
                    getchar();
                    continue;
                }

                break;
            }
            while (1);

            vendas_ananas_coco = venda_ananas_coco(ananas_coco.quantidade, chance1, chance2, ananas_coco.preco);
            orcamento += (vendas_ananas_coco * ananas_coco.preco);
        }

        int desperdicio_limonada = limonada.quantidade - vendas_limonada;
        int desperdicio_laranja = limonada.quantidade - vendas_sumo_laranja;
        int desperdicio_coco_ananas = ananas_coco.quantidade - vendas_ananas_coco;

        lucro_limonada = ((limonada.preco - custo_por_unidade_limonada) * vendas_limonada) - (custo_por_unidade_limonada * desperdicio_limonada);

        printf("\nForam vendidas %d limonadas.", vendas_limonada);
        printf("\nDesperdiçaste %d limonadas.", desperdicio_limonada);
        if (sumo_laranja.quantidade > 0) {
            printf("\nForam vendidos %d sumos de laranja.", vendas_sumo_laranja);
            printf("\nDesperdiçaste %d sumos de laranja.", desperdicio_laranja);
            lucro_laranja = (laranja.preco * vendas_sumo_laranja) - (laranja.preco * desperdicio_laranja) * 0.1;
        }
        if (ananas_coco.quantidade > 0) {
            printf("\nForam vendidos %d sumos de ananás e coco.", vendas_sumo_laranja);
            printf("\nDesperdiçaste %d sumos de ananás e coco.", desperdicio_laranja);
            lucro_coco_ananas = ((ananas_coco.preco - custo_por_unidade_ananas) * vendas_ananas_coco) - (custo_por_unidade_ananas * desperdicio_coco_ananas) * 0.3;
        }
        lucro_do_dia = lucro_limonada + lucro_coco_ananas + lucro_laranja;
        lucro_total += lucro_do_dia;
        printf("\nLucro: %.2f €", lucro_do_dia);
        printf("\nSaldo Total: %.2f €\n", orcamento);
        stock(limoes.quantidade,acucar.quantidade,agua.quantidade, laranja.quantidade, ananas.quantidade, coco.quantidade, laranja.comprado, ananas.comprado, coco.comprado);

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
