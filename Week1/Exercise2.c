

#include <stdio.h>

// Function to swap the values of two integers using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}



int main(int argc, char *argv[]) {
   int val_a = 50;
   int val_b = 20;

   // call the swap() function correctly, swap() should swap the values stored in val_a and val_b so
   // that the swapped values of val_a and val_b are printed in the next two lines

    swap(&val_a, &val_b);

   printf("val_a is %d (should be 20)\n", val_a);
   printf("val_b is %d (should be 50)\n", val_b);

  return 0;
}

