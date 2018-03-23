#ifndef _INPUTS_H_
#define _INPUTS_H_

void getExpression(char * string){
	scanf("%[^\n]", string);
}

int validExpression(char * string, t_stack * parentesis){
	int i;

	for(i = 0; string[i] != '\0'; ++i){
		if(isOpParenthesis(input))
			pushStack(input, parenthesis);
		else if(isClParenthesis(input)){
			if(topElement(parenthesis) != '(')
				return 0;
			else
				popStack(parenthesis);
		}
	}

	if(!emptyStack(parenthesis)) /* If true, there are still '(' in the stack. More '(' than ')' */
		return 0;	
	return 1;
}

