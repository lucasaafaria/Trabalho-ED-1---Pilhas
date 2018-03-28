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
					add(queue, &number, t_int);
					number = 0;
				}
			}
			if(item != ' ' && item != '\n')
				add(queue, &item, t_char);
		}
	}

	int validExpression(t_queue * queue){
	    /* Nao percorrer a fila, retirar os elementos pra interpretar */
		char element;
		t_stack * stack = newStack();
		t_queueElement * current = queue->inicio;
		/* sugestao
		t_queueElement * current = removeQElement(queue);
		*/

		while(current != NULL){
			if(isParenthesis((char *)current->dado) == OPEN_PAR){
				element = *(char *) current->dado;
				push(stack, &element, t_char);
			}else if(isParenthesis((char *)current->dado) == CLOSE_PAR){
				if(emptyStack(stack)) /* If true, there aren't any '(' in the stack. */
					return 0;	
				element = popChar(stack);	
			}else if(!isOperator((char *)current->dado) && !isNumber((char *)current->dado))
				return 0;
			/* sugestao
			free(current);
			current = removeQElement(queue);
			*/
			current = current->proximo;
		}

		if(!emptyStack(stack)) /* If true, there are still '(' in the stack. More '(' than ')' */
			return 0;
		return 1;
	}
