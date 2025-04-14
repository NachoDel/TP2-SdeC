#include <stdio.h>
#include <stdlib.h>

#define MAX_DATOS 20

typedef struct {
    int year;
    float indice;
} DatosGini;

// Declaración de función externa ASM
extern void modificar_indices_asm(DatosGini* datos, int cantidad);

int main() {
    FILE *pipe;
    DatosGini datos[MAX_DATOS];
    int count = 0;

    pipe = popen("python3 Capa_python.py", "r");
    if (!pipe) {
        printf("Error al abrir el pipe.\n");
        return 1;
    }

    while (fscanf(pipe, "%d %f", &datos[count].year, &datos[count].indice) != EOF && count < MAX_DATOS) {
        count++;
    }

    pclose(pipe);

    printf("Valores originales:\n");
    for (int i = 0; i < count; i++) {
        printf("Año %d: %.2f\n", datos[i].year, datos[i].indice);
    }

    // Llamada a la función en ensamblador
    modificar_indices_asm(datos, count);

    printf("\nValores modificados (ASM +1.0):\n");
    for (int i = 0; i < count; i++) {
        printf("Año %d: %.2f\n", datos[i].year, datos[i].indice);
    }

    return 0;
}
