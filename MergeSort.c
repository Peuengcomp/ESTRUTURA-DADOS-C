#include <stdio.h>
#include <stdlib.h>

void imprimir(int vetor[], int tamanho);
void mergesort(int vetor[], int inicio, int fim);
void merge(int vetor[], int inicio, int meio, int fim);

int main()
{
    int tamanho; int i = 0;
    printf("Digite a quantidade de números no vetor\n");
    scanf("%d", &tamanho);
    int vetor[tamanho];
    while (i<tamanho)
    {
        printf("Digite o valor: ");
        scanf("%d", &vetor[i]);
        i++;
    }
    printf("Vetor sem ordenar:");
    imprimir(vetor, tamanho);
    printf("Vetor ordenado:");
    mergesort(vetor, 0, tamanho-1);
    imprimir(vetor, tamanho);
    return 0;
}

void imprimir(int vetor[], int tamanho)
{
    int k;
    for (k=0;k<tamanho;k++)
    {
        printf("%d ", vetor[k]);
    }
    printf("\n");
}

void mergesort(int vetor[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = (inicio + fim)/2;
        mergesort(vetor, inicio, meio);
        mergesort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

void merge(int vetor[], int inicio, int meio, int fim)
{
    int tamanho = fim - inicio + 1;
    int *aux = (int*) malloc(tamanho*sizeof(int));
    int i = inicio; int j = meio + 1; int k = 0;
    if (aux != NULL)
    {
        while (i <= meio && j <= fim)
        {
            if (vetor[i] <= vetor[j])
            {
                aux[k] = vetor[i];
                k++;
                i++;
            }
            else
            {
                aux[k] = vetor[j];
                k++;
                j++;
            }
        }
        while (i <= meio)
        {
            aux[k] = vetor[i];
            k++;
            i++;
        }
        while (j <= fim)
        {
            aux[k] = vetor[j];
            k++;
            j++;
        }
        i = inicio; k = 0;
        while (i <= fim)
        {
            vetor[i] = aux[k];
            i++;
            k++;
        }
    }
    free(aux);
}