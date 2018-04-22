/*------------------------- Trabalho 1 - Pilhas -------------------------
*       header do processamento da entrada de dados e validação
*		@autores: Lucas de Almeida Abreu Faria, Mateus Berardo de Souza Terra
*	 @matriculas: 17/0016668 ; 17/0018806
*    @disciplina: Estruturas de Dados
*     @professor: Eduardo Alchieri
*/

#ifndef _INPUTS_H_
#define _INPUTS_H_

    #include "queue.h"

	/* Definição de funções de comparação */
	extern int isNumber(char * dado);
	extern int isOperator(char * dado);
	extern int isParenthesis(char * dado);
	extern int isLowerPrior(char * dado);

	/* Definição de funções de entrada e tratamento de dados */
	extern void getExpression(t_queue * queue);
	extern int okTestsDouble(int lastType, char lastChar);
	extern int okTestsChar(char dado, int lastType, char lastChar);
	extern int validExpression(t_queue * queue, t_queue * validada);

#endif
