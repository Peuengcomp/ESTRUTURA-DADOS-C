#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct celula
{
    int n;
    struct celula *prox;
}cel;

int menu();
void push(cel **cabeca, cel **ultimo, int i);
void pop(cel **cabeca, cel **aux);
void imprimir(cel **cabeca, cel **aux);
void limpar(cel **cabeca, cel **aux);

int main()
{
    cel *cabeca = NULL; cel *aux = NULL; cel *ultimo = NULL;
    int i; bool start = true;
    while (start)
    {
        int escolha = menu();
        if (escolha == 1)
        {
            printf("Qual valor deseja inserir\n");
            scanf("%d", &i);
            push(&cabeca, &ultimo, i);
        }
        else if (escolha == 2)
        {
            pop(&cabeca, &aux);
        }
        else if (escolha == 3)
        {
            imprimir(&cabeca, &aux);
        }
        else
        {
            limpar(&cabeca, &aux);
            start = false;
        }
    }
    return 0;
}

int menu()
{
    int opcao;
    printf("1 - INSERIR\n");
    printf("2 - RETIRAR\n");
    printf("3 - IMPRIMIR\n");
    scanf("%d", &opcao);
    return opcao;
}

void push(cel **cabeca, cel **ultimo, int i)
{
    cel *nova;
    nova = (cel*) malloc(sizeof(cel));
    nova->n = i;
    nova->prox = NULL;
    if (*cabeca == NULL)
    {
        *cabeca = nova;
        *ultimo = nova;
    }
    else
    {
        (**ultimo).prox = nova;
        *ultimo = nova;
    }
}

void pop(cel **cabeca, cel **aux)
{
    if (*cabeca == NULL)
    {
        printf("A fila está vazia\n");
    }
    else
    {
        *aux = *cabeca;
        *cabeca = (**cabeca).prox;
        free(*aux);
    }
}

void limpar(cel **cabeca, cel **aux)
{
    *aux = *cabeca;
    *cabeca = (**cabeca).prox;
    free(*aux);
}

void imprimir(cel **cabeca, cel **aux)
{
    *aux = *cabeca;
    while (*aux != NULL)
    {
        printf("%d ", (**aux).n);
        *aux = (**aux).prox;
    }
    printf("\n");
}
