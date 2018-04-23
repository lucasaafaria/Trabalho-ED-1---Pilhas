#include "../queue.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    t_queue *queue = newQueue();
    double x=0,y=1,z=2;
    add(queue, &x, t_double);
    add(queue, &y, t_double);
    add(queue, &z, t_double);
    double saindo = removeDouble(queue);
    while(saindo != -1){
        printf("%lf\n", saindo);
        saindo = removeDouble(queue);
    }
    return 0;
}
