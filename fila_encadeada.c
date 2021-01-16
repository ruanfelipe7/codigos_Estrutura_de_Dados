#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	int chave;
	struct No *proximo;
} No; 

No *CriarFilaEnc(){
	No *v = malloc (sizeof (No));
	v->proximo = NULL; 
	return v;
}

No *FrontEncadeada(No *v){
	return v->proximo;
}


void EnfileirarEncadeada(No *v, int x){
	No *u = malloc (sizeof(No));
	u->chave = x;
	while(v->proximo != NULL){
		v = v->proximo;
	}
	u->proximo = NULL;
	v->proximo = u; 
}

No *DesenfileiraEncadeada(No *v){
	No *r = malloc (sizeof(No));
	if(v->proximo == NULL)
		return NULL;
	r = v->proximo;
	v->proximo = r->proximo;
	return r;	
}


int main(){
	No *v;
	int n = 0, x = 0, i = 0;
	v = CriarFilaEnc();
	printf("Digite o valor de n\n");
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		printf("Digite o valor de x\n");
		scanf("%d", &x);
		EnfileirarEncadeada(v, x);
	}
	
	printf("Frente da Fila - %d\n", FrontEncadeada(v)->chave);
	
	printf("\n\nDesenfileirando\n\n");
	while(FrontEncadeada(v) != NULL){
		printf("%d\n", DesenfileiraEncadeada(v)->chave);
	}
	
	free(v);
	return 0;
}
