#include "../transform.h"

void imprimir(t_queue * queue){
	int tipoDado;

	while(!isEmptyQueue(queue)){
		tipoDado = getNextQueueType(queue);
		switch(tipoDado){
			case t_double:
				printf("%.0f", removeDouble(queue));
				break;
			case t_char:
				printf("%c", removeChar(queue));
				break;
		}
	}
	printf("\nFila vazia\n");
}

int main(){
	t_queue * queue = newQueue();
	getExpression(queue);
	t_queue * saida = transform(queue);
	imprimir(saida);

	return 0;
}