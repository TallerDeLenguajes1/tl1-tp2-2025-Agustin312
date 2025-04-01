#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

int main(){
    int i;
    int j = 0;
    double vt[N];
    double *punterovt;

    punterovt = vt;

    srand(time(NULL));
    for(i = 0;i<N; i++){
        *(punterovt+j)=1+rand()%100;
        j++;
        printf(" Numero %i : %.2f\n",i+1, punterovt[i]);
    }
    return 0;
}