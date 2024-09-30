

#include <stdio.h>
#include <string.h>

int count_words(char *str) {
    // this function should return the number of words in str
    int i;
    int words = 0;
    
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == ' '){
            words++;
        }
    }
    if (strlen(str) > 0 && words == 0){
        words ++;
    }
    printf("thigny %d",str[strlen(str)-5]);
    if (str[strlen(str)-2] == ' '){
        words --;
    }
    return words;
}

int main() {
    char str[100];

    printf("Enter a string:");
    fgets(str, 100, stdin);    // this function reads a line or at most 99 bytes from stdin file stream that represents the keyboard

    printf("Number of words in the entered string is %d\n", count_words(str));

    return 0;

}

