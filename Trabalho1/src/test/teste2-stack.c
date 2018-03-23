#include "../stack.h"

int main(){
    t_stack *stack = newStack();
    char x='a',y='b',z='c';
    push(stack, &x);
    push(stack, &y);
    push(stack, &z);
    printStack(stack, t_char);
    return 0;
}
