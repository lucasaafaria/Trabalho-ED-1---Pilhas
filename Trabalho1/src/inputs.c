/*------------------------- Trabalho 1 - Pilhas -------------------------
* Implementação das funções de entrada de dados, validação e transformação em pós-fixo
*		@autores: Lucas de Almeida Abreu Faria, Mateus Berardo de Souza Terra
*	 @matriculas: 17/0016668 ; 17/0018806
*    @disciplina: Estruturas de Dados
*     @professor: Eduardo Alchieri
*/

#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "stack.h"

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
	
	int isSpace(char * dado){
		if((*dado) == ' ')
			return 1;
		return 0;
	}