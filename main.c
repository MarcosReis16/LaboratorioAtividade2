#include <stdio.h>
#include <stdlib.h>
#include "ModuloFuncoes.h"

int main(){

    int op,i,j;
    int sair = 0;
    VetorPrincipal vet[10];


    while (!sair){
        op = menu();
        switch (op){
            case 0:{
                sair =1;
                break;
            }
            case 1:{ //inserir
                printf("Digite a posicao do vetor que deseja inserir um valor:\n");
                scanf("%d", &i);

                if (vet[i].auxiliar == NULL){
                    printf("Nosso vetor ainda nao tem um tamanho. Digite um tamanho para ele:\n");
                    scanf("%d", &j);
                    vet[i].auxiliar = (int*)malloc(sizeof(int)*j);
                }



                break;
            }

            case 2:{ //excluir
                //TODO
                break;
            }
            default:{
                printf("opcao inválida\n");
            }


        }


    }

    return 0;

}
