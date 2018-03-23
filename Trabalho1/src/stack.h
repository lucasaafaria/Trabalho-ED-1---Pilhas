/*------------------------- Trabalho 1 - Pilhas -------------------------
*       header da pilha com dados *void
*		@autores: Lucas de Almeida Abreu Faria, Mateus Berardo de Souza Terra
*	 @matriculas: 17/0016668 ; 17/0018806
*    @disciplina: Estruturas de Dados
*     @professor: Eduardo Alchieri
*/

#ifndef _STACK_H_
#define _STACK_H_
    
    /* definicao de constantes */
    #define t_int 1
    #define t_char 2
    
    /* definicao de tipos */
    typedef struct elemento{
        void *dado;
        struct elemento *proximo;
    } t_stackElement;
    typedef struct stack{
        t_stackElement *inicio;
    } t_stack;
    
    /* declaracao de prototipos de funcoes */
    extern t_stack *newStack();
    extern void push(t_stack *stack, void *dado, int tipoDado);
    extern void *pop(t_stack *stack);
    extern void printStack(t_stack *stack, int tipoDado);       

#endif
