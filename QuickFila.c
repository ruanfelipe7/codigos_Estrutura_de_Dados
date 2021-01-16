#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

typedef struct noh {
    struct noh* prox;
    int a, b;
} noh;

noh* CriaFila() {
    noh* v = malloc(sizeof(noh));
    v->prox=NULL;
    return v;
}

void ImprimeFila(noh* v) {
    if(v->prox==NULL) {
        printf("Fila vazia!\n");
    }
    while(v->prox!=NULL) {
        v=v->prox;
        printf("%d %d\n%",v->a,v->b);
    }
}

noh* Front(noh* v) {
    return v->prox;
}

void Enfileira(noh* v, int a, int b) {
    noh* u = malloc(sizeof(noh));
    u->a=a;
    u->b=b;
    u->prox=NULL;
    while(v->prox!=NULL) {
        v=v->prox;
    }
    v->prox=u;
}

noh* Desenfileira(noh* v) {
    noh* r = malloc(sizeof(noh));
    r=v->prox;
    v->prox=r->prox;
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

void QuickFila(int V[], int p, int r) {
    noh* v = CriaFila();
    noh* x;
    int q;
    Enfileira(v,p,r);
    while(Front(v)!=NULL) {
        x = Desenfileira(v);
        if(x->a < x->b) {
            q=Partition(V,x->a,x->b);
            Enfileira(v,x->a,q-1);
            Enfileira(v,q+1,x->b);
        }
    }
}

int main() {
    int i,n,k=100;
    printf("Insira a quantidade de elementos do vetor: ");
    scanf("%d",&n);
    int V[n];

    srand(time(NULL));
    for(i=0;i<n;i++) {
        V[i] = rand()%k;
    }
    
    printf("\nVetor antes da ordenacao:\n");
    for(i=0;i<n;i++) {
        printf("%d ",V[i]);
    }
    printf("\n\n");
    
    QuickFila(V,0,n-1);
    
    printf("\nVetor apos a ordenacao:\n");
    for(i=0;i<n;i++) {
        printf("%d ",V[i]);
    }
    printf("\n\n");
    
    system("PAUSE");
    
    return(0);
}
