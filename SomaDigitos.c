#include <stdio.h>

 int SomaDigitos(long long int n){
	return n+ n==0? 0: (n % 10) + SomaDigitos(n/10);
}

int main(){
	long long int n = 0;
	printf("Digite um numero n\n");
	scanf("%lli", &n);
	printf("Soma de digitos - %d", SomaDigitos(n));
	return 0;
}
