#include <stdio.h>
#include <string.h>

// Custom data type for student records
struct Record {
    int id;
    char name[30];
    short int age;
    short int course;
    char class;
    float grades[5];
};

void create(struct Record* records, int index) {
    --index;
    records[index].id = index + 1;
    printf("\nEnter student name: ");
    fgets(records[index].name, 30, stdin);
    records[index].name[strcspn(records[index].name, "\n")] = '\0';
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
    char field;
    int index;
    printf("\nIntroduce the record ID to be modified: ");
    scanf("%d", &index);
    --index;
    while (1) {
        printf("\nWhat data field you want to modify: ");
        fflush(stdin);
        scanf("%c", &field);
        fflush(stdin);

        switch (field) {
            case 'n':
                printf("\nEnter student new name: ");
                fgets(records[index].name, 30, stdin);
                records[index].name[strspn(records[index].name, "\n")] = '\0';
                break;
            case 'a':
                printf("\nEnter student new age: ");
                scanf("%d", &records[index-1].age);
                break;
            case 'c':
                printf("\nEnter student new course: ");
                scanf("%d", &records[index-1].course);
                break;
            case 'x':
                printf("\nEnter student new class: ");
                scanf("%c", &records[index-1].class);
                if (records[index].class > 68) {
                    records[index].class -= 32;
                }
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

void delete(struct Record* records, int size) {
    int index;
    fflush(stdin);
    fflush(stdout);
    printf("Enter the record ID to be deleted: ");
    scanf("%d", &index);
    for (int c = index - 1; c < size; c++) {
        records[c] = records[c+1];
        records[c].id -= 1;
    }
    printf("Record deleted successfully");
}

void view(struct Record* records, int size) {
    printf("\n");
    for (int c = 0; c < size; c++) {
        // Add grades print
        printf("%d, %s, %d, %d, %c\n", records[c].id, records[c].name, records[c].age,
            records[c].course, records[c].class);
    }
}

void save(struct Record* records) {
    // Recognize where program is executing
    FILE *fptr = fopen("C:\\Users\\chess\\CLionProjects\\SRMS\\records.txt", "w");
    // Print each record into the file
    for (int i = 0; i + 1 == records[i].id; i++) {
        fprintf(fptr, "%d,%s,%d,%d,%c\n", records[i].id, records[i].name,
            records[i].age, records[i].course, records[i].class);
    }
    fclose(fptr);
}

void load(struct Record* records) {
    //Recognize where program is executing
    FILE *fptr = fopen("C:\\Users\\chess\\CLionProjects\\SRMS\\records.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file");
    }else {
        int i = 0;
        while (fscanf(fptr, "%d,%[^,],%d,%d,%c", &records[i].id, &records[i].name,
            &records[i].age, &records[i].course, &records[i].class) == 5) {
            ++i;
        }
    }
}

void fill(struct Record* records) {
    records[0].id = 1;
    strcpy(records[0].name, "Pablo Moya");
    records[0].age = 20;
    records[0].course = 2;
    records[0].class = 'A';
    records[1].id = 2;
    strcpy(records[1].name, "Ignacio Gomez");
    records[1].age = 23;
    records[1].course = 1;
    records[1].class = 'B';
}

int main() {
    struct Record records[30];
    // Size for dynamic memory allocation
    int size = sizeof(records) / sizeof(records[0]);
    //fill(records);
    //save(records);
    load(records);
    view(records, 2);
    return 0;
}