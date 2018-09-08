struct vetorprincipal{
    int *auxiliar,tamanho,cont;

} ;
typedef struct vetorprincipal VetorPrincipal;

int menu();
void alocarMemoria(VetorPrincipal *vet,int indice);
void realocarMemoria(VetorPrincipal *vet, int indice);
void apagaValorMemoria(VetorPrincipal *vet,int i, int valor);
