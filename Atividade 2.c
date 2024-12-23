#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct aluno
{
    int mat;
    char *nome;
    int ano;
    float score;
    struct aluno *prox;
}cel;

void inserir(cel **cabeca, int mat, char *nome, int ano, float score, int *tamanho)
{
    cel *nova = (cel*) malloc(sizeof(cel));
    nova->mat = mat;
    nova->nome = nome;
    nova->ano = ano;
    nova->score = score;
    if (*cabeca == NULL)
    {
        *cabeca = nova;
    }
    else
    {
        nova->prox = *cabeca;
        *cabeca = nova;
    }
    *tamanho = *tamanho + 1;
}

void remover(cel *cabeca, int mat, int *tamanho)
{
    if (cabeca == NULL)
    {
        printf("A lista está vazia\n");
    }
    else
    {
        cel *aux = cabeca;
        cel *anterior;
        while (aux->mat != mat && aux->prox != NULL)
        {
            anterior = aux;
            aux = aux->prox;
        }
        if(aux->mat == mat)
        {
            if (aux->prox != NULL)
            {
                anterior->prox = aux->prox;
                free(aux);
                *tamanho = *tamanho - 1;
            }
            else
            {
                anterior->prox = NULL;
                free(aux);
                *tamanho = *tamanho - 1;
            }
        }
        else
        {
            printf("Elemento não encontrado\n");
        }
    }
}

void buscar(cel *cabeca, int mat)
{
    cel *aux = cabeca;
    while (aux->mat != mat && aux->prox != NULL)
        {
            aux = aux->prox;
        }
    if (aux->mat == mat)
    {
        printf("matrícula: %d \n", aux->mat);
        printf("nome: %s \n", aux->nome);
        printf("ano: %d \n", aux->ano);
        printf("score: %f \n", aux->score);
    }
    else
    {
        printf("Elemento não encontrado\n");
    }
}

void atualizar(cel *cabeca, int mat)
{
    cel *aux = cabeca;
    while (aux->mat != mat && aux->prox != NULL)
        {
            aux = aux->prox;
        }
    if (aux->mat == mat)
    {
        int nova_mat; int ano; float score;
        char *novo_nome = (char*) malloc(32*sizeof(char));
        printf("Digite a nova matrícula\n");
        scanf("%d", &nova_mat);
        printf("Digite o novo nome\n");
        scanf("%31s", novo_nome);
        printf("Digite o ano\n");
        scanf("%d", &ano);
        printf("Digite o score\n");
        scanf("%f", &score);

        free(aux->nome);
        aux->mat = nova_mat;
        aux->nome = novo_nome;
        aux->ano = ano;
        aux->score = score;
    }
    else
    {
        printf("Elemento não encontrado\n");
    }
}

void imprimir(cel *cabeca)
{
    if (cabeca == NULL)
    {
        printf("Lista vazia\n");
    }
    else
    {
        cel *aux = cabeca;
        while (aux != NULL)
        {
            printf("matrícula: %d \n", aux->mat);
            printf("nome: %s \n", aux->nome);
            printf("ano: %d \n", aux->ano);
            printf("score: %f \n", aux->score);
            aux = aux->prox;
            printf("\n");
        }
    }
    
}

void apagar(cel *cabeca, int *tamanho)
{
    cel *aux = cabeca; cel *aux_end = aux;
    while (aux != NULL)
    {
        aux_end = aux;
        free(aux_end->nome);
        aux = aux->prox;
        free(aux_end);
        *tamanho = *tamanho - 1;
    }
}
int menu()
{
    int opcao;
    printf("0 - INSERIR\n");
    printf("1 - REMOVER\n");
    printf("2 - BUSCAR\n");
    printf("3 - ATUALIZAR\n");
    printf("4 - TAMANHO\n");
    printf("5 - LIMPAR\n");
    printf("6 - IMPRIMIR\n");
    printf("7 - SAIR\n");
    scanf("%d", &opcao);
    return opcao;
}

int main()
{
    cel *cabeca = NULL;
    int opcao; int tamanho = 0;
    int mat; char *nome; int ano; float score; 
    bool inicio = true;


    while (inicio == true)
    {
        opcao = menu();
        switch (opcao)
        {
        case 0:
            nome = (char*) malloc(32*sizeof(char));
            printf("Digite a matrícula\n");
            scanf("%d", &mat);
            printf("Digite seu nome\n");
            scanf("%31s", nome);
            printf("Digite o ano\n");
            scanf("%d", &ano);
            printf("Digite o score\n");
            scanf("%f", &score);
            inserir(&cabeca, mat, nome, ano, score, &tamanho);
            break;
        case 1:
            printf("Digite a matrícula\n");
            scanf("%d", &mat);
            remover(cabeca, mat, &tamanho);
            break;
        case 2:
            printf("Digite a matrícula\n");
            scanf("%d", &mat);
            buscar(cabeca, mat);
            break;
        case 3:
            printf("Digite a matrícula\n");
            scanf("%d", &mat);
            atualizar(cabeca, mat);
            break;
        case 4:
            printf("O tamanho da lista é: %d\n", tamanho);
            break;
        case 5:
            apagar(cabeca, &tamanho);
            break;
        case 6:
            imprimir(cabeca);
            break;
        case 7:
            printf("SAINDO...\n");
            inicio = false;
            break;
        default:
            printf("Opção inválida\n");
            break;
        }
    }
}