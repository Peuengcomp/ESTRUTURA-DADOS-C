#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int valor;
    struct celula *prox;
}cel;

int menu();
void push(cel **cabeca, int i);
void pop(cel **cabeca, int *valor);

int main()
{
    cel *cabeca = NULL; int qtd; int i; int num; int *pnum = &num; cel *aux;

    int opcao = menu();
    while (opcao != 3)
    {
        if (opcao == 1)
        {
            printf("Digite seu valor\n");
            scanf("%d", &i);
            push(&cabeca, i);
            opcao = menu();
        }
        else if (opcao == 2)
        {
            pop(&cabeca, pnum);
            opcao = menu();
        }
    }
    return 0;
}

int menu()
{
    int opcao;
    printf("1 - INSERIR\n");
    printf("2 - RETIRAR\n");
    scanf("%d", &opcao);
    return opcao;
}

void push(cel **cabeca, int i)
{
    cel *nova = (cel*) malloc(sizeof(cel));
    nova->valor = i;
    if (*cabeca == NULL)
    {
        *cabeca = nova;
        (**cabeca).prox = NULL;
    }
    else
    {
        nova->prox = *cabeca;
        *cabeca = nova;
    }
}

void pop(cel **cabeca, int *valor)
{
    if (*cabeca == NULL)
    {
        printf("Pilha vazia\n");
    }
    else
    {
        cel *aux = *cabeca;
        *valor = (**cabeca).valor;
        *cabeca = (**cabeca).prox;
        free(aux);
        printf("O elemento retirado foi %d\n", *valor);
    }
}
