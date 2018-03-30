#include "../queue.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    t_queue *queue = newQueue();
    int x=0,y=1,z=2;
    add(queue, &x, t_int);
    add(queue, &y, t_int);
    add(queue, &z, t_int);
    int saindo = removeInt(queue);
    while(saindo != -1){
        printf("%d\n", saindo);
        saindo = removeInt(queue);
    }
    return 0;
}
