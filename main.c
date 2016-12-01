/*Incluye las funciones de b_sort.c y arreglos_random.c*/
#include "b_sort.h"
#include "arreglos_random.h"

/*Declara las funciones que vamos a ocupar*/
// función que compara dos enteros
int cmp_int(const void *a, const void *b);
// función que compara dos doubles
int cmp_double(const void *a, const void *b);
// función que imprime una lista de enteros de tamaño num
void imprime_int(int *arreglo, size_t num);
// función que imprime una lista de doubles de tamaño num
void imprime_double(double *arreglo, size_t num);


int cmp_double(const void *a, const void *b){//Función que compara dos doubles
    double comp1 = *(double *)a;
    double comp2 = *(double *)b;
    if (comp1<comp2) { //Si el primero de los numero es menor al segundo nos devuelve -1
        return -1;
    } else if (comp1>comp2){ // De no ser así nos devuelve 1
        return 1;
    }
    return 0;
}//Termino de la Funcion cmp_double

void imprime_double(double *arreglo, size_t num){//Funcion que imprime una lista de douables de tamaño num
    for (int i = 0; i < num; i++){ //For que recorre el arreglo e imprime el elemento en cada iteracíón
        double d = arreglo[i];
        printf("%lf\n",d );
    }
}//Termino de la Funcion imprime_double

int cmp_int(const void *a, const void *b){; //Funcion que compara dos numeros enteros
    int comp1 = *(int *)a;
    int comp2 = *(int *)b;
    if (comp1<comp2) { // Si el primero de los numeros es menor al segundo nos devuelve -1
        return -1;
    } else if (comp1>comp2){ // De no ser así nos devuelve -1
        return 1;
    }
    return 0;   
}//Termino de la funcion cmp_doubles

void imprime_int(int *arreglo, size_t num){//Funcion que imprime una lista de enteros de temaño num
     for (int i = 0; i < num; i++){ //For que recorre el arreglo e imprime el elemento en cada iteración
        int n = arreglo[i];
        printf("%d\n",n );
    }
}//Termino de la funcion imprime_int



int b_sort(void * A, int num, int size, int (*compar)(const void*, const void*)){//Funcion de ordenamiento bubble sort
    int i = 0;
    int j = 0;
    int n;
    for (int i = 0; i < num; ++i) {//For que se usa para recorrer todos los elementos del arreglo
        for (j = i+1; j < num; ++i) {  //For que se usa para recorrer los elementos posteriores al elemento que se encuentra en la posicion i del arreglo
             int a = *((int*) A + i);
             int b = *((int*) A + j);
             if(cmp_int(&a,&b) > 0){ // Se Realizan las comparaciones necesarias y se hacen los intercambios
                n = a;
                a = b;
                b = n;
            }
        }
    }
    return 0;
}//Termino de la funcion bubble sort

int main(){ //Funcion principal del programa   
    // Se inicializan 2 arreglos, uno de ints y otro de doubles
    int * arr1 = arreglo_int(20, 0, 10);
    double *arr2 = arreglo_double(20, 0, 10);

    // Se imprime ordena e imprime el primer arreglo de enteros
    imprime_int(arr1, 20);
    bsort(arr1, 20, sizeof(int), &cmp_int);    
    imprime_int(arr1, 20);
    printf("\n");

    // Se imprime ordena e imprime el segundo arreglo de doubles
    imprime_double(arr2, 20);
    bsort(arr2, 20, sizeof(double), &cmp_double);
    imprime_double(arr2, 20);

    // Se libera la memoria que ocupan los arreglos ordenados
    free(arr1);
    free(arr2);
    return 0;

}