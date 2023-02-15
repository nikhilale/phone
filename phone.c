#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    char name[50];
    char number[20];
} phone_record;

void add_record(phone_record records[], int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Error: maximum number of records reached\n");
        return;
    }
    
    printf("Enter name: ");
    scanf("%s", records[*count].name);
    
    printf("Enter phone number: ");
    scanf("%s", records[*count].number);
    
    (*count)++;
}
void list_records(phone_record records[], int count) {
    if (count == 0) {
        printf("No records found\n");
        return;
    }
    
    printf("Name\tPhone Number\n");
    printf("------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\n", records[i].name, records[i].number);
    }
}
void edit_record(phone_record records[], int count) {
    if (count == 0) {
        printf("No records found\n");
        return;
    }
    
    char name[50];
    printf("Enter name of record to edit: ");
    scanf("%s", name);
    
    int found = 0;
    
    for (int i = 0; i < count; i++) {
        if (strcmp(name, records[i].name) == 0) {
            found = 1;
            printf("Enter new phone number: ");
            scanf("%s", records[i].number);
            printf("Record updated\n");
            break;
        }
    }
    
    if (!found) {
        printf("Record not found\n");
    }
}
void delete_record(phone_record records[], int *count) {
    if (*count == 0) {
        printf("No records found\n");
        return;
    }
    
    char name[50];
    printf("Enter name of record to delete: ");
    scanf("%s", name);
    
    int found = 0;
    
    for (int i = 0; i < *count; i++) {
        if (strcmp(name, records[i].name) == 0) {
            found = 1;
            (*count)--;
            for (int j = i; j < *count; j++) {
                records[j] = records[j+1];
            }
            printf("Record deleted\n");
            break;
        }
    }
    
    if (!found) {
        printf("Record not found\n");
    }
}


int main() {
    phone_record records[MAX_RECORDS];
    int count = 0;
    
    int choice;
    
    while (1) {
        printf("\nPhone Management System\n");
        printf("1. Add Record\n");
        printf("2. List Records\n");
        printf("3. Edit Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_record(records, &count);
                break;
            case 2:
                list_records(records, count);
                break;
            case 3:
                edit_record(records, count);
                break;
                case 4:
                delete_record(records, &count);
                break;
            case 5:
                printf("Goodbye\n");
                exit(0);
            default:
                printf("Invalid choice\n");    }
}

return 0;
}
