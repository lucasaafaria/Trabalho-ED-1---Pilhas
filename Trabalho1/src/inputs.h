#ifndef _INPUTS_H_
#define _INPUTS_H_

    #include "stack.h"
    #include "queue.h"

	/* Definição de constantes para '(' e ')' */
	#define OPEN_PAR	1
	#define CLOSE_PAR	2

	/* Definição de funções de comparação */
	extern int isNumber(char * dado);
	extern int isOperator(char * dado);
	extern int isParenthesis(char * dado);
	extern int isSpace(char * dado);

	/* Definição de funções de entrada e tratamento de dados */
	extern void getExpression(t_queue * queue);
	extern int validExpression(t_queue * queue);

#endif
