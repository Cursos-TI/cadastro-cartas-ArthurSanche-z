#include <stdio.h>
#include <stdlib.h>

int main() {
   
  // Área para definição das variáveis para armazenar as propriedades das cidades
   
  // Declaração das Variáveis para a Carta 1 

    char  estado_carta1;
    char  codigo_carta1[5];       
    char  cidade_carta1[50];      
    int   populacao_carta1;
    float area_carta1;
    float pib_carta1;
    int   pontos_turisticos_carta1;
  // Variáveis para os resultados calculados
    float densidade_populacional1;
    float pib_per_capita1;

  // Declaração das Variáveis para a Carta 2 

    char  estado_carta2;
    char  codigo_carta2[5];
    char  cidade_carta2[50];
    int   populacao_carta2;
    float area_carta2;
    float pib_carta2;
    int   pontos_turisticos_carta2;
  // Variáveis para os resultados calculados
    float densidade_populacional2;
    float pib_per_capita2;

    // Área para entrada de dados

  // Seção de Entrada de Dados da Carta 1 
    
    printf(" Cadastro da Carta 1 \n");

    printf("Digite o Estado (A-H): \n");
    scanf(" %c", &estado_carta1); 

    printf("Digite o Codigo da Carta (ex: A01): \n");
    scanf("%s", codigo_carta1);

    printf("Digite o Nome da Cidade: \n");
    scanf("%s", cidade_carta1); 

    printf("Digite a Populacao: \n");
    scanf("%d", &populacao_carta1);

    printf("Digite a Area (em km2): \n");
    scanf("%f", &area_carta1);

    printf("Digite o PIB (em bilhoes): \n");
    scanf("%f", &pib_carta1);

    printf("Digite o Numero de Pontos Turisticos: \n");
    scanf("%d", &pontos_turisticos_carta1);

  // Seção de Entrada de Dados da Carta 2 
    
    printf("\n Cadastro da Carta 2 \n");

    printf("Digite o Estado (A-H): \n");
    scanf(" %c", &estado_carta2);

    printf("Digite o Codigo da Carta (ex: B02): \n");
    scanf("%s", codigo_carta2);

    printf("Digite o Nome da Cidade: \n");
    scanf("%s", cidade_carta2);

    printf("Digite a Populacao: \n");
    scanf("%d", &populacao_carta2);

    printf("Digite a Area (em km2): \n");
    scanf("%f", &area_carta2);

    printf("Digite o PIB (em bilhoes): \n");
    scanf("%f", &pib_carta2);

    printf("Digite o Numero de Pontos Turisticos: \n");
    scanf("%d", &pontos_turisticos_carta2);

  // Seção de Cálculos 

    // Cálculos para a Carta 1
  
  // A população é convertida para float para garantir a precisão na divisão.
      densidade_populacional1 = (float)populacao_carta1 / area_carta1;
  
  // O PIB é multiplicado por 1 bilhão para o cálculo per capita ser em reais.
    pib_per_capita1 = (pib_carta1 * 1000000000.0) / populacao_carta1;

  // Cálculos para a Carta 2
  
    densidade_populacional2 = (float)populacao_carta2 / area_carta2;
  
    pib_per_capita2 = (pib_carta2 * 1000000000.0) / populacao_carta2;

  // Área para exibição dos dados da cidade
    
    printf("\n\n DADOS FINAIS DAS CARTAS \n");

  // Exibição Completa da Carta 1
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado_carta1);
    printf("Codigo: %s\n", codigo_carta1);
    printf("Nome da Cidade: %s\n", cidade_carta1);
    printf("Populacao: %d\n", populacao_carta1);
    printf("Area: %.2f km2\n", area_carta1); 
    printf("PIB: %.2f bilhoes de reais\n", pib_carta1);
    printf("Numero de Pontos Turisticos: %d\n", pontos_turisticos_carta1);
  // Exibição dos dados calculados
    printf("Densidade Populacional: %.2f hab/km2\n", densidade_populacional1);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita1);

  // Exibição da Carta 2
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado_carta2);
    printf("Codigo: %s\n", codigo_carta2);
    printf("Nome da Cidade: %s\n", cidade_carta2);
    printf("Populacao: %d\n", populacao_carta2);
    printf("Area: %.2f km2\n", area_carta2);
    printf("PIB: %.2f bilhoes de reais\n", pib_carta2);
    printf("Numero de Pontos Turisticos: %d\n", pontos_turisticos_carta2);
  // Exibição dos novos dados calculados
    printf("Densidade Populacional: %.2f hab/km2\n", densidade_populacional2);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita2);

    return 0;
} 