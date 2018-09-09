#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "ModuloFuncoes.h"

int main(){

    int op,i,valor;
    int sair = 0;
    VetorPrincipal vet[10];
    for(i=0;i<10;i++){
        vet[i].auxiliar = NULL;
        vet[i].cont = 0;
    }


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
                printf("Digite a posicao (1-10) do vetor que deseja inserir um valor:\n");
                scanf("%d", &i);

                if(i>=1 && i<=10){

                        if (vet[i-1].auxiliar == NULL){
                            printf("Nosso vetor ainda nao tem um tamanho. Digite um tamanho para ele:\n");
                            scanf("%d", &vet[i-1].tamanho);
                            alocarMemoria(vet,i-1);

                            printf("Digite um valor para inserir:\n");
                            scanf("%d",&valor);
                            inserirValor(vet,i,valor);

                        }
                        else{
                            if(vet[i].cont == vet[i].tamanho){
                                printf("Nosso vetor ja atingiu seu limite, precisamos alocar mais espaço.\n");
                            }
                            else{
                                printf("Digite um valor para inserir:\n");
                                scanf("%d",&valor);
                                inserirValor(vet,i,valor);
                            }
                        }
                }else
                    printf("\nPosicao invalida\n");


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
                    scanf("%d",&valor);
                    apagaValorMemoria(vet,i,valor);
                }
                break;
            case 3:{//listar
                printf("Digite a posicao do vetor principal que deseja listar: \n");
                scanf("%d",&i);

                if(vet[i-1].auxiliar!=NULL)
                    listaVetor(vet,i-1);
                else
                    printf("Este vetor esta vazio.\n");

                break;
            }
            case 4:{
                printf("Digite a opcao que deseja realocar espaço: \n");
                scanf("%d",&i);

                if(vet[i].auxiliar != NULL){
                    printf("Digite o novo tamanho do vetor: \n");
                    scanf("%d",&vet[i].tamanho);
                    realocarMemoria(vet,i);
                }
            }
            }
            default:{
                printf("opcao inválida\n");
            }
        }
    }
    return 0;
}
