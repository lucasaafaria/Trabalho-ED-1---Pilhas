/*------------------------- Trabalho 1 - Pilhas -------------------------
*       implementacao pilha com dados *void
*		@autores: Lucas de Almeida Abreu Faria, Mateus Berardo de Souza Terra
*	 @matriculas: 17/0016668 ; 17/0018806
*    @disciplina: Estruturas de Dados
*     @professor: Eduardo Alchieri
*/

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
    
    /* declaracao de funcoes */
    t_stack *newStack(){
        t_stack *stack = (t_stack*) malloc(sizeof(t_stack));
        stack->inicio = NULL;
        return stack;
    }
    
    void push(t_stack *stack, void *dado, int tipoDado){
        t_stackElement *elemento = (t_stackElement*) malloc(sizeof(t_stackElement));
        void *inserir;
        switch(tipoDado){
            case t_int:
                inserir = (int*) malloc(sizeof(int));
                *(int*)inserir=*(int*)dado;
                break;
            case t_char:
                inserir = (char*) malloc(sizeof(char));
                *(char*)inserir=*(char*)dado;
                break;
        }
        elemento->dado = inserir;
        elemento->proximo = stack->inicio;
        elemento->tipoDado = tipoDado;
        stack->inicio = elemento;
    }
    
    int popInt(t_stack *stack){
        int dado=-1;
        t_stackElement *remover = stack->inicio;
        if(remover == NULL){
            return dado;
        }
        dado = *(int*)remover->dado;
        stack->inicio = remover->proximo;
        free(remover->dado);
        free(remover);
        return dado;
    } 
    
    char popChar(t_stack *stack){
        char dado=0;
        t_stackElement *remover = stack->inicio;
        if(remover == NULL){
            return dado;
        }
        dado = *(char*)remover->dado;
        stack->inicio = remover->proximo;
        free(remover->dado);
        free(remover);
        return dado;
    } 
    
    int emptyStack(t_stack *stack){
        if(stack->inicio == NULL){
            return 1;
        } 
        return 0;
    }
    
      
