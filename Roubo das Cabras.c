#include <stdio.h>

int main() {
    int N;

    printf("Digite o número de estrelas: ");
    scanf("%d", &N);

    int carneiros[10];
    int atacadas[10];

    for (int i = 0; i < N; i++) {
        printf("Digite a quantidade de carneiros na Estrela %d: ", i + 1);
        scanf("%d", &carneiros[i]);
        atacadas[i] = 0;
    }

    int pos = 0;

    while (pos >= 0 && pos < N) {
        int atual = carneiros[pos];

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
    int carneirosRestantes = 0;

    for (int i = 0; i < N; i++) {
        if (atacadas[i] == 1) {
            estrelasAtacadas++;
        }
        carneirosRestantes += carneiros[i];
    }

    printf("\nEstrelas atacadas: %d\n", estrelasAtacadas);
    printf("Carneiros restantes: %d\n", carneirosRestantes);

    return 0;
}
