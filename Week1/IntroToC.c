// #include <stdio.h> // Includes the stdio.h library 

// int main(int argc, char *argv[]) { // main method is called when program is run    
//    printf("Hello, world!\n");      // Use the printf function from stdio.h to print a string to the terminal    
//    return 0;                       // return code zero means no problems occurred 
// }


// #include <stdio.h>

// int main(int argc, char *argv[]) {    
//     int sum = 0;
//     int i;
//     for (i = 0; i < 10; i++) {
//         sum = sum + i;    
//     }
//     printf("The sum is: %d\n", sum);   
//     return 0; 
// }


#include <stdio.h>


int factorial(int m) {  // computes the factorial of a positive integer m
    int i, prod = 1;

    for (i = 2; i <= m; i++) {
        prod = prod * i;
    }
    return prod;
}

// int main() {
//     int n;

//     printf("Enter a positive integer:");
//     scanf("%d", &n); // scanf() scans the integer entered by the user

//     printf("The factoral of %d is %d\n", n, factorial(n));
//     return 0;
// }


int isPrime(int number){

    if (number <= 1) return 0; // zero and one are not prime
    unsigned int i;
    for (i=2; i*i<=number; i++) {
        if (number % i == 0) return 0;
    }
    return 1;
}


int main(){
    int n;
    printf("Enter a positive integer:");
    scanf("%d", &n);

    int output = isPrime(n);
    if (output == 1){
        printf ("%d is a Prime number",n);
    }else{
        printf ("%d is not a Prime number",n);
    }
}