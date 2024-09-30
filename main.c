#include <stdio.h>

double a0 = 186752;
double a1 = -148235;
double a2 = 34504.9;
double a3 = -3509.1;
double a4 = 0.183166;
double a5 = -0.00513554;
double a6 = 0.0000735464;
double a7 = -4.22038e-7;

double potencia(int base, int expoente) {
    double resultado = 1;
    for (int i = 0; i < expoente; i++) {
        resultado *= base;
    }
    return resultado;
}

double f(int x, int b) {
    return a0 + (a1 + b) * x + a2 * potencia(x, 2) + a3 * potencia(x, 3) +
           a4 * potencia(x, 4) + a5 * potencia(x, 5) + a6 * potencia(x, 6) + a7 * potencia(x, 7);
}

int hex_para_decimal(char c1, char c2) { // Função para converter dois caracteres hexadecimais em um número decimal
    int valor1, valor2;

    if (c1 >= '0' && c1 <= '9') {
        valor1 = c1 - '0';
    } else {
        valor1 = c1 - 'A' + 10;
    }

    if (c2 >= '0' && c2 <= '9') {
        valor2 = c2 - '0';
    } else {
        valor2 = c2 - 'A' + 10;
    }

    return (valor1 << 4) | valor2;
}

void decodificar_mensagem(int b, char* mensagem_hex) {
    for (int i = 0; i < 100; i += 2) {
        int valor = hex_para_decimal(mensagem_hex[i], mensagem_hex[i+1]);

        if (valor == 0) { // Se o valor for 00, termina a mensagem
            break;
        }

        int x = (i / 2) + 1;

        if (f(x, b) < 128) {
            printf("%c", valor); 
        }
    }
    printf("\n");
}

int main() {
    int n;

    printf("Quantas mensagens? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int b;
        char mensagem_hex[101];

        printf("Valor de b: ");
        scanf("%d", &b);

        printf("Digite a mensagem hexadecimal: ");
        scanf("%s", mensagem_hex);

        decodificar_mensagem(b, mensagem_hex);
    }

    return 0;
}
