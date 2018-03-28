#include "../stack.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    t_stack *stack = newStack();
    int x=0,y=1,z=2;
    push(stack, &x, t_int);
    push(stack, &y, t_int);
    push(stack, &z, t_int);
    int saindo = popInt(stack);
    while(saindo != -1){
        printf("%d\n", saindo);
        saindo = popInt(stack);
    }
    return 0;
}
