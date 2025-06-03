#include <stdio.h>

#define MAX_ESTRELAS 1000000

long long int carneiros[MAX_ESTRELAS];
int atacadas[MAX_ESTRELAS];

int main() {
    int N;

    printf("Digite o número de estrelas (máx %d): ", MAX_ESTRELAS);
    scanf("%d", &N);

    if (N > MAX_ESTRELAS) {
        printf("Número de estrelas excede o limite permitido.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        printf("Digite a quantidade de carneiros na Estrela %d: ", i + 1);
        scanf("%lld", &carneiros[i]);
        atacadas[i] = 0;
    }

    int pos = 0;

    while (pos >= 0 && pos < N) {
        long long int atual = carneiros[pos];

        if (carneiros[pos] > 0) {
            carneiros[pos]--;
        }

        if (atacadas[pos] == 0) {
            atacadas[pos] = 1;
        }

        if (atual % 2 == 0) {
            pos--;
        } else {
            pos++;
        }
    }

    int estrelasAtacadas = 0;
    long long int carneirosRestantes = 0;

    for (int i = 0; i < N; i++) {
        if (atacadas[i] == 1) {
            estrelasAtacadas++;
        }
        carneirosRestantes += carneiros[i];
    }

    printf("\nEstrelas atacadas: %d\n", estrelasAtacadas);
    printf("Carneiros restantes: %lld\n", carneirosRestantes);

    return 0;
}
