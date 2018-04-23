#include "../list.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    t_list *list = newList();
    char x='a',y='b',z='c';
    addStart(list, &x, t_double);
    addStart(list, &y, t_double);
    addStart(list, &z, t_double);
    char saindo = removeFirstChar(list);
    while(saindo != 0){
        printf("%c\n", saindo);
        saindo = removeFirstChar(list);
    }
    return 0;
}
