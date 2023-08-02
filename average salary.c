#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char name[100];
    char designation[100];
    float salary;
    struct Employee* next;
};

struct Employee* createEmployee() {
    struct Employee* newEmployee = (struct Employee*)malloc(sizeof(struct Employee));
    if (newEmployee == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newEmployee->next = NULL;
    return newEmployee;
}

void getEmployeeDetails(struct Employee* employee) {
    printf("Enter employee name: ");
    getchar(); // Consume the newline character left by previous scanf
    fgets(employee->name, sizeof(employee->name), stdin);
    employee->name[strcspn(employee->name, "\n")] = '\0'; // Remove the trailing newline

    printf("Enter employee designation: ");
    fgets(employee->designation, sizeof(employee->designation), stdin);
    employee->designation[strcspn(employee->designation, "\n")] = '\0'; // Remove the trailing newline

    printf("Enter employee salary: ");
    scanf("%f", &employee->salary);
}

float calculateAverageSalary(struct Employee* head) {
    float total_salary = 0.0;
    int num_employees = 0;
    struct Employee* current = head;

    while (current != NULL) {
        total_salary += current->salary;
        num_employees++;
        current = current->next;
    }

    return (num_employees > 0) ? (total_salary / num_employees) : 0.0;
}

void freeLinkedList(struct Employee* head) {
    struct Employee* current = head;
    while (current != NULL) {
        struct Employee* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int num_employees;
    struct Employee* head = NULL;
    struct Employee* tail = NULL;

    printf("Enter the number of employees: ");
    scanf("%d", &num_employees);

    for (int i = 0; i < num_employees; i++) {
        struct Employee* newEmployee = createEmployee();
        printf("\nEnter details for Employee %d:\n", i + 1);
        getEmployeeDetails(newEmployee);

        if (head == NULL) {
            head = newEmployee;
            tail = newEmployee;
        } else {
            tail->next = newEmployee;
            tail = newEmployee;
        }
    }

    // Calculate average salary of all employees
    float average_salary = calculateAverageSalary(head);
    printf("\nAverage Salary of all employees: $%.2f\n", average_salary);

    // Free allocated memory for the linked list
    freeLinkedList(head);

    return 0;
}
