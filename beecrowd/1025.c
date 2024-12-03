#include <stdio.h>
#include <math.h>

int obterDigito(int numero, int posicao) {
    int divisor = pow(10,posicao);
    return (numero / divisor) % 10;
}
int main() {
    int numero = 95;
    int posicao = 1; // Posição do dígito (0 = unidade, 1 = dezena, etc.)
    printf("Dígito na posição %d: %d\n", posicao, obterDigito(numero, posicao));
    return 0;
}