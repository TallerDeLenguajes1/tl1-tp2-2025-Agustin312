#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct compu {
 int velocidad; // Velocidad de procesamiento en GHz (valor entre 1 y 3)
 int anio; // Año de fabricación (valor entre 2015 y 2024)
 int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
 char *tipo_cpu; // Tipo de procesador (apuntador a cadena de caracteres)
}typedef compu;

void listarPCs(compu *pcs, int cantidad);
void mostrarMasVieja(compu *pcs, int cantidad);
void mostrarMasVeloz(compu *pcs, int cantidad);
void cargarDatos(compu *pcs);

int main(){
    compu PCs[5];   
   
    cargarDatos(PCs);

    for (int i = 0; i < 5; i++)
    {
        printf("Tipo pc %i : %s\n",i+1,PCs[i].tipo_cpu);
    }
    
}

void cargarDatos(compu *pcs){

    int i;
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core",
    "Pentium"};
    
    srand(time(NULL));
    
    for(i=0; i<5; i++){  
        int indiceRand =rand() % 6;

        pcs[i].anio =  (rand() % (2024- 2015 + 1)) + 2015;
        pcs[i].cantidad_nucleos = (rand() % (8 - 1+ 1)) + 1;
        pcs[i].velocidad = (rand() % (3 - 1+ 1)) + 1;
        pcs[i].tipo_cpu = tipos[indiceRand];
    }
}