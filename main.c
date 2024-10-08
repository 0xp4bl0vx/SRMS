#include <stdio.h>
#include <stdlib.h>
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

void reallocate_memory(struct Record** records, int size) {
    struct Record* tmp = realloc(*records, size * sizeof(struct Record));
    if (tmp == NULL) {
        printf("Memory allocation error");
        free(*records);
        exit(1);
    } else {
        *records = tmp;
    }
}

void create(struct Record* records, int index) {
    --index;
    records[index].id = index + 1;
    printf("Enter student name: ");
    fgets(records[index].name, 30, stdin);
    records[index].name[strcspn(records[index].name, "\n")] = '\0';
    printf("Enter student age: ");
    scanf("%d", &records[index].age);
    fflush(stdin);
    printf("Enter student course [1, 2, 3, 4]: ");
    scanf("%d", &records[index].course);
    fflush(stdin);
    printf("Enter student class [A, B, C, D]: ");
    scanf("%c", &records[index].class);
    // Convert input from lowercase to uppercase
    if (records[index].class > 68) {
        records[index].class -= 32;
    }
    printf("Grades must be introduced as comma separated floats\n");
    printf("Following this order: Calculus, Business Management, Programming, Computers Technology, Physics\n");
    printf("Enter student grades: ");
    scanf("%f,%f,%f,%f,%f", &records[index].grades[0], &records[index].grades[1], &records[index].grades[2],
        &records[index].grades[3], &records[index].grades[4]);
    printf("New record created successfully\n");
}

void edit(struct Record* records) {
    int field = -1;
    int index;
    printf("Introduce the record ID to be modified: ");
    scanf("%d", &index);
    --index;
    while (1) {
        printf("[0] Name\n");
        printf("[1] Age\n");
        printf("[2] Course\n");
        printf("[3] Class\n");
        printf("[4] Grades\n");
        printf("[5] Exit\n");
        printf("What data field you want to modify: ");
        scanf("%d", &field);
        fflush(stdin);

        switch (field) {
            case 0:
                printf("Enter student new name: ");
                fgets(records[index].name, 30, stdin);
                records[index].name[strcspn(records[index].name, "\n")] = '\0';
                break;
            case 1:
                printf("Enter student new age: ");
                scanf("%d", &records[index].age);
                fflush(stdin);
                break;
            case 2:
                printf("Enter student new course: ");
                scanf("%d", &records[index].course);
                fflush(stdin);
                break;
            case 3:
                printf("Enter student new class: ");
                scanf("%c", &records[index].class);
                if (records[index].class > 68) {
                    records[index].class -= 32;
                }
                break;
            case 4:
                printf("Grades must be introduced as comma separated floats\n");
                printf("Following this order: Calculus, Business Management, Programming, Computers Technology, Physics\n");
                printf("Enter student new grades: ");
                scanf("%f,%f,%f,%f,%f", &records[index].grades[0], &records[index].grades[1], &records[index].grades[2],
                    &records[index].grades[3], &records[index].grades[4]);
                break;
            case 5:
                printf("Record updated successfully\n");
                return;
            default:
                printf("Wrong data field\n");
                break;
        }
    }
}

void delete(struct Record* records, int size) {
    int index;
    scanf("\n");
    printf("Enter the record ID to be deleted: ");
    scanf("%d", &index);
    fflush(stdin);
    for (int c = index - 1; c < size; c++) {
        records[c] = records[c+1];
        records[c].id -= 1;
    }
    reallocate_memory(&records, size-1);
    printf("Record deleted successfully\n");
}

void view(struct Record* records, int size) {
    for (int c = 0; c < size; c++) {
        printf("%d, %s, %d, %d, %c", records[c].id, records[c].name, records[c].age,
            records[c].course, records[c].class);
        for (int i = 0; i < 5; i++) {
            printf(", %0.2f", records[c].grades[i]);
        }
        printf("\n");
    }
}

