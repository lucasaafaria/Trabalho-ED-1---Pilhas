#include "../queue.h"
#include "../calculate.h"

int main(){
    t_queue *queue = newQueue();
    int valor = 2;
    char op = '+';
    add(queue, &valor, t_int);
    valor = 3;
    add(queue, &valor, t_int);
    add(queue, &op, t_char);
    printf("fila gerada! 2 3 +\n");
    printf("%lf\n",calculate(queue));
    return 0;
}
