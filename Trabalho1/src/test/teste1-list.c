#include "../list.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    t_list *list = newList();
    double x=0,y=1,z=2;
    addStart(list, &x, t_double);
    addStart(list, &y, t_double);
    addStart(list, &z, t_double);
    double saindo = removeFirstDouble(list);
    while(saindo != -1){
        printf("%lf\n", saindo);
        saindo = removeFirstDouble(list);
    }
    return 0;
}
