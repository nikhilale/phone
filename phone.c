#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20
#define PHONEBOOK_FILENAME "phonebook.txt"

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

void add_contact();
void list_contacts();
void search_contact();

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

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                list_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
void add_contact() {
    Contact contact;
    FILE *file;

    printf("Enter name: ");
    scanf("%s", contact.name);

    printf("Enter phone number: ");
    scanf("%s", contact.phone);

    file = fopen(PHONEBOOK_FILENAME, "a");

    if (file == NULL) {
        printf("Error opening file. Please try again.\n");
        return;
    }

    fprintf(file, "%s %s\n", contact.name, contact.phone);
    fclose(file);

    printf("Contact added successfully.\n");
}
void list_contacts() {
    char name[MAX_NAME_LENGTH], phone[MAX_PHONE_LENGTH];
    FILE *file;

    file = fopen(PHONEBOOK_FILENAME, "r");

    if (file == NULL) {
        printf("Error opening file. Please try again.\n");
        return;
    }

    printf("Name\tPhone\n");
    printf("=====================\n");

    while (fscanf(file, "%s %s", name, phone) != EOF) {
        printf("%s\t%s\n", name, phone);
    }

    fclose(file);
}
void search_contact() {
    char name[MAX_NAME_LENGTH], phone[MAX_PHONE_LENGTH], search_name[MAX_NAME_LENGTH];
    int found = 0;
    FILE *file;

    printf("Enter name to search: ");
    scanf("%s", search_name);

    file = fopen(PHONEBOOK_FILENAME, "r");

    if (file == NULL) {
        printf("Error opening file. Please try again.\n");
        return;
    }
     while (fscanf(file, "%s %s", name, phone) != EOF) {
        if (strcmp(name, search_name) == 0) {
            printf("Name: %s\nPhone: %s\n", name, phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }

    fclose(file);
}