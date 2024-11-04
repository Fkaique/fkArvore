#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int global;
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
        return novo;
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
    if (global==0){
          printf("%d",raiz->info);
          global=1;   //raiz
      }else{
          printf(" %d",raiz->info);
      }   //raiz
    impr_pre(raiz->left);         //sub left
    impr_pre(raiz->right);         //sub right
  }
}

void impr_ord(Arv * raiz){
  if (raiz!=NULL) {
    impr_ord(raiz->left);         //sub left
    if (global==0){
          printf("%d",raiz->info);
          global=1;   //raiz
      }else{
          printf(" %d",raiz->info);
      }   //raiz
    impr_ord(raiz->right);         //sub right
  }
}

void impr_pos(Arv * raiz){
  if (raiz!=NULL) {
      impr_pos(raiz->left);         //sub left
      impr_pos(raiz->right);         //sub right
      if (global==0){
          printf("%d",raiz->info);
          global=1;
      }else{
          printf(" %d",raiz->info);
      }
  }
}
int busca(int info, Arv* raiz){
    if (raiz!=NULL){
        if (raiz->info==info){
            return 1;
        }else if (info < raiz->info){
            return busca(info, raiz->left);
        }else{
            return busca(info, raiz->right);
        }
    }
    return 0;
}

Arv *remover(int info, Arv* raiz){
    if(raiz==NULL){
        return NULL;
    }else if (info < raiz->info){
        raiz->left=remover(info, raiz->left);
    }else if (info > raiz->info){
        raiz->right=remover(info, raiz->right);
    }else{
        if (raiz->left==NULL && raiz->right==NULL){
            free(raiz);
            raiz=NULL;
        }else if(raiz->left==NULL){
            Arv* aux=raiz;
            raiz=raiz->right;
            free(aux);
        }else if(raiz->right==NULL){
            Arv* aux=raiz;
            raiz=raiz->left;
            free(aux);
        }else{
            Arv* aux=raiz->left;
            while (aux->right!=NULL){
                aux=aux->right;
            }
            raiz->info=aux->info;
            raiz->left=remover(info,raiz->left);
        }
    }
    return raiz;
}
int main(){
    char option[9];
    int info;
    int value;
    Arv* arv=NULL;
    while(scanf("%s", option) != EOF){
        if(strcmp(option,"INFIXA") == 0){
            global=0;
            impr_ord(arv);
            printf("\n");
        }else if(strcmp(option,"PREFIXA") == 0){
            global=0;
            impr_pre(arv);
            printf("\n");
        }else if(strcmp(option,"POSFIXA") == 0){
            global=0;
            impr_pos(arv);
            printf("\n");
        }else if (option[0]=='I'){
            scanf("%d", &info);
            arv=ins_arv(info,arv);
        }else if(option[0]=='P'){
            scanf("%d", &info);
            value = busca(info, arv);
            if (value==1){
                printf("%d existe\n", info);
            }else{
                printf("%d nao existe\n", info);
            }
        }else if(option[0]=='R'){
            scanf("%d", &info);
            arv=remover(info, arv);
        }
    }
    return 0;
}