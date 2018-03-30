/*------------------------- Trabalho 1 - Pilhas -------------------------
*       implementacao pilha com dados *void
*		@autores: Lucas de Almeida Abreu Faria, Mateus Berardo de Souza Terra
*	 @matriculas: 17/0016668 ; 17/0018806
*    @disciplina: Estruturas de Dados
*     @professor: Eduardo Alchieri
*/

#include "stack.h"
    
t_stack *newStack(){
    t_stack *stack = (t_stack*) malloc(sizeof(t_stack));
    stack->l = newList();
    return stack;
}

void push(t_stack *stack, void *dado, int tipoDado){
    addStart(stack->l, dado, tipoDado);
}

int popInt(t_stack *stack){
    return removeFirstInt(stack->l);
} 

char popChar(t_stack *stack){
    return removeFirstChar(stack->l);
}

double popDouble(t_stack *stack){
    return removeFirstDouble(stack->l);
} 

int isStackEmpty(t_stack *stack){
    return isEmpty(stack->l);
}

int getNextStackType(t_stack *stack){
    return getNextType(stack->l);
}

  
