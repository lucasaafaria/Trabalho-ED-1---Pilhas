#include "../inputs.h"
#include <stdio.h>

int main(){
	int i;
	char dado[] = "B+-*/() 0";

	for(i = 0; i < 9; ++i){
		printf("is %c a number? R: %d\n", dado[i], isNumber(&dado[i]));
		printf("is %c an operator? R: %d\n", dado[i], isOperator(&dado[i]));
		printf("is %c a parenthesis? R: %d\n", dado[i], isParenthesis(&dado[i]));
		printf("is %c a space? R: %d\n", dado[i], isSpace(&dado[i]));		
	}
}
