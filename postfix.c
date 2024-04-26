#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 100

int stack[max];
int top=-1;

bool isEmpty()
{
    return top==-1;

}
bool isFull()
{
    return top==max-1;
}
void push(int data)
{
if(isFull())
{
    printf("Stack Overflow\n");

}
else
{
    stack[++top]=data;
}
}
int pop()
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
    }
    else{
        return stack[top--];
    }
}

int calculate(int operator,int operand1,int operand2)
{
    switch(operator)
    {
    case '+':
        return operand1+operand2;
    case '-':
        return operand1-operand2;
    case '*':
        return operand1*operand2;
    case '/':
            if (operand2 == 0) {
                printf("Error: Division by zero\n");
                return -1;
            }
            else{
                 return operand1 / operand2;
            }

    default:
        printf("Error: Invalid operator\n");
        return -1;
    }
}









int main()
{
    char characters[100];
    int num,result;
    char ch;
    printf("Enter a postfix expression(e.g 2 3 +): ");
    fgets(characters,sizeof(characters),stdin);


    for(int i=0;characters[i]!='\0';i++)
    {
        ch=characters[i];
        if(isdigit(ch))
        {
            num=0;
            while(isdigit(ch))
            {
                num = num * 10 + (ch-'0');
                ch=characters[++i];
            }
            i--;
            push(num);
        }
        else if(ch=='+' || ch=='-' || ch=='/' || ch=='*')
        {
            if(isEmpty())
            {
                printf("Error: Not Enough Operands\n");
                return 1;
            }
            else{
                int operand2=pop();
                if(isEmpty())
            {
                printf("Error: Not Enough Operands\n");
            }
                int operand1=pop();
                 result=calculate(ch,operand1,operand2);
                 if(result!=-1)
                 {
                     push(result);
                 }
                 else
                    continue;

            }
        }
    }
    if(isEmpty())
    {
        printf("Error: Invalid Expression\n");
        return 1;
    }
    result=pop();
    if(!isEmpty())
    {
        printf("Error: Extra operands in Expressions\n");
        return 1;
    }
    printf("%d\n",result);



}







