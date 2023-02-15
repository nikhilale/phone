#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    int choice;

    while (1) {
        printf("Phonebook Management System\n");
        printf("===========================\n");
        printf("1. Add contact\n");
        printf("2. List contacts\n");
        printf("3. Search contact\n");
        printf("4. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
    }

    return 0;
}
