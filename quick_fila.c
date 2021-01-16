#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	int num1, num2;
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


void EnfileirarEncadeada(No *v, int a, int b){
	No *u = malloc (sizeof(No));
	u->num1 = a;
	u->num2 = b;
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

int Partition(int S[], int p, int r) {
    int i, j, x, aux;
    x = S[p];
    i = p;
    j = r;
    while(i<j) {
        while(S[i]<=x) {
            i++;
        }
        while(S[j]>x) {
            j--;
        }
        if (i<j) {
            aux = S[i];
            S[i] = S[j];
            S[j] = aux;
        }
    }
    S[p] = S[j];
    S[j] = x;
    return j;
}

void QuickFila(int v[], int p, int r){
	int quebra;
	No *fila = CriarFilaEnc();
	No *aux;
	EnfileirarEncadeada(fila, p, r);
	while(FrontEncadeada(fila) != NULL){
		aux = DesenfileiraEncadeada(fila);
		if(aux->num1 < aux->num2){
			quebra = Partition(v, aux->num1, aux->num2);
			EnfileirarEncadeada(fila, aux->num1, quebra - 1);
			EnfileirarEncadeada(fila, quebra + 1, aux->num2);
		}
	}
}

int main(){
	int n, i;
	printf("Digite o tamanho do vetor\n");
	scanf("%d", &n);
	
	int vetor[n];
	
	for(i = 0; i < n; i++){
		printf("Digite um numero\n");
		scanf("%d", &vetor[i]);
	}
	
	QuickFila(vetor, 0, n-1);
	printf("Em ordem\n");
	
	for(i = 0; i < n; i++){
		printf("%d\n", vetor[i]);
	}
	
	return 0;
}

