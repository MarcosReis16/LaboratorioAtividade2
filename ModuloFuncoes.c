#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "ModuloFuncoes.h"

int menu(){
    int op;
    printf("Digite as opção desejada\n");
    printf("0 - Sair\n");
    printf("1 - Inserir\n");
    printf("2 - Excluir\n");
    printf("3 - Listar\n");
    printf("4 - \n");
    printf("5 - \n");
    scanf("%d", &op);
    return op;
}

void alocarMemoria(VetorPrincipal *vet,int indice){
    vet[indice].auxiliar = (int*)malloc(sizeof(int)*vet[indice].tamanho);
    if (vet[indice].auxiliar == NULL){
        exit(1);
    }
    else{
        vet[indice].cont++;
    }
}

void realocarMemoria(VetorPrincipal *vet, int indice){
    vet[indice].auxiliar = (int*)realloc(vet[indice].auxiliar,vet[indice].tamanho*sizeof(int));
    if(vet[indice].auxiliar == NULL){
        exit(1);
    }
    else{
        vet[indice].cont++;
    }
}

void apagaValorMemoria(VetorPrincipal *vet,int i, int valor){
    int j,k,troca;
    for(j=0;vet[i].auxiliar[j]!=NULL;j++){
        if(vet[i].auxiliar[j]==valor){
            for(k=j;vet[i].auxiliar[k]!=NULL;k++){
                if(vet[i].auxiliar[k+1]!=NULL){
                    vet[i].auxiliar[k]=vet[i].auxiliar[k+1];
                }
            }
        vet[i].cont--;
        break;
        }
    }
}
