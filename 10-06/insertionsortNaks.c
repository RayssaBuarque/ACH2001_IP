/* Funções para criação e impressão de arrays
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *criaArray (int tamanho) {
  return (int*) malloc (tamanho*sizeof(int));
}

void telaArray (int *A, int tamanho) {
  puts ("telaArray");
  for (int i=0;i<tamanho;i++) {
    printf ("%d ", A[i]);
  }
}

void preencheAleatorioArray (int *A, int tamanho, int semente) {
  srand(semente);
  for (int i=0;i<tamanho;i++) {
    A[i]=rand();
  }
}

/* funções auxiliares para usar qsort */
int intCmp(int *a, int *b) {
  return (*a)-(*b);
}

/* funções auxiliares para tratar tempo */

long int subtime (struct timespec fim, struct timespec inicio) {
  long int nsec=fim.tv_nsec-inicio.tv_nsec;
  long int sec=fim.tv_sec-inicio.tv_sec;
  return sec*1E9+nsec;
}

/* insertion sort */
/* transcrito de CLRS Introduction To Algorithms, 3rd Ed. p.26 */
int *isort(int *array, int comprimentoDoArray) {
	for (int j=1;j<comprimentoDoArray;j++) {    // em C, índices começam em zero
		int key=array[j];
		int i=j-1;
		while ((i>=0) && (array[i]>key)) {
			array[i+1]=array[i];
			i--;
		}
		array[i+1]=key;
	}
	return array;
}


/* lembrete 
struct timespec t;
clock_gettime(CLOCK_MONOTONIC, &t);
printf ("%ld, %ld\n", t.tv_sec, t.tv_nsec);
*/

/* teste das funções definidas neste arquivo */

void main () {
  int *A, tamanho;
  struct timespec ini, fim;
//   tamanho= 1000000;
    tamanho= 1000;

  A=criaArray(tamanho);
  telaArray(A, tamanho);
  preencheAleatorioArray(A,tamanho,4);
  telaArray(A, tamanho);

  clock_gettime(CLOCK_MONOTONIC, &ini);
  // qsort (A, tamanho, sizeof(int), intCmp);
  isort(A,tamanho);
  clock_gettime(CLOCK_MONOTONIC, &fim);

  telaArray(A, tamanho);
  printf ("Tempo de execução: %ld\n", subtime(fim, ini));
  free(A);
}

// Tempo de execução isort: 800 358 888 282 para tamanho=1 000 000
// Tempo de execução qsort: 183 278 786 para o mesmo tamanho de 1 000 000

