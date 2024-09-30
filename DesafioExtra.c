#include <stdio.h>

int main() {
    float N1, N2, PPD, N3 = 0;
    float EU;
    float nota_final;
    int realizou_exame, realizou_n3;

    printf("Nota N1 (0 a 4.5): ");
    scanf("%f", &N1);
    
    printf("Nota N2 (0 a 4.5): ");
    scanf("%f", &N2);
    
    printf("Nota PPD (0 a 1): ");
    scanf("%f", &PPD);

    if (N1 < 0 || N1 > 4.5 || N2 < 0 || N2 > 4.5 || PPD < 0 || PPD > 1) {
        printf("Notas inválidas. Código de erro 3.\n");
        return 3;
    }

    printf("Fez o Exame Unificado? (0 - Não, 1 - Sim): ");
    scanf("%d", &realizou_exame);

    if (realizou_exame == 1) {
        printf("Nota do Exame (0 a 1): ");
        scanf("%f", &EU);
        
        if (EU < 0 || EU > 1) {
            printf("Nota do Exame inválida. Código de erro 3.\n");
            return 3;
        }
    }

    printf("Fez a N3? (0 - Não, 1 - Sim): ");
    scanf("%d", &realizou_n3);

    if (realizou_n3 == 1) {
        printf("Nota N3 (0 a 4.5): ");
        scanf("%f", &N3);
        
        if (N3 < 0 || N3 > 4.5) {
            printf("Nota N3 inválida. Código de erro 3.\n");
            return 3;
        }
    }

    if (realizou_n3 == 1) {
        if (N1 < N2) {
            nota_final = (N3 + N2 + PPD) / 3;
        } else {
            nota_final = (N1 + N3 + PPD) / 3;
        }
    } else {
        nota_final = (N1 + N2 + PPD) / 3;
    }

    if (realizou_exame == 1) {
        nota_final = (nota_final + EU) / 2;
    }

    if (nota_final > 10) {
        nota_final = 10;
    } else if (nota_final < 0) {
        nota_final = 0;
    }

    printf("Nota final: %.2f\n", nota_final);
    if (nota_final >= 6) {
        printf("Aprovado.\n");
    } else {
        printf("Reprovado.\n");
    }

    return 0;
}


