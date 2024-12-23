#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct celula
{
    int n;
    int prioridade;
    struct celula *prox;
}cel;

int menu();
void push(cel **cabeca, cel **aux, int i, int j);
void pop(cel **cabeca, cel **aux);
void imprimir(cel **cabeca, cel **aux);
void limpar(cel **cabeca, cel **aux);

int main()
{
    cel *cabeca = NULL; cel *aux = NULL; cel *ultimo = NULL;
    int i; bool start = true; int j;
    while (start)
    {
        int escolha = menu();
        if (escolha == 1)
        {
            printf("Qual valor deseja inserir\n");
            scanf("%d", &i);
            printf("Digite a prioridade\n");
            scanf("%d", &j);
            push(&cabeca, &aux, i, j);
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
    printf("4 - SAIR\n");
    scanf("%d", &opcao);
    return opcao;
}

void push(cel **cabeca, cel **aux, int i, int j)
{
    cel *nova;
    nova = (cel*) malloc(sizeof(cel));
    (*nova).n = i;
    (*nova).prioridade = j;
    if (*cabeca == NULL || j > (**cabeca).prioridade)
    {
        nova->prox = *cabeca;
        *cabeca = nova;
    }
    else
    {
        *aux = *cabeca;
        while ((**aux).prox != NULL && ((**aux).prox)->prioridade >= j)
        {
            *aux = (**aux).prox;
        }
        (*nova).prox = (**aux).prox;
        (**aux).prox = nova;
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
    while (*cabeca != NULL)
    {
        *aux = *cabeca;
        *cabeca = (**cabeca).prox;
        free(*aux);
    }
}

void imprimir(cel **cabeca, cel **aux)
{
    *aux = *cabeca;
    while (*aux != NULL)
    {
        printf("%d.%d ", (**aux).n, (**aux).prioridade);
        *aux = (**aux).prox;
    }
    printf("\n");
}