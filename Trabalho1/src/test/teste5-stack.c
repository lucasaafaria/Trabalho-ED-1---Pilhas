#include "../stack.h"

int main(){
    t_stack *stack = newStack();
    pushChar(stack,'a');
    pushChar(stack,'b');
    pushChar(stack,'c');
    printStack(stack, t_char);
    return 0;
}
