#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Necessário para strcpy (copiar strings)


int main(void) {

    //  1. Definição dos Dados das Cartas (Pré-definidas) 
    // Carta 1: Brasil
    char  pais_carta1[] = "Brasil";
    unsigned long int populacao_carta1 = 215300000;
    float area_carta1 = 8516000.0;
    float pib_carta1 = 1.608; // Em trilhões de Reais
    int   pontos_turisticos_carta1 = 150;
    float densidade_demografica1;

    // Carta 2: Argentina
    char  pais_carta2[] = "Argentina";
    unsigned long int populacao_carta2 = 45810000;
    float area_carta2 = 2780000.0;
    float pib_carta2 = 0.487; // Em trilhões de Reais
    int   pontos_turisticos_carta2 = 80;
    float densidade_demografica2;

    //  2. Cálculos Iniciais 
    densidade_demografica1 = (float)populacao_carta1 / area_carta1;
    densidade_demografica2 = (float)populacao_carta2 / area_carta2;

    //  3. Normalização de "Scores" 
    // Para que a SOMA funcione, todos os atributos devem seguir a regra
    // "maior é melhor". Invertemos a densidade (1/valor) para que
    // uma densidade MENOR resulte em um score MAIOR.
    float score_pop1 = (float)populacao_carta1;
    float score_area1 = area_carta1;
    float score_pib1 = pib_carta1;
    float score_turismo1 = (float)pontos_turisticos_carta1;
    float score_densidade1 = 1.0f / densidade_demografica1; // Score Invertido

    float score_pop2 = (float)populacao_carta2;
    float score_area2 = area_carta2;
    float score_pib2 = pib_carta2;
    float score_turismo2 = (float)pontos_turisticos_carta2;
    float score_densidade2 = 1.0f / densidade_demografica2; // Score Invertido

    //  4. Variáveis para Armazenar Escolhas 
    int escolha1 = 0;
    int escolha2 = 0;

    // Variáveis para os scores (usados no cálculo)
    float attr1_score_c1 = 0.0, attr1_score_c2 = 0.0;
    float attr2_score_c1 = 0.0, attr2_score_c2 = 0.0;

    // Variáveis para os valores originais (usados na exibição)
    float attr1_display_c1 = 0.0, attr1_display_c2 = 0.0;
    float attr2_display_c1 = 0.0, attr2_display_c2 = 0.0;
    
    // Variáveis para os nomes e unidades dos atributos
    char attr1_nome[50], attr2_nome[50];
    char attr1_unidade[20], attr2_unidade[20];


    //  5. Menu 1: Escolha do Primeiro Atributo (switch) 
    printf("--- SUPER TRUNFO - ESCOLHA O ATRIBUTO 1 ---\n");
    printf("Cartas: %s vs %s\n", pais_carta1, pais_carta2);
    printf("--------------------------------------------\n");
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB (em trilhoes de USD)\n");
    printf("4. Pontos Turisticos\n");
    printf("5. Densidade Demografica (menor vence)\n");
    printf("--------------------------------------------\n");
    printf("Digite sua escolha (1-5): ");
    scanf("%d", &escolha1);

    // Armazena os valores do Atributo 1
    switch (escolha1) {
        case 1:
            attr1_score_c1 = score_pop1; attr1_score_c2 = score_pop2;
            attr1_display_c1 = (float)populacao_carta1; attr1_display_c2 = (float)populacao_carta2;
            strcpy(attr1_nome, "Populacao"); strcpy(attr1_unidade, "hab");
            break;
        case 2:
            attr1_score_c1 = score_area1; attr1_score_c2 = score_area2;
            attr1_display_c1 = area_carta1; attr1_display_c2 = area_carta2;
            strcpy(attr1_nome, "Area"); strcpy(attr1_unidade, "km2");
            break;
        case 3:
            attr1_score_c1 = score_pib1; attr1_score_c2 = score_pib2;
            attr1_display_c1 = pib_carta1; attr1_display_c2 = pib_carta2;
            strcpy(attr1_nome, "PIB"); strcpy(attr1_unidade, "trilhoes R$");
            break;
        case 4:
            attr1_score_c1 = score_turismo1; attr1_score_c2 = score_turismo2;
            attr1_display_c1 = (float)pontos_turisticos_carta1; attr1_display_c2 = (float)pontos_turisticos_carta2;
            strcpy(attr1_nome, "Pontos Turisticos"); strcpy(attr1_unidade, "pontos");
            break;
        case 5:
            attr1_score_c1 = score_densidade1; attr1_score_c2 = score_densidade2;
            attr1_display_c1 = densidade_demografica1; attr1_display_c2 = densidade_demografica2;
            strcpy(attr1_nome, "Densidade Demografica"); strcpy(attr1_unidade, "hab/km2");
            break;
        default:
            printf("Opcao invalida. Fim do programa.\n");
            return 1; // Encerra o programa com código de erro
    }


    //  6. Menu 2: Escolha do Segundo Atributo (Dinâmico com Ternário) 
    printf("\n--- SUPER TRUNFO - ESCOLHA O ATRIBUTO 2 ---\n");
    printf("Atributo 1 ja escolhido: %s\n", attr1_nome);
    printf("--------------------------------------------\n");
    
    // Uso do Operador Ternário (condição ? se_verdadeiro : se_falso)
    // Se 'escolha1' NÃO for 1, imprime a opção 1. Senão, não imprime nada ("").
    printf(escolha1 != 1 ? "1. Populacao\n" : "");
    printf(escolha1 != 2 ? "2. Area\n" : "");
    printf(escolha1 != 3 ? "3. PIB (em trilhoes de R$)\n" : "");
    printf(escolha1 != 4 ? "4. Pontos Turisticos\n" : "");
    printf(escolha1 != 5 ? "5. Densidade Demografica (menor vence)\n" : "");
    printf("--------------------------------------------\n");
    printf("Digite sua escolha (nao pode ser %d): ", escolha1);
    scanf("%d", &escolha2);

    //  7. Validação da Escolha 2 
    if (escolha2 == escolha1) {
        printf("\nErro: Voce nao pode escolher o mesmo atributo duas vezes. Fim do programa.\n");
        return 1;
    }

    // Armazena os valores do Atributo 2
    switch (escolha2) {
        case 1:
            attr2_score_c1 = score_pop1; attr2_score_c2 = score_pop2;
            attr2_display_c1 = (float)populacao_carta1; attr2_display_c2 = (float)populacao_carta2;
            strcpy(attr2_nome, "Populacao"); strcpy(attr2_unidade, "hab");
            break;
        case 2:
            attr2_score_c1 = score_area1; attr2_score_c2 = score_area2;
            attr2_display_c1 = area_carta1; attr2_display_c2 = area_carta2;
            strcpy(attr2_nome, "Area"); strcpy(attr2_unidade, "km2");
            break;
        case 3:
            attr2_score_c1 = score_pib1; attr2_score_c2 = score_pib2;
            attr2_display_c1 = pib_carta1; attr2_display_c2 = pib_carta2;
            strcpy(attr2_nome, "PIB"); strcpy(attr2_unidade, "trilhoes R$");
            break;
        case 4:
            attr2_score_c1 = score_turismo1; attr2_score_c2 = score_turismo2;
            attr2_display_c1 = (float)pontos_turisticos_carta1; attr2_display_c2 = (float)pontos_turisticos_carta2;
            strcpy(attr2_nome, "Pontos Turisticos"); strcpy(attr2_unidade, "pontos");
            break;
        case 5:
            attr2_score_c1 = score_densidade1; attr2_score_c2 = score_densidade2;
            attr2_display_c1 = densidade_demografica1; attr2_display_c2 = densidade_demografica2;
            strcpy(attr2_nome, "Densidade Demografica"); strcpy(attr2_unidade, "hab/km2");
            break;
        default:
            printf("Opcao invalida. Fim do programa.\n");
            return 1;
    }

    //  8. Cálculo da Soma 
    float soma_carta1 = attr1_score_c1 + attr2_score_c1;
    float soma_carta2 = attr1_score_c2 + attr2_score_c2;

    //  9. Exibição Detalhada e Comparação Final (if-else) 
    printf("\n\n======================================\n");
    printf("--- RESULTADO FINAL DA RODADA ---\n");
    printf("======================================\n");
    printf("Cartas: %s vs %s\n", pais_carta1, pais_carta2);
    printf("--------------------------------------\n");

    // %g é um formato "inteligente": imprime números grandes sem decimais
    // e números pequenos com decimais.
    printf("Atributo 1: %s\n", attr1_nome);
    printf("   > %s: %g %s\n", pais_carta1, attr1_display_c1, attr1_unidade);
    printf("   > %s: %g %s\n", pais_carta2, attr1_display_c2, attr1_unidade);

    printf("\nAtributo 2: %s\n", attr2_nome);
    printf("   > %s: %g %s\n", pais_carta1, attr2_display_c1, attr2_unidade);
    printf("   > %s: %g %s\n", pais_carta2, attr2_display_c2, attr2_unidade);
    printf("--------------------------------------\n");
    
    printf("--- CALCULO DA SOMA DOS SCORES ---\n");
    printf("(Nota: Para a soma, Densidade Demografica usa um score invertido (1/valor))\n");
    printf("Soma %s (Score 1 + Score 2): %g\n", pais_carta1, soma_carta1);
    printf("Soma %s (Score 1 + Score 2): %g\n", pais_carta2, soma_carta2);
    printf("--------------------------------------\n");

    // Lógica de decisão aninhada (if-else if-else) para o resultado final
    if (soma_carta1 > soma_carta2) {
        printf("VENCEDOR DA RODADA: %s!\n", pais_carta1);
    } else if (soma_carta2 > soma_carta1) {
        printf("VENCEDOR DA RODADA: %s!\n", pais_carta2);
    } else {
        printf("VENCEDOR DA RODADA: Empate!\n");
    }
    printf("======================================\n");

    return 0; // Fim do programa
} 
