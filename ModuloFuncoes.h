struct vetorprincipal{
    int *auxiliar;
    int tamanho,cont;
} ;
typedef struct vetorprincipal VetorPrincipal;

int menu();
void alocarMemoria(VetorPrincipal *vet,int indice);
void realocarMemoria(VetorPrincipal *vet, int indice);
void apagaValorMemoria(VetorPrincipal *vet,int i, int valor);
void listaVetor(VetorPrincipal *vet, int i);
void inserirValor(VetorPrincipal *vet, int i, int valor);
void insertionSort(int *vetor, int tamanho);
void transfereConteudo(VetorPrincipal *vet,int i,int *vetorAlvo);
void listaVetorOrdenado(int *vetor,int quantidade);
