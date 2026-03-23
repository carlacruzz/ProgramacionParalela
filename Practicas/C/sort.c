#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N 10000

int V[N];

/* Function to get wall time */
double cp_Wtime(){
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + 1.0e-6 * tv.tv_usec;
}

void ordena(int vector[], int n){
/*Aquí heu d'escriure el codi que ordeni de forma ascendent
  els elements del vector*/

/*Temps d'execució amb N=1000: 0,001359789 segons
Temps d'execució amb N=10000: 0,042250000 segons
Proporció d'increment del temps: 31.07099704
Aquest algoritme té una complexitat temporal de O(n^2), per tant, quan la mida del problema augmenta x10, el temps d'execució augmenta x100 (10^2).
 */
	for (int i = 0; i < n - 1; i++) {
                int maxim = 0;
                for (int j = 1; j < n - i; j++) {
                        if (vector[j] > vector[maxim]) {
                                maxim = j;
                        }
                }
                int aux = vector[maxim];
                vector[maxim] = vector[n - 1 - i];
                vector[n - 1 - i] = aux;
        }
}

/* 
    Funció que verifica si l'array rebut com a paràmetre està
    ordenat (retorna 1) o no (retorna 0)
*/
int verifica(int vector[], int n){
    for( int i = 1; i < n; i++ )
        if ( vector[i] < vector[i-1] ) return 0;
    return 1;
}

/*
    Funció que inicialitza l'array rebut com a paràmetre amb 
    valors enters aleatòris en el rang (-500,500)
*/
void init(int vector[], int n){
    for( int i = 0; i < n; i++ )
        vector[i] = ( i%10 ) ? random()%500 : -1*random()%500;
}
int main(){
    init(V,N);

    if (!verifica(V,N)) printf("Inicialment l'array no està ordenat (ja ho sabiem però ens assegurem)\n");

    double start = cp_Wtime();
    ordena(V,N);
    double total = cp_Wtime() - start;

    if(!verifica(V,N)) printf("Aquesta rutina d'ordenació no ordena! Try again!\n");
    else printf("Molt bé! Array ordenat! (%lf)\n", total);
}