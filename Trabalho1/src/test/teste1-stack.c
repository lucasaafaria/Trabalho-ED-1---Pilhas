#include "../stack.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    t_stack *stack = newStack();
    double x=3,y=1,z=2;
    push(stack, &x, t_double);
    push(stack, &y, t_double);
    push(stack, &z, t_double);
    double saindo = popDouble(stack);
    while(saindo != 0){
        printf("%lf\n", saindo);
        saindo = popDouble(stack);
    }
    return 0;
}
