#include "../stack.h"
#include <stdio.h>
#include <stdlib.h>

void inserir(t_stack *stack){
    double x=0,y=1,z=2;
    push(stack, &x, t_double);
    push(stack, &y, t_double);
    push(stack, &z, t_double);  
}

int main(){
    t_stack *stack = newStack();
    inserir(stack);
    double saindo = popDouble(stack);
    while(saindo != -1){
        printf("%lf\n", saindo);
        saindo = popDouble(stack);
    }
    return 0;
}
