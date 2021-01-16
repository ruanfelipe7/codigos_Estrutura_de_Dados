#include <stdio.h>

int Mediana(int vetor[], int n){
	int i, j, meio = 0, meio2 = 0;
	if(n > 1){
		
		
		if(n % 2 == 0){
			meio = n/2;	
			meio2 = n/2;	
		}
		else{
			meio = (n/2) + 1;
			meio2 = (n/2);
		}
		
		int A[meio], B[meio2];
		
		for(i = 0; i < n; i++){
			A[i] = vetor[i];
			B[i] = vetor[i + meio];
		}
		Mediana(A,meio);
		Mediana(B, meio2);
	}
	if(n == 1){
		return vetor[0];	
	}
	
}

int main(){
	int n, i = 0;
	printf("Digite um valor n\n");
	scanf("%d", &n);
	int V[n];
	for(i = 0; i < n; i++){
		printf("Digite os valores do vetor\n");
		scanf("%d", &V[i]);
	}
	printf("Mediana: %d", Mediana(V,n) );
	return 0;
}
