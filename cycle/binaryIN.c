#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *right;
    struct node *left;    
};
 //node creation
 struct node *createNode(int data){
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->right = NULL;
    n->left = NULL;
    return n;   
}

void printtree(struct node *root){
    if(root == NULL){
        return;        
    }
    
    printtree(root->left);
    printf("%d ",root->data);
    printtree(root->right);
}
//recursion
struct node *createTree() {
    int data;
    printf("Enter the data: ");
    scanf("%d", &data);

    //base case and to exit
    if(data == -1){
        return NULL;
    }
    //recursive case
    else{
        struct node *newNode = createNode(data);
        printf("Enter the left child of %d: ", data);
        newNode -> left = createTree();
        printf("Enter the right child of %d: ", data);
        newNode -> right = createTree();
        return newNode;
    }


}
int main(){
    while(1){
      int choice;
    printf("1: to create binary tree and 2: to print it\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("Creating binary tree:\n");
        struct node *root = createTree();
        
        case 2:
        printf("In-order Traversal: ");
        printtree(root);
        printf("\n");
        break;

        default:
        exit(0);  
    }
    
    }
    
    return 0;
}