#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "ModuloFuncoes.h"

int main(){

    int op,i,valor,num;
    int sair = 0;
    VetorPrincipal vet[10];
    int *vetor;

    for(i=0;i<10;i++){
        vet[i].auxiliar = NULL;
        vet[i].cont = 0;
        vet[i].tamanho = 0;
    }
    vetor = NULL;


    while (!sair){
        op = menu();
        switch (op){
            case 0:
                for(i=0;i<=9;i++){
                    if(vet[i].auxiliar != NULL){
                        free(vet[i].auxiliar);
                    }
                }
                if (vetor != NULL){
                    free(vetor);
                }
                sair =1;
                break;

            case 1: //inserir
                printf("Digite a posicao (1-10) do vetor que deseja inserir um valor:\n");
                scanf("%d", &i);

                if(i>=1 && i<=10){
                        i = i-1;
                        if (vet[i].auxiliar == NULL){
                            printf("Nosso vetor ainda nao tem um tamanho. Digite um tamanho para ele:\n");
                            scanf("%d", &vet[i].tamanho);
                            alocarMemoria(vet,i);

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


            case 2: //excluir
                //TODO
                printf("Digite a posicao do vetor principal que deseja apagar um valor:\n");
                scanf("%d", &i);
                i=i-1;
                if(vet[i].auxiliar == NULL){
                    printf("Não existe um vetor alocado neste índice.");
                }
                else{
                    printf("Escolha um valor para apagar do vetor:\n");
                    scanf("%d",&valor);
                    apagaValorMemoria(vet,i,valor);
                }
                break;

            case 3://listar
                printf("Digite a posicao do vetor principal que deseja listar: \n");
                scanf("%d",&i);
                i=i-1;
                if(vet[i].auxiliar!=NULL)
                    listaVetor(vet,i);
                else
                    printf("Este vetor esta vazio.\n");

                break;

            case 4: //realocar espaço
                printf("Digite a posicao que deseja realocar espaço: \n");
                scanf("%d",&i);
                i=i-1;
                if(vet[i].auxiliar != NULL){
                    printf("Digite quantas posições deseja adicionar: \n");
                    scanf("%d",&num);
                    vet[i].tamanho = vet[i].tamanho + num;
                    realocarMemoria(vet,i);
                }
                else
                    printf("Nao ha espaco alocado para esse vetor.\n");

                break;

            case 5: //Listar vetor de posição específica ordenado
                printf("Digite a posicao que deseja ordenar o vetor: \n");
                scanf("%d",&i);
                vetor = (int*)malloc(sizeof(int)*(vet[i].cont));
                transfereConteudo(vet,i,vetor);
                insertionSort(vetor,vet[i].cont);
                listaVetorOrdenado(vetor,vet[i].cont);


                break;
            case 6: //Listar todos os elementos ordenados

                break;
            default:
                printf("opcao inválida\n");

        }
    }
    return 0;
}
