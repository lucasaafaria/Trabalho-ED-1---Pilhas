/*------------------------- Trabalho 1 - Pilhas -------------------------
*       implementação da transformação da forma infixa para posfixa
*		@autores: Lucas de Almeida Abreu Faria, Mateus Berardo de Souza Terra
*	 @matriculas: 17/0016668 ; 17/0018806
*    @disciplina: Estruturas de Dados
*     @professor: Eduardo Alchieri
*/

#include "transform.h"

void parenthesisProcess(char * dado, t_stack * stack, t_queue * saida){
	if(*dado == '(')
		push(stack, dado, t_char);
	else{
		while(*dado != '('){
			*dado = popChar(stack);
			if(*dado != '(')
				add(saida, dado, t_char);
		}
	}
}

void operatorProcess(char * dado, t_stack * stack, t_queue * saida){
	char popped = '+';

	while(!isStackEmpty(stack) && isLowerPrior(&popped)){
		popped = popChar(stack);
		if(!isLowerPrior(&popped) && !isParenthesis(&popped))
			add(saida, &popped, t_char);
		else if((isLowerPrior(&popped) && !isLowerPrior(dado)) || isParenthesis(&popped)){
			push(stack, &popped, t_char);
			break;
		}
		else if(isLowerPrior(&popped) && isLowerPrior(dado))
			add(saida, &popped, t_char);
	}
	push(stack, dado, t_char);
}

t_queue * transform(t_queue * queue){
	t_stack * stack = newStack();
	t_queue * saida = newQueue();
	int tipoDado;
	double dadoDouble;
	char dadoChar;

	while(!isEmptyQueue(queue)){
		tipoDado = getNextQueueType(queue);
		if(tipoDado == t_double){
			dadoDouble = removeDouble(queue);
			add(saida, &dadoDouble, t_double);
		}else{
			dadoChar = removeChar(queue);
			if(isParenthesis(&dadoChar))
				parenthesisProcess(&dadoChar, stack, saida);
			else
				operatorProcess(&dadoChar, stack, saida);
		}
	}
	while(!isStackEmpty(stack)){
		dadoChar = popChar(stack);
		add(saida, &dadoChar, t_char);
	}
	free(queue);
	return saida;
}