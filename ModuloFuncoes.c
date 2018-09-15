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
    printf("5 - Lista Vetor Auxiliar Ordenado\n");
    printf("6 - Lista todos os elementos ordenados\n");
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
    int *v = (int *)malloc((vet[i].cont - 1) * sizeof(int));

    int find = 0;

    for (int j = 0, l = 0; j < vet[i].cont; j++) {
        if (vet[i].auxiliar[j] != valor)
            v[l++] = vet[i].auxiliar[j];
        else
            find = 1;
    }

    if (find) {
        vet[i].cont--;

        free(vet[i].auxiliar);

        vet[i].auxiliar = v;
    }
    else
        free(v);
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

void transfereConteudo(VetorPrincipal *vet,int i,int *vetorAlvo){
    for(int j=0;j<vet[i].cont;j++){
        vetorAlvo[j] = vet[i].auxiliar[j];
    }
}

void insertionSort(int *vetor, int tamanho){
    int i, j, aux;
    for(i=1;i<tamanho;i++){
        aux=vetor[i];
        for(j=i-1;(j>=0)&&(aux<vetor[j]);j--){
            vetor[j+1]=vetor[j];
        }
        vetor[j+1]=aux;
    }
}

void listaVetorInt(int *vetor,int quantidade){
    for(int i =0;i<quantidade;i++){
        printf("%d\n",vetor[i]);
    }
}
