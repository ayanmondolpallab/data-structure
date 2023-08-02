#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BankAccount {
    int account_number;
    char account_holder_name[100];
    float balance;
    struct BankAccount* next;
};

struct BankAccount* createBankAccount() {
    struct BankAccount* newAccount = (struct BankAccount*)malloc(sizeof(struct BankAccount));
    if (newAccount == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newAccount->next = NULL;
    return newAccount;
}

void getAccountDetails(struct BankAccount* account) {
    printf("Enter account number: ");
    scanf("%d", &account->account_number);

    printf("Enter account holder name: ");
    getchar(); // Consume the newline character left by previous scanf
    fgets(account->account_holder_name, sizeof(account->account_holder_name), stdin);
    account->account_holder_name[strcspn(account->account_holder_name, "\n")] = '\0'; // Remove the trailing newline

    printf("Enter initial balance: ");
    scanf("%f", &account->balance);
}

void depositMoney(struct BankAccount* account, float amount) {
    account->balance += amount;
}

void withdrawMoney(struct BankAccount* account, float amount) {
    if (amount > account->balance) {
        printf("Insufficient balance. Cannot withdraw.\n");
    } else {
        account->balance -= amount;
    }
}

void displayAccountDetails(struct BankAccount* account) {
    printf("\nAccount Details:\n");
    printf("Account Number: %d\n", account->account_number);
    printf("Account Holder Name: %s\n", account->account_holder_name);
    printf("Balance: $%.2f\n", account->balance);
}

void freeLinkedList(struct BankAccount* head) {
    struct BankAccount* current = head;
    while (current != NULL) {
        struct BankAccount* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct BankAccount* head = NULL;
    struct BankAccount* tail = NULL;
    int num_accounts;

    printf("Enter the number of bank accounts: ");
    scanf("%d", &num_accounts);

    for (int i = 0; i < num_accounts; i++) {
        struct BankAccount* newAccount = createBankAccount();
        printf("\nEnter details for Account %d:\n", i + 1);
        getAccountDetails(newAccount);

        if (head == NULL) {
            head = newAccount;
            tail = newAccount;
        } else {
            tail->next = newAccount;
            tail = newAccount;
        }
    }

    int account_number;
    float amount;
    printf("\nEnter the account number for deposit: ");
    scanf("%d", &account_number);
    printf("Enter the amount to deposit: ");
    scanf("%f", &amount);

    // Find the specified account for deposit and perform the transaction
    struct BankAccount* current = head;
    while (current != NULL) {
        if (current->account_number == account_number) {
            depositMoney(current, amount);
            break;
        }
        current = current->next;
    }

    printf("\nEnter the account number for withdrawal: ");
    scanf("%d", &account_number);
    printf("Enter the amount to withdraw: ");
    scanf("%f", &amount);

    // Find the specified account for withdrawal and perform the transaction
    current = head;
    while (current != NULL) {
        if (current->account_number == account_number) {
            withdrawMoney(current, amount);
            break;
        }
        current = current->next;
    }

    // Display updated account details
    printf("\n--- Updated Account Details ---\n");
    current = head;
    while (current != NULL) {
        displayAccountDetails(current);
        current = current->next;
    }

    // Free allocated memory for the linked list
    freeLinkedList(head);

    return 0;
}

