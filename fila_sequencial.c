#include <stdio.h>
#include <stdlib.h>

typedef struct Fila{
	int tam;
	int inicio;
	int fim;
	int vetor[];
} Fila;

Fila *CriarFilaSequencial(int n){
	Fila *f =  malloc(sizeof(Fila));
	f->tam = n;
	f->vetor[n];
	f->inicio = 0;
	f->fim = 1;
	return f;
}

int FrontFilaSequencial(Fila *f){
	if((f->inicio == f->fim - 1) || (f->inicio == f->fim - 1 + f->tam)){
		return -1;
	}
	if(f->inicio == f->tam-1){
		return f->vetor[0];
	}
	return f->vetor[f->inicio + 1];
}

void Enfileirar(Fila *f, int a, int b){
	if(f->fim == f->inicio){
	printf("Fila cheia\n");
		return;
	}
	f->vetor[f->fim] = x;
	f->fim += 1;
	if(f->fim == f->tam)
		f->fim = 0;
}

int Desenfileirar(Fila *f){
	if((f->inicio == f->fim - 1) || (f->inicio == f->fim - 1 + f->tam)){
		printf("Fila Vazia\n");
		return -1;
	}
	
	f->inicio += 1;
	if(f->inicio == f->tam){
		f->inicio = 0;
	}
	return f->vetor[f->inicio];
	
}

int main(){
	int x, n, aux;
	Fila *a;
	printf("Digite o tamanho da fila\n");
	scanf("%d", &n);
	a = CriarFilaSequencial(n);
	printf("Digite quantos elementos na fila\n");
	scanf("%d", &n);
	while(n > 0){
		printf("Digite o elemento da fila\n");
		scanf("%d", &aux);
		Enfileirar(a, aux);
		n--;
	}
	
	printf("Elemento da frente da fila: %d", FrontFilaSequencial(a));
	printf("\n\n");
	printf("Desenfileirando\n\n");
	
	while(FrontFilaSequencial(a) != -1){
		printf("%d\n", FrontFilaSequencial(a));
		Desenfileirar(a);
	}
	
	free(a);
	
	return 0;
}
