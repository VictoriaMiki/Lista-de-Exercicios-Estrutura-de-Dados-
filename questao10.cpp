#include <stdio.h>

int somatoria(int n) {
    if (n == 1) {
        return 1;
    }
    return n + somatoria(n - 1);
}

int main() {
    int n;

    printf("Digite um numero N: ");
    scanf("%d", &n);

    int resultado = somatoria(n);
    printf("A somatoria de 1 a %d eh: %d\n", n, resultado);

    return 0;
}

