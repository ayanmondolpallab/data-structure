
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[100];
    char author[100];
    float price;
    struct Book* next;
};

struct Book* createBook() {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    if (newBook == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newBook->next = NULL;
    return newBook;
}

void getBookDetails(struct Book* book) {
    printf("Enter book title: ");
    getchar();
    fgets(book->title, sizeof(book->title), stdin);
    book->title[strcspn(book->title, "\n")] = '\0';

    printf("Enter book author: ");
    fgets(book->author, sizeof(book->author), stdin);
    book->author[strcspn(book->author, "\n")] = '\0';

    printf("Enter book price: ");
    scanf("%f", &book->price);
}

void displayBookDetails(struct Book* book) {
    printf("\nBook Details:\n");
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Price: $%.2f\n", book->price);
}

void freeLinkedList(struct Book* head) {
    struct Book* current = head;
    while (current != NULL) {
        struct Book* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int num_books;
    struct Book* head = NULL;
    struct Book* tail = NULL;

    printf("Enter the number of books: ");
    scanf("%d", &num_books);

    for (int i = 0; i < num_books; i++) {
        struct Book* newBook = createBook();
        printf("\nEnter details for Book %d:\n", i + 1);
        getBookDetails(newBook);

        if (head == NULL) {
            head = newBook;
            tail = newBook;
        } else {
            tail->next = newBook;
            tail = newBook;
        }
    }

    printf("\n--- Details of All Books ---\n");
    struct Book* current = head;
    while (current != NULL) {
        displayBookDetails(current);
        current = current->next;
    }


    float total_price = 0.0;
    current = head;
    while (current != NULL) {
        total_price += current->price;
        current = current->next;
    }
    printf("\nTotal Price of All Books: $%.2f\n", total_price);


    freeLinkedList(head);

    return 0;
}
