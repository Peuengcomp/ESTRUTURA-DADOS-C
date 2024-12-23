#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct celula
{
    int valor;
    struct celula *prox;
}cel;

void criar(cel **cabeca, int n, cel **novo, cel **ultimo);
void contar(cel **aux, int *contador, cel **cabeca);
void soma(cel **aux, int *soma, cel **cabeca);
void buscar(cel **aux, int valor, cel **cabeca);

int main()
{
    cel *cabeca = NULL; int i = 0; cel *ultimo = NULL; cel *novo = NULL;
    int contador = 0; int somatorio = 0; int n = 0;
    while (i != -1)
    {
        printf("Digite um valor de entrada\n");
        scanf("%d", &i);
        if (i == -1)
        {
            break;
        }
        else
        {
            criar(&cabeca, i, &novo, &ultimo);
        }
    }
    cel *aux;
    printf("Digite o valor que deseja excluir\n");
    scanf("%d", &n);
    contar(&aux, &contador, &cabeca);
    soma(&aux, &somatorio, &cabeca);
    buscar(&aux, n, &cabeca);
    printf("Há %d elementos\n", contador);
    printf("A soma de todos os elementos é %d\n", somatorio);
    printf("Os elementos da lista:\n");
    while (cabeca != NULL)
    {
        aux = cabeca;
        printf("%d ",(*cabeca).valor);
        cabeca = (*cabeca).prox;
        free(aux);
    }
    printf("\n");
    return 0;
}

void criar(cel **cabeca, int n, cel **novo, cel **ultimo)
{
    *novo = (cel*) malloc(sizeof(cel));
    (**novo).valor = n;
    (**novo).prox = NULL;
    if (*cabeca == NULL)
    {
        *cabeca = *novo;
        *ultimo = *novo;
    }
    else
    {
        (**ultimo).prox = *novo;
        *ultimo = *novo;
    }
}

void contar(cel **aux, int *contador, cel **cabeca)
{
    *aux = *cabeca;
    while (*aux != NULL)
    {
        *contador = *contador + 1;
        *aux = (**aux).prox;
    }
}

void soma(cel **aux, int *soma, cel **cabeca)
{
    *aux = *cabeca;
    while (*aux != NULL)
    {
        *soma = *soma + (**aux).valor;
        *aux = (**aux).prox;
    }
}

void buscar(cel **aux, int valor, cel **cabeca)
{
    cel *anterior = NULL;
    *aux = *cabeca;
    while (*aux != NULL)
    {
        if ((**aux).valor == valor)
        {
            (*anterior).prox = (**aux).prox;
            free(*aux);
            break;
        }
        else
        {
            anterior = *aux;
            *aux = (**aux).prox;
        }
    }
}
