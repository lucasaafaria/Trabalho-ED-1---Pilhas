/*------------------------- Trabalho 1 - Pilhas -------------------------
*       Implementação da entrada de dados e validação
*		@autores: Lucas de Almeida Abreu Faria, Mateus Berardo de Souza Terra
*	 @matriculas: 17/0016668 ; 17/0018806
*    @disciplina: Estruturas de Dados
*     @professor: Eduardo Alchieri
*/


#include "inputs.h"

	/* Funções de comparação */
	int isParenthesis(char * dado){
		if((*dado) == '(' || (*dado) == ')')
			return 1;
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

	int isLowerPrior(char * dado){
		if(*dado == '+' || *dado == '-')
			return 1;
		return 0;
	}

	/* Recebe a entrada de dados do programa */
	void getExpression(t_queue * queue){
		char dado = '\0';
		double number = 0.0;

		while(dado != '\n'){
			scanf("%c", &dado);
			while(isNumber(&dado)){	/* Algoritmo para lidar com números de mais de 1 algarismo */
				number = (number * 10.0) + (dado - '0');
				scanf("%c", &dado);
				if(!isNumber(&dado)){
					add(queue, &number, t_double);
					number = 0.0;
				}
			}
			if(dado != ' ' && dado != '\n') /* Ignora espaços vazios */
				add(queue, &dado, t_char);
		}
	}

	/* Testes para validação da entrada */
	int okTestsDouble(int lastType, char lastChar){
		if(lastType == t_double) /* Dois números seguidos na fila */
			return 0;
		if(lastChar == ')' && lastType == t_char) /* ')' seguido de número */
			return 0;
		return 1;
	}

	int okTestsChar(char dado, int lastType, char lastChar){
		if(!isOperator(&dado) && !isParenthesis(&dado)) /* Caractere inválido */
			return 0;
		switch(dado){
			case '(':
				if(lastType == t_double) /* número seguido de '(' */
					return 0;
				if(lastChar == ')' && lastType == t_char) /* ')' seguido de '(' */
					return 0;
				break;
			case ')':
				if(isOperator(&lastChar) && lastType == t_char) /* operador seguido de ')' */
					return 0;
				break;
			default:
				if(lastType == -1 && !isLowerPrior(&dado)) /* expressão começa com '*' ou '/' */
					return 0;
				if(lastChar == '(' && lastType == t_char && !isLowerPrior(&dado)) /* '(' seguido de '*' ou '/' */
					return 0; 
				if(isOperator(&lastChar) && lastType == t_char) /* dois operadores seguidos */
					return 0;
				break;
		}
		return 1;
	}

	/* Valida a expressão */
	int validExpression(t_queue * queue, t_queue * validada){
		t_stack * stack = newStack();
		char lastChar = '\0', dadoChar;
		int tipoDado, lastType = -1, opCount = 0, doubleCount = 0;
		double dadoDouble;

		while(!isEmptyQueue(queue)){
			tipoDado = getNextQueueType(queue);
			if(tipoDado == t_double){
				dadoDouble = removeDouble(queue);
				if(!okTestsDouble(lastType, lastChar))
					return 0;
				doubleCount++;
				lastType = t_double;
				add(validada, &dadoDouble, t_double);
			}else{
				dadoChar = removeChar(queue);
				if(!okTestsChar(dadoChar, lastType, lastChar))
					return 0;
				if(dadoChar == '(')
					push(stack, &dadoChar, t_char);
				else if(dadoChar == ')'){
					if(isStackEmpty(stack))
						return 0;
					if(popChar(stack) != '(')
						return 0; 
				}else if(isLowerPrior(&dadoChar)){
					if((lastChar == '(' && lastType == t_char) || lastType == -1){
						dadoDouble = 0;
						doubleCount++;
						add(validada, &dadoDouble, t_double);
					}
				}
				if(isOperator(&dadoChar))
					opCount++;
				lastType = t_char;
				lastChar = dadoChar;
				add(validada, &dadoChar, t_char);
			}
		}
		if(opCount >= doubleCount)
			return 0;
		if(!isStackEmpty(stack))
			return 0;
		return 1;
	}
