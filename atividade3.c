#include <math.h>

int func_val(int x, int b) {
    // cálculo usando inteiros
    int resultado = 186752 + (-148235 + b) * x + 34504 * x * x +
                    -3509 * x * x * x + 0 * x * x * x * x +
                    -0 * x * x * x * x * x + 0 * x * x * x * x * x * x +
                    -0 * x * x * x * x * x * x * x;
    
    if (resultado > 0) {
        return (resultado + 500) / 1000; // arrendodamento
    } else {
        return (resultado - 500) / 1000; 
    }
}
