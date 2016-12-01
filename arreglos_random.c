#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int* arreglo_int(size_t num, int min, int max){
	int * array = malloc(num*sizeof(int));
	int x;
	srand(time(NULL));
	for (int i = 0; i < num; i++) {
		x = rand()%((max + 1 - min))+min;
		array[i] = x;
	}
	return array;
}

/*  Crea un arreglo de doubles(en el heap) con números aleatorios
    num indica el tamaño del arreglo
    min indica el mínimo número aleatorio permitido en el arreglo
    max indica el máximo número aleatorio permitido en el arreglo
*/
double* arreglo_double(size_t num, double min, double max){
	double * array1 = malloc(num*sizeof(double));
	srand((unsigned)time(NULL));
	double r1 = (max - min); 
    double div = RAND_MAX / r1;
	for (int i = 0; i < num; i++) {
		array1[i] = min + (rand() / div);
	}
	return array1;
}