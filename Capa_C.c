#include <stdio.h>
#include <stdlib.h>

#define MAX_DATOS       20 // Cantidad de datos - ajustado segun los años tomados

typedef struct{
    int year;
    float indice;
} DatosGini;


int main() {
    FILE *pipe;
    DatosGini datos[MAX_DATOS];
    int count = 0;

    // Abrir un pipe para ejecutar Python y leer su salida
    pipe = popen("python3 Capa_python.py", "r");
    if (pipe == NULL) {
        printf("Error al abrir el pipe.\n");
        return 1;
    }

    printf("Guardado de datos. \n");

    // Leer los datos de python y guardar en un array
    while( fscanf(pipe, "%d %f", &datos[count].year, &datos[count].indice) != EOF && count < MAX_DATOS){
        printf("Año %d: %.2f\n", datos[count].year, datos[count].indice);
        count++;
    }
    
    // Cerrar el pipe
    pclose(pipe);

    // Ahora tienes los datos almacenados en `datos[]` y puedes procesarlos
    printf("\nTotal de registros guardados: %d\n", count);

    return 0;
}
