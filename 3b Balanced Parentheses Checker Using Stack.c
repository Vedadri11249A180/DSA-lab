#include &lt;stdio.h&gt;
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
if (isFull(s)) {
printf(&quot;Stack Overflow\n&quot;);
return;
}
s-&gt;arr[++(s-&gt;top)] = c;
}
char pop(Stack *s) {
if (isEmpty(s)) {
return &#39;\0&#39;; // Empty stack
}
return s-&gt;arr[(s-&gt;top)--];
}
int isMatchingPair(char open, char close) {
return (open == &#39;(&#39; &amp;&amp; close == &#39;)&#39;) ||
(open == &#39;{&#39; &amp;&amp; close == &#39;}&#39;) ||
(open == &#39;[&#39; &amp;&amp; close == &#39;]&#39;);
}
int areParenthesesBalanced(char *expr) {
Stack s;
init(&amp;s);
for (int i = 0; expr[i] != &#39;\0&#39;; i++) {
char ch = expr[i];
// If opening bracket, push it
if (ch == &#39;(&#39; || ch == &#39;{&#39; || ch == &#39;[&#39;) {
push(&amp;s, ch);

}
// If closing bracket, stack must not be empty and top must match
else if (ch == &#39;)&#39; || ch == &#39;}&#39; || ch == &#39;]&#39;) {
if (isEmpty(&amp;s)) {
return 0; // No matching opening bracket
}
char topChar = pop(&amp;s);
if (!isMatchingPair(topChar, ch)) {
return 0; // Mismatched pair
}
}
}

// At the end, stack should be empty if balanced
return isEmpty(&amp;s);
}

int main() {
char expr[MAX];

printf(&quot;Enter expression: &quot;);
fgets(expr, MAX, stdin);

// Remove trailing newline if present
expr[strcspn(expr, &quot;\n&quot;)] = &#39;\0&#39;;

if (areParenthesesBalanced(expr)) {
printf(&quot;Parentheses are balanced.\n&quot;);
} else {
printf(&quot;Parentheses are NOT balanced.\n&quot;);
}

return 0;
}
