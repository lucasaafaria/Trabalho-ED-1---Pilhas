/*------------------------- Trabalho 2 - Árvores -------------------------
*       implementacao lista
*		@autores: Lucas de Almeida Abre Faria, Mateus Berardo de Souza Terra
*	 @matriculas: 17/0016668 ; 17/0018806
*    @disciplina: Estruturas de Dados
*     @professor: Eduardo Alchieri
*/

#include "list.h"

typedef struct elemento{
    char simbolo;
    char codigo[10];
    struct elemento *prox;
} t_elemento;

typedef struct lista{
    t_elemento *inicio;
    t_elemento *fim;
} t_lista;

t_lista * novaLista(){
    t_lista * l = (t_lista*) malloc(sizeof(t_lista));
    l->inicio = NULL;
    l->fim = NULL;
    return l;
}

void insereInicio(t_lista *lista, char simbolo, char * codigo){
    t_elemento * elemento = (t_elemento*) malloc(sizeof(t_elemento));
    elemento->simbolo = simbolo;
    sprintf(elemento->codigo, "%s", codigo);
    elemento->prox = lista->inicio;
    lista->inicio = elemento;
    if(lista->fim == NULL) 
        lista->fim = lista->inicio;
}

t_lista * dicionario(){
    int lido = 1;
    char simbolo, codigo[15];
    t_lista * lista = novaLista();
    FILE * morse = fopen("morse.txt", "r");
    while(lido != -1){
        lido = fscanf(morse, "%c %s\n", &simbolo, codigo);
        if(lido != -1)
            insereInicio(lista, simbolo, codigo);
    }
    fclose(morse);
    return lista;
}

char procura(char * codigo, t_lista * l){
    int naoAchou = 1;
    t_elemento * atual = l->inicio;
    while(naoAchou){
        if(strcmp(atual->codigo, codigo) != 0)
            atual = atual->prox;
        else
            naoAchou = 0;
    }
    return atual->simbolo;
}

void decodificaLista(t_lista * tradutor){
    int lido = 1;
    char codigo[10];
    FILE * mensagem = fopen("mensagem.txt", "r");

    while(lido != -1){
        lido = fscanf(mensagem, "%s ", codigo);
        if(lido != -1){
            if(strcmp(codigo, "/") != 0)
                printf("%c", procura(codigo, tradutor));
            else
                printf(" ");
        }
    }
    fclose(mensagem);
}