/*------------------------- Trabalho 1 - Pilhas -------------------------
*       header da transformação da forma infixa para posfixa
*		@autores: Lucas de Almeida Abreu Faria, Mateus Berardo de Souza Terra
*	 @matriculas: 17/0016668 ; 17/0018806
*    @disciplina: Estruturas de Dados
*     @professor: Eduardo Alchieri
*/

#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

    #include "inputs.h"

	extern void parenthesisProcess(char * dado, t_stack * stack, t_queue * saida);
	extern void operatorProcess(char * dado, t_stack * stack, t_queue * saida);
	extern t_queue * transform(t_queue * queue);

#endif