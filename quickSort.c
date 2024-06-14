#include "comuns.h"
#include <stdio.h>
#include <stdlib.h>

int *sortearNumeros(int tamanhoArray);
void printfuf(int *numeros, int arraySize);

// callback do qsort: função de comparação dos itens da array
int compare(const void *p, const void *q) {
  // Busca o valor numérico dos ponteiros
  int v1 = *(const int *)p;
  int v2 = *(const int *)q;

  if (v1 < v2) {
    return -1; // se retorno é <0, quer dizer que v1 vem ANTES
  } else if (v1 > v2) {
    return 1; // se retorno é >0, quer dizer que v1 vem DEPOIS
  } else {
    return 0; // se retorno é 0, ele está no LOCAL CORRETO
  }
}

// função manual que realiza um quicksort com base em uma array de números sorteados
void quicksort(int tamanhoArray) {
  int *sorteioA = sortearNumeros(tamanhoArray);

  qsort(sorteioA, tamanhoArray, sizeof(int), compare);
  free(sorteioA);
}

int main() {
  int arraySize;
  long tempoInicial;
  long tempoFinal;

  printf("Informe o tamanho do array digitado com um inteiro: ");
  scanf("%d", &arraySize);

  tempoInicial = getTime();
  quicksort(arraySize);
  tempoFinal = getTime();

  long tempoQsort = tempoFinal - tempoInicial;

  printf("\n /********************************************/ \n %lu ns\n",
         tempoQsort);

  return 0;
}