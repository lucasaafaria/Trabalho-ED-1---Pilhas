#include "../list.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    t_list *list = newList();
    int x=0,y=1,z=2;
    addStart(list, &x, t_int);
    addStart(list, &y, t_int);
    addStart(list, &z, t_int);
    int saindo = removeFirstInt(list);
    while(saindo != -1){
        printf("%d\n", saindo);
        saindo = removeFirstInt(list);
    }
    return 0;
}
