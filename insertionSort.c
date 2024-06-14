#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "comuns.h"

// Loop para printar todos os números, recebe o array dos números sorteados
void printuf(int *numeros, int arraySize) {
  for (int i = 0; i < arraySize; i++) {
    printf("%d\n", numeros[i]);
  }
}

// odernação dos números através do insertionsort, a funcao recebe o array
// gerado aleatoriamente (desordenado) e seu tamanho
int *insertionSort(int *numsDesordenados, int tamanhoArray) {

  for (int j = 1; j < tamanhoArray; j++) {
    int key = numsDesordenados[j];
    int i = j - 1;

    while ((i >= 0) && (numsDesordenados[i] > key)) {
      numsDesordenados[i + 1] = numsDesordenados[i];
      i = i - 1;
    }
    numsDesordenados[i + 1] = key;
  }

  // "numsDesordenados" torna-se um array ordenado após o loop
  return numsDesordenados;
}

int main() {
  long tempoInicial;
  long tempoFinal;

  int arraySize;
  printf("Informe o tamanho do array digitado com um inteiro: ");
  scanf("%d", &arraySize);

  // chama a função de ordenação e recebe o tempo de execução
  int *sorteio = sortearNumeros(arraySize);

  tempoInicial= getTime();
  insertionSort(sorteio, arraySize);
  tempoFinal = getTime();

  long tempoIsort = tempoFinal - tempoInicial;

  printf("\n /********************************************/ \n %lu\n", tempoIsort);

  return 0;
}
