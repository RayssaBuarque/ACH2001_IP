#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Função para gerar os números aleatórios
// Vai retornar um ponteiro de inteiro e recebe o tamanho do array para gerar os números em loop

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

// Loop para printar todos os números, recebe o array dos números sorteados
void printuf(int *numeros, int arraySize) {
  for (int i = 0; i < arraySize; i++) {
    printf("%d\n", numeros[i]);
  }
}

// odernação dos números através do insertionsort, a funcao recebe o array
// gerado aleatoriamente (desordenado) e seu tamanho
void *insertionSort(int *numsDesordenados, int tamanhoArray) {

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
}

int main() {
  int arraySize;
  printf("Informe o tamanho do array digitado com um inteiro: ");
  scanf("%d", &arraySize);

  // chama a funçao de ordenacao e recebe o tempo de execucao
  int *sorteio = sortearNumeros(arraySize);
  insertionSort(sorteio, arraySize);

  printuf(sorteio, arraySize);
  
  return 0;
}
