#include &lt;stdio.h&gt;
#define MAX 100
typedef struct {
int arr[MAX];
int front;
int rear;
} Queue;
void init(Queue *q) {
q-&gt;front = -1;
q-&gt;rear = -1;
}
int isEmpty(Queue *q) {
return q-&gt;front == -1;
}
int isFull(Queue *q) {
return (q-&gt;rear + 1) % MAX == q-&gt;front;
}
void enqueue(Queue *q, int value) {
if (isFull(q)) {
printf(&quot;Queue Overflow! Cannot enqueue %d\n&quot;, value);
return;
}

if (isEmpty(q)) {
q-&gt;front = 0;
}
q-&gt;rear = (q-&gt;rear + 1) % MAX;
q-&gt;arr[q-&gt;rear] = value;
printf(&quot;Enqueued %d\n&quot;, value);
}

int dequeue(Queue *q) {
if (isEmpty(q)) {
printf(&quot;Queue Underflow! Cannot dequeue\n&quot;);
return -1; // Indicate error
}
int value = q-&gt;arr[q-&gt;front];
if (q-&gt;front == q-&gt;rear) {
// Queue has only one element, reset after dequeue
q-&gt;front = -1;
q-&gt;rear = -1;
} else {
q-&gt;front = (q-&gt;front + 1) % MAX;
}
return value;
}

int peek(Queue *q) {
if (isEmpty(q)) {
printf(&quot;Queue is empty\n&quot;);
return -1;
}
return q-&gt;arr[q-&gt;front];
}

int main() {
Queue q;
init(&amp;q);
enqueue(&amp;q, 10);
enqueue(&amp;q, 20);
enqueue(&amp;q, 30);
printf(&quot;Front element is %d\n&quot;, peek(&amp;q));
printf(&quot;Dequeued element is %d\n&quot;, dequeue(&amp;q));
printf(&quot;Dequeued element is %d\n&quot;, dequeue(&amp;q));
if (isEmpty(&amp;q)) {
printf(&quot;Queue is empty now\n&quot;);
} else {
printf(&quot;Queue is not empty\n&quot;);
}
return 0;
}
