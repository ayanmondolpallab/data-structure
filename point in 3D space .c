#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
    float x;
    float y;
    float z;
    struct Point* next;
};

struct Point* createPoint() {
    struct Point* newPoint = (struct Point*)malloc(sizeof(struct Point));
    if (newPoint == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newPoint->next = NULL;
    return newPoint;
}

void getPointDetails(struct Point* point) {
    printf("Enter x-coordinate: ");
    scanf("%f", &point->x);

    printf("Enter y-coordinate: ");
    scanf("%f", &point->y);

    printf("Enter z-coordinate: ");
    scanf("%f", &point->z);
}

float calculateDistance(struct Point* point1, struct Point* point2) {
    float distance;
    float x_diff = point1->x - point2->x;
    float y_diff = point1->y - point2->y;
    float z_diff = point1->z - point2->z;

    distance = sqrt(x_diff * x_diff + y_diff * y_diff + z_diff * z_diff);

    return distance;
}

void freeLinkedList(struct Point* head) {
    struct Point* current = head;
    while (current != NULL) {
        struct Point* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Point* point1 = createPoint();
    struct Point* point2 = createPoint();

    printf("Enter details for Point 1:\n");
    getPointDetails(point1);

    printf("\nEnter details for Point 2:\n");
    getPointDetails(point2);

    float distance = calculateDistance(point1, point2);
    printf("\nDistance between Point 1 and Point 2: %.2f\n", distance);

    // Free allocated memory for the linked list
    free(point1);
    free(point2);

    return 0;
}

