#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define M 7

int main(){
    int i,j;
    int mt[N][M];
    int *punteromt;

    srand(time(NULL));
    
    printf("%p \n", punteromt);

    for(i= 0;i<N; i++){
        for(j = 0;j<M; j++){
            *punteromt = 1+rand()%100;
            printf("%i - ", *punteromt);
            punteromt++;
        }
        printf("\n");
    }
}

