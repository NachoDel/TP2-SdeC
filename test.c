#include <stdio.h>

extern int process_gini_asm(float gini_value);

int main() {
    float gini = 41.3;
    int resultado = process_gini_asm(gini);
    printf("Resultado: %d\n", resultado);
    return 0;
}
