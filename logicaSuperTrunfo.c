#include <stdio.h>
#include <string.h>


struct CartaCidade {
    char estado[50];
    int codigo;
    char nome[100];
    long long populacao;
    double area;
    long long pib;
    int pontosTuristicos;
};


void exibirCarta(struct CartaCidade carta) {
    printf("\n--- Dados da Carta: %s ---\n", carta.nome);
    printf("Estado: %s\n", carta.estado);
    printf("Codigo da Carta: %d\n", carta.codigo);
    printf("Populacao: %lld habitantes\n", carta.populacao);
    printf("Area: %.2f km2\n", carta.area);
    printf("PIB: %lld\n", carta.pib);
    printf("Pontos Turisticos: %d\n", carta.pontosTuristicos);
}

int main() {
    struct CartaCidade carta1, carta2;
    int escolha;
    
    printf("=== Cadastro da Primeira Carta ===\n");
    printf("Estado: ");
    scanf("%s", carta1.estado);
    printf("Codigo da Carta: ");
    scanf("%d", &carta1.codigo);
    printf("Nome da Cidade: ");
    scanf("%s", carta1.nome);
    printf("Populacao: ");
    scanf("%lld", &carta1.populacao);
    printf("Area (km2): ");
    scanf("%lf", &carta1.area);
    printf("PIB: ");
    scanf("%lld", &carta1.pib);
    printf("Pontos Turisticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    printf("\n=== Cadastro da Segunda Carta ===\n");
    printf("Estado: ");
    scanf("%s", carta2.estado);
    printf("Codigo da Carta: ");
    scanf("%d", &carta2.codigo);
    printf("Nome da Cidade: ");
    scanf("%s", carta2.nome);
    printf("Populacao: ");
    scanf("%lld", &carta2.populacao);
    printf("Area (km2): ");
    scanf("%lf", &carta2.area);
    printf("PIB: ");
    scanf("%lld", &carta2.pib);
    printf("Pontos Turisticos: ");
    scanf("%d", &carta2.pontosTuristicos);
    
    
    printf("\n--- Escolha o Atributo para Comparar ---\n");
    printf("1 - Populacao (Menor valor vence)\n");
    printf("2 - Area (Maior valor vence)\n");
    printf("3 - PIB (Maior valor vence)\n");
    printf("4 - Pontos Turisticos (Maior valor vence)\n");
    printf("Escolha (1-4): ");
    scanf("%d", &escolha);
    
    printf("\n\n--- Resultados da Comparacao ---\n");

    if (escolha == 1) {
        printf("Atributo escolhido: Populacao\n");
        if (carta1.populacao < carta2.populacao) { 
            printf("A carta vencedora e: %s\n", carta1.nome);
        } else if (carta2.populacao < carta1.populacao) {
            printf("A carta vencedora e: %s\n", carta2.nome);
        } else {
            printf("As cartas tem a mesma populacao. Empate!\n");
        }
    } else if (escolha == 2) {
        printf("Atributo escolhido: Area\n");
        if (carta1.area > carta2.area) { 
            printf("A carta vencedora e: %s\n", carta1.nome);
        } else if (carta2.area > carta1.area) {
            printf("A carta vencedora e: %s\n", carta2.nome);
        } else {
            printf("As cartas tem a mesma area. Empate!\n");
        }
    } else if (escolha == 3) {
        printf("Atributo escolhido: PIB\n");
        if (carta1.pib > carta2.pib) { 
            printf("A carta vencedora e: %s\n", carta1.nome);
        } else if (carta2.pib > carta1.pib) {
            printf("A carta vencedora e: %s\n", carta2.nome);
        } else {
            printf("As cartas tem o mesmo PIB. Empate!\n");
        }
    } else if (escolha == 4) {
        printf("Atributo escolhido: Pontos Turisticos\n");
        if (carta1.pontosTuristicos > carta2.pontosTuristicos) { 
            printf("A carta vencedora e: %s\n", carta1.nome);
        } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
            printf("A carta vencedora e: %s\n", carta2.nome);
        } else {
            printf("As cartas tem o mesmo numero de pontos turisticos. Empate!\n");
        }
    } else {
        printf("Escolha invalida. O programa sera encerrado.\n");
    }

    exibirCarta(carta1);
    exibirCarta(carta2);

    return 0;
}