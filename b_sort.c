#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(void * a, void * b, size_t size){
	void * temporal = malloc(size);
	memcpy(temporal,a,size);//Funcion mempcy que sirve para copiar un cierto numero de bytes desde una posicion incial a una final
	memcpy(a,b,size);
	memcpy(b,temporal,size);
	free(temporal); // Funcion free que se usa para liberar memoria reservada en este caso con malloc 
}

void bsort(void* base, size_t num, size_t size,int (*compar)(const void*, const void*)){
	for (int i = 0; (i <num); i++){ //Con este primer for recorremos todos los elementos del arreglo
		for (int j = i+1; j < num; j++){ //Con el segundo for recorremos los elementos posteriores al elemento al que apunte i 
			char * mom1 = (char*)base + size*i; 
			char *mom2 = (char*)base + size*j;
			if(compar(mom1,mom2)>0){//Realiza las comparaciones necesarias y con ayuda del metodo swap intercambia los elementos
				swap(mom1,mom2,size);
			}
		}
	}
}
