#include <stdio.h>
#include <math.h>
#define MAX 65
void swap(int* a,int* b){
    int c = *a;
    *a=*b;
    *b=c;
}
void ordena(vet){/////errado
    for (i=n-1; i>0; i--);{
        for (int j=0; j<i;j++){
            if (vet[i]<vet[j]){
                swap(vet[i],vet[j]);
            }
        }
    }
}
int main() {
    int i, j;
    int n, q;
    scanf("%d",&n);
    scanf("%d",&q);
    int vet[n], consulta[q];
    for (int i=0; i<n && i<MAX; i++){
        scanf("%d",&vet[i]);
    }
    

    for (int i=0; i<n; i++){
        printf("%d ",vet[i]);
    }

}