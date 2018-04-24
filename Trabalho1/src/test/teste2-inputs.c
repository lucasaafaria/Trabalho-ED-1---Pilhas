#include "../inputs.h"

void imprimir(t_list * l){
	int tipoDado;

	while(!isEmpty(l)){
		tipoDado = getNextType(l);
		switch(tipoDado){
			case t_double:
				printf("%.0f ", removeFirstDouble(l));
				break;
			case t_char:
				printf("%c ", removeFirstChar(l));
				break;
		}
	}
	printf("\nFila vazia\n");
}

int main(){
	t_queue * queue = newQueue();
    printf("Digite uma expressão");
	getExpression(queue);
	imprimir(queue->l);

	return 0;
}
