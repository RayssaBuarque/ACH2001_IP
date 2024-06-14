#include <stdlib.h>
#include <stdio.h>
#include "comuns.h"

int *sortearNumeros(int tamanhoArray);
void printfuf(int *numeros, int arraySize); 

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
void *selectionSort(int tamanhoArray) {
  int *sorteioC = sortearNumeros(tamanhoArray);

    int imaior;
    int tmenor = tamanhoArray-1;

    // para cada item da array:
    for(int i=tmenor; i>=0; i--){ 
        imaior = maior(sorteioC, tamanhoArray); 
        int aux = sorteioC[i]; 
        sorteioC[i] = sorteioC[imaior];
        sorteioC[imaior] = aux; 
        tamanhoArray--;
    }

    printfuf(sorteioC, tmenor+1);
    free(sorteioC);
}

int main (){
    int arraySize;
    printf("Informe o tamanho do array digitado com um inteiro: ");
    scanf("%d", &arraySize);

    selectionSort(arraySize);

    return 0;
}

