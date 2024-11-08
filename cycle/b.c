#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * right,*left;
}node;
struct node *create(){
    node *newnode ;
    newnode = (node*)malloc(sizeof(node));
    printf("enter the data");
    int data;
    scanf("%d",&data);
    if(data==-1){
        return NULL;
    }
    else{
        newnode->data=data;
        newnode->left=create();
        newnode->right=create();
        return newnode;
    }
}

void print(node *root){
    if(root==NULL){
        return;
    }
    print(root->left);
    printf("%d ",root->data);
    print(root->right);
}
void main(){
     node *root = NULL;
     root=create();
     print(root);
}