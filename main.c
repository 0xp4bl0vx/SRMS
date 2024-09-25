#include <stdio.h>

// Custom data type for student records
struct Record {
    int id;
    char name[30];
    short int age;
    short int course;
    char class;
    float grades[5];
};

void create(struct Record records) {
    short int last_index = sizeof(records)/sizeof(struct Record)-1;
    records[last_index-1].id = last_index;
    printf("Enter student name: ");
    scanf("%[^\n]%*c", &records[last_index].name);
    printf("Enter student age: ");
    scanf("%d", &records[last_index].age);
    printf("Enter student course [1, 2, 3, 4]: ");
    scanf("%d", &records[last_index].course);
    printf("Enter student class [A, B, C, D]: ");
    scanf("%c", &records[last_index].class);
    printf("Enter student grades: ");
    // Grades read and write must be reworked, a function might be useful for reading and writing the input
    scanf("%f", &records[last_index].grades);
    printf("New record created successfully");
}

void edit(struct Record records) {
    short int record_ID;
    char field;
    printf("Introduce the record ID to be modified: ");
    scanf("%d", &record_ID);
    while (field != 'e') {
        printf("What data field you want to modify: ");
        scanf("%c", &field);
        if (field == 'n') {
            printf("Enter student new name: ");
            scanf("%s", &records[record_ID-1].name);
        } else if (field == 'n') {
            printf("Enter student new age: ");
            scanf("%d", &records[record_ID-1].age);
        } else if (field == 'c') {
            printf("Enter student new course: ");
            scanf("%d", &records[record_ID-1].course);
        } else if (field == 'x') {
            printf("Enter student new class: ");
            scanf("%c", &records[record_ID-1].class);
        } else if (field == 'g') {
            printf("Enter student new grades: ");
            // Read and Write grades function
        }
    }
    printf("Record updated successfully");
}

void delete(struct Record records) {
    short int record_ID;
    short int last_index = sizeof(records)/sizeof(struct Record)-1;
    printf("Enter the record ID to be deleted: ");
    scanf("%d", &record_ID);
    for (short int c = record_ID; c < last_index-1; c++) {
        records[c] = records[c+1];
    }
    printf("Record deleted successfully");
}

void view() {

}

void save() {

}

void load() {

}

int main() {
    return 0;
}