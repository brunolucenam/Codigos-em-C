#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    int conteudo;
    struct no *prox;
} tNo;

typedef struct pilha {
    tNo *topo;
    int tam;
} tPilha;

void CriaPilha (tPilha *pilha){
    pilha->topo = NULL;
    pilha->tam = 0;
}

int PilhaVazia (tPilha pilha){
    if (pilha.tam == 0)
        return 1;
    return 0;
}

int Push (tPilha *pilha, char novoConteudo){
    tNo *novoNo;

    novoNo = (tNo *) malloc(sizeof(tNo));

    if (novoNo == NULL)
        return 0;

    novoNo->conteudo = novoConteudo;
    novoNo->prox = pilha->topo;
    pilha->topo = novoNo;

    pilha->tam++;

    return 1;
}

int Pop (tPilha *pilha, char *novoConteudo){
    tNo *p;

    if (PilhaVazia(*pilha))
        return 0;

    p = pilha->topo;
    *novoConteudo = p->conteudo;
    pilha->topo = p->prox;

    pilha->tam--;
    free(p);

    return 1;
}

int main(){
    int numExp = 0, i, j, cont = 0;
    char lixo, sinal;
    tPilha pilha1;
    tPilha pilha2;

    CriaPilha(&pilha2);
    CriaPilha(&pilha1);
    scanf("%d", &numExp);

    char Aux[numExp][401];

    while(cont < numExp){
        scanf("%s", Aux[cont]);
        cont++;
    }

    for (i = 0; i < numExp; i++){
        for (j = 0; j < strlen(Aux[i]); j++){
            if (Aux[i][j] == '('){
                Push(&pilha1, Aux[i][j]);
            }

            if (Aux[i][j] >= 'a' && Aux[i][j] <= 'z'){
                printf("%c", Aux[i][j]);
            }

            if (Aux[i][j] == '+' || Aux[i][j] == '-' || Aux[i][j] == '*' || Aux[i][j] == '^' || Aux[i][j] == '/'){
                Push(&pilha2, Aux[i][j]);
            }

            if (Aux[i][j] == ')'){
                Pop(&pilha1, &lixo);
                Pop(&pilha2, &sinal);
                printf("%c", sinal);
            }
        }
        printf("\n");
    }

    return 0;
}
