#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *link;
};

struct node*head=NULL;

void sorted_insertion(int v){
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = v;
    newnode->link = NULL;

    if(head == NULL || head->data > newnode->data){
        newnode->link = head;
        head = newnode;
        return;
    }

    struct node *ptr = head;
    while(ptr->link != NULL && ptr->link->data < newnode->data){
        ptr = ptr->link;
    }

    newnode->link = ptr->link;
    ptr->link = newnode;
}







void display(){
    struct node *ptr = head;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
   // printf("NULL\n");
}














int main(){
    int n, value;

    printf("How many numbers ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Enter value %d: ", i+1);
        scanf("%d", &value);
        sorted_insertion(value);
    }

    printf("sorted  List\n");
    display();

    return 0;
}
