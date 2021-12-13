#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h> 

// change infix to postfix

char stack[100];
int top = -1;


void pushIP(char item)
{
	if(top >= 99)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}


char popIP()
{
	char item ;

	if(top <0)
	{
		printf("stack under flow: invalid infix expression");
		getchar();
		exit(1);
	}
	else
	{
		item = stack[top];
		top = top-1;
		return(item);
	}
}


int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}


int precedence(char symbol)
{
	if(symbol == '^')
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')          
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void InfixToPostfix(char infix_exp[], char postfix_exp[])
{ 
	int i, j;
	char item;
	char x;

	pushIP('(');                               /* push '(' onto stack */
	strcat(infix_exp,")");                  /* add ')' to infix expression */

	i=0;
	j=0;
	item=infix_exp[i];         /* initialize before loop*/

	while(item != '\0')        /* run loop till end of infix expression */
	{
		if(item == '(')
		{
			pushIP(item);
		}
		else if( isdigit(item) || isalpha(item))
		{
			postfix_exp[j] = item;              /* add operand symbol to postfix expr */
			j++;
		}
		else if(is_operator(item) == 1)        /* means symbol is operator */
		{
			x=popIP();
			while(is_operator(x) == 1 && precedence(x)>= precedence(item))
			{
				postfix_exp[j] = x;                  /* so pop all higher precendence operator and */
				j++;
				x = popIP();                       /* add them to postfix expresion */
			}
			pushIP(x);
			pushIP(item);                 /* push current oprerator symbol onto stack */
		}
		else if(item == ')')         /* if current symbol is ')' then */
		{
			x = popIP();                   /* pop and keep popping until */
			while(x != '(')                /* '(' encounterd */
			{
				postfix_exp[j] = x;
				j++;
				x = popIP();
			}
		}
		else
		{ 
			printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
			getchar();
			exit(1);
		}
		i++;


		item = infix_exp[i]; 
	}
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
		getchar();
		exit(1);
	}
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
		getchar();
		exit(1);
	}


	postfix_exp[j] = '\0'; 
}




  
// Stack exp 
struct Stack 
{ 
    int top; 
    unsigned capacity; 
    int* array; 
}; 
  
// Stack Operations 
struct Stack* createStack( unsigned capacity ) 
{ 
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 
  
    if (!stack) return NULL; 
  
    stack->top = -1; 
    stack->capacity = capacity; 
    stack->array = (int*) malloc(stack->capacity * sizeof(int)); 
  
    if (!stack->array) return NULL; 
  
    return stack; 
} 
  
int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1 ; 
} 
  
char peek(struct Stack* stack) 
{ 
    return stack->array[stack->top]; 
} 
  
char pop(struct Stack* stack) 
{ 
    if (!isEmpty(stack)) 
        return stack->array[stack->top--] ; 
    return '$'; 
} 
  
void push(struct Stack* stack, char op) 
{ 
    stack->array[++stack->top] = op; 
} 
  
  
// The main function that returns value of a given postfix expression 
int evaluatePostfix(char* exp) 
{ 
    struct Stack* stack = createStack(strlen(exp)); 
    int i; 
  
    if (!stack) return -1; 
  
    for (i = 0; exp[i]; ++i) 
    { 
        if (isdigit(exp[i])) 
            push(stack, exp[i] - '0'); 
        else
        { 
            int val1 = pop(stack); 
            int val2 = pop(stack); 
            switch (exp[i]) 
            { 
            case '+': push(stack, val2 + val1); break; 
            case '-': push(stack, val2 - val1); break; 
            case '*': push(stack, val2 * val1); break; 
            case '/': push(stack, val2/val1); break; 
            } 
        } 
    } 
    return pop(stack); 
}



int main() 
{ 
    char exp[100];
    char postfix[100];
    printf("Enter a exp:");
    scanf("%s",exp);
    InfixToPostfix(exp,postfix);
    printf("%s",postfix);
    //printf("%s",postfix);
    printf("\nExp: %d",evaluatePostfix(postfix));
    return 0; 
} 
