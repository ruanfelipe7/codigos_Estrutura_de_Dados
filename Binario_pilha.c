#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No* prox;
} No;

No* CriaPilha() {
    No* v = malloc(sizeof(No));
    v->prox=NULL;
    return v;
}

No* Top(No* v) {
    return v->prox;
}

void Empilha(No* v, int x) {
    No* u = malloc(sizeof(No));
    u->chave=x;
    u->prox=v->prox;
    v->prox=u;
}

No* Desempilha(No* v) {
    if(v->prox==NULL) {
        return NULL;
    }
    No* r = v->prox;
    v->prox=v->prox->prox;
    return r;
}

int main(){
	int n, aux;
	No *pilha = CriaPilha();
	printf("Digite um numero n\n");
	scanf("%d", &n);
	while( n > 0){
		Empilha(pilha, n%2);
		n /= 2;
	}
	
	printf("Em binario: ");
	while(Top(pilha) != NULL){
		printf("%d", Desempilha(pilha)->chave);
	}
	return 0;
}
