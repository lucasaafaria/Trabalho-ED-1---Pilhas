/*------------------------- Trabalho 1 - Pilhas -------------------------
* Implementação das funções de entrada de dados, validação e transformação em pós-fixo
*		@autores: Lucas de Almeida Abreu Faria, Mateus Berardo de Souza Terra
*	 @matriculas: 17/0016668 ; 17/0018806
*    @disciplina: Estruturas de Dados
*     @professor: Eduardo Alchieri
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "inputs.h"
#include "stack.h"
#include "queue.h"

/* Funções de comparação */
	int isParenthesis(char * dado){
		if((*dado) == '(')
			return OPEN_PAR;
		else if((*dado) == ')')
			return CLOSE_PAR;
		return 0;
	}
	
	int isNumber(char * dado){
		if((*dado) >= '0' && (*dado) <= '9')
			return 1;
		return 0;
	}
	
	int isOperator(char * dado){
		if((*dado) == '+' || (*dado) == '-' || (*dado) == '*' || (*dado) == '/')
			return 1;
		return 0;
	}

	void getExpression(t_queue * queue){
		char item = '\0';
		int number = 0;

		while(item != '\n'){
			scanf("%c", &item);
			while(isNumber(&item)){
				number += (number * 10) + (item - '0');
				scanf("%c", &item);
				if(!isNumber(&item)){
					pushQueue(queue, &number, t_int);
					number = 0;
				}
			}
			if(item != ' ' && item != '\n')
				pushQueue(queue, &item, t_char);
		}
	}

	int validExpression(t_queue * queue){
		char * element;
		t_stack * stack = newStack();
		t_queueElement * current = queue->inicio;

		while(current != NULL){
			if(isParenthesis((char *)current->dado) == OPEN_PAR){
				element = (char *) current->dado;
				pushStack(element, stack, t_char);
			}else if(isParenthesis((char *)current->dado) == CLOSE_PAR){
				if(emptyStack(stack)) /* If true, there aren't any '(' in the stack. */
					return 0;	
				element = (char *) popStack(stack);	
			}else if(!isOperator((char *)current->dado) && !isNumber((char *)current->dado))
				return 0;
			current = current->proximo;
		}

		if(!emptyStack(stack)) /* If true, there are still '(' in the stack. More '(' than ')' */
			return 0;
		return 1;
	}
