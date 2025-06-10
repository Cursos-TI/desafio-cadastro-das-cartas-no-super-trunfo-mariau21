#include <stdio.h>
#include <string.h>

#define NUM_CARTAS 2
#define BILHAO 1000000000.0f   // 1 bilhão em reais

typedef struct {
    /* Dados digitados pelo usuário */
    char  estado;                  // 'A'-'H'
    char  codigo[4];               // “A01” … “H04”
    char  nome[100];               // Nome da cidade
    int   populacao;               // Habitantes
    float area;                    // km²
    float pibBilhoes;              // PIB (em bilhões de reais)
    int   pontosTuristicos;

    /* Dados calculados */
    float densidade;               // hab/km²
    float pibPerCapita;            // reais
} Carta;

int main(void) {
    Carta cartas[NUM_CARTAS];

    /* ---------- Leitura ---------- */
    for (int i = 0; i < NUM_CARTAS; ++i) {
        printf("=== Carta %d ===\n", i + 1);

        printf("Estado (A-H): ");
        scanf(" %c", &cartas[i].estado);

        printf("Código (ex.: A01): ");
        scanf(" %3s", cartas[i].codigo);

        getchar();                                    // limpa '\n'

        printf("Nome da Cidade: ");
        fgets(cartas[i].nome, sizeof(cartas[i].nome), stdin);
        cartas[i].nome[strcspn(cartas[i].nome, "\n")] = '\0';

        printf("População: ");
        scanf("%d", &cartas[i].populacao);

        printf("Área (km²): ");
        scanf("%f", &cartas[i].area);

        printf("PIB (em bilhões de R$): ");
        scanf("%f", &cartas[i].pibBilhoes);

        printf("Número de Pontos Turísticos: ");
        scanf("%d", &cartas[i].pontosTuristicos);

        getchar();                                    // limpa '\n'

        /* ---------- Cálculos ---------- */
        if (cartas[i].area > 0)
            cartas[i].densidade = cartas[i].populacao / cartas[i].area;
        else
            cartas[i].densidade = 0.0f;

        /* converte PIB de “bilhões” → reais antes de dividir */
        float pibReais = cartas[i].pibBilhoes * BILHAO;
        if (cartas[i].populacao > 0)
            cartas[i].pibPerCapita = pibReais / cartas[i].populacao;
        else
            cartas[i].pibPerCapita = 0.0f;

        putchar('\n');
    }

    /* ---------- Exibição ---------- */
    for (int i = 0; i < NUM_CARTAS; ++i) {
        printf("Carta %d:\n", i + 1);
        printf("Estado: %c\n", cartas[i].estado);
        printf("Código: %s\n", cartas[i].codigo);
        printf("Nome da Cidade: %s\n", cartas[i].nome);
        printf("População: %d\n", cartas[i].populacao);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("PIB: %.2f bilhões de reais\n", cartas[i].pibBilhoes);
        printf("Número de Pontos Turísticos: %d\n", cartas[i].pontosTuristicos);
        printf("Densidade Populacional: %.2f hab/km²\n", cartas[i].densidade);
        printf("PIB per Capita: %.2f reais\n\n", cartas[i].pibPerCapita);
    }

    return 0;
}
