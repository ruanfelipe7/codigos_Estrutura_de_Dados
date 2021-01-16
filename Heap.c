#include <stdio.h>
#include <stdlib.h>

typedef struct Heap{
	int max;
	int pos;
	int vetor[];
} Heap;

int Pai(int i){
	return (i-1)/2;
}

int Filhoesquerdo(int i){
	return (2*i) + 1;
}

int Filhodireito(int i){
	return (2*i) + 2;
}

Heap *CriarHeap(int n){
	Heap *h = malloc(sizeof(Heap));
	h->max = n;
	h->pos = 0;
	h->vetor[n];
	return h;
}

int InserirHeap(Heap *h, int x){
	if(h->pos == h->max){
		printf("ARVORE CHEIA");
		return 0;
	}
	int i, troca;
	i = h->pos;
	h->vetor[h->pos] = x;
	h->pos += 1;
	while(i > 0 && h->vetor[i] < h->vetor[Pai(i)]){
		troca = h->vetor[i];
		h->vetor[i] = h->vetor[Pai(i)];
		h->vetor[Pai(i)] = troca;
		i = Pai(i);
	}
	return 1;
}

int main(){
	Heap *arv = CriarHeap(8);
	int num = 0, j = 0, i = 0;
	for(i = 0; i < 4; i++){
		printf("Digite um elemento a ser inserido\n");
		scanf("%d", &num);
		if(InserirHeap(arv, num))
			printf("Elemento inserido com sucesso\n");
	
		
	}
	
			
	printf("Listando\n\n");
	while(j < arv->pos){
			printf("%d\n", arv->vetor[j]);
			j++;
		}	
	
	return 0;
}
