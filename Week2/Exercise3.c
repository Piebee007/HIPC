#include <stdio.h>
#include <stdlib.h>

struct element {
  struct element *next;
  int data;
};

struct linked_list {
  struct element *head;
};

// Function to append an element to the end of the list
void append_int(struct linked_list *list, int val) {
  struct element *elem = malloc(sizeof(struct element));

  elem->data = val;
  elem->next = NULL; // Important to explicitly set this to null

  if (list->head == NULL) {
    // Empty list, append to head
    list->head = elem;
  } else {
    // List has elements, find the end and append
    struct element *tail = list->head;
    while (tail->next != NULL) {
      tail = tail->next;
    }
    tail->next = elem;
  }
}

// Function to insert an element at the head of the list
void insert_at_head(struct linked_list *list, int val) {
  struct element *elem = malloc(sizeof(struct element));

  elem->data = val;
  elem->next = list->head; // New element points to current head
  list->head = elem; // Head points to new element
}

// Function to remove an element from the head of the list
void remove_from_head(struct linked_list *list) {
  if (list->head == NULL) {
    printf("List is already empty.\n");
    return;
  }

  struct element *temp = list->head;
  list->head = list->head->next; // Move head to next element
  free(temp); // Free the memory of the removed element
}

// Function to print the list contents
void print_list(struct linked_list *list) {
  struct element *current = list->head;
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

int main() {
  struct linked_list my_list = {NULL};

  append_int(&my_list, 10);
  append_int(&my_list, 20);
  append_int(&my_list, 30);

  printf("List after appending elements:\n");
  print_list(&my_list);

  insert_at_head(&my_list, 5);
  printf("\nList after inserting 5 at head:\n");
  print_list(&my_list);

  remove_from_head(&my_list);
  printf("\nList after removing element from head:\n");
  print_list(&my_list);

  return 0;
}
