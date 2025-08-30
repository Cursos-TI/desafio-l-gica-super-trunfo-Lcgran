#include <stdio.h>
#include <string.h>

// Definição da estrutura da carta do Super Trunfo
struct Carta {
    char estado[3];
    char codigo[10];
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
};

// Protótipo da função de comparação
void compararCartas(struct Carta carta1, struct Carta carta2, const char* atributo_escolhido);

int main() {

    printf("Desafio Novato!\n");
    printf("Novo commit\n");
    // Declaração e inicialização dos dados das duas cartas pré-definidas
    struct Carta carta1;
    strcpy(carta1.estado, "SP");
    strcpy(carta1.codigo, "SP-01");
    strcpy(carta1.nome_cidade, "Sao Paulo");
    carta1.populacao = 12396372;
    carta1.area = 1521.11;
    carta1.pib = 763.8;
    carta1.pontos_turisticos = 25;

    struct Carta carta2;
    strcpy(carta2.estado, "RJ");
    strcpy(carta2.codigo, "RJ-01");
    strcpy(carta2.nome_cidade, "Rio de Janeiro");
    carta2.populacao = 6775561;
    carta2.area = 1200.25;
    carta2.pib = 370.4;
    carta2.pontos_turisticos = 30;

    // Calcular densidade populacional e PIB per capita para ambas as cartas
    carta1.densidade_populacional = (float)carta1.populacao / carta1.area;
    carta1.pib_per_capita = carta1.pib / (float)carta1.populacao;
    
    carta2.densidade_populacional = (float)carta2.populacao / carta2.area;
    carta2.pib_per_capita = carta2.pib / (float)carta2.populacao;

    // Escolha do atributo para a comparação (modifique esta linha para escolher outro atributo)
    const char* atributo_para_comparar = "Densidade Populacional";
    
    // Chamada da função para comparar as cartas
    compararCartas(carta1, carta2, atributo_para_comparar);

    return 0;
}

/**
 * Função para comparar duas cartas com base em um atributo numérico.
 * @param carta1 Dados da primeira carta.
 * @param carta2 Dados da segunda carta.
 * @param atributo_escolhido O nome do atributo para a comparação.
 */
void compararCartas(struct Carta carta1, struct Carta carta2, const char* atributo_escolhido) {
    printf("Comparacao de cartas (Atributo: %s):\n\n", atributo_escolhido);

    // Variáveis para armazenar os valores e o vencedor
    float valor1 = 0.0;
    float valor2 = 0.0;
    const char* nome_vencedor = NULL;

    // Lógica para determinar qual atributo comparar e obter os valores
    if (strcmp(atributo_escolhido, "População") == 0) {
        valor1 = (float)carta1.populacao;
        valor2 = (float)carta2.populacao;
        if (valor1 > valor2) {
            nome_vencedor = carta1.nome_cidade;
        } else if (valor2 > valor1) {
            nome_vencedor = carta2.nome_cidade;
        }
    } else if (strcmp(atributo_escolhido, "Area") == 0) {
        valor1 = carta1.area;
        valor2 = carta2.area;
        if (valor1 > valor2) {
            nome_vencedor = carta1.nome_cidade;
        } else if (valor2 > valor1) {
            nome_vencedor = carta2.nome_cidade;
        }
    } else if (strcmp(atributo_escolhido, "PIB") == 0) {
        valor1 = carta1.pib;
        valor2 = carta2.pib;
        if (valor1 > valor2) {
            nome_vencedor = carta1.nome_cidade;
        } else if (valor2 > valor1) {
            nome_vencedor = carta2.nome_cidade;
        }
    } else if (strcmp(atributo_escolhido, "Pontos Turisticos") == 0) {
        valor1 = (float)carta1.pontos_turisticos;
        valor2 = (float)carta2.pontos_turisticos;
        if (valor1 > valor2) {
            nome_vencedor = carta1.nome_cidade;
        } else if (valor2 > valor1) {
            nome_vencedor = carta2.nome_cidade;
        }
    } else if (strcmp(atributo_escolhido, "Densidade Populacional") == 0) {
        valor1 = carta1.densidade_populacional;
        valor2 = carta2.densidade_populacional;
        // Regra especial: menor valor vence
        if (valor1 < valor2) {
            nome_vencedor = carta1.nome_cidade;
        } else if (valor2 < valor1) {
            nome_vencedor = carta2.nome_cidade;
        }
    } else if (strcmp(atributo_escolhido, "PIB per capita") == 0) {
        valor1 = carta1.pib_per_capita;
        valor2 = carta2.pib_per_capita;
        if (valor1 > valor2) {
            nome_vencedor = carta1.nome_cidade;
        } else if (valor2 > valor1) {
            nome_vencedor = carta2.nome_cidade;
        }
    } else {
        printf("Atributo de comparacao invalido.\n");
        return;
    }

    // Exibir os valores das cartas para o atributo escolhido
    printf("Carta 1 - %s (%s): %.2f\n", carta1.nome_cidade, carta1.estado, valor1);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.nome_cidade, carta2.estado, valor2);

    // Exibir o resultado final da comparação
    if (nome_vencedor != NULL) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nome_vencedor);
    } else {
        printf("Resultado: Empate!\n");
    }
}
