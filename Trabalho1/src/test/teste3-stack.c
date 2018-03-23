#include "../stack.h"

void inserir(t_stack *stack){
    int x=0,y=1,z=2;
    push(stack, &x);
    push(stack, &y);
    push(stack, &z);  
}

int main(){
    t_stack *stack = newStack();
    inserir(stack);
    printStack(stack, t_int);
    return 0;
}
