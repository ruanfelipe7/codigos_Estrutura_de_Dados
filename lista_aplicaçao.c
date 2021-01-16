#include <stdio.h>
#include <string.h>

typedef struct Pessoa{
	int id;
	char nome[20];
	long int cpf;
} Pessoa;

typedef struct Lista{
	int cardinalidade;
	int tamanho;
	Pessoa pessoas[];
} Lista;

Lista CriarLista(int n){
	Lista l;
	l.tamanho = n;
	l.cardinalidade = 0;
	l.pessoas[n];
	return l;
}

void ImprimePessoa(Pessoa p){
	printf("---------------Pessoa------------------\n");
	printf("ID: %d\n", p.id);
	printf("NOME: %s\n", p.nome);
	printf("CPF: %ld\n\n", p.cpf);
	
}

int BuscaLista(Lista *l, int x){
	int i = 0;
	while(i < l->cardinalidade){
		if(l->pessoas[i].id == x){
			return i;
		}
			
		i++;	
	}
	return -1;
} 

int IncluirLista(Lista *l, Pessoa p){
	if(l->cardinalidade < l->tamanho){
	
		
		l->pessoas[l->cardinalidade] = p;	
		l->cardinalidade++;
		return l->cardinalidade;
	}
	
	return -1;
}

int ExcluirLista(Lista *l, int x){
	int i = 0;
	i = BuscaLista(l, x);
	if(i >= 0){
		l->cardinalidade--;
		l->pessoas[i] = l->pessoas[l->cardinalidade];
	}
	return i;
}

void ImprimeLista(Lista *l){
	int i = 0;
	while(i < l->cardinalidade){
		printf("Pessoa ID: %d\n:",l->pessoas[i].id );
		printf("Pessoa NOME: %s\n:",l->pessoas[i].nome );
		printf("Pessoa CPF: %li\n\n:",l->pessoas[i].cpf );
		i++;	
	}
}

Pessoa GetDados(){
	Pessoa k;
	printf("Digite sua id:\n");
	scanf("%d", &k.id);
	printf("Digite seu nome:\n");
	scanf(" %s", k.nome);
	printf("Digite seu cpf:\n");
	scanf("%li", &k.cpf);
	return k;
}

void Limpar(){
	system("cls");
}


int main(){
	int ctrl, tam, teste = 0;
	Pessoa t;
	Lista list;
	do{
		printf("Escolha uma das opções\n");
		printf("1 - Criar Lista de Pessoas\n");
		printf("2 - Incluir Pessoa na Lista\n");
		printf("3 - Buscar Pessoa na Lista\n");
		printf("4 - Excluir Pessoa da Lista\n");
		printf("0 - Sair\n\n");
		scanf("%d", &ctrl);
		
		switch(ctrl){
			case 1:
				printf("Digite o tamanho da lista:\n");
				scanf("%d", &tam);
				list = CriarLista(tam);
				if(list.tamanho){
					Limpar();
					printf("Lista Criada com Sucesso\n\n\n");
				}
			
			break;	
			
			case 2:
				t = GetDados();
				teste = IncluirLista(&list, t);
				if(teste > 0){
					Limpar();
					printf("Pessoa inserida na lista\n\n");
					ImprimePessoa(list.pessoas[teste - 1]);
					ImprimeLista(&list);
				}else{
					Limpar();
					printf("Lista Cheia\n\n");
				}
			break;
			
			case 3:
				printf("Digite a id da pessoa a ser buscada\n");
				scanf("%d", &tam);
				teste = BuscaLista(&list, tam);
				if(teste >= 0){
					Limpar();
					printf("Pessoa encontrada na Lista\n\n");
			 	ImprimePessoa(list.pessoas[teste]);
				}	
				else{
					Limpar();
					ImprimeLista(&list);
					printf("Pessoa nao encontrada na Lista\n\n");
				}
			
			break;	
			case 4:
				printf("Digite a id da pessoa a ser excluida\n");
				scanf("%d", &tam);
				teste = ExcluirLista(&list, tam);
				if(teste >= 0){
					Limpar();
					printf("Pessoa excluida da lista\n\n");
					ImprimeLista(&list);
				}else{
					Limpar();
					printf("Pessoa nao encontrada na lista\n\n");
					ImprimeLista(&list);
				}
				
			break;
			
			default:
				printf("Opcao Inexistente\n\n");	
		}
				
	}while(ctrl);
	
	return 0;
}
