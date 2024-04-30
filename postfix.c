#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;


void initialize(Stack *stack);
bool isEmpty(Stack *stack);
bool isFull(Stack *stack);
void push(Stack *stack, int data);
int pop(Stack *stack);
int calculate(int operator, int operand1, int operand2);

int main() {
    Stack stack;
    initialize(&stack);

    char characters[100];
    int num, result;
    char ch;
    printf("Enter a postfix expression (e.g., 2 3 +): ");
    fgets(characters, sizeof(characters), stdin);

    for (int i = 0; characters[i] != '\0'; i++) {
        ch = characters[i];
        if (isdigit(ch)) {
            num = 0;
            while (isdigit(ch)) {
                num = num * 10 + (ch - '0');
                ch = characters[++i];
            }
            i--;
            push(&stack, num);
        } else if (ch == '+' || ch == '-' || ch == '/' || ch == '*') {
            if (isEmpty(&stack)) {
                printf("Error: Not Enough Operands\n");
                return 1;
            } else {
                int operand2 = pop(&stack);
                if (isEmpty(&stack)) {
                    printf("Error: Not Enough Operands\n");
                    return 1;
                }
                int operand1 = pop(&stack);
                result = calculate(ch, operand1, operand2);
                if (result != -1) {
                    push(&stack, result);
                } else {
                    continue;
                }
            }
        }
    }

    if (isEmpty(&stack)) {
        printf("Error: Invalid Expression\n");
        return 1;
    }
    result = pop(&stack);
    if (!isEmpty(&stack)) {
        printf("Error: Extra operands in Expression\n");
        return 1;
    }
    printf("%d\n", result);
    return 0;
}


void initialize(Stack *stack) {
    stack->top = -1;
}


bool isEmpty(Stack *stack) {
    return stack->top == -1;
}


bool isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}


void push(Stack *stack, int data) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
    } else {
        stack->data[++stack->top] = data;
    }
}


int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack->data[stack->top--];
    }
}


int calculate(int operator, int operand1, int operand2) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                printf("Error: Division by zero\n");
                return -1;
            } else {
                return operand1 / operand2;
            }
        default:
            printf("Error: Invalid operator\n");
            return -1;
    }
}

