#include <stdio.h>
#include <stdlib.h>

struct Rectangle {
    float length;
    float width;
    struct Rectangle* next;
};

struct Rectangle* createRectangle() {
    struct Rectangle* newRectangle = (struct Rectangle*)malloc(sizeof(struct Rectangle));
    if (newRectangle == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newRectangle->next = NULL;
    return newRectangle;
}

void getRectangleDetails(struct Rectangle* rectangle) {
    printf("Enter length of the rectangle: ");
    scanf("%f", &rectangle->length);

    printf("Enter width of the rectangle: ");
    scanf("%f", &rectangle->width);
}

float calculateArea(struct Rectangle* rectangle) {
    return rectangle->length * rectangle->width;
}

float calculatePerimeter(struct Rectangle* rectangle) {
    return 2 * (rectangle->length + rectangle->width);
}

void displayRectangleDetails(struct Rectangle* rectangle) {
    printf("\nRectangle Details:\n");
    printf("Length: %.2f\n", rectangle->length);
    printf("Width: %.2f\n", rectangle->width);
    printf("Area: %.2f\n", calculateArea(rectangle));
    printf("Perimeter: %.2f\n", calculatePerimeter(rectangle));
}

void freeLinkedList(struct Rectangle* head) {
    struct Rectangle* current = head;
    while (current != NULL) {
        struct Rectangle* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int num_rectangles;
    struct Rectangle* head = NULL;
    struct Rectangle* tail = NULL;

    printf("Enter the number of rectangles: ");
    scanf("%d", &num_rectangles);

    for (int i = 0; i < num_rectangles; i++) {
        struct Rectangle* newRectangle = createRectangle();
        printf("\nEnter details for Rectangle %d:\n", i + 1);
        getRectangleDetails(newRectangle);

        if (head == NULL) {
            head = newRectangle;
            tail = newRectangle;
        } else {
            tail->next = newRectangle;
            tail = newRectangle;
        }
    }

    // Display details of all rectangles
    printf("\n--- Details of All Rectangles ---\n");
    struct Rectangle* current = head;
    while (current != NULL) {
        displayRectangleDetails(current);
        current = current->next;
    }

    // Free allocated memory for the linked list
    freeLinkedList(head);

    return 0;
}

