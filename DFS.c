#include <stdio.h>
#include <stdlib.h>

#define BRANCO 0
#define CINZA 1
#define PRETO 2
#define qtd 5

int cor[qtd];
int pred[qtd];
int d[qtd];
int f[qtd];
int time;

typedef struct no {
	struct no * proximo;
	int numero;	
} no;

typedef struct no * grafo[qtd];

void iniciarGrafo(grafo g){
	int i;
	for(i = 0; i < qtd; i++){
		g[i] = NULL;
	}
}

void inserirGrafo(grafo g, int u, int v){
	no * novo = (no*)malloc(sizeof(no));
	novo->numero = v;
	novo->proximo = g[u];
	g[u] = novo;
}

void DFS_visit(grafo g, int u){
	cor[u] = CINZA;
	time = time + 1;
	d[u] = time;
	
	no * v = g[u];
	while(v != NULL){
		if (cor[v->numero] == BRANCO){
			pred[v->numero] = u;
			DFS_visit(g, v->numero);
		}
		v = (no*)v->proximo;
	}
	cor[u] = PRETO;
	time++;
	f[u] = time;
}

void DFS(grafo g){
	for(int u = 1; u < qtd; u++){
		cor[u] = BRANCO;
		pred[u] = -1;
	}
	time = 0;
	for(int u = 1; u < qtd; u++) {
		if(cor[u] == BRANCO)
			DFS_visit(g, u);
	}
}

int main() {
	grafo oi;
	
	iniciarGrafo(oi);
	inserirGrafo(oi, 1, 4);
	inserirGrafo(oi, 1, 3);
	inserirGrafo(oi, 1, 2);
	inserirGrafo(oi, 1, 1);
    inserirGrafo(oi, 2, 3);
    inserirGrafo(oi, 3, 3);
    inserirGrafo(oi, 2, 2);
    inserirGrafo(oi, 4, 1);
	
	DFS(oi);
	
	int u;
	for (u = 1; u < qtd; u++)  
		printf("Vertice %d: descoberta = %d, termino = %d\n", u, d[u], f[u]);
	
	
	return 0;
}