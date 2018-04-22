/*------------------------- Trabalho 1 - Pilhas -------------------------
*       implementacao pilha com dados *void
*		@autores: Lucas de Almeida Abreu Faria, Mateus Berardo de Souza Terra
*	 @matriculas: 17/0016668 ; 17/0018806
*    @disciplina: Estruturas de Dados
*     @professor: Eduardo Alchieri
*/

#include "queue.h"
    
    /* declaracao de funcoes */
    t_queue *newQueue(){
        t_queue *queue = (t_queue*) malloc(sizeof(t_queue));
        queue->l = newList();
        return queue;
    }
    
    void add(t_queue *queue, void *dado, int tipoDado){
        addEnd(queue->l, dado, tipoDado);
    }
    
    char removeChar(t_queue *queue){
        return removeFirstChar(queue->l);
    }
    
    double removeDouble(t_queue *queue){
        return removeFirstDouble(queue->l);
    }
    
    int isEmptyQueue(t_queue *queue){
        return isEmpty(queue->l);
    }   
    
    int getNextQueueType(t_queue *queue){
        return getNextType(queue->l);
    }
