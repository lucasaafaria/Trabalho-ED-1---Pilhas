#include "../stack.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    t_stack *stack = newStack();
    char x='a',y='b',z='c';
    push(stack, &x, t_char);
    push(stack, &y, t_char);
    push(stack, &z, t_char);
    char saindo = popChar(stack);
    while(saindo != 0){
        printf("%c\n", saindo);
        saindo = popChar(stack);
    }
    return 0;
}
