#include &lt;stdio.h&gt;
#include &lt;ctype.h&gt; // for isalpha() and isdigit()
#include &lt;string.h&gt;
#define MAX 100
typedef struct {
char arr[MAX];
int top;
} Stack;
void init(Stack *s) {
s-&gt;top = -1;
}
int isEmpty(Stack *s) {
return s-&gt;top == -1;
}
int isFull(Stack *s) {
return s-&gt;top == MAX - 1;
}
void push(Stack *s, char c) {
if (!isFull(s)) {
s-&gt;arr[++(s-&gt;top)] = c;
}
}
char pop(Stack *s) {
if (!isEmpty(s)) {
return s-&gt;arr[(s-&gt;top)--];
}
return &#39;\0&#39;; // stack empty
}
char peek(Stack *s) {

if (!isEmpty(s)) {
return s-&gt;arr[s-&gt;top];
}
return &#39;\0&#39;;
}
// Function to return precedence of operators
int precedence(char op) {
switch (op) {
case &#39;+&#39;:
case &#39;-&#39;: return 1;
case &#39;*&#39;:
case &#39;/&#39;: return 2;
case &#39;^&#39;: return 3;
}
return 0;
}
// Check if character is operator
int isOperator(char c) {
return c == &#39;+&#39; || c == &#39;-&#39; || c == &#39;*&#39; || c == &#39;/&#39; || c == &#39;^&#39;;
}
void infixToPostfix(char* infix, char* postfix) {
Stack s;
init(&amp;s);
int k = 0; // Index for postfix
for (int i = 0; infix[i] != &#39;\0&#39;; i++) {
char c = infix[i];
// If operand (letter or digit), add to postfix
if (isalnum(c)) {
postfix[k++] = c;
}
// If &#39;(&#39;, push to stack

else if (c == &#39;(&#39;) {
push(&amp;s, c);
}
// If &#39;)&#39;, pop and output until &#39;(&#39;
else if (c == &#39;)&#39;) {
while (!isEmpty(&amp;s) &amp;&amp; peek(&amp;s) != &#39;(&#39;) {
postfix[k++] = pop(&amp;s);
}
pop(&amp;s); // Remove &#39;(&#39; from stack
}
// If operator
else if (isOperator(c)) {
while (!isEmpty(&amp;s) &amp;&amp; precedence(peek(&amp;s)) &gt;= precedence(c)) {
if (c == &#39;^&#39; &amp;&amp; peek(&amp;s) == &#39;^&#39;) {
// Right associative operator &#39;^&#39; should not pop same precedence
operator
break;
} else {
postfix[k++] = pop(&amp;s);
}
}
push(&amp;s, c);
}
}

// Pop all remaining operators
while (!isEmpty(&amp;s)) {
postfix[k++] = pop(&amp;s);
}
postfix[k] = &#39;\0&#39;; // Null-terminate postfix string
}

int main() {
char infix[MAX];
char postfix[MAX];
printf(&quot;Enter infix expression: &quot;);
fgets(infix, MAX, stdin);
infix[strcspn(infix, &quot;\n&quot;)] = &#39;\0&#39;; // Remove trailing newline
infixToPostfix(infix, postfix);
printf(&quot;Postfix expression: %s\n&quot;, postfix);
return 0;
}
