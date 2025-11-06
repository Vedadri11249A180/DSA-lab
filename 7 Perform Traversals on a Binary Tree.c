#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

#define MAX_QUEUE 100
typedef struct {
    Node* items[MAX_QUEUE];
    int front, rear;
} Queue;

Node* createNode(int value) {
   
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->rear < q->front;
}
void enqueue(Queue* q, Node* node) {
    if (q->rear < MAX_QUEUE - 1) {
        q->items[++q->rear] = node;
    } else {
        // Simple error handling for full queue
        fprintf(stderr, "Queue overflow!\n");
    }
}
Node* dequeue(Queue* q) {
    if (!isEmpty(q)) {
        return q->items[q->front++];
    }
    return NULL;
}
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);          // Visit left subtree
    printf("%d ", root->data);    // Visit root
    inorder(root->right);         // Visit right subtree
}

void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);    // Visit root
    preorder(root->left);         // Visit left subtree
    preorder(root->right);        // Visit right subtree
}
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);        // Visit left subtree
    postorder(root->right);       // Visit right subtree
    printf("%d ", root->data);    // Visit root
}
void levelOrder(Node* root) {
    if (root == NULL) return;

    Queue q;
    initQueue(&q);

    enqueue(&q, root);

    while (!isEmpty(&q)) {
        Node* current = dequeue(&q);

        printf("%d ", current->data);

       
        if (current->left != NULL) {
            enqueue(&q, current->left);
        }

     
        if (current->right != NULL) {
            enqueue(&q, current->right);
        }
    }
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}



int main() {
  
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6); // Node 3 has no left child

    printf("--- Binary Tree Traversal Demonstration ---\n");

    
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    printf("Level-order traversal: ");
    levelOrder(root);
    printf("\n");

    // Clean up memory
    freeTree(root);

    return 0;
}
