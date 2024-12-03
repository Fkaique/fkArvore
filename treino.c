#include <stdio.h>
#include <stdlib.h>

typedef struct arv
{
    int info;
    struct arv* right;
    struct arv* left;
}Arv;

Arv* inserir(int info, Arv* raiz){
    if (raiz==NULL){
        Arv* novo=(Arv*)malloc(sizeof(Arv));
        novo->info=info;
        novo->right=novo->left=NULL;
        return novo;
    }else{
        if (info<raiz->info){
            raiz->left=inserir(info,raiz->left);
        }else{
            raiz->right=inserir(info,raiz->right);
        }
    }
    return raiz;
}
void imp_pre(Arv* raiz){
    if (raiz!=NULL){
        printf(" %d",raiz->info);
        imp_pre(raiz->left);
        imp_pre(raiz->right);
    }
}
void imp_ord(Arv* raiz){
    if (raiz!=NULL){
        imp_ord(raiz->left);
        printf(" %d",raiz->info);
        imp_ord(raiz->right);
    }
}
void imp_pos(Arv* raiz){
    if (raiz!=NULL){
        imp_pos(raiz->left);
        imp_pos(raiz->right);
        printf(" %d",raiz->info);
    }
}
int busca(int info, Arv* raiz){
    if(raiz!=NULL){
        if (info>raiz->info){
            busca(info,raiz->right);
        }else if(info<raiz->info){
            busca(info,raiz->left);
        }else{
            return 1;
        }
    }
    return 0;
}
Arv* remover(int info, Arv* raiz){
    if(raiz==NULL){
        return NULL;
    }else if(info>raiz->info){
        raiz->right=remover(info, raiz->right);
    }else if(info<raiz->info){
        raiz->left=remover(info, raiz->left);
    }else{
        if(raiz->left==NULL && raiz->right==NULL){
            free(raiz);
            raiz=NULL;
        }else if (raiz->left==NULL){
            Arv* aux=raiz;
            raiz=raiz->right;
            free(aux);
        }else if (raiz->right==NULL){
            Arv* aux=raiz;
            raiz=raiz->left;
            free(aux);
        }else{
            Arv* aux=raiz->left;
            while(aux->right!=NULL){
                aux=aux->right;
            }
            raiz->info=aux->info;
            raiz->left=remover(info,raiz->left);
        }
    }
    return raiz;
}
int main(){
    Arv* arv=NULL;
    arv=inserir(30,arv);
    arv=inserir(15,arv);
    arv=inserir(40,arv);
    arv=inserir(10,arv);
    arv=inserir(20,arv);
    arv=inserir(35,arv);
    arv=inserir(50,arv);
    arv=inserir(5,arv);
    arv=inserir(12,arv);
    arv=inserir(18,arv);
    imp_pre(arv);
    printf("\n");
    imp_ord(arv);
    printf("\n");
    imp_pos(arv);
    return 0;
}