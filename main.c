#include <stdio.h>
#include <stdlib.h>

typedef struct arv{
    int info;
    struct arv *right;
    struct arv *left;
}Arv;

Arv *ins_arv(int info, Arv *raiz){
    if (raiz == NULL){
        Arv* novo=(Arv*)malloc(sizeof(Arv));
        novo->info = info;
        novo->right = novo->left = NULL;
    }else{
        if (info < raiz->info){
            raiz->left = ins_arv(info, raiz->left);
        }else{
            raiz->right = ins_arv(info, raiz->right);
        }
    }
    return raiz;
}

void impr_pre(Arv * raiz){
  if (raiz!=NULL) {
    printf("%c ",raiz->info );   //raiz
    impr_pre(raiz->left);         //sub left
    impr_pre(raiz->right);         //sub right
  }
}

void impr_ord(Arv * raiz){
  if (raiz!=NULL) {
    impr_ord(raiz->left);         //sub left
    printf("%c ",raiz->info );   //raiz
    impr_ord(raiz->right);         //sub right
  }
}

void impr_pos(Arv * raiz){
  if (raiz!=NULL) {
    impr_pos(raiz->left);         //sub left
    impr_pos(raiz->right);         //sub right
    printf("%c ",raiz->info );   //raiz
  }
}

int main(){
    int i=0;
    int info, value=-1;
    Arv *a;
    while(1){
        printf("Escolha uma das opcoes abaixo: \n");
        printf("0 (sair)\n1 (print in)\n2 (print in)\n3 (print pos)\n4 (inserir)\n");
        scanf("%d",&value);
        if (value!=1 && value!=2 && value!=3 && value!=4 && value!=0 && value!=5){
            printf("ERRO! digite um dos comandos abaixo: \n");
            printf("0 (sair)\n1 (print in)\n2 (print in)\n3 (print pos)\n4 (inserir)\n");
        }
        switch(value){
            case 1: 
                impr_pre(a);
            break;
            case 2: 
                impr_ord(a);
            break;
            case 3: 
                impr_pos(a);
            break;
            case 4: 
                printf("digite o caracter a ser inserido: ");
                scanf("%d",&info);
                ins_arv(info,a);
            break;
            case 0: 
                return 0;
            break;
            case 5: printf("NEH");
            break;
            default: printf("NEH");
        }
    }
    return 0;
}