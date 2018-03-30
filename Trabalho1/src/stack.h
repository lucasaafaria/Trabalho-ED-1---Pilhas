/*------------------------- Trabalho 1 - Pilhas -------------------------
*       header da pilha com dados *void
*		@autores: Lucas de Almeida Abreu Faria, Mateus Berardo de Souza Terra
*	 @matriculas: 17/0016668 ; 17/0018806
*    @disciplina: Estruturas de Dados
*     @professor: Eduardo Alchieri
*/

#ifndef _STACK_H_
#define _STACK_H_

    #include <stdlib.h>
    #include "list.h"
    
    /* definicao de tipos */
    typedef struct stack{
        t_list *l;
    } t_stack;
    
    /* declaracao de prototipos de funcoes */
    extern t_stack *newStack();
    extern void push(t_stack *stack, void *dado, int tipoDado);
    extern int popInt(t_stack *stack);
    extern char popChar(t_stack *stack);
    extern double popDouble(t_stack *stack);
    extern int isStackEmpty(t_stack *stack);
    extern int getNextStackType(t_stack *stack);
    
#endif
