#include <stdio.h>
#include "remove.h"

int main() {
    int b;
    char mensagem_hex[101];
    
    printf("Digite o valor de b: ");
    scanf("%d", &b); 
    printf("Digite a mensagem cifrada: ");
    scanf("%s", mensagem_hex); 

    for (int j = 0; j < 100; j += 2) {
        int valor1 = (mensagem_hex[j] >= '0' && mensagem_hex[j] <= '9') ? 
                    (mensagem_hex[j] - '0') : (mensagem_hex[j] - 'A' + 10);
        int valor2 = (mensagem_hex[j + 1] >= '0' && mensagem_hex[j + 1] <= '9') ? 
                    (mensagem_hex[j + 1] - '0') : (mensagem_hex[j + 1] - 'A' + 10);
        int valor = (valor1 << 4) | valor2;

        if (valor == 0) {
            break; 
        }

        int x = (j / 2) + 1;
        if (func_val(x, b) != 0) {
            printf("%c", valor);
        }
    }
    
    printf("\n");
    
    return 0;
}

