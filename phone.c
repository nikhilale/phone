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

int main() {
    phone_record records[MAX_RECORDS];
    int count = 0;
    
    int choice;
    
    while (1) {
        printf("\nPhone Management System\n");
        printf("1. Add Record\n");
        printf("2. List Records\n");
        switch (choice) {
            case 1:
                add_record(records, &count);
                break;
            case 2:
                list_records(records, count);
                break;
            default:
                printf("Invalid choice\n");    }
}

return 0;
}
