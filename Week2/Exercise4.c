#include <stdio.h>
#include <stdlib.h>

// Define the structure for each element (node) in the queue
struct node {
    int data;
    struct node *next;
};

// Define the structure for the queue, which keeps track of the head and tail
struct queue {
    struct node *head; // Points to the front of the queue
    struct node *tail; // Points to the end of the queue
};

// Function to check if the queue is empty
int isempty(struct queue *q) {
    return (q->head == NULL); // Returns 1 if the queue is empty, otherwise 0
}

// Function to insert a node to the tail of the queue (enqueue)
void enqueue(struct queue *q, int val) {
    // Create a new node
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = NULL; // The new node will be the new tail, so it points to NULL

    // If the queue is empty, set both head and tail to the new node
    if (isempty(q)) {
        q->head = new_node;
        q->tail = new_node;
    } else {
        // Attach the new node to the current tail and update the tail pointer
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

// Function to remove a node from the head of the queue (dequeue)
int dequeue(struct queue *q) {
    // Check if the queue is empty before attempting to dequeue
    if (isempty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return -1 to indicate an error (empty queue)
    }

    // Get the data from the head node
    int val = q->head->data;

    // Store the current head node temporarily
    struct node *temp = q->head;

    // Move the head pointer to the next node
    q->head = q->head->next;

    // If the head becomes NULL, the queue is now empty, so set the tail to NULL
    if (q->head == NULL) {
        q->tail = NULL;
    }

    // Free the memory of the old head node
    free(temp);

    return val; // Return the dequeued value
}

// Function to print the contents of the queue (for testing)
void print_queue(struct queue *q) {
    if (isempty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    struct node *current = q->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Initialize an empty queue
    struct queue q = {NULL, NULL};

    // Enqueue elements to the queue
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    
    // Print the queue
    printf("Queue after enqueuing 10, 20, 30:\n");
    print_queue(&q);

    // Dequeue elements from the queue
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Queue after dequeuing:\n");
    print_queue(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Queue after dequeuing:\n");
    print_queue(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Queue after dequeuing:\n");
    print_queue(&q);

    // Try dequeuing from an empty queue
    printf("Dequeued: %d\n", dequeue(&q));

    return 0;
}
