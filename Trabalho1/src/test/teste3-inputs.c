#include "../inputs.h"

int main(){
	t_queue * queue = newQueue();
    t_queue * final = newQueue();
    printf("Insira uma expressão:\n");
	getExpression(queue);
	if(validExpression(queue, final))
		printf("Expressão Válida!\n");
	else
		printf("Expressão Inválida!\n");

	return 0;
}
