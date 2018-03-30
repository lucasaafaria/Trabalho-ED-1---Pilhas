#include "../list.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    t_list *list = newList();
    char x='a',y='b',z='c';
    addStart(list, &x, t_int);
    addStart(list, &y, t_int);
    addStart(list, &z, t_int);
    char saindo = removeFirstChar(list);
    while(saindo != 0){
        printf("%c\n", saindo);
        saindo = removeFirstChar(list);
    }
    return 0;
}
