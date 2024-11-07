#include <stdio.h>

typedef struct {
    char estado[50];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} CartaCidade;

CartaCidade cadastrar_carta() {
    CartaCidade carta;

    printf("Digite o estado da cidade: ");
    scanf(" %[^\n]", carta.estado);
    printf("Digite o código da carta: ");
    scanf(" %[^\n]", carta.codigo);
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta.nome);
    printf("Digite a população: ");
    scanf("%d", &carta.populacao);
    printf("Digite a área (em km²): ");
    scanf("%f", &carta.area);
    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &carta.pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta.pontos_turisticos);

    return carta;
}


void exibir_detalhes(CartaCidade carta) {
    printf("\nCarta da Cidade: %s\n", carta.nome);
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
}

void comparar_cartas(CartaCidade carta1, CartaCidade carta2, int criterio) {
    printf("\nComparando as cartas de %s e %s\n", carta1.nome, carta2.nome);
    switch (criterio) {
        case 1: // População
            if (carta1.populacao > carta2.populacao)
                printf("A carta vencedora é: %s (População: %d)\n", carta1.nome, carta1.populacao);
            else if (carta2.populacao > carta1.populacao)
                printf("A carta vencedora é: %s (População: %d)\n", carta2.nome, carta2.populacao);
            else
                printf("Empate na população!\n");
            break;
        case 2: // Area 
            if (carta1.area > carta2.area)
                printf("A carta vencedora é: %s (Área: %.2f km²)\n", carta1.nome, carta1.area);
            else if (carta2.area > carta1.area)
                printf("A carta vencedora é: %s (Área: %.2f km²)\n", carta2.nome, carta2.area);
            else
                printf("Empate na área!\n");
            break;
        case 3: // PIB
            if (carta1.pib > carta2.pib)
                printf("A carta vencedora é: %s (PIB: %.2f bilhões)\n", carta1.nome, carta1.pib);
            else if (carta2.pib > carta1.pib)
                printf("A carta vencedora é: %s (PIB: %.2f bilhões)\n", carta2.nome, carta2.pib);
            else
                printf("Empate no PIB!\n");
            break;
        case 4: // Densidade Populacional
            if ((float)carta1.populacao / carta1.area < (float)carta2.populacao / carta2.area)
                printf("A carta vencedora é: %s (Menor Densidade Populacional)\n", carta1.nome);
            else if ((float)carta2.populacao / carta2.area < (float)carta1.populacao / carta1.area)
                printf("A carta vencedora é: %s (Menor Densidade Populacional)\n", carta2.nome);
            else
                printf("Empate na densidade populacional!\n");
            break;
        default:
            printf("Critério inválido.\n");
            break;
    }
}

int main() {
    printf("Cadastro da primeira carta:\n");
    CartaCidade carta1 = cadastrar_carta();

    printf("\nCadastro da segunda carta:\n");
    CartaCidade carta2 = cadastrar_carta();

    printf("\nCartas cadastradas:\n");
    exibir_detalhes(carta1);
    exibir_detalhes(carta2);

    int criterio;
    printf("\nEscolha o critério para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Populacional\n");
    printf("Digite o número do critério: ");
    scanf("%d", &criterio);

    comparar_cartas(carta1, carta2, criterio);

    return 0;
}
