#include "../queue.h"
#include "../calculate.h"

int main(){
    t_queue *queue = newQueue();
    double valor = 2;
    char op = '+';
    add(queue, &valor, t_double);
    valor = 3;
    add(queue, &valor, t_double);
    add(queue, &op, t_char);
    valor = 5;
    op = '*';
    add(queue, &valor, t_double);
    add(queue, &op, t_char);
    printf("fila gerada! 2 3 + 5 *\n");
    printf("%lf\n",calculate(queue));
    return 0;
}
