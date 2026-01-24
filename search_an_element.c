#include<stdio.h>
#include<stdlib.h>
struct node{

int data;
struct node *link;
};
struct node *head=NULL;







void insert(int n){
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = n;
    newnode->link = NULL;

    if(head == NULL){
        head = newnode;
        return;
    }

    struct node *ptr = head;
    while(ptr->link != NULL){
        ptr = ptr->link;
    }
    ptr->link = newnode;
}

void search(int n){
    struct node *ptr = head;
    int found = 0;

    while(ptr != NULL){
        if(ptr->data == n){
            found = 1;
            break;
        }
        ptr = ptr->link;
    }

    if(found == 1){
        printf("Element found\n");
    } else {
        printf("Element not found\n");
    }
}





int main(){



 int n;
    scanf("%d", &n);

    int x;
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        insert(x);
    }

int value;
scanf("%d",&value);


search(value);





return 0;}
