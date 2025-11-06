#include &lt;stdio.h&gt;
#define MAX 100 // Maximum size of stack
// Stack structure
typedef struct {
int arr[MAX];
int top;
} Stack;
// Initialize stack
void init(Stack *s) {
s-&gt;top = -1;
}
// Check if stack is empty
int isEmpty(Stack *s) {
return s-&gt;top == -1;
}
// Check if stack is full
int isFull(Stack *s) {
return s-&gt;top == MAX - 1;
}
// Push element onto stack
void push(Stack *s, int value) {
if (isFull(s)) {
printf(&quot;Stack Overflow! Cannot push %d\n&quot;, value);
return;
}
s-&gt;arr[++(s-&gt;top)] = value;
printf(&quot;Pushed %d\n&quot;, value);
}
// Pop element from stack
int pop(Stack *s) {

if (isEmpty(s)) {
printf(&quot;Stack Underflow! Cannot pop\n&quot;);
return -1; // Return -1 to indicate error
}
return s-&gt;arr[(s-&gt;top)--];
}
// Peek top element of stack
int peek(Stack *s) {
if (isEmpty(s)) {
printf(&quot;Stack is empty\n&quot;);
return -1;
}
return s-&gt;arr[s-&gt;top];
}
int main() {
Stack s;
init(&amp;s);
push(&amp;s, 10);
push(&amp;s, 20);
push(&amp;s, 30);
printf(&quot;Top element is %d\n&quot;, peek(&amp;s));
printf(&quot;Popped element is %d\n&quot;, pop(&amp;s));
printf(&quot;Popped element is %d\n&quot;, pop(&amp;s));
if (isEmpty(&amp;s)) {
printf(&quot;Stack is empty now\n&quot;);
} else {
printf(&quot;Stack is not empty\n&quot;);
}
return 0;
}
