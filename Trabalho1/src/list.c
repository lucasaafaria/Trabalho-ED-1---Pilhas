/*------------------------- Trabalho 1 - Pilhas -------------------------
*       implementacao lista com dados *void
*		@autores: Lucas de Almeida Abreu Faria, Mateus Berardo de Souza Terra
*	 @matriculas: 17/0016668 ; 17/0018806
*    @disciplina: Estruturas de Dados
*     @professor: Eduardo Alchieri
*/

#include "list.h"

t_list *newList(){
    t_list *l = (t_list*) malloc(sizeof(t_list));
    l->inicio = NULL;
    l->fim = NULL;
    return l;
}

void addStart(t_list *list, void *dado, int tipoDado){
    t_element *elemento = (t_element*) malloc(sizeof(t_element));
    void *inserir;
    switch(tipoDado){
        case t_char:
            inserir = (char *) malloc(sizeof(char));
            *(char *)inserir=*(char *)dado;
            break;
        case t_double:
            inserir = (double *) malloc(sizeof(double));
            *(double *)inserir=*(double *)dado;
            break;
    }
    elemento->dado = inserir;
    elemento->proximo = list->inicio;
    elemento->tipoDado = tipoDado;
    list->inicio = elemento;
    if(list->fim == NULL) 
        list->fim = list->inicio;
}

void addEnd(t_list *list, void *dado, int tipoDado){
    t_element *elemento = (t_element*) malloc(sizeof(t_element));
    void *inserir;
    switch(tipoDado){
        case t_char:
            inserir = (char *) malloc(sizeof(char));
            *(char *)inserir=*(char *)dado;
            break;
        case t_double:
            inserir = (double *) malloc(sizeof(double));
            *(double *)inserir=*(double *)dado;
            break;
    }
    elemento->dado = inserir;
    elemento->proximo = NULL;
    elemento->tipoDado = tipoDado;
    if(list->fim != NULL)
        list->fim->proximo = elemento;
    list->fim = elemento;
    if(list->inicio == NULL){
        list->inicio = elemento;
    }
}

int isEmpty(t_list *list){
    if(list->inicio == NULL)
        return 1;
    return 0;
}

char removeFirstChar(t_list *list){
    int dado = 0;
    t_element *remover = list->inicio;
    if(isEmpty(list)){
        return dado;
    }
    dado = *(char *)remover->dado;
    if(list->fim == list->inicio){
        list->fim == NULL;
    }
    list->inicio = remover->proximo;
    free(remover->dado);
    free(remover);
    return dado;
}

double removeFirstDouble(t_list *list){
    double dado;
    t_element *remover = list->inicio;
    if(isEmpty(list)){
        return dado;
    }
    dado = *(double *)remover->dado;
    if(list->fim == list->inicio){
        list->fim == NULL;
    }
    list->inicio = remover->proximo;
    free(remover->dado);
    free(remover);
    return dado;
}

int getNextType(t_list *list){
    return list->inicio->tipoDado;
}  
