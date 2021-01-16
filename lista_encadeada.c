#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	int chave;
	struct No *proximo;
} No; 

No *CriarListaEncadeada(){
	No *v = malloc (sizeof (No));
	v->proximo = NULL; 
	return v;
}

void InsereListaEncadeada(No *v, int x){
	No *u = malloc (sizeof(No));
	u->chave = x;
	u->proximo = v->proximo;
	v->proximo = u;
}

void Listar(No *v){
	while(v->proximo != NULL){
		v = v->proximo;
		printf("Elemento: %d\n", v->chave);
	}
}

void ListarInverso(No *v){
	No *p;
	int trocado = 0;
	p = v;
	while(p->proximo != NULL){
		trocado = 0;
		if(p->proximo->proximo == NULL){
			printf("ELEMENTO INVERSO - %d\n", p->proximo->chave);
			p->proximo = NULL;
			trocado = 1;
		}
		if(trocado){
			p = v;
		}else{
			p = p->proximo;
		}
		
	}	
}


int TamanhoListaEncadeada(No *v){
	int cont = 0;
	while(v->proximo != NULL){
		v = v->proximo;
		cont++;
	}
	return cont;
}

void ListarInv(No *v){
	int t, i = 0;
	No *inicio;
	inicio = v;
	t = TamanhoListaEncadeada(v);
	for(i = 0; i < t; t--){
		v = v->proximo;
		if(i == (t - 1)){
			printf("Elemeneto inverso: %d\n", v->chave);
			v = inicio;
		}
	}
}

void ListarInversoRec(No *v){
	if(v != NULL){
		ListarInversoRec(v->proximo);
		printf("El INv: %d\n", v->chave);
	}
}


void RemoveTodos(No *v, int x){
	No *r, *inicio;
	inicio = v;
	int trocado = 0;
		while(v->proximo != NULL){
			trocado = 0;
			if(v->proximo->chave == x){
				v->proximo = v->proximo->proximo;
				trocado = 1;
			}
			v = v->proximo;
			if(trocado){
				v = inicio;
			}
		}	
}

int main(){
	No *v;
	int n = 0, x = 0, i = 0;
	v = CriarListaEncadeada();
	printf("Digite o valor de n\n");
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		printf("Digite o valor de x\n");
		scanf("%d", &x);
		InsereListaEncadeada(v, x);
	}
	
	Listar(v);
	printf("Tamanho da Lista - %d\n", TamanhoListaEncadeada(v));
	ListarInversoRec(v->proximo);
	printf("Digite um valor a ser excluido\n");
	scanf("%d", &x);
	RemoveTodos(v, x);
	Listar(v);
	
	free(v);
	return 0;
}
