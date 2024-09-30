#include <stdio.h>
#include <stdlib.h>

struct element {
  struct element * next;
  int data;
};

struct linked_list {
  struct element * head;
};

void append_int(struct linked_list * list, int val) {
  struct element * elem = malloc(sizeof(struct element));

  elem->data = val;
  elem->next = NULL; // Really important to explicitly set this to null. Malloc does not zero memory

  if (list->head == NULL) {
    // Empty list, we need to append to head
    list->head = elem;
  } else {
    // List has some elements, find the end and append to that
    struct element * tail = list->head;
    while (tail->next != NULL) {
      tail = tail->next;
    }
    tail->next = elem;
  }
}

void insert_at_head(struct linked_list * list, int val){
    struct element * elem = malloc(sizeof(struct element));

}

void remove_head(){
    
}

int main() {
  // Initialize an empty linked list
  struct linked_list my_list;
  my_list.head = NULL;

  // Append some integers
  append_int(&my_list, 10);
  append_int(&my_list, 20);
  append_int(&my_list, 30);

  // Traverse and print the list
  struct element *current = my_list.head;
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");

  // Free allocated memory (not shown here)
  return 0;
}
