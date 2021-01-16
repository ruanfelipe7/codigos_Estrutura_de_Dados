#include <stdio.h>

void MatProd(int m, int n, int p, int A[m][n], int B[n][p]){
	int i, j, k;
	int result[m][p];
	for(i = 0; i < m; i++){
		for(j = 0; j < p; j++){
			result[i][j] = 0;
			for(k = 0; k < n; k++){
				result[i][j] = (result[i][j] + (A[i][k] * B[k][j]));
			}
		}
	}
	for(i = 0; i < m; i++){
		for(j = 0; j < p; j++){
			printf("%d  ", result[i][j]);
		}
		printf("\n");
	}
	
}

int main(){
	int m, n, p;
	printf("DIgite o valor de m, n, p\n");
	scanf("%d%d%d", &m, &n, &p);
	int matriz1[m][n];
	int matriz2[n][p];
	int i = 0, j = 0;
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("Digite o valor da matriz 1: \n");
			scanf("%d", &matriz1[i][j]);
		}
	}
	for(i = 0; i < n; i++){
		for(j = 0; j < p; j++){
			printf("Digite o valor da matriz 2: \n");
			scanf("%d", &matriz2[i][j]);
		}
	}
	
	MatProd(m,n,p, matriz1, matriz2);
	
	
	return 0;
}
