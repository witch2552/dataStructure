#include <stdio.h>
#include <stdlib.h>

// Function to create a binary tree from user input
int* createTree(int size) {
    int* tree = (int*)malloc(size * sizeof(int));
    if (tree == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &tree[i]);
    }
    return tree;
}

// Function to print the binary tree in level order
void levelOrderTraversal(int* tree, int size) {
    printf("Level Order Traversal: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", tree[i]);
    }
    printf("\n");
}

// Function to calculate the height of the tree
int height(int* tree, int index, int size) {
    if (index >= size) {
        return 0; // Out of bounds
    }
    int leftHeight = height(tree, 2 * index + 1, size);
    int rightHeight = height(tree, 2 * index + 2, size);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Menu-driven program
int main() {
    int choice;
    int size;
    int* tree = NULL; // Pointer to the dynamic array

    do {
        printf("\nMenu:\n");
        printf("1. Create Binary Tree\n");
        printf("2. Level Order Traversal\n");
        printf("3. Height of Tree\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of nodes: ");
                scanf("%d", &size);
                tree = createTree(size);
                break;

            case 2:
                if (tree != NULL) {
                    levelOrderTraversal(tree, size);
                } else {
                    printf("Tree not created yet!\n");
                }
                break;

            case 3:
                if (tree != NULL) {
                    printf("Height of Tree: %d\n", height(tree, 0, size));
                } else {
                    printf("Tree not created yet!\n");
                }
                break;

            case 4:
                printf("Exiting...\n");
                free(tree); // Free allocated memory
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}