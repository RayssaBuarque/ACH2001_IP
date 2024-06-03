#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/********************** FUNÇÕES AUXILIARES *************************/
// Função para gerar os números aleatórios
int *sortearNumeros(int tamanhoArray) {
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
int *insertionSort(int *numsDesordenados, int tamanhoArray) {
  for (int j = 1; j < tamanhoArray; j++) {
    int key = numsDesordenados[j];
    int i = j - 1;
    
    while ((i > 0) && (numsDesordenados[i] > key)) {
      numsDesordenados[i + 1] = numsDesordenados[i];
      i = i - 1;
    }
    numsDesordenados[i + 1] = key;
  }

  // "numsDesordenados" torna-se um array ordenado após o loop
  return numsDesordenados;
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
int *ordenararrays(int tipoOrdenacao, int tamanhoArray) {

  // declarações para medir o tempo
  struct timespec tInicioQsort;
  struct timespec tFinalQsort;
    struct timespec tInicioIsort;
    struct timespec tFinalIsort;
  struct timespec tInicioSsort;
  struct timespec tFinalSsort;

  // arrays que guardarao o resultado do tempo de execucao,
  // [0] = tempo em ns
  // [1] = tempo em s
  int *tempo_execucaoI = (int *)malloc(tamanhoArray * sizeof(int));
  int *tempo_execucaoQ = (int *)malloc(tamanhoArray * sizeof(int));
  int *tempo_execucaoS = (int *)malloc(tamanhoArray * sizeof(int));

  // aleatoriamente e o organiza com 'qsort'
  if (tipoOrdenacao == 1) {
    int *sorteioA = sortearNumeros(tamanhoArray);
    
    // capturando o tempo de sistema antes e depois do qsort rodar
    clock_gettime(CLOCK_MONOTONIC, &tInicioQsort);
        qsort(sorteioA, tamanhoArray, sizeof(int), compare);
    clock_gettime(CLOCK_MONOTONIC, &tFinalQsort);

    // tempo total = tempo final - tempo inicial
    tempo_execucaoQ[0] = tFinalQsort.tv_nsec - tInicioQsort.tv_nsec;
    tempo_execucaoQ[1] = tFinalQsort.tv_sec - tInicioQsort.tv_sec;

    printf("QUICK SORT MAIOR VALOR: %d\n", sorteioA[(tamanhoArray - 1)]);

    free(sorteioA);
    return tempo_execucaoQ;

  }
  // aleatoriamente e o organiza com 'insertion-sort'
  else if (tipoOrdenacao == 2) {
    int *sorteioB = sortearNumeros(tamanhoArray);

    // capturando o tempo de sistema antes e depois do qsort rodar
    clock_gettime(CLOCK_MONOTONIC, &tInicioIsort);
        int *ordenaB = insertionSort(sorteioB, tamanhoArray);
    clock_gettime(CLOCK_MONOTONIC, &tFinalIsort);

    tempo_execucaoI[0] = tFinalIsort.tv_nsec - tInicioIsort.tv_nsec;
    tempo_execucaoI[1] = tFinalIsort.tv_sec - tInicioIsort.tv_sec;

    printf("INSERTION SORT MAIOR VALOR: %d\n", ordenaB[(tamanhoArray - 1)]);

    free(sorteioB);
    return tempo_execucaoI;
  }
  // aleatoriamente e o organiza com 'selection-sort'
  else if(tipoOrdenacao == 3){
    int *sorteioC = sortearNumeros(tamanhoArray);

    clock_gettime(CLOCK_MONOTONIC, &tInicioSsort);
        selectionSort(sorteioC, tamanhoArray);
    clock_gettime(CLOCK_MONOTONIC, &tFinalSsort);

    tempo_execucaoS[0] = tFinalSsort.tv_nsec - tInicioSsort.tv_nsec;
    tempo_execucaoS[1] = tFinalSsort.tv_sec - tInicioSsort.tv_sec;

    printf("SELECTION SORT MAIOR VALOR: %d\n", sorteioC[(tamanhoArray - 1)]);

    free(sorteioC);
    return tempo_execucaoS;

  }
}

int main() {
  int arraySize;

  printf("Informe o tamanho do array digitado com um inteiro: ");
  scanf("%d", &arraySize);

  // chama a funçao de ordenacao no modo desejado e recebe o tempo de execucao
  int *dadoQsort = ordenararrays(1, arraySize);
  int *insertionsort = ordenararrays(2, arraySize);
  int *selectSort = ordenararrays(3, arraySize);


  printf("\n Tempo execução QSORT:");
  printf("\n %dns %ds", dadoQsort[0], dadoQsort[1]);

  printf("\n\n Tempo execução INSERTION-SORT:");
  printf("\n %dns %ds", insertionsort[0], insertionsort[1]);

  printf("\n\n Tempo execução SELECTION-SORT:");
  printf("\n %dns %ds", selectSort[0], selectSort[1]);

  // if (dadoQsort[0] > insertionsort[0]) {
  //   printf("\n\n QSORT demorou mais");
  // } else if (insertionsort[0] > dadoQsort[0]) {
  //   printf("\n\n INSERTION-SORT demorou mais");
  // }
  
  // liberando espaços de memória
  free(dadoQsort);
  free(insertionsort);
  free(selectSort);

  return 0;
}
