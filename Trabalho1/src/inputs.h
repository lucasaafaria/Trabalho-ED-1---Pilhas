/*------------------------- Trabalho 1 - Pilhas -------------------------
*       processamento da entrada infixa e transformação em posfixa
*		@autores: Lucas de Almeida Abreu Faria, Mateus Berardo de Souza Terra
*	 @matriculas: 17/0016668 ; 17/0018806
*    @disciplina: Estruturas de Dados
*     @professor: Eduardo Alchieri
*/

#ifndef _INPUTS_H_
#define _INPUTS_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include "stack.h"
    #include "list.h"
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
