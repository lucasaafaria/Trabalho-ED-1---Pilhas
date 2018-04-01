#include "../inputs.h"

int main(){
	t_queue * queue = newQueue();

	getExpression(queue);
	if(validExpression(queue))
		printf("Expressão Válida!\n");
	else
		printf("Expressão Inválida!\n");

	return 0;
}