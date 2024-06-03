// #define tamanhoArray 7
#include <stdio.h>
#include <stdlib.h>

int *sortearNumeros(int tamanhoArray) {
  // Ponteiro que aponta para a memória alocada de maneira dinâmica para o array
  // de números aleatórios
  int *numsSorteados = (int *)malloc(tamanhoArray * sizeof(int));

  // Definição da semente:
  srand(1023);

  for (int i = 0; i < tamanhoArray; i++) {
    numsSorteados[i] = rand();
  }

  return numsSorteados;
}

// Loop para printar todos os números, recebe o array dos números sorteados
void printuf(int *numeros, int arraySize) {
  for (int i = 0; i < arraySize; i++) {
    printf("%d\n", numeros[i]);
  }
}

// função que retorna o índice do maior item da array
int maior(int *array, int tamanhoArray){
    int iaux = 0; // índice auxiliar

    // para cada item da array, cheque se a[iaux] > a[i]
    // se for verdade, salve o novo índice menor.
    for(int i = 1; i<tamanhoArray; i++){
        if(array[i] > array[iaux]){
            iaux = i;   
        }
    }

    return iaux;
}

// função de organização da array
void selectionSort(int *array, int tamanhoArray){
    int imaior;
    int tmenor = tamanhoArray-1;

    // para cada item da array:
    for(int i=tmenor; i>=0; i--){ 
        imaior = maior(array, tamanhoArray); // colete seu maior índice
        int aux = array[i]; // armazene o valor atual do loop numa var auxiliar
        array[i] = array[imaior]; // substitua-o pelo maior valor
        array[imaior] = aux; // coloque o valor auxiliar na antiga posição do menor valor 
        tamanhoArray--;
    }
}

int main(){
    int tamanhoArray = 7;
    int * arrayNum = sortearNumeros(tamanhoArray);

    selectionSort(arrayNum, tamanhoArray);
    printuf(arrayNum, tamanhoArray);
    free(arrayNum);
}
