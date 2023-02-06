#include<stdio.h>
#include<ctype.h>
#include<math.h>

#define MAX 100
char stack[MAX];
int top = -1;

int push(int x)
{
if(top == MAX-1)
{
printf("Error: Stack Overflow\n");
return -1;
}
stack[++top] = x;
return 0;
}

int pop()
{
if(top == -1)
{
printf("Error: Stack Underflow\n");
return -1;
}
return stack[top--];
}

int eval(int a, int b, char op)
{
switch(op)
{
case '+': return b+a;
case '-': return b-a;
case '*': return b*a;
case '/': return b/a;
case '%': return b%a;
case '^': return pow(b, a);
default: printf("Invalid operator\n");
return -1;
}
}

int evaluate(char exp[])
{
int i, a, b;
for(i = 0; exp[i]; i++)
{
if(isdigit(exp[i]))
{
push(exp[i] - '0');
}
else
{
a = pop();
b = pop();
push(eval(a, b, exp[i]));
}
}
return stack[top];
}

void main()
{
char exp[MAX];
printf("Enter the suffix expression: ");
scanf("%s", exp);
printf("Evaluated expression: %d\n", evaluate(exp));
}
