#include <stdlib.h>
#include <stdio.h>
#include "comuns.h"

int *sortearNumeros(int tamanhoArray);
void printfuf(int *numeros, int arraySize); 

int *insertionSort(int tamanhoArray) {
  
  int *sorteioB = sortearNumeros(tamanhoArray);

  for (int j = 1; j < tamanhoArray; j++) {
    int key = sorteioB[j];
    int i = j - 1;
    
    while ((i > 0) && (sorteioB[i] > key)) {
      sorteioB[i + 1] = sorteioB[i];
      i = i - 1;
    }
    sorteioB[i + 1] = key;
  }

    printfuf(sorteioB, tamanhoArray);

    free(sorteioB);

  // "numsDesordenados" torna-se um array ordenado após o loop
  return sorteioB;
}

int main (){
    int arraySize;
    printf("Informe o tamanho do array digitado com um inteiro: ");
    scanf("%d", &arraySize);

    insertionSort(arraySize);

    return 0;
}

