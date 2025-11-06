#include <stdio.h>
#define MAX 100  // Maximum size of stack


typedef struct {
    int arr[MAX];
    int top;
} Stack;


void init(Stack *s) {
    s->top = -1;
}


int isEmpty(Stack *s) {
    return s->top == -1;
}


int isFull(Stack *s) {
    return s->top == MAX - 1;
}


void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    s->arr[++(s->top)] = value;
    printf("Pushed %d\n", value);
}


int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop\n");
        return -1; // Return -1 to indicate error
    }
    return s->arr[(s->top)--];
}

// Peek top element of stack
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->arr[s->top];
}


int main() {
    Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element is %d\n", peek(&s));

    printf("Popped element is %d\n", pop(&s));
    printf("Popped element is %d\n", pop(&s));

    if (isEmpty(&s)) {
        printf("Stack is empty now\n");
    } else {
        printf("Stack is not empty\n");
    }

    return 0;
}
