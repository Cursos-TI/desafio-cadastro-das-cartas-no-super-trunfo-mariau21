#include <stdio.h>

int main(){

char estado;
char codigo[50];
char nome [50];
int populacao;
float area;
float pib;
int pontos;
char unidade;
char code[50];
char cidade[50];
int pessoas;
float tamanho;
float capital;
int turisticos;


printf("Digite o estado: \n");
scanf("%c", &estado);

printf("Digite o codigo: \n");
scanf("%s", &codigo);

printf("Digite o nome da cidade: \n");
scanf("%s", &nome);

printf("Digite a população: \n");
scanf("%d", &populacao);

printf("Digite a área: \n");
scanf("%f", &area);

printf("Digite o PIB: \n");
scanf("%f", &pib);

printf("Digite o numero de pontos turísticos: \n");
scanf("%d", &pontos);

printf("Digite o estado: \n");
scanf("%c", &unidade);

printf("Digite o codigo: \n");
scanf("%s", &code);
    
printf("Digite o nome da cidade: \n");
scanf("%s", &cidade);

printf("Digite a população: \n");
scanf("%d", &pessoas);

printf("Digite a área: \n");
scanf("%f", &tamanho);

printf("Digite o PIB: \n");
scanf("%f", &capital);

printf("Digite o numero de pontos turísticos: \n");
scanf("%d", &turisticos);


printf("Carta 1 \n");
printf("Estado: %c - Codigo: %s \n", estado, codigo);
printf("Nome da cidade: %s - População: %d \n", nome, populacao);
printf("Área da cidade: %f - PIB da cidade: %f \n", area, pib);
printf("Pontos turísticos: %d \n", pontos);

printf("Carta 2 \n");
printf("Estado: %c - Codigo: %s \n", unidade, code);
printf("Nome da cidade: %s - População: %d \n", cidade, pessoas);
printf("Área da cidade: %f - PIB da cidade: %f \n", tamanho, capital);
printf("Pontos turísticos: %d", turisticos);

return 0;

}