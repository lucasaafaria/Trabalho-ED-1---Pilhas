/*------------------------- Trabalho 1 - Pilhas -------------------------
*       header da pilha com dados *void
*		@autores: Lucas de Almeida Abreu Faria, Mateus Berardo de Souza Terra
*	 @matriculas: 17/0016668 ; 17/0018806
*    @disciplina: Estruturas de Dados
*     @professor: Eduardo Alchieri
*/

#ifndef _QUEUE_H_
#define _QUEUE_H_

    #include "stack.h"
    
    /* definicao de tipos */
    typedef struct queue{
        t_list *l;
    } t_queue;
    
    /* declaracao de prototipos de funcoes */
    extern t_queue *newQueue();
    extern void add(t_queue *queue, void *dado, int tipoDado);
    extern char removeChar(t_queue *queue);
    extern double removeDouble(t_queue *queue);
    extern int isEmptyQueue(t_queue *queue);
    extern int getNextQueueType(t_queue *queue);      

#endif
