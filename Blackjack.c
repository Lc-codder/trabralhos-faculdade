#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CARDS 52
#define MAX_NAME_LENGTH 50

// Estrutura para representar uma carta
typedef struct {
    char *face;
    char *naipe;
    int valor;
} Carta;

// Funções
void inicializarBaralho(Carta baralho[]);
void embaralharBaralho(Carta baralho[]);
int puxarCarta(Carta baralho[], int *indiceAtual, int *numAses);
void exibirCarta(Carta carta);
int calcularValorComAs(int soma, int numAses);
void exibirBemVindo(char nomeJogador[]);
void exibirRegras();

int main() {
    Carta baralho[MAX_CARDS];
    int indiceBaralho = 0;
    int jogadorSoma = 0, dealerSoma = 0;
    int jogadorNumAses = 0, dealerNumAses = 0;
    char escolha;
    char nomeJogador[MAX_NAME_LENGTH];

    srand(time(0));  // Semente para gerar números aleatórios

    // Inicializando o baralho
    inicializarBaralho(baralho);
    embaralharBaralho(baralho);

    // Entrada do nome do jogador
    printf("Digite seu nome: ");
    fgets(nomeJogador, MAX_NAME_LENGTH, stdin);
    nomeJogador[strcspn(nomeJogador, "\n")] = 0;  // Remove o '\n' da entrada do jogador

    exibirBemVindo(nomeJogador);
    exibirRegras();

    // Puxar cartas para o jogador e para o dealer
    jogadorSoma += puxarCarta(baralho, &indiceBaralho, &jogadorNumAses);
    jogadorSoma += puxarCarta(baralho, &indiceBaralho, &jogadorNumAses);
    dealerSoma += puxarCarta(baralho, &indiceBaralho, &dealerNumAses);

    // Mostrar cartas do jogador
    printf("\n%s, suas cartas somam: %d\n", nomeJogador, jogadorSoma);

    // Jogador decide se quer puxar mais cartas
    while (jogadorSoma < 21) {
        printf("\nDeseja puxar mais uma carta? (s/n): ");
        scanf(" %c", &escolha);

        if (escolha == 's' || escolha == 'S') {
            jogadorSoma += puxarCarta(baralho, &indiceBaralho, &jogadorNumAses);
            jogadorSoma = calcularValorComAs(jogadorSoma, jogadorNumAses);  // Ajusta valor se houver Ás
            printf("Agora suas cartas somam: %d\n", jogadorSoma);
        } else {
            break;
        }
    }

    // Verificar se o jogador estourou
    if (jogadorSoma > 21) {
        printf("\n%s, você estourou com %d! O dealer vence.\n", nomeJogador, jogadorSoma);
        return 0;
    }

    // Jogada do dealer
    printf("\nDealer está puxando suas cartas...\n");
    while (dealerSoma < 17) {
        dealerSoma += puxarCarta(baralho, &indiceBaralho, &dealerNumAses);
        dealerSoma = calcularValorComAs(dealerSoma, dealerNumAses);  // Ajusta valor se houver Ás
    }

    // Exibir resultado final
    printf("\nAs cartas do dealer somam: %d\n", dealerSoma);
    if (dealerSoma > 21 || jogadorSoma > dealerSoma) {
        printf("Parabéns, %s! Você venceu!\n", nomeJogador);
    } else if (jogadorSoma == dealerSoma) {
        printf("Empate! Jogo equilibrado.\n");
    } else {
        printf("Dealer venceu! Mais sorte na próxima, %s.\n", nomeJogador);
    }

    return 0;
}

void inicializarBaralho(Carta baralho[]) {
    char *faces[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    char *naipes[] = {"Copas", "Ouros", "Paus", "Espadas"};
    int valores[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
    int contador = 0;

    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            baralho[contador].face = faces[i];
            baralho[contador].naipe = naipes[j];
            baralho[contador].valor = valores[i];
            contador++;
        }
    }
}

void embaralharBaralho(Carta baralho[]) {
    for (int i = 0; i < MAX_CARDS; i++) {
        int r = rand() % MAX_CARDS;
        Carta temp = baralho[i];
        baralho[i] = baralho[r];
        baralho[r] = temp;
    }
}

int puxarCarta(Carta baralho[], int *indiceAtual, int *numAses) {
    Carta carta = baralho[*indiceAtual];
    (*indiceAtual)++;
    exibirCarta(carta);
    if (strcmp(carta.face, "A") == 0) {
        (*numAses)++;  // Contar o Ás
    }
    return carta.valor;
}

void exibirCarta(Carta carta) {
    printf("Carta puxada: %s de %s\n", carta.face, carta.naipe);
}

int calcularValorComAs(int soma, int numAses) {
    while (soma > 21 && numAses > 0) {
        soma -= 10;  // Ajustar Ás de 11 para 1
        numAses--;
    }
    return soma;
}

void exibirBemVindo(char nomeJogador[]) {
    printf("\n==============================\n");
    printf("Bem-vindo ao Blackjack, %s!\n", nomeJogador);
    printf("==============================\n");
}

void exibirRegras() {
    printf("\nRegras do jogo:\n");
    printf("1. O objetivo é somar 21 pontos ou o mais próximo disso, sem ultrapassar.\n");
    printf("2. As cartas de 2 a 10 valem o número da face.\n");
    printf("3. J, Q, K valem 10 pontos.\n");
    printf("4. O Ás vale 11, mas pode ser ajustado para 1 se necessário.\n");
    printf("5. Você competirá contra o dealer, que para em 17 ou mais.\n");
    printf("Boa sorte!\n");
}

