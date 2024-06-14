#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// função que coleta o tempo atual da máquina em nanossegundos
extern long getTime() {
  struct timespec timestamp;
  clock_gettime(CLOCK_MONOTONIC, &timestamp);

  return ((timestamp.tv_sec * 1000000000) + timestamp.tv_nsec);
}

// Função para gerar os números aleatórios
extern int *sortearNumeros(int tamanhoArray) {
  // Alocando um espaço de memória em bytes para gerar os números
  int *numsSorteados = (int *)malloc(tamanhoArray * sizeof(int));
  /*
    Espaços de memória alocados com malloc, calloc e realloc são atribuidos na
    Heap (memória dinâmica).Eles atuam como uma variável global que são apenas
    "descartados" manualmente por meio de free() - caso contrário, ocorrem erros de memory leak. 
  */

  // definindo uma semente de geração
  srand(1023);
  /* 
    Sementes de geração são a base para os números "aleatórios" gerados por rand()
    Se você usar a mesma semente de geração e rodar o mesmo arquivo várias vezes,
    os números gerados serão os mesmos.
  */

  for (int i = 0; i < tamanhoArray; i++) {
    numsSorteados[i] = rand();
  }
  
  return numsSorteados;
}

// função que imprime todos os itens de uma array
extern void printfuf(int *numeros, int arraySize) {
  for (int i = 0; i < arraySize; i++) {
    printf("%d\n", numeros[i]);
  }
}
