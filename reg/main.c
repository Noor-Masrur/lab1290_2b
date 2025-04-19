
// main.c
#include <stdio.h>
#include "crud.h"


int main() {
    int choice, id;
    Record record;
    do {
        printf("\n1. Create Record\n2. Read Records\n3. Update Record\n4. Delete Record\n5. Exit\nChoose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter ID, Name, Age: ");
                scanf("%d %49s %d", &record.id, record.name, &record.age);
                createRecord(record);
                break;
            case 2:
                readRecords();
                break;
            case 3:
                printf("Enter ID to update: ");
                scanf("%d", &id);
                printf("Enter new Name and Age: ");
                scanf("%49s %d", record.name, &record.age);
                record.id = id;
                updateRecord(id, record);
                break;
            case 4:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteRecord(id);
                break;
        }
    } while (choice != 5);
    return 0;
}
