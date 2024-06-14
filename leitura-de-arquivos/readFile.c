#include <stdio.h>
#include <time.h>

#define BUFLEN 100

void main () {
  struct timespec t_inicio;
  struct timespec t_final;
  int tempo_execucao_sec;
  int tempo_execucao_nsec;

  // pegando o timestamp do Sistema operacional no momento em q a linha roda e alocando ele na var t_inicio	
  clock_gettime(CLOCK_MONOTONIC, &t_inicio);

  // alguma coisa de leitura de arquivos, pesquisa dps
  char buf[BUFLEN];
  FILE *fp;
  fp=fopen ("texto.txt", "rt");
  if (!fp) { 
    // caso haja erro para abrir o arquivo, escreve na tela a mensagem de erro.
	perror("");
	return;
  }
  while (!feof(fp)) {
	if (fgets (buf, BUFLEN, fp)) {
      printf ("%s", buf);
    }
  }
  fclose(fp);
  // pegando o timestamp do Sistema operacional no momento em q a linha roda e alocando ele na var t_final
  clock_gettime(CLOCK_MONOTONIC, &t_final);

  // calculando a diferença de tempo em segundos e nanosegundos do timestamp inicial ao final, e printando na tela
  tempo_execucao_sec = (t_final.tv_sec - t_inicio.tv_sec);
  tempo_execucao_nsec = (t_final.tv_nsec - t_inicio.tv_nsec);
  printf("TEMPO DE EXECUÇÃO: %dsec %dnsec\n", tempo_execucao_sec, tempo_execucao_nsec); 

}
