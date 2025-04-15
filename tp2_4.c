#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct compu {
 int velocidad; // Velocidad de procesamiento en GHz (valor entre 1 y 3)
 int anio; // Año de fabricación (valor entre 2015 y 2024)
 int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
 char *tipo_cpu; // Tipo de procesador (apuntador a cadena de caracteres)
}typedef compu;

char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core",
    "Pentium"};

void listarPCs(compu *pcs, int cantidad);
void mostrarMasVieja(compu *pcs, int cantidad);
void mostrarMasVeloz(compu *pcs, int cantidad);
void cargarDatos(compu *pcs);

int main(){
    compu PCs[5];   
   
    cargarDatos(PCs);

    listarPCs(PCs,4);

    mostrarMasVieja(PCs,4);

    return 0;
}

void cargarDatos(compu *pcs){

    int i;

    srand(time(NULL));
    
    for(i=0; i<5; i++){  
        int indiceRand =rand() % 6;

        pcs[i].anio =  (rand() % (2024- 2015 + 1)) + 2015;
        pcs[i].cantidad_nucleos = (rand() % (8 - 1+ 1)) + 1;
        pcs[i].velocidad = (rand() % (3 - 1+ 1)) + 1;
        pcs[i].tipo_cpu = tipos[indiceRand];
    }
}


void listarPCs(compu *pcs, int cantidad){

    printf("----Lista de las primeras %i PCs ----\n",cantidad);

    for (int i = 0; i < cantidad; i++)
    {
        printf("-----Pc numero %i -----\n",i+1);
        printf("Velocidad: %iGHz\n",pcs[i].velocidad);
        printf("Anio de fabricacion: %i\n",pcs[i].anio);
        printf("Cantidad de Nucleos: %i\n",pcs[i].cantidad_nucleos);
        printf("Tipo de CPU: %s\n",pcs[i].tipo_cpu);
    }
    
}

void mostrarMasVieja(compu *pcs, int cantidad){

    int menor = 10000;
    int indice;

    for (int i = 0; i < cantidad; i++)
    {
        if (pcs[i].anio < menor)
        {
            menor = pcs[i].anio;
            indice = i;
        }
        
    }

    printf("--- La computadora más vieja es la PC numero: %i\n ---",indice+1);
    printf("Sus caracteristicas son: \n");
    printf("Velocidad: %iGHz\n",pcs[indice].velocidad);
    printf("Anio de fabricacion: %i\n",pcs[indice].anio);
    printf("Cantidad de Nucleos: %i\n",pcs[indice].cantidad_nucleos);
    printf("Tipo de CPU: %s\n",pcs[indice].tipo_cpu);

}