#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

struct Node {
    int key;
    char* value;
    struct Node* next;
};

struct Hashtable {
    struct Node* table[SIZE];
};

int hashFunction(int key) {
    return key % SIZE;
}

void insert(struct Hashtable* ht, int key, const char* value) {
    int index = hashFunction(key);

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->key = key;
    new_node->value = strdup(value);
    new_node->next = NULL;

    if (ht->table[index] == NULL) {
        ht->table[index] = new_node;
    } else {
        struct Node* temp = ht->table[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

char* search(struct Hashtable* ht, int key) {
    int index = hashFunction(key);

    struct Node* temp = ht->table[index];
    while (temp != NULL) {
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    }
    return NULL;
}

int main() {
    struct Hashtable ht;
    for (int i = 0; i < SIZE; i++) {
        ht.table[i] = NULL;
    }

    int choice, key;
    char value[100];

   

    while (1) {
         printf("\n1. Insert key-value pair\n");
         printf("2. Search for a key\n");
         printf("0. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%s", value);
                insert(&ht, key, value);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                char* result = search(&ht, key);
                if (result != NULL) {
                    printf("Value found for key %d: %s\n", key, result);
                } else {
                    printf("Key %d not found\n", key);
                }
                break;
            case 0:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}