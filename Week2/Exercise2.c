// #include <stdio.h>
// #include <stdlib.h> // required for the exit() function

// #define BUFSIZE 10

// int main() {
//     FILE *fptr1 = fopen("./textfile1.txt", "r");

//     if(fptr1 == NULL){
//         fprintf(stderr, "Error opening file\n");
//         exit(1);
//     }

//     char str[BUFSIZE];
//     printf("Content of the opened file:\n");

//     while(fgets(str, BUFSIZE, fptr1) != NULL) { // read the file line by line
//         fprintf(stdout, "%s", str);             // same as doing printf("%s",str);
//     }

//     printf("\n");
//     fclose(fptr1);

//     return 0;
// }
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <fcntl.h>  // for the open() function
// #include <unistd.h> // for read(), write() and close() functions

// #define BUFSIZE 10

// int main() {
//     int fd1 = open("./textfile1.txt", O_RDONLY);  // opens the file in read only mode and returns a file descriptor for the file
//     int x;

//     if (fd1 < 0) {
//         write(2, "Error opening file\n", sizeof("Error opening file\n")); // writes the error message to stderr
//         exit(1);
//     }

//     char str[BUFSIZE];

//     printf("Content of the opened file:\n");

//     while((x = read(fd1, str, BUFSIZE-1)) > 0){ // read() reads up to BUFSIZE-1 bytes from fd1 and stores in str
//                                                 // the number of bytes actually read is returned
//             str[x] = '\0';
//             write(1, str, strlen(str));   // '1' is the file descriptor for stdout, hence this is equivalent to printf("%s", str)
//     }

//     printf("\n");
//     close(fd1);

//     return 0;

// }





#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>  // for the open() function
#include <unistd.h> // for read(), write() and close() functions

#define BUFSIZE 10

int main() {
    FILE *fptr1 = fopen("./textfile1.txt", "r");
    FILE *fptr2 = fopen("./textfile2.txt", "w");
    
    if(fptr1 == NULL || fptr2 == NULL){
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }
    char str[BUFSIZE];
    printf("Content of the opened file:\n");

    while(fgets(str, BUFSIZE, fptr1) != NULL) { // read the file line by line
        fprintf(stdout, "%s", str); 
        fprintf(fptr2, "%s",str);          // same as doing printf("%s",str);
    }



    printf("\n");
    fclose(fptr1);
    fclose(fptr2);
    return 0;

}


int mainComplete() {
    int fd1 = open("./textfile1.txt", O_RDONLY);  // opens the file in read only mode and returns a file descriptor for the file
    int fd2 = open("./textfile2.txt", O_WRONLY);
    int x;

    if (fd1 < 0) {
        write(2, "Error opening file\n", sizeof("Error opening file\n")); // writes the error message to stderr
        exit(1);
    }

    char str[BUFSIZE];

    printf("Content of the opened file:\n");

    while((x = read(fd1, str, BUFSIZE-1)) > 0){ // read() reads up to BUFSIZE-1 bytes from fd1 and stores in str
                                                // the number of bytes actually read is returned
            str[x] = '\0';
            write(fd2, str, strlen(str));
            // write(1, str, strlen(str));   // '1' is the file descriptor for stdout, hence this is equivalent to printf("%s", str)
    }

    printf("\n");
    close(fd1);
    close(fd2);

    return 0;

}


int main2() {
    int fd1 = open("./textfile1.txt", O_RDONLY);  // opens the file in read only mode and returns a file descriptor for the file
    int x;

    if (fd1 < 0) {
        write(2, "Error opening file\n", sizeof("Error opening file\n")); // writes the error message to stderr
        exit(1);
    }

    char str[BUFSIZE];

    printf("Content of the opened file:\n");

    while((x = read(fd1, str, BUFSIZE-1)) > 0){ // read() reads up to BUFSIZE-1 bytes from fd1 and stores in str
                                                // the number of bytes actually read is returned
            str[x] = '\0';
            write(1, str, strlen(str));   // '1' is the file descriptor for stdout, hence this is equivalent to printf("%s", str)
    }

    printf("\n");
    close(fd1);

    return 0;

}
