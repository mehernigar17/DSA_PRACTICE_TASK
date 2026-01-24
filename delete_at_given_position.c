
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *head = NULL;


void insert(int n){
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = n;
    newnode->link = NULL;

    if(head == NULL){
        head = newnode;
    }
    else{
        struct node *ptr = head;
        while(ptr->link != NULL){
            ptr = ptr->link;
        }
        ptr->link = newnode;
    }
}



void delete_pos(int pos){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }

    struct node *ptr;

    if(pos == 1){
        ptr = head;
        head = head->link;
        free(ptr);
    }
    else{
        ptr = head;
        for(int i = 1; i < pos-1 && ptr != NULL; i++){
            ptr = ptr->link;
        }
        if(ptr == NULL || ptr->link == NULL){
            printf("Invalid position\n");
            return;
        }
        struct node *ptr1 = ptr->link;
        ptr->link = ptr1->link;
        free(ptr1);
    }
}


void traverse(){
    if(head == NULL){
        printf("Empty list\n");
        return;
    }
    struct node *ptr = head;
    while(ptr != NULL){
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}

int main(){
    int n, value, pos;

    printf("Enter number of elements to insert at end: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &value);
        insert(value);
    }

    printf("Current linked list: ");
    traverse();

    printf("Enter position to delete: ");
    scanf("%d", &pos);
    delete_pos(pos);

    printf("Linked list after deletion: ");
    traverse();

    return 0;
}
