#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    char data[MAX_SIZE];
    int top;
};

struct Stack stack;

int precedence(char operator) 
{
    switch (operator) 
    {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

void push(char item) 
{
    if (stack.top == MAX_SIZE - 1) 
    {
        printf("Stack Overflow\n");
    } 
    else 
    {
        stack.data[++stack.top] = item;
    }
}

char pop() {
    if (stack.top == -1) 
    {
        return '\0';
    } 
    else 
    {
        return stack.data[stack.top--];
    }
}

int isOperator(char ch) 
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void infixToPostfix(char* infix) 
{
    char postfix[MAX_SIZE];
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) 
    {
        char currentChar = infix[i];
        switch (currentChar) 
        {
            case '(':
                push(currentChar);
                break;
            case ')':
                while (stack.top != -1 && stack.data[stack.top] != '(') { 
                    postfix[j++] = pop();
                }
                if (stack.data[stack.top] == '(') 
                {
                    pop();  // Remove the '(' from the stack
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (stack.top != -1 && stack.data[stack.top] != '(' && precedence(stack.data[stack.top]) >= precedence(currentChar)) 
                       {
                        postfix[j++] = pop();
                       }
                push(currentChar);
                break;
            default:
                postfix[j++] = currentChar;
                break;
        }
    }
    while (stack.top != -1) 
    {
        if (stack.data[stack.top] == '(') 
        {
            pop();  // Remove the '(' from the stack
        } 
        else 
        {
            postfix[j++] = pop();
        }
    }
    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
}

void infixToPrefix(char* infix) 
{
    char reversedInfix[MAX_SIZE];
    char prefix[MAX_SIZE];
    int i, j = 0;

    // Reverse the infix expression
    for (i = strlen(infix) - 1; i >= 0; i--) 
    {
        reversedInfix[j++] = infix[i];
    }
    reversedInfix[j] = '\0';

    // Swap '(' and ')' in the reversed expression
    for (i = 0; reversedInfix[i] != '\0'; i++) 
    {
        if (reversedInfix[i] == '(') 
        {
            reversedInfix[i] = ')';
        } 
        else if (reversedInfix[i] == ')') 
        {
            reversedInfix[i] = '(';
        }
    }
    j = 0;
    for (i = 0; reversedInfix[i] != '\0'; i++) 
    {
        char currentChar = reversedInfix[i];
        switch (currentChar) 
        {
            case '(':
                push(currentChar);
                break;
            case ')':
                while (stack.top != -1 && stack.data[stack.top] != '(')
                {
                    prefix[j++] = pop();
                }
                if (stack.data[stack.top] == '(') 
                {
                    pop();  // Remove the '(' from the stack
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (stack.top != -1 && stack.data[stack.top] != '(' && precedence(stack.data[stack.top]) > precedence(currentChar)) 
                       {
                         prefix[j++] = pop();
                       }
                push(currentChar);
                break;
            default:
                prefix[j++] = currentChar;
                break;
        }
    }

    while (stack.top != -1) {
        if (stack.data[stack.top] == '(') 
        {
            pop();  // Remove the '(' from the stack
        } else {
            prefix[j++] = pop();
        }
    }

    prefix[j] = '\0';

    // Reverse the prefix expression
    char finalPrefix[MAX_SIZE];
    j = 0;
    for (i = strlen(prefix) - 1; i >= 0; i--) 
    {
        finalPrefix[j++] = prefix[i];
    }
    finalPrefix[j] = '\0';

    printf("Prefix expression: %s\n", finalPrefix);
}

int main() {
    char infix[MAX_SIZE];

    printf("Enter an infix expression: ");
    gets(infix);

    stack.top = -1;  // Initialize the stack

    infixToPostfix(infix);
    infixToPrefix(infix);

    return 0;
}