void save(struct Record* records) {
    // Recognize where program is executing
    FILE *fptr = fopen("C:\\Users\\chess\\CLionProjects\\SRMS\\records.txt", "w");
    // Print each record into the file
    for (int i = 0; i + 1 == records[i].id; i++) {
        fprintf(fptr, "%d,%s,%d,%d,%c", records[i].id, records[i].name,
            records[i].age, records[i].course, records[i].class);
        for (int j = 0; j < 5; j++) {
            fprintf(fptr, ",%0.2f", records[i].grades[j]);
        }
        fprintf(fptr, "\n");
    }
    fclose(fptr);
}

void load(struct Record* records, int* size) {
    //Recognize where program is executing
    FILE *fptr_1 = fopen("C:\\Users\\chess\\CLionProjects\\SRMS\\records.txt", "r");
    FILE *fptr_2 = fopen("C:\\Users\\chess\\CLionProjects\\SRMS\\records.txt", "r");
    if (fptr_1 == NULL || fptr_2 == NULL) {
        printf("Error opening file\n");
        return;
    }else {
        int lines = 0;
        for (char c = getc(fptr_1); c != EOF; c = getc(fptr_1)) {
            if (c == '\n') {
                lines++;
            }
        }
        if (*size < lines) {
            reallocate_memory(&records, lines - *size);
        }
        fclose(fptr_1);
        *size = lines;
        int i = 0;
        while (fscanf(fptr_2, "%d,%[^,],%d,%d,%c,%f,%f,%f,%f,%f", &records[i].id, &records[i].name,
        &records[i].age, &records[i].course, &records[i].class, &records[i].grades[0], &records[i].grades[1],
        &records[i].grades[2], &records[i].grades[3], &records[i].grades[4]) == 10) {
            ++i;
        }
        fclose(fptr_2);
    }
}
/* Function for testing
void fill(struct Record* records) {
    records[0].id = 1;
    strcpy(records[0].name, "name surname");
    records[0].age = 20;
    records[0].course = 2;
    records[0].class = 'A';
    records[0].grades[0] = 3.4;
    records[0].grades[1] = 5.33;
    records[0].grades[2] = 7.45;
    records[0].grades[3] = 9.89;
    records[0].grades[4] = 8.8;
    records[1].id = 2;
    strcpy(records[1].name, "name1 surname1");
    records[1].age = 23;
    records[1].course = 1;
    records[1].class = 'B';
    records[0].grades[0] = 3.4;
    records[0].grades[1] = 5.33;
    records[0].grades[2] = 7.45;
    records[0].grades[3] = 9.89;
    records[0].grades[4] = 8.8;
}
*/
void banner() {
    printf("+------------------------------------+\n");
    printf("| Students Records Management System |\n");
    printf("+------------------------------------+\n\n");
}

int main() {
    int size = 1;
    struct Record* records = malloc(size * sizeof(struct Record));
    if (records == NULL) {
        printf("Memory allocation error");
        exit(1);
    } else {
        banner();
        int option = -1;
        int initial_data = 0;
        while (initial_data == 0) {
            option = -1;
            printf("[0] Create record\n");
            printf("[1] Load records\n");
            printf("[2] Exit\n");
            printf("Enter your option: ");
            scanf("%d", &option);
            fflush(stdin);
            switch (option) {
                case 0:
                    create(records, 1);
                    initial_data = 1;
                    break;
                case 1:
                    load(records, &size);
                    initial_data = 1;
                    break;
                case 2:
                    free(records);
                    exit(0);
                default:
                    printf("Wrong option");
                    break;
            }
        }
        while (1) {
            option = -1;
            scanf("\n");
            printf("[0] Create record\n");
            printf("[1] Edit record\n");
            printf("[2] View record\n");
            printf("[3] Delete record\n");
            printf("[4] Save\n");
            printf("[5] Load\n");
            printf("[6] Exit\n");
            printf("Enter your option: ");
            scanf("%d", &option);
            fflush(stdin);

            switch (option) {
                case 0:
                    size++;
                    reallocate_memory(&records, size);
                    create(records, size);
                    break;
                case 1:
                    edit(records);
                    break;
                case 2:
                    view(records, size);
                    break;
                case 3:
                    delete(records, size);
                    size--;
                    break;
                case 4:
                    save(records);
                    break;
                case 5:
                    load(records, &size);
                    break;
                case 6:
                    free(records);
                    exit(0);
                default:
                    printf("Wrong option");
                    break;
            }
        }
    }
}