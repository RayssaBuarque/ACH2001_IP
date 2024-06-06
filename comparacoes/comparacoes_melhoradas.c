#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define seed 1023


/********************** FUNÇÕES AUXILIARES *************************/
// Função para gerar os números aleatórios
int *sortearNumeros(int tamanhoArray) {

  // Definição da semente:
  srand(seed);
  
  int *numsSorteados = (int *)malloc(tamanhoArray * sizeof(int));
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

// calculando em nanossegundos o período de tempo
long getTime(){
  struct timespec timestamp;
  clock_gettime(CLOCK_MONOTONIC, &timestamp);

  return ((timestamp.tv_sec*1000000000) + timestamp.tv_nsec);
}

/********************** FUNÇÕES DE ORDENAÇÃO *************************/

// callback do Qsort:
int compare(const void *p, const void *q){
  // Busca o valor numérico dos ponteiros
  int v1 = *(const int *)p;
  int v2 = *(const int *)q;

  if (v1 < v2) {
    return -1;
  }
  else if (v1 > v2) {
    return 1;
  }
  else {
    return 0;
  }
}

// odernação dos números através do insertionsort
void *insertionSort(int *array, int tamanhoArray) {
  for (int j = 1; j < tamanhoArray; j++) {
    int key = array[j];
    int i = j - 1;
    
    while ((i >= 0) && (array[i] > key)) {
      array[i + 1] = array[i];
      i = i - 1;
    }
    array[i + 1] = key;
  }  
}

// função que retorna o índice do maior item da array p/ selectionSort
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

// odernação dos números através do selectionSort
void selectionSort(int *array, int tamanhoArray){
    int imaior;
    int tmenor = tamanhoArray-1;

    // para cada item da array:
    for(int i=tmenor; i>=0; i--){ 
        imaior = maior(array, tamanhoArray); 
        int aux = array[i]; 
        array[i] = array[imaior];
        array[imaior] = aux; 
        tamanhoArray--;
    }
}

// função que ordena as arrays com cada possibilidade
long ordenararrays(int tipoOrdenacao, int tamanhoArray) {

  // declarações para medir o tempo
  long tempoInicial;
  long tempoFinal;

  // organização com 'qsort'
  if (tipoOrdenacao == 1) {
    int *sorteioQ = sortearNumeros(tamanhoArray);
    
    // capturando o tempo de sistema antes e depois do qsort rodar
    tempoInicial = getTime();
        qsort(sorteioQ, tamanhoArray, sizeof(int), compare);
    tempoFinal = getTime();

    // tempo total = tempo final - tempo inicial
    long tempoQsort = tempoFinal - tempoInicial;

    //printf("QUICK SORT MAIOR VALOR: %d\n", sorteioQ[(tamanhoArray - 1)]);
    free(sorteioQ);
    return tempoQsort;

  }
  // organização com 'insertion-sort'
  else if (tipoOrdenacao == 2) {
     int *sorteioI = sortearNumeros(tamanhoArray);

     // capturando o tempo de sistema antes e depois do qsort rodar
     tempoInicial = getTime();
         insertionSort(sorteioI, tamanhoArray);
     tempoFinal = getTime();

     long tempoIsort = tempoFinal - tempoInicial;

     //printf("INSERTION SORT MAIOR VALOR: %d\n", sorteioI[(tamanhoArray - 1)]);
     free(sorteioI);
     return tempoIsort;
   }
   // organização com 'selection-sort'
   else if(tipoOrdenacao == 3){
     int *sorteioS = sortearNumeros(tamanhoArray);

     tempoInicial = getTime();
         selectionSort(sorteioS, tamanhoArray);
     tempoFinal = getTime();

     long tempoSsort = tempoFinal - tempoInicial;

     //printf("SELECTION SORT MAIOR VALOR: %d\n", sorteioS[(tamanhoArray - 1)]);
     free(sorteioS);
     return tempoSsort;
   }
}

int main() {
  int arraySize;

  printf("\nInforme o tamanho do array digitado com um inteiro: ");
  scanf("%d", &arraySize);

  // chama a funçao de ordenacao no modo desejado e recebe o tempo de execucao
  // long dadoQsort = ordenararrays(1, arraySize);
  long dadoIsort = ordenararrays(2, arraySize);
  // long dadoSsort = ordenararrays(3, arraySize);

  printf("\n**********************************\n");
  // printf("\n Tempo execução QSORT:");
  // printf("\n %lu\n", dadoQsort);

  printf("\n Tempo execução INSERTION-SORT:");
  printf("\n %lu\n", dadoIsort);

  // printf("\n\n Tempo execução SELECTION-SORT:");
  // printf("\n %lu\n", dadoSsort);

  return 0;
}
