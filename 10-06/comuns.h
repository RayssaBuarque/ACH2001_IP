#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

extern long getTime() {
  struct timespec timestamp;
  clock_gettime(CLOCK_MONOTONIC, &timestamp);

  return ((timestamp.tv_sec * 1000000000) + timestamp.tv_nsec);
}

extern int *sortearNumeros(int tamanhoArray) {
  int *numsSorteados = (int *)malloc(tamanhoArray * sizeof(int));

  srand(1023);

  for (int i = 0; i < tamanhoArray; i++) {
    numsSorteados[i] = rand();
  }

  return numsSorteados;
}

extern void printfuf(int *numeros, int arraySize) {
  for (int i = 0; i < arraySize; i++) {
    printf("%d\n", numeros[i]);
  }
}
