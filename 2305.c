#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Função para gerar os números aleatórios
// Vai retornar um ponteiro de inteiro e recebe o tamanho do array para gerar os
// números em loop
int *sortearNumeros(int tamanhoArray) {
  // Ponteiro que aponta para a memória alocada de maneira dinâmica para o array
  // de números aleatórios
  int *numsSorteados = (int *)malloc(tamanhoArray * sizeof(int));

  /*
    NOTA SOBRE MALLOC:
      Espaços de memória alocados com malloc, calloc e realloc são atribuidos na
    Heap (memória dinâmica). Ou seja: eles atuam como uma variável global,
    porém, para serem "descartados" tal qual uma var local, é necessário a ação
    manual por meio do comando "free" - caso contrário, ocorrem erros de memory
    leak. Internamente, malloc mantém uma lista de blocos de memória, rodando o
    comando, ele atribui um apto para suportar o tamanho requisitado em bytes
      isso tudo depende de quais estiverem livres, por isso a importância do
    comando "free". "são globais até que se prove o contrário"
  */

  // Definição da semente:
  srand(1023);

  for (int i = 0; i < tamanhoArray; i++) {
    numsSorteados[i] = rand();
  }

  return numsSorteados;
}

// callback do qsort:
int compare(const void *p,
            const void *q) // qsort envia ponteiros de dois valores da vítima
{
  // Busca o valor numérico dos ponteiros
  int v1 = *(const int *)p;
  int v2 = *(const int *)q;

  if (v1 < v2) { // se v1>v2, seu retorno é <0, isso quer dizer que v1 vem ANTES
    return -1;
  }

  else if (v1 > v2) { // se v1<v2, seu retorno é >0, isso quer dizer que v1 vem
                      // DEPOIS
    return 1;
  }

  else { // se v1=v2, ele retorna 0.
    return 0;
  }
}

// Loop para printar todos os números, recebe o array dos números sorteados
void printuf(int *numeros, int arraySize) {
  for (int i = 0; i < arraySize; i++) {
    printf("%d\n", numeros[i]);
  }
}

// odernação dos números através do insertionsort, a funcao recebe o array
// gerado aleatoriamente (desordenado) e seu tamanho
int *insertionSort(int *numsDesordenados, int tArray) {

  for (int j = 1; j < tArray; j++) {
    int key = numsDesordenados[j];
    int i = j - 1;
    while ((i > 0) && (numsDesordenados[i] > key)) {
      numsDesordenados[i + 1] = numsDesordenados[i];
      i = i - 1;
    }
    numsDesordenados[i + 1] = key;
  }

  // embora a variavel chame-se "numsDesordenados", eles estão ordernados após
  // passarem pelo loop
  return numsDesordenados;
}

int *ordenararrays(int tipoOrdenacao, int tamanhoArray) {

  // declarações para medir o tempo
  struct timespec tInicioQsort;
  struct timespec tFinalQsort;
  struct timespec tInicioIsort;
  struct timespec tFinalIsort;

  // arrays que guardarao o resultado do tempo de execucao, [0] armazena o tempo
  // em ns e [1] o tempo em s
  int *tempo_execucaoQ = (int *)malloc(tamanhoArray * sizeof(int));
  int *tempo_execucaoI = (int *)malloc(tamanhoArray * sizeof(int));

  // quando ordenaarrays é chamada com o parametro '1' ela gera o array
  // aleatoriamente e o organiza com 'qsort'
  if (tipoOrdenacao == 1) {
    int *sorteioA = sortearNumeros(tamanhoArray);

    // printf("Array desordenado:");
    // printuf(sorteioA, tamanhoArray);

    // tempo de sistema antes do qsort rodar
    clock_gettime(CLOCK_MONOTONIC, &tInicioQsort);

    qsort(sorteioA, tamanhoArray, sizeof(int), compare);

    // tempo de sistema após o qsort rodar
    clock_gettime(CLOCK_MONOTONIC, &tFinalQsort);

    // printf("\nArray ordenado:");
    // printuf(sorteioA, tamanhoArray);

    // tempo total = tempo final - tempo inicial
    tempo_execucaoQ[0] = tFinalQsort.tv_nsec - tInicioQsort.tv_nsec;
    tempo_execucaoQ[1] = tFinalQsort.tv_sec - tInicioQsort.tv_sec;

    // liberacao de memoria
    free(sorteioA);
    return tempo_execucaoQ;

  }
  // quando ordenaarrays é chamada com o parametro '2' ela gera o array
  // aleatoriamente e o organiza com 'insertion-sort'
  else if (tipoOrdenacao == 2) {
    int *sorteioB = sortearNumeros(tamanhoArray);

    // pra ver se funciona
    // printf("\n Array desordenado:");
    // printuf(sorteioB, tamanhoArray);

    clock_gettime(CLOCK_MONOTONIC, &tInicioIsort);
    int *ordenaB = insertionSort(sorteioB, tamanhoArray);
    clock_gettime(CLOCK_MONOTONIC, &tFinalIsort);

    // printf("\n Array ordenado:");
    // printuf(ordenaB, tamanhoArray);

    tempo_execucaoI[0] = tFinalIsort.tv_nsec - tInicioIsort.tv_nsec;
    tempo_execucaoI[1] = tFinalIsort.tv_sec - tInicioIsort.tv_sec;

    free(sorteioB);
    return tempo_execucaoI;
  }
}

int main() {
  int arraySize;

  printf("Informe o tamanho do array digitado com um inteiro: ");
  scanf("%d", &arraySize);

  // chama a funçao de ordenacao no modo desejado e recebe o tempo de execucao
  int *qsort = ordenararrays(1, arraySize);
  int *insertionsort = ordenararrays(2, arraySize);

  printf("\n Tempo execução QSORT:");
  printf("\n %dns %ds", qsort[0], qsort[1]);

  printf("\n\n Tempo execução INSERTIONSORT:");
  printf("\n %dns %ds", insertionsort[0], insertionsort[1]);

  if (qsort[0] > insertionsort[0]) {
    printf("\n\n QSORT demorou mais");
  } else if (insertionsort[0] > qsort[0]) {
    printf("\n\n INSERTION-SORT demorou mais");
  }
  free(qsort);
  free(insertionsort);

  return 0;
}
