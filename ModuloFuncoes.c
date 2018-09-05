#include <stdlib.h>
#include <stdio.h>

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
    vet[indice]->auxiliar = (int*)malloc(sizeof(int)*vet[indice].tamanho);
    if (vet[indice]->auxiliar == NULL){
        exit(1);
    }
    vet[indice].cont++;
}

void realocarMemoria(VetorPrincipal *vet, int indice){
    vet[indice]->auxiliar = (int*)realloc(vet[indice]->auxiliar,vet[indice].tamanho*sizeof(int))
    if(vet[indice]->auxiliar == NULL){
        exit(1);
    }
    vet[indice].cont++;
}
