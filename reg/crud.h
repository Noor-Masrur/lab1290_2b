
// crud.h
#ifndef CRUD_H
#define CRUD_H

#define FILE_NAME "data.csv"
#define MAX_LINE 1024

typedef struct {
    int id;
    char name[50];
    int age;
} Record;

void createRecord(Record record);
void readRecords();
void updateRecord(int id, Record updatedRecord);
void deleteRecord(int id);

#endif // CRUD_H
