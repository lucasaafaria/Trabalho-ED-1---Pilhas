/*------------------------- Trabalho 1 - Pilhas -------------------------
*		@autores: Lucas de Almeida Abreu Faria, Mateus Berardo de Souza Terra
*	 @matriculas: 17/0016668 , 17/0018806
*    @disciplina: Estruturas de Dados
*     @professor: Eduardo A. P. Alchieri
*/

#include "calculate.h"

int main(){
    t_queue * queue = newQueue();
    t_queue * validada = newQueue();
	getExpression(queue);
	if(!validExpression(queue, validada)){
		printf("Expressão inválida\n");
	}else{
		free(queue);
		printf("%lf\n", calculate(transform(validada)));
	}
	return 0;
}