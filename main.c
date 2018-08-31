#include <stdio.h>
#include <stdlib.h>
#include "ModuloFuncoes.h"

int main(){

    int op,i,valor;
    int sair = 0;
    VetorPrincipal vet[10];


    while (!sair){
        op = menu();
        switch (op){
            case 0:{
                for(i=0;i<=9;i++){
                    if(vet[i].auxiliar != NULL){
                        free(vet[i].auxiliar);
                    }
                }
                sair =1;
                break;
            }
            case 1:{ //inserir
                printf("Digite a posicao do vetor que deseja inserir um valor:\n");
                scanf("%d", &i);

                if (vet[i].auxiliar == NULL){
                    printf("Nosso vetor ainda nao tem um tamanho. Digite um tamanho para ele:\n");
                    scanf("%d", &vet[i].tamanho);
                    vet[i].auxiliar = (int*)malloc(sizeof(int)*vet[i].tamanho);
                    vet[i].ptr = vet[i].auxiliar;
                    printf("Digite um valor para inserir:\n");
                    scanf("%d",&valor);
                    *vet[i]->ptr = valor;
                    ptr = ptr+1;
                }
                else{
                    printf("Digite um valor para inserir:\n");
                    scanf("%d",&valor);
                    *vet[i]->ptr = valor;
                    ptr = ptr+1;
                }



                break;
            }

            case 2:{ //excluir
                //TODO
                printf("Digite a posicao do vetor principal que deseja apagar um valor:\n");
                scanf("%d", &i);
                
                if(vet[i].auxiliar == NULL){
                    printf("Não existe um vetor alocado neste índice.");
                }
                else{
                    printf("Escolha um valor para apagar do vetor");
                    
                }
                
                break;
            }
            default:{
                printf("opcao inválida\n");
            }


        }


    }

    return 0;

}
