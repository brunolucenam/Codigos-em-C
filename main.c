#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    struct no *prox;
    struct no *ant;
    int conteudo;
} tNo;

typedef struct fila{
    tNo *inicio;
    tNo *fim;
    int tam;
} tFila;

void CriaFila (tFila *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tam = 0;
}

int FilaVazia (tFila fila){
    if (fila.tam == 0)
        return 1;
    return 0;
}

int Primeiro (tFila fila, int *elemento){
    if (FilaVazia(fila))
        return 0;

    *elemento = (fila.inicio)->conteudo;
    return 1;
}

int InserirTras (tFila *fila, int conteudo){
    tNo *novoNo;

    novoNo = (tNo *)malloc(sizeof(tNo));

    if (novoNo == NULL)
        return 0;

    novoNo->conteudo = conteudo;
    novoNo->prox = NULL;

    if (FilaVazia(*fila)){
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } else {
        (fila->fim)->prox = novoNo;
        fila->fim = novoNo;
    }

    fila->tam++;
    return 1;
}

int InserirFrente (tFila *fila, int conteudo){
    tNo *novoNo;

    novoNo = (tNo *)malloc(sizeof(tNo));

    if (novoNo == NULL)
        return 0;

    novoNo->conteudo = conteudo;

    if (FilaVazia(*fila)){
        novoNo->ant = NULL;
        novoNo->prox = NULL;
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } else {
        novoNo->ant = NULL;
        novoNo->prox = fila->inicio;
        (fila->inicio)->ant = novoNo;
        fila->inicio = novoNo;
    }
    fila->tam++;

    return 1;
}

int RetirarFrente (tFila *fila, int *conteudo){
    tNo *p;

    if (FilaVazia(*fila)){
        return 0;
    } else {
        p = fila->inicio;
        *conteudo = p->conteudo;

        if (fila->inicio == fila->fim)
            fila->fim = NULL;

        p = fila->inicio;
        fila->inicio = p->prox;

        fila->tam--;
        free(p);
    }
    return 1;
}

int RetirarTras (tFila *fila, int *conteudo){
    tNo *p;

    if (FilaVazia(*fila)){
        return 0;
    } else {
        p = fila->fim;
        *conteudo = p->conteudo;

        if (fila->inicio == fila->fim)
            fila->fim = NULL;

        p = fila->fim;
        fila->fim = p->prox;

        fila->tam--;
        free(p);
    }
    return 1;
}


int main(){
    int qtde, valor, flag = 0, imprimirFrente = 0, imprimirTras = 0;;
    char comparaString[10];
    tFila fila;

    CriaFila(&fila);

    scanf("%d", &qtde);
    fflush(stdin);
    while(qtde){
        scanf("%s", comparaString);
            switch(comparaString[0]){
                    case 't':
                        if (flag == 1){
                            scanf("%d", &valor);
                            InserirTras(&fila, valor);
                            break;
                        } else {
                            scanf("%d", &valor);
                            InserirFrente(&fila, valor);
                            break;
                        }
                    case 'p':
                        if (flag == 1){
                            scanf("%d", &valor);
                            InserirFrente(&fila, valor);
                            break;
                        } else {
                            scanf("%d", &valor);
                            InserirTras(&fila, valor);
                            break;
                        }
                    case 'f':
                        if (flag == 1){
                            RetirarTras(&fila, &imprimirTras);
                                    if (fila.tam == 0){
                                        printf("No job for Ada?\n");
                                    } else {
                                    printf("%d\n", imprimirTras);
                                    }
                            break;
                        } else {
                            RetirarFrente(&fila, &imprimirFrente);
                                    if (fila.tam == 0){
                                        printf("No job for Ada?\n");
                                    } else {
                                    printf("%d\n", imprimirFrente);
                                    }
                            break;
                        }
                    case 'b':
                        if (flag == 1){
                            RetirarFrente(&fila, &imprimirFrente);
                                    if (fila.tam == 0){
                                        printf("No job for Ada?\n");
                                    } else {
                                    printf("%d\n", imprimirFrente);
                                    }
                            break;
                        } else {
                            RetirarTras(&fila, &imprimirTras);
                                    if (fila.tam == 0){
                                        printf("No job for Ada?\n");
                                    } else {
                                    printf("%d\n", imprimirTras);
                                    }
                            break;
                        }
                    case 'r':
                        if(flag == 0){
                            flag = 1;
                        }else if (flag == 1){
                            flag = 0;
                        }
            }
        fflush(stdin);
    }
    return 0;
}

