#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
    int key;
    int value;
} Entry;

Entry table[SIZE];

int hash_function(int key) {
    return key % SIZE;
}

void insert(int key, int value) {
    int index = hash_function(key);
    while (table[index].key != -1) {
        index = (index + 1) % SIZE;
    }
    table[index].key = key;
    table[index].value = value;
    printf("Key-Value pair (%d, %d) inserted at index %d\n", key, value, index);
}

int search(int key) {
    int index = hash_function(key);
    while (table[index].key != -1 && table[index].key != key) {
        index = (index + 1) % SIZE;
    }
    if (table[index].key != -1 && table[index].key == key) {
        return table[index].value;
    } else {
        return -1;
    }
}

int main() {
    for (int i = 0; i < SIZE; i++) {
        table[i].key = -1; // Initialize keys to -1 to indicate empty slot
    }

    int choice, key, value;

    do {
        printf("\n1. Insert key-value pair\n");
        printf("2. Search value by key\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &value);
                insert(key, value);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                int result = search(key);
                if (result != -1) {
                    printf("Value found: %d\n", result);
                } else {
                    printf("Key not found\n");
                }
                break;
            case 3:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice. Please try again\n");
        }

    } while (choice != 3);

    return 0;
}