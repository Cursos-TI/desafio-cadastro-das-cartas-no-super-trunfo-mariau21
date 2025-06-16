#include <stdio.h>
#include <string.h>

#define NUM_CARTAS 2
#define BILHAO 1000000000.0f

typedef struct {
    char estado;
    char codigo[4];
    char nome[100];
    unsigned long int populacao;
    float area;
    float pibBilhoes;
    int pontosTuristicos;

    // Cálculos
    float densidade;
    float pibPerCapita;
    float superPoder;
} Carta;

void calcular_dados(Carta *c) {
    if (c->area > 0)
        c->densidade = c->populacao / c->area;
    else
        c->densidade = 0.0f;

    float pibReais = c->pibBilhoes * BILHAO;
    if (c->populacao > 0)
        c->pibPerCapita = pibReais / c->populacao;
    else
        c->pibPerCapita = 0.0f;

    // Inverso da densidade: quanto menor a densidade, maior o poder.
    float inversoDensidade = c->densidade > 0 ? 1.0f / c->densidade : 0.0f;

    c->superPoder = (float)c->populacao +
                    c->area +
                    (c->pibBilhoes * BILHAO) +
                    (float)c->pontosTuristicos +
                    c->pibPerCapita +
                    inversoDensidade;
}

int main(void) {
    Carta cartas[NUM_CARTAS];

    // Leitura
    for (int i = 0; i < NUM_CARTAS; ++i) {
        printf("=== Carta %d ===\n", i + 1);

        printf("Estado (A-H): ");
        scanf(" %c", &cartas[i].estado);

        printf("Código (ex.: A01): ");
        scanf(" %3s", cartas[i].codigo);

        getchar(); // limpar \n

        printf("Nome da Cidade: ");
        fgets(cartas[i].nome, sizeof(cartas[i].nome), stdin);
        cartas[i].nome[strcspn(cartas[i].nome, "\n")] = '\0';

        printf("População: ");
        scanf("%lu", &cartas[i].populacao);

        printf("Área (km²): ");
        scanf("%f", &cartas[i].area);

        printf("PIB (em bilhões de R$): ");
        scanf("%f", &cartas[i].pibBilhoes);

        printf("Número de Pontos Turísticos: ");
        scanf("%d", &cartas[i].pontosTuristicos);

        calcular_dados(&cartas[i]);

        putchar('\n');
    }

    // Exibição das cartas
    for (int i = 0; i < NUM_CARTAS; ++i) {
        printf("Carta %d:\n", i + 1);
        printf("Estado: %c\n", cartas[i].estado);
        printf("Código: %s\n", cartas[i].codigo);
        printf("Nome da Cidade: %s\n", cartas[i].nome);
        printf("População: %lu\n", cartas[i].populacao);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("PIB: %.2f bilhões de reais\n", cartas[i].pibBilhoes);
        printf("Número de Pontos Turísticos: %d\n", cartas[i].pontosTuristicos);
        printf("Densidade Populacional: %.2f hab/km²\n", cartas[i].densidade);
        printf("PIB per Capita: %.2f reais\n", cartas[i].pibPerCapita);
        printf("Super Poder: %.2f\n", cartas[i].superPoder);
        printf("\n");
    }

    // Comparações
    printf("Comparação de Cartas:\n\n");

    printf("População: Carta 1 venceu (%d)\n", cartas[0].populacao > cartas[1].populacao);
    printf("Área: Carta 1 venceu (%d)\n", cartas[0].area > cartas[1].area);
    printf("PIB: Carta 1 venceu (%d)\n", cartas[0].pibBilhoes > cartas[1].pibBilhoes);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", cartas[0].pontosTuristicos > cartas[1].pontosTuristicos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", cartas[0].densidade < cartas[1].densidade); // menor vence
    printf("PIB per Capita: Carta 1 venceu (%d)\n", cartas[0].pibPerCapita > cartas[1].pibPerCapita);
    printf("Super Poder: Carta 1 venceu (%d)\n", cartas[0].superPoder > cartas[1].superPoder);

    return 0;
}
