

#include <stdio.h>


// Function to swap the values of two integers using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// write the code for the sort() function that sorts an integer array in ascending order
void sort(int arr[], int length){

}
// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
          
            // Swap if the element found is greater than the
            // next element
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main() {
   int x[]= { 4, 1, 4, 3, 10, 5 };
   int i;

   bubbleSort(x, 6); // sort() function sorts the array x in ascending order

   printf("The sorted array is as follows:\n");

   for (i=0; i < 6; i++){
      printf("%d ", x[i]);
   }

   printf("\n");
   return 0;
}

