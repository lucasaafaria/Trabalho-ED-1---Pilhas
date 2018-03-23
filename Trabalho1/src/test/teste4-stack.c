#include "../stack.h"

int main(){
    t_stack *stack = newStack();
    pushInt(stack,0);
    pushInt(stack,1);
    pushInt(stack,2);
    printStack(stack, t_int);
    return 0;
}
