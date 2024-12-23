#include <stdio.h>

void quicksort(int vetor[], int p, int r);
int part(int vetor[], int p, int r);
void swap(int *a, int *b);
void imprimir(int vetor[], int tamanho);

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
    quicksort(vetor, 0, tamanho-1);
    imprimir(vetor, tamanho);
    return 0;
}

void quicksort(int vetor[], int p, int r)
{
    if (p < r)
    {
        int q = part(vetor, p, r);
        quicksort(vetor, p, q-1);
        quicksort(vetor, q+1, r);
    }
}

int part(int vetor[], int p, int r)
{
    int pivo = vetor[r];
    int i = p-1;
    int j;
    for (j=p;j<r;j++)
    {
        if (vetor[j] <= pivo)
        {
            i++;
            swap(&vetor[i], &vetor[j]);
        }
    }
    swap(&vetor[i+1], &vetor[r]);
    return i+1;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
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