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
        switch(tipoDado){
            case t_int:
                int *inserir = (int*) malloc(sizeof(int));
                break;
            case t_char):
                char *inserir = (char*) malloc(sizeof(char));
                break;
        }
        *inserir=*dado;
        elemento->dado = inserir;
        elemento->proximo = stack->inicio;
        stack->inicio = elemento;
    }
    
    void *pop(t_stack *stack){
        void *dado = NULL;
        t_stackElement *remover = stack->inicio;
        if(remover == NULL){
            return dado;
        }
        dado = remover->dado;
        stack->inicio = remover->proximo;
        free(remover->dado);
        free(remover);
        return dado;
    }  
    
    void printStack(t_stack *stack, int tipoDado){
        t_stackElement *atual = stack->inicio;
        while(atual != NULL){
            switch(tipoDado){
                case t_int:
                    printf("%d\n", *((int*)atual->dado));
                    break;
                case t_char:
                    printf("%c\n", *((char*)atual->dado));
                    break;
            }
            atual=atual->proximo;
        }
        printf("FIM DA PILHA\n");
    }   
