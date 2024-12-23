// Pedro Lucas Fernandes de Souza e Maria Clara Nunes Ramos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct cel
{
    char letra;
    struct cel *prox;
}celula;

void inserir(celula **cabeca, celula **ultimo, celula **novo, celula **aux, celula **aux0, char texto, bool estado);

int main()
{
    char texto[100001]; int i;
    while (scanf("%s", texto[100001]) != EOF)
    {
        i = 0;
        celula *cabeca = NULL;  celula *ultimo = NULL; 
        celula *novo = NULL; celula *aux = NULL;
        celula *aux0 = NULL;
        bool estado = true;
        while (texto[i] != '\0')
        {  
            while ((texto[i] == '[' || texto[i] == ']'))
            {
                if (texto[i] == ']')
                {
                    i++;
                    estado = true;
                    aux = NULL;
                }
                else if (texto[i] == '[')
                {
                    i++;
                    estado = false;
                }
            }
            inserir(&cabeca, &ultimo, &novo, &aux, &aux0, texto[i], estado);
            i++;
        }
        while (cabeca != NULL)
        {
            printf("%c", (*cabeca).letra);
            cabeca = (*cabeca).prox;
        }
        printf("\n");
    }
    return 0;
}

void inserir(celula **cabeca, celula **ultimo, celula **novo, celula **aux, celula **aux0, char texto, bool estado)
{
    *novo = (celula*) malloc(sizeof(celula));
    (**novo).letra = texto;
    if (estado == true)
    {
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
    else
    {
        if (*aux == NULL)
        {
            *aux0 = *cabeca;
            (**novo).prox = *aux0;
            *cabeca = *novo;
            *aux = *novo;
        }
        else
        {
            (**novo).prox = *aux0;
            (**aux).prox = *novo;
            *aux = *novo;
        }
    }
}
