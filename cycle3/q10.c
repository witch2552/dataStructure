#include <stdio.h>
#include <stdlib.h>

struct Node {
    int user_id;
    struct Node* friends;
    int num_friends;
};

struct Graph {
    struct Node* nodes;
    int num_nodes;
};

struct Graph* createGraph(int num_users) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->num_nodes = num_users;
    graph->nodes = (struct Node*)malloc(num_users * sizeof(struct Node));

    for (int i = 0; i < num_users; i++) {
        graph->nodes[i].user_id = i + 1;
        graph->nodes[i].friends = NULL;
        graph->nodes[i].num_friends = 0;
    }

    return graph;
}

void addFriendship(struct Graph* graph, int user_id1, int user_id2) {
    if (user_id1 < 1 || user_id1 > graph->num_nodes || user_id2 < 1 || user_id2 > graph->num_nodes) {
        printf("Invalid user IDs\n");
        return;
    }

    // Add user_id2 to user_id1's friends list
    struct Node* user1 = &graph->nodes[user_id1 - 1];
    user1->friends = (struct Node*)realloc(user1->friends, (user1->num_friends + 1) * sizeof(struct Node));
    user1->friends[user1->num_friends].user_id = user_id2;
    user1->num_friends++;

    // Add user_id1 to user_id2's friends list
    struct Node* user2 = &graph->nodes[user_id2 - 1];
    user2->friends = (struct Node*)realloc(user2->friends, (user2->num_friends + 1) * sizeof(struct Node));
    user2->friends[user2->num_friends].user_id = user_id1;
    user2->num_friends++;
}

int main() {
    int num_users;
    int choice;
    printf("Enter the number of users: ");
    scanf("%d", &num_users);
    struct Graph* social_network = createGraph(num_users);
    scanf("%d", &choice);
    while (1)
    {   printf("1. Add friendship\n 2. free node\n3. Exit\n");
        switch (choice)
        {
        case /* constant-expression */1:
            /* code */
            int first,second;
            printf("Enter the first user: ");
            scanf("%d",&first);
            printf("Enter the second user: ");
            scanf("%d",&second);
            addFriendship(social_network, first,second);
            break;

        case /* constant-expression */2:
            /* code */
                free(social_network->nodes);
                free(social_network);
            break;
        
        default:
            break;
        }
    }
    
    /*addFriendship(social_network, 1, 2);
    addFriendship(social_network, 1, 3);
    addFriendship(social_network, 2, 4);

    // You can add more friendships and perform other operations here

    free(social_network->nodes);
    free(social_network);*/

    return 0;
}