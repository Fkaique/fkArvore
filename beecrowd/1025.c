#include <stdio.h>
#include <math.h>
#define MAX 65
void swap(int* a,int* b){
    int c = *a;
    *a=*b;
    *b=c;
}
void ordena(int vet[], int qtd){/////errado
    int i, j; 
    for (i=0; i<qtd; i++){
        for(j=i+1; j<qtd; j++){
            if (vet[i]>vet[j]){
                swap(&vet[i],&vet[j]);
            }
        }
    }
}
int consulta(int vetor[] ,int value, int qtd){
    for (int i=1; i<=qtd; i++){
        if (value==vetor[i]){
            return i;
        }
        printf("%d ",vetor[i]);
    }
    return 0;
}
int main() {
    int i, j;
    int n, q;
    scanf("%d",&n);
    scanf("%d",&q);
    int vet[n], consult[q];
    for (int i=0; i<n && i<MAX; i++){
        scanf("%d",&vet[i]);
    }
    for (int i=0; i<q && i<MAX; i++){
        scanf("%d",&consult[i]);
    }
    ordena(vet, n);
    printf("%d",consulta(&vet, consult, n));
}