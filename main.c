#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTOS 30

struct pilha{
  int valores[MAX_ELEMENTOS];
  int topo;
};

void empilha(struct pilha *p, int empilhar);
struct pilha * cria();
void ImprimirPilha(struct pilha *p);
int desempilha(struct pilha *p);
void ImprimirTamanhoPilha(struct pilha *p);

int main() {
  cria();
  struct pilha LucasNeto;
  empilha(&LucasNeto, 2);
  empilha(&LucasNeto, 3);
  empilha(&LucasNeto, 4);
  ImprimirPilha(&LucasNeto);
  ImprimirTamanhoPilha(&LucasNeto);
  int valor = desempilha(&LucasNeto);
  printf("\nValor desempilhado: %d\n", valor);
  return 0;
}

struct pilha * cria() {
  struct pilha *p;
  p = malloc(sizeof(struct pilha));
  if (!p) { 
    perror(NULL);
    exit(1);
  }
  p->topo = 0;
  return p;
}

void empilha(struct pilha *p, int empilhar){
  p->valores[p->topo] = empilhar;
  p->topo = p->topo + 1;
}

void ImprimirPilha(struct pilha *p){
	int x;
  int total = p->topo;
  	for (x=0; x < total; x++){
	    int valor = p->valores[x];
	    printf("Valor: %d\n", valor);
  	}
  	x = p->topo;
}

void ImprimirTamanhoPilha(struct pilha *p){
	    printf("\nTamanho da pilha: %d\n", p->topo);
}

int desempilha(struct pilha *p) {
p->topo = p->topo-1;
return p->valores[p->topo];
}