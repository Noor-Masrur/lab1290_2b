
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crud.h"


void createRecord(Record record) {
    FILE *file = fopen(FILE_NAME, "a");  //file mode read, write, append
    if (!file) {
        perror("Error opening file");
        return;
    }
    fprintf(file, "%d,%s,%d\n", record.id, record.name, record.age);
    fclose(file);
}

void readRecords() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }
    char line[MAX_LINE];
    printf("ID, Name, Age\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

void updateRecord(int id, Record updatedRecord) {
    FILE *file = fopen(FILE_NAME, "r");
    FILE *tempFile = fopen("temp.csv", "w");
    if (!file || !tempFile) {
        perror("Error opening file");
        return;
    }
    char line[MAX_LINE];
    while (fgets(line, sizeof(line), file)) {
        Record record;
        sscanf(line, "%d,%49[^,],%d", &record.id, record.name, &record.age);
        if (record.id == id) {
            fprintf(tempFile, "%d,%s,%d\n", updatedRecord.id, updatedRecord.name, updatedRecord.age);
        } else {
            fprintf(tempFile, "%s", line);
        }
    }
    fclose(file);
    fclose(tempFile);
    remove(FILE_NAME);
    rename("temp.csv", FILE_NAME);
}

void deleteRecord(int id) {
    FILE *file = fopen(FILE_NAME, "r");
    FILE *tempFile = fopen("temp.csv", "w");
    if (!file || !tempFile) {
        perror("Error opening file");
        return;
    }
    char line[MAX_LINE];
    while (fgets(line, sizeof(line), file)) {
        Record record;
        sscanf(line, "%d,%49[^,],%d", &record.id, record.name, &record.age);
        if (record.id != id) {
            fprintf(tempFile, "%s", line);
        }
    }
    fclose(file);
    fclose(tempFile);
    remove(FILE_NAME);
    rename("temp.csv", FILE_NAME);
}
