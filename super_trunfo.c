#include <stdio.h>
#include <string.h>

// Definição da estrutura de uma carta
typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;       // população / área
} Carta;

// Função para calcular densidade demográfica
void calcular_densidade(Carta *c) {
    if (c->area > 0)
        c->densidade = c->populacao / c->area;
    else
        c->densidade = 0;
}

int main() {
    // Cadastro das duas cartas (já definido neste nível)
    Carta carta1 = {"Brasil", 215000000, 8515767.0, 2000.0, 100, 0};
    Carta carta2 = {"Argentina", 46000000, 2780000.0, 500.0, 80, 0};

    calcular_densidade(&carta1);
    calcular_densidade(&carta2);

    int opcao;

    // MENU INTERATIVO
    printf("===== MENU DE COMPARAÇÃO SUPER TRUNFO =====\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);

    printf("\nComparação entre %s e %s:\n", carta1.nome, carta2.nome);

    switch (opcao) {
        case 1:
            printf("Atributo: População\n");
            printf("%s: %d\n", carta1.nome, carta1.populacao);
            printf("%s: %d\n", carta2.nome, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: %s venceu!\n", carta1.nome);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Resultado: %s venceu!\n", carta2.nome);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2:
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", carta1.nome, carta1.area);
            printf("%s: %.2f km²\n", carta2.nome, carta2.area);
            if (carta1.area > carta2.area) {
                printf("Resultado: %s venceu!\n", carta1.nome);
            } else if (carta2.area > carta1.area) {
                printf("Resultado: %s venceu!\n", carta2.nome);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3:
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhões R$\n", carta1.nome, carta1.pib);
            printf("%s: %.2f bilhões R$\n", carta2.nome, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("Resultado: %s venceu!\n", carta1.nome);
            } else if (carta2.pib > carta1.pib) {
                printf("Resultado: %s venceu!\n", carta2.nome);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4:
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d\n", carta1.nome, carta1.pontosTuristicos);
            printf("%s: %d\n", carta2.nome, carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Resultado: %s venceu!\n", carta1.nome);
            } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
                printf("Resultado: %s venceu!\n", carta2.nome);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5:
            printf("Atributo: Densidade Demográfica\n");
            printf("%s: %.2f hab/km²\n", carta1.nome, carta1.densidade);
            printf("%s: %.2f hab/km²\n", carta2.nome, carta2.densidade);
            if (carta1.densidade < carta2.densidade) {
                printf("Resultado: %s venceu! (menor densidade)\n", carta1.nome);
            } else if (carta2.densidade < carta1.densidade) {
                printf("Resultado: %s venceu! (menor densidade)\n", carta2.nome);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default:
            printf("Opção inválida! Por favor, escolha entre 1 e 5.\n");
            break;
    }

    return 0;
}

