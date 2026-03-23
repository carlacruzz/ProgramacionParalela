#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int *V;
int N = 1000;

double cp_Wtime(){
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + 1.0e-6 * tv.tv_usec;
}

void ordena(int vector[], int n){
/*Aquí heu de copiar (sense canvis) el codi que heu programat per l'exercici preliminar*/
        for (int i=0; i<n-1; i++) {
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

int main(int argc, char *argv[]){
    /*
        Aquí heu d'escriure el codi que verifiqui que l'usuari ha proporcionat el
        nombre d'elements a ordenar i que aquest nombre és > 2
        En cas de que l'usuari no proporcioni el nombre d'elements o aquest sigui
        <=2 es farà servir la constant N.
*/

    if (argc > 1) {
            int mida = atoi(argv[1]);
            if (mida > 2) {
                 N = mida;
            }
    }

    V = (int *)malloc(N * sizeof(int));
    if (V == NULL) {
        printf("Error: No s'ha pogut reservar memòria.\n");
        return 1;
    }

    // Ara cal reservar la memòria de l'array, abans de fer-lo servir

    init(V,N);

    if (!verifica(V,N)) printf("Inicialment l'array no està ordenat (ja ho sabiem però ens assegurem)\n");

    double start = cp_Wtime();
    ordena(V,N);
    double total = cp_Wtime() - start;

    if(!verifica(V,N)) printf("Aquesta rutina d'ordenació no ordena! Try again!\n");
    else printf("Molt bé! Array ordenat! (%lf)\n", total);

    free(V);
    return 0;
    // Abans d'acabar cal alliberar la memòria reservada per l'array

}