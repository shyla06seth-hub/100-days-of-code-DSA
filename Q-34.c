//Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push function
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop function
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return 0;
    }
    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

int main() {
    char exp[100];
    char *token;

    fgets(exp, sizeof(exp), stdin);

    token = strtok(exp, " \n");

    while (token != NULL) {

        // If number
        if (isdigit(token[0]) || (token[0]=='-' && isdigit(token[1]))) {
            push(atoi(token));
        }
        else {
            int b = pop();
            int a = pop();
            int result;

            switch(token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(result);
        }

        token = strtok(NULL, " \n");
    }

    printf("%d", pop());

    return 0;
}