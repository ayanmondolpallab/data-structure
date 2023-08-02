#include <stdio.h>
#include <stdlib.h>

struct Date {
    int day;
    int month;
    int year;
    struct Date* next;
};

struct Date* createDate() {
    struct Date* newDate = (struct Date*)malloc(sizeof(struct Date));
    if (newDate == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newDate->next = NULL;
    return newDate;
}

void getDateDetails(struct Date* date) {
    printf("Enter day: ");
    scanf("%d", &date->day);

    printf("Enter month: ");
    scanf("%d", &date->month);

    printf("Enter year: ");
    scanf("%d", &date->year);
}

int compareDates(struct Date* date1, struct Date* date2) {
    if (date1->year < date2->year)
        return -1;
    else if (date1->year > date2->year)
        return 1;
    else {
        if (date1->month < date2->month)
            return -1;
        else if (date1->month > date2->month)
            return 1;
        else {
            if (date1->day < date2->day)
                return -1;
            else if (date1->day > date2->day)
                return 1;
            else
                return 0; // Both dates are equal
        }
    }
}

void displayDate(struct Date* date) {
    printf("%02d/%02d/%04d", date->month, date->day, date->year);
}

void freeLinkedList(struct Date* head) {
    struct Date* current = head;
    while (current != NULL) {
        struct Date* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Date* date1 = createDate();
    struct Date* date2 = createDate();

    printf("Enter details for Date 1:\n");
    getDateDetails(date1);

    printf("\nEnter details for Date 2:\n");
    getDateDetails(date2);

    int comparison = compareDates(date1, date2);
    if (comparison == -1)
        printf("\nDate 1 ");
    else if (comparison == 1)
        printf("\nDate 2 ");
    else
        printf("\nBoth dates ");

    printf("is %s than the other.\n", (comparison < 0) ? "earlier" : ((comparison > 0) ? "later" : "equal"));

    // Free allocated memory for the linked list
    free(date1);
    free(date2);

    return 0;
}











