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
    printf("4 - Redimensionar Espaço\n");
    printf("5 - \n");
    scanf("%d", &op);
    return op;
}

void alocarMemoria(VetorPrincipal *vet,int indice){
    vet[indice].auxiliar = (int*)malloc(sizeof(int)*(vet[indice].tamanho));
    if (vet[indice].auxiliar == NULL){
        exit(1);
    }

}

void realocarMemoria(VetorPrincipal *vet, int indice){
    vet[indice].auxiliar = (int*)realloc(vet[indice].auxiliar,vet[indice].tamanho*sizeof(int));
    if(vet[indice].auxiliar == NULL){
        exit(1);
    }
}

void apagaValorMemoria(VetorPrincipal *vet,int i, int valor){
    int j,k,troca;
    for(j=0;vet[i].auxiliar[j]<vet[i].auxiliar[vet[i].cont];j++){
        if(vet[i].auxiliar[j]==valor){
            for(k=j;vet[i].auxiliar[j]<vet[i].auxiliar[vet[i].cont];k++){
                if(vet[i].auxiliar[k+1]!=vet[i].auxiliar[vet[i].cont]){
                    vet[i].auxiliar[k]=vet[i].auxiliar[k+1];
                }
            }
        vet[i].cont--;
        break;
        }
    }
}

void listaVetor(VetorPrincipal *vet, int i){
    printf("Temos %d elementos neste vetor.\n",vet[i].cont);
    for(int j=0;j<vet[i].cont;j++){
        printf("Valor: %d \n",vet[i].auxiliar[j]);
    }
}

void inserirValor(VetorPrincipal *vet, int i, int valor){
    vet[i].auxiliar[vet[i].cont]= valor;
    vet[i].cont = vet[i].cont + 1;
}
