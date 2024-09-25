#include <stdio.h>

// Custom data type for student records
struct Record {
    int id;
    char name[30];
    int age;
    int course;
    char class;
    float grades[5];
};

void create(struct Record* records, int index) {
    records[index].id = index + 1;
    fflush(stdin);
    printf("\nEnter student name: ");
    fflush(stdout);
    fgets(records[index].name, 30, stdin);
    printf("\nEnter student age: ");
    fflush(stdout);
    scanf("%d", &records[index].age);
    printf("\nEnter student course [1, 2, 3, 4]: ");
    fflush(stdout);
    scanf("%d", &records[index].course);
    printf("\nEnter student class [A, B, C, D]: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%c", &records[index].class);
    // Convert input from lowercase to uppercase
    if (records[index].class > 68) {
        records[index].class -= 32;
    }
    printf("%c", records[index].class);
    printf("\nEnter student grades: ");
    fflush(stdout);
    // Grades read and write must be reworked, a function might be useful for reading and writing the input
    //scanf("%f", &records[index].grades);
    printf("\nNew record created successfully");
    fflush(stdout);
}

void edit(struct Record* records) {
    short int record_ID;
    char field;
    printf("\nIntroduce the record ID to be modified: ");
    scanf("%d", &record_ID);
    records[record_ID].id -= 1;
    while (1) {
        printf("\nWhat data field you want to modify: ");
        fflush(stdin);
        scanf("%c", &field);

        switch (field) {
            case 'n':
                printf("\nEnter student new name: ");
                fgets(records[record_ID].name, 30, stdin);
                break;
            case 'a':
                printf("\nEnter student new age: ");
                scanf("%d", &records[record_ID-1].age);
                break;
            case 'c':
                printf("\nEnter student new course: ");
                scanf("%d", &records[record_ID-1].course);
                break;
            case 'x':
                printf("\nEnter student new class: ");
                scanf("%c", &records[record_ID-1].class);
                break;
            case 'g':
                printf("\nEnter student new grades: ");
                // Read and Write grades function
                break;
            case 'e':
                printf("\nRecord updated successfully");
                return;
            default:
                printf("\nWrong data field");
                break;
        }
    }
}

void delete(struct Record* records) {
    int record_ID;
    fflush(stdin);
    fflush(stdout);
    printf("Enter the record ID to be deleted: ");
    scanf("%d", &record_ID);
    for (int c = record_ID - 1; c < 30-1; c++) {
        records[c] = records[c+1];
    }
    printf("Record deleted successfully");
}

void view(struct Record* records) {
    while (1) {
        int index = 0;
        if (records[index].id > 0) {
            // Add grades to the output
            printf("%d, %s, %d, %d, %c\n", records[index].id, records[index].name, records[index].age,
                records[index].course, records[index].class);
        } else {
            return;
        }
        index++;
    }
}

void save() {

}

void load() {

}

void fill(struct Record* records) {
    records[0].id = 1;
    *records[0].name = "Pablo Moya";
    records[0].age = 20;
    records[0].class = 2;
    records[0].course = "A";
    records[1].id = 2;
    *records[1].name = "Ignacio Gomez";
    records[1].age = 23;
    records[1].class = 1;
    records[1].course = "B";
}

int main() {
    struct Record records[30];
    int index = 0;
    fill(records);
    view(records);
    return 0;
}