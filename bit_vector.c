#include <stdio.h>

int main() {
    int i;
    char universal[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char set1[26];
    int size1;
    char set2[26];
    int size2;

  
    printf("Enter the size of set 1: ");
    scanf("%d", &size1);
    //getchar(); // To consume the newline character after entering the size

    printf("Enter the elements of set 1:\n");
    for (i = 0; i < size1; i++) {
        scanf("%c", &set1[i]);
    }

  
    printf("Elements of set 1: ");
    for (i = 0; i < size1; i++) {
        printf("%c ", set1[i]);
    }
    printf("\n");

    printf("Enter the size of set 2: ");
    scanf("%d", &size2);
    //getchar(); // To consume the newline character after entering the size

    printf("Enter the elements of set 2:\n");
    for (i = 0; i < size2; i++) {
        scanf("%c", &set2[i]);
    }

    // Output the elements of set 2
    printf("Elements of set 2: ");
    for (i = 0; i < size2; i++) {
        printf("%c ", set2[i]);
    }
    printf("\n");

    return 0;
}

