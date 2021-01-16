#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int vetor[], int p, int r);
void BubbleSort2(int vetor[], int p, int r);
void SelectionSort(int vetor[], int p, int r);
void InsertionSort(int vetor[], int p, int r);
void MergeSort(int vetor[], int p, int r);
void Merge(int vetor[], int p, int q, int r);
int Partition(int vetor[], int p, int r);
int RandonPartition(int vetor[], int p, int r);
void QuickSort(int vetor[], int p, int r);
void CountingSort(int vetor[], int n, int k);
void QuickIterativo(int vetor[], int p, int r);
int MaximoVetor(int vetor[], int q);
void PreencherVetor(int vetor[], int f);
void ImprimeVetor(int vetor[], int f);
int RandomizedPartition(int vetor[], int p, int r);

int main(){
	int tam = 0, i;
	printf("Digite o tamanho do vetor: \n");
	scanf("%d", &tam);
	int v[tam];

	PreencherVetor(v, tam);
	//BubbleSort(v, 0, tam);
	//SelectionSort(v, 0, tam);
	//InsertionSort(v, 0, tam);
	//printf("%d", MaximoVetor(v, tam));
	//MergeSort(v, 0, tam - 1);
	//QuickSort(v, 0, tam - 1);
	//BubbleSort2(v, 0, tam);
	CountingSort(v, tam, 20);
	//QuickIterativo(v, 0, tam - 1);
	ImprimeVetor(v, tam);
	return 0;
}


void PreencherVetor(int vetor[], int f){
	int i = 0;	
	for(i = 0; i < f; i++){
		printf("Digite os elementos do vetor: \n");
		scanf("%d", &vetor[i]);
	}	
}

void ImprimeVetor(int vetor[], int f){
	int i = 0;
	for(i = 0; i < f; i++){
		printf("\n %d", vetor[i]);
	}	
	
}

void BubbleSort(int vetor[], int p, int r) {
	int m, troca, i;
	while(r > p){
		m = p;
		for(i = p + 1; i < r; i++ ){
			if(vetor[i] > vetor[m]){
				m = i;
			}
		}
		
		troca = vetor[r - 1];
		vetor[r - 1] = vetor[m];
		vetor[m] = troca;
		r--;
	}	
}

void BubbleSort2(int vetor[], int p, int r){
	int i, trocado = 0, troca = 0;
	do{	
		trocado = 0;
		for(i = p; i < r; i++){
			if(vetor[i] > vetor[i+1]){
				trocado = 1;
				troca = vetor[i];
				vetor[i] = vetor[i + 1];
				vetor[i + 1] = troca;
			}
		}
	}while(trocado);
}

void SelectionSort(int vetor[], int p, int r) {
	int m, troca, i;
	while(r > p){
		m = p;
		for(i = p + 1; i < r; i++ ){
			if(vetor[i] < vetor[m]){
				m = i;
			}
		}
		
		troca = vetor[p];
		vetor[p] = vetor[m];
		vetor[m] = troca;
		p++;
	}
}

void InsertionSort(int vetor[], int p, int r) {
	int x, i, j;
	for(i = p + 1; i < r; i++){
		x = vetor[i];
		j = i - 1;
		while(j >= p && vetor[j] > x){
			vetor[j + 1] = vetor[j];
			j--;
		}
		vetor[j + 1] = x;
	}
}

int MaximoVetor(int vetor[], int q){
	int i = 0, max = 0;
	max = vetor[i];
	for(i = 1; i <= q; i++){
		if(max < vetor[i])
			max = vetor[i];
	}
	max++;
	return max;
}

void Merge(int vetor[], int p, int q, int r){
	int n1 = 0, n2 = 0, i = 0, j = 0, k = 0;
	n1 = q - p + 1;
	n2 = r - q;
	int L[n1 + 1], R[n2 + 1];
	for(i = 0;i < n1; i++){
		L[i] = vetor[p + i];
	}
	for(j = 0; j < n2; j++)
		R[j] = vetor[q + j + 1];
		
	L[n1] = MaximoVetor(vetor, r);	
	R[n2] = MaximoVetor(vetor, r);

	
	i = 0;
	j = 0;
	for(k = p; k < (r + 1);  k++){
		if(L[i] <= R[j]){
			vetor[k] = L[i];
			i++;
		}else{
			vetor[k] = R[j];
			j++;
		}
	}
	
}	

void MergeSort(int vetor[], int p, int r){
	int q;
	if(p < r){
		q = (p + r) / 2;
		MergeSort(vetor, p, q);
		MergeSort(vetor, q + 1, r);
		Merge(vetor, p, q, r);
	}
	
}

int Partition(int vetor[], int p, int r){
	int x = 0, i = 0, j = 0, troca = 0;
	x = vetor[p];
	i = p;
	j = r;
	while(i < j){
		while(vetor[i] <= x){
			i++;
		}
		while(vetor[j] > x){
			j--;
		}
		if(i < j){
			troca = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = troca;
		}
	}
	
	vetor[p] = vetor[j];
	vetor[j] = x;
	return j;
}

int RandonPartition(int vetor[], int p, int r){
	int x = 0, i = 0, j = 0, troca = 0, indice = 0;
	srand( (unsigned)time(NULL) );
	indice = p + rand() % r;
	while(indice > r){
		indice = p + rand() % r;	
	}
	x = vetor[indice];	
	
	
	printf("Pivo escolhido - %d\n", x);
	printf("INDICE - %d\n", indice);
	i = p;
	j = r;
	troca = vetor[i];
	vetor[i] = x;
	vetor[indice] = troca;
	while(i < j){
		while(vetor[i] <= x){
			i++;
		}
		while(vetor[j] > x){
			j--;
		}
		if(i < j){
			troca = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = troca;
		}
	}
	
	vetor[p] = vetor[j];
	vetor[j] = x;
	return j;
}

int RandomizedPartition(int vetor[], int p, int r){
	int indice = 0, q;
	srand( (unsigned)time(NULL) );
	indice = p + rand() % r;
	while(indice > r){
		indice = p + rand() % r;	
	}
	q = vetor[indice];	
	vetor[indice] = vetor[p];
	vetor[p] = q;
	return Partition(vetor, p, r);
	
}

void QuickSort(int vetor[], int p, int r){
	int q = 0;
	if(p < r){
		q = RandomizedPartition(vetor, p, r);
		QuickSort(vetor, p, q-1);
		QuickSort(vetor, q+1, r);
	}
}

void CountingSort(int vetor[], int n, int k){
	int B[n], C[k+1], i = 0, j = 0;
	for(i = 0; i < k;i++)
		C[i] = 0;
	for(j = 0; j < n; j++)
		C[vetor[j]] = C[vetor[j]] + 1;
	for(i = 0; i < k; i++)	
		C[i] = C[i] + C[i-1];
	for(j = n-1;j>=0; j++){
		B[C[vetor[j]]] = vetor[j];
		C[vetor[j]] = C[vetor[j]] - 1;
	}
	
	for(i = 0; i < n; i++)
		vetor[i] = B[i];
}

void QuickIterativo(int vetor[], int p, int r){
	int q;
	q = Partition(vetor, p, r);
	BubbleSort2(vetor,p, q);
	BubbleSort2(vetor,q+1, r+1);
}	
