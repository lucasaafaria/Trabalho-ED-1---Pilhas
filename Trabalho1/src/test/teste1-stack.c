#include "../stack.h"

int main(){
    t_stack *stack = newStack();
    int x=0,y=1,z=2;
    push(stack, &x);
    push(stack, &y);
    push(stack, &z);
    printStack(stack, t_int);
    return 0;
}
