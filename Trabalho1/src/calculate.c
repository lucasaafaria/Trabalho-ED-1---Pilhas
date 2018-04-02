/*------------------------- Trabalho 1 - Pilhas -------------------------
*       implementacao de calculadora de expressoes posfixas
*		@autores: Lucas de Almeida Abreu Faria, Mateus Berardo de Souza Terra
*	 @matriculas: 17/0016668 ; 17/0018806
*    @disciplina: Estruturas de Dados
*     @professor: Eduardo Alchieri
*/

#include "calculate.h"

double calculate(t_queue *queue){
    t_stack *stack = newStack();
    double op1, op2, resultado;
    while(!isEmptyQueue(queue)){
        if(getNextQueueType(queue) == t_double){
            double dado = removeDouble(queue);
            push(stack, &dado, t_double);
        } else if(getNextQueueType(queue) == t_int){
            double dado = removeInt(queue);
            push(stack, &dado, t_double);
        } else {
            char operacao = removeChar(queue);
            op1 = popDouble(stack);
            op2 = popDouble(stack);
            switch (operacao){
                case '*':
                    resultado = op2*op1;
                    break;
                case '/':
                    resultado = op2/op1;
                    break;
                case '+':
                    resultado = op2+op1;
                    break;
                case '-':
                    resultado = op2-op1;
                    break;
            }
            push(stack, &resultado, t_double);
        }
    }
    return popDouble(stack);
}
