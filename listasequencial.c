#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
	int tamanho;
	int cardinalidade;
	int vetor[];
} Lista;

Lista *CriarLista(int n){
	Lista *l = malloc(sizeof(Lista));
	l->tamanho = n;
	l->cardinalidade = 0;
	l->vetor[l->tamanho];
	return l;
}

int IncluirLista(Lista *l, int x){
	if(l->cardinalidade < l->tamanho){
		l->vetor[l->cardinalidade] = x;
		l->cardinalidade = l->cardinalidade + 1;
		return l->cardinalidade;
	}
	return -1;
}

void ImprimeLista(Lista *l){
	int i = 0;
	for(i = 0; i < l->cardinalidade; i++){
		printf("Elemento - %d\n", l->vetor[i]);
	}
		
}

int BuscaLista(Lista *l, int x){
	int i = 0;
	while(i < l->cardinalidade){
		if(l->vetor[i] == x){
			return i;
		}
		i++;
	}
	return -1;
}

void RemoveTodos(Lista *l, int x){
	int i;
	i = BuscaLista(l, x);
	while(i >= 0){
		l->cardinalidade = l->cardinalidade - 1;
		l->vetor[i] = l->vetor[l->cardinalidade];
		i = BuscaLista(l, x);
	}
}

int main(){
	Lista *z;
	int el = 5, i, contd, ctrl;
	z = CriarLista(el);
	printf("Criada lista de tamanho %d\n", z->tamanho);
	printf("Digite quantos elementos a inserir\n");
	scanf("%d", &el);
	for(i = 0; i < el; i++){
		printf("Digite o elemento\n");
		scanf("%d", &contd);	
		IncluirLista(z, contd);
	}
	
	ImprimeLista(z);
	printf("Digite um elemento para excluir\n");
	scanf("%d", &el);
	RemoveTodos(z, el);
	ImprimeLista(z);
	free(z);
	return 0;
}
