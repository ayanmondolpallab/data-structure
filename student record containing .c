
#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int roll_number;
    float physics_marks;
    float chemistry_marks;
    float math_marks;
    float total_marks;
    struct Student* next;
};

struct Student* createStudent() {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newStudent->next = NULL;
    return newStudent;
}

void getStudentDetails(struct Student* student) {
    printf("Enter student's name: ");
    scanf("%s", student->name);

    printf("Enter student's roll number: ");
    scanf("%d", &student->roll_number);

    printf("Enter marks for Physics: ");
    scanf("%f", &student->physics_marks);

    printf("Enter marks for Chemistry: ");
    scanf("%f", &student->chemistry_marks);

    printf("Enter marks for Mathematics: ");
    scanf("%f", &student->math_marks);

    student->total_marks = student->physics_marks + student->chemistry_marks + student->math_marks;
}

void displayStudentDetails(struct Student* student) {
    printf("\nStudent Details:\n");
    printf("Name: %s\n", student->name);
    printf("Roll Number: %d\n", student->roll_number);
    printf("Physics Marks: %.2f\n", student->physics_marks);
    printf("Chemistry Marks: %.2f\n", student->chemistry_marks);
    printf("Mathematics Marks: %.2f\n", student->math_marks);
    printf("Total Marks: %.2f\n", student->total_marks);
}

void freeLinkedList(struct Student* head) {
    struct Student* current = head;
    while (current != NULL) {
        struct Student* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int num_students;
    struct Student* head = NULL;
    struct Student* tail = NULL;

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    for (int i = 0; i < num_students; i++) {
        struct Student* newStudent = createStudent();
        printf("\nEnter details for Student %d:\n", i + 1);
        getStudentDetails(newStudent);

        if (head == NULL) {
            head = newStudent;
            tail = newStudent;
        } else {
            tail->next = newStudent;
            tail = newStudent;
        }
    }

    struct Student* highest_scoring_student = head;
    struct Student* current = head->next;
    while (current != NULL) {
        if (current->total_marks > highest_scoring_student->total_marks) {
            highest_scoring_student = current;
        }
        current = current->next;
    }

    printf("\n--- Student with the Highest Total Marks ---\n");
    displayStudentDetails(highest_scoring_student);

    freeLinkedList(head);

    return 0;
}


