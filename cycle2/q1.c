#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *CreateNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node *head)
{
    struct Node *curr = head;
    while (curr != NULL)
    {
        printf(" %d", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    int a, c;
    printf("Enter the head element: ");
    scanf("%d", &a);
    struct Node *head = CreateNode(a);

    while (1)
    {
        printf("Beginning : 1, End : 2, Other position : 3, Delete beg: 4, Delete End: 5, Delete Other: 6, Print : 7, Exit : Any other key\n");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
        {

            printf("Enter the element: ");
            scanf("%d", &a);
            struct Node *newNode = CreateNode(a);
            newNode->next = head;
            head = newNode;
            break;
        }
        case 2:
        {

            printf("Enter the element: ");
            scanf("%d", &a);
            struct Node *newNode = CreateNode(a);
            struct Node *curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = newNode;
            break;
        }
        case 3:
        {

            printf("Enter the element: ");
            scanf("%d", &a);
            struct Node *newNode = CreateNode(a);
            printf("Current list is: ");
            printList(head);
            printf("Enter the element to the left of the preferred location: ");
            scanf("%d", &a);

            struct Node *curr = head;
            while (curr != NULL)
            {
                if (curr->data == a)
                {
                    newNode->next = curr->next;
                    curr->next = newNode;
                    break;
                }
                else if (curr->next == NULL)
                {
                    printf("Element not found\n");
                    free(newNode);
                    break;
                }
                curr = curr->next;
            }
            break;
        }
        case 4:
        {

            if (head == NULL)
            {
                printf("List is empty\n");
                break;
            }
            struct Node *delNode = head;
            head = head->next;
            free(delNode);
            break;
        }
        case 5:
        {

            if (head == NULL)
            {
                printf("List is empty\n");
                break;
            }
            struct Node *curr = head;
            struct Node *prev = NULL;
            while (curr->next != NULL)
            {
                prev = curr;
                curr = curr->next;
            }
            if (prev != NULL)
            {
                prev->next = NULL;
            }
            else
            {
                head = NULL;
            }
            free(curr);
            break;
        }
        case 6:
        {

            printf("Current list is: ");
            printList(head);
            printf("Enter the left element of the element to be deleted: ");
            scanf("%d", &a);

            struct Node *curr = head;
            while (curr != NULL)
            {
                if (curr->next != NULL && curr->next->data == a)
                {
                    struct Node *delNode = curr->next;
                    curr->next = delNode->next;
                    free(delNode);
                    break;
                }
                curr = curr->next;
            }
            break;
        }
        case 7:
        {

            printList(head);
            break;
        }
        default:
        {

            printf("Exiting...\n");
            return 0;
        }
        }
    }

    return 0;
}