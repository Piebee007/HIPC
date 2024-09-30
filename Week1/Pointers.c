#include <stdio.h>

int main(int argc, char *argv[]) {
   int *a_pointer;
   int a_value = 5;
   int x[] = { 10, 1, 2, 5, -3 };

   a_pointer = &a_value;

   printf("The value of a_value is %d\n", a_value); // print the value of the variable a_value
   printf("The value of the pointer is %p,\n", a_pointer); // prints the address of the variable a_value
   printf("The value pointed to by the pointer is %d,\n", *a_pointer); // prints the value of the variable a_value

   *a_pointer = 10;

   printf("The value of a_value is now %d\n", a_value); // the value of a_value will be changed
   printf("The start address of the array x is %p\n", &x); // prints the base address of the array x
   printf("The address of the first element is %p\n", &x[0]); // also prints the same

   int i;
   for (i = 0; i < 5; i++) {
      printf("Value stored in address %p is %d\n", (x+i), x[i]);  // shows that array elements are stored in contiguous locations
   }

   printf("Size of each integer is %lu bytes\n", sizeof(int));  // the address of each location in array x differs by this amount from its previous location
   return 0;
}
