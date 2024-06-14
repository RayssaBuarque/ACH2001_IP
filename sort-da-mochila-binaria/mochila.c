/*
Resolvendo problemas (e criando outros...)

Há um conjunto (grande) de problemas computacionais que podem ser resolvidos enumerando (todas) as soluções-candidatas e verificando se estas são aceitáveis. Um desses problemas é o da mochila binária.

Uma maneira de formular este problema em linguagem natural é: *Você tem uma mochila com volume de 30 litros e pretende viajar levando objetos nela. Cada objeto tem uma utilidade e ocupa um volume. A utilidade é um valor que você atribui ao objeto e que representa quão necessário é o objeto. Quando são escolhidos vários objetos, formando um conjunto, a utilidade do conjunto de objetos é a soma das utilidades de cada objeto. Dado o universo de objetos "escolhíveis", Deseja-se escolher os objetos de maneira que a utilidade dos objetos escolhidos seja máxima e o volume ocupado pelos objetos escolhidos não supere o volume da mochila.*

O programa a seguir resolve esse problema para até 31 elementos, este exemplo usa 6 elementos:

*/

#include <stdio.h>

#define N 6
#define VOLUME_MOCHILA 30

struct obj {  // características de 1 objeto
  int u;      // utilidade do objeto
  int v;      // volume do objeto
};

struct obj universo[N];

int ehAceitavel (int cand, int vMax);
unsigned int achacmax ();
void imprimec (int c);

void main () {
  unsigned int cmax=0; // candidato inicial: nenhum objeto escolhido

  /* define 6 objetos, cada volume e cada utilidade. */
  universo[0].u=3;
  universo[0].v=6;
  universo[1].u=6;
  universo[1].v=3;
  universo[2].u=9;
  universo[2].v=15;
  universo[3].u=12;
  universo[3].v=12;
  universo[4].u=15;
  universo[4].v=9;
  universo[5].u=12;
  universo[5].v=4;
  /*resolve o problema*/
  cmax=achacmax();
  /*mostra a solução*/
  imprimec(cmax);
}

/* Para entender o funcionamendo tas funções, seguem algumas explicações antes
 * do restante do código:
 * Lembre que pode-se dizer que no computador números são representados em binário. Um dígito binário pode assumir valor "zero" ou valor "um", logo, um dígito binário pode ser usado para armazenar se um objeto está ou não no conjunto. Para este programa, se o objeto está no conjunto o dígito correspondente vale "um".
 * Um número é a concatenação de vários dígitos. Convenciona-se que o dígito menos significativo seja o da direita. Desta forma, 1010 é um número (que corresponde a dez em decimal). Neste programa, se esse número representa um conjunto de objetos, é o conjunto em que os objetos de índice 3 e 1 estão presentes e os objetos de índice 2 e 0 estão ausentes.
 * 
 * Questão 1: Converta o número decimal 25 para binário. Considere que esse número representa um conjunto de objetos. Quais objetos estão presentes? Lembre-se de dizer qual é o primeiro índice.
 * 
 * Questão 2: Em teoria de conjuntos, o conjunto que contém todos os elementos geralmente é chamado conjunto universo. Um conjunto universo com 8 objetos é representado por que número binário? Converta esse número para decimal e apresente-o na resposta.
 * 
 * Questão 3: Com esta representação para conjuntos, enumerar todos os subconjuntos desse universo corresponde a enumerar todos os inteiros dentro de um intervalo de valores. Se o universo tem 20 elemento, que intervalo de valores deve ser enumerado? Se o universo tiver N elementos, qual o intervalo de valores? Pense como seria o (trecho do) programa que enumera valores, que comando você usaria?
 */ 

int ehAceitavel (int cand, int vMax) {
/* retorna a utilidade de cand, conjunto de objetos, caso o volume dos objetos em C seja menor ou igual a vMax. Caso o volume seja maior que vMax, retorna -1. 
 * Considerando as explicações e questões anteriores, explique o que faz a linha marcada com o comentário *explique* . Explique também para que o resto da divisão por 2 é usado. */
  int utilidadeMoch=0, volumeMoch=0;
  for (int i=0;i<=N;i++) {              // *Q4 explique estas linhas*
    if (cand%2==1) { // o i-esimo elemento está em C
      utilidadeMoch+=universo[i].u;
      volumeMoch+=universo[i].v;
    }
    cand=cand/2;
  }
  if (volumeMoch>vMax) return -1;
  return utilidadeMoch;
}

unsigned int achacmax () {
  int cmaxAteOMomento=0;  // candidato com utilidade máxima até o momento
  int umaxAteOMomento=0;  // utilidade do candidato com utilidade máxima até o momento.
  for (unsigned int candidato=0;candidato<(1u<<N); candidato++) {
    int u=ehAceitavel(candidato, VOLUME_MOCHILA);
    if ((u>0) && (u>umaxAteOMomento)) { // *Q5 explique para que serve este teste e as duas linhas seguintes no contexto do problema narrado em linguagem natural.*
    /* achou um candidato melhor */
      cmaxAteOMomento=candidato;
      umaxAteOMomento=u;
    }
  }
  return cmaxAteOMomento;
}

void imprimec (int c) {
  int utotal=0, vtotal=0;
  for (int i=0;i<N; i++) {
    if (c%2==1) {
      printf ("objeto %d, volume %d, utilidade %d\n", i, universo[i].v, universo[i].u);
      utotal+=universo[i].u;
      vtotal+=universo[i].v;
    }
    c=c/2;
  }
  printf ("Volume total: %d, utilidade total: %d\n", vtotal, utotal);
}
