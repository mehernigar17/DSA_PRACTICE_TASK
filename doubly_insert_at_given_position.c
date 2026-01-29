





#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;


void insert_at_end(int data){
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL){
        newnode->prev = NULL;
        head = newnode;
    }
    else{
        struct node *ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->prev = ptr;
    }
}


int count(){
    struct node *ptr = head;
    int c = 0;
    while(ptr != NULL){
        c++;
        ptr = ptr->next;
    }
    return c;
}


void insert_at_given_pos(int value, int pos){
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = value;

    int n = count();


    if(pos == 1){
        newnode->prev = NULL;
        newnode->next = head;
        if(head != NULL)
            head->prev = newnode;
        head = newnode;
        return;
    }

    if(pos > n){
        insert_at_end(value);
        return;
    }

    struct node *ptr = head;
    for(int i = 1; i < pos-1; i++){
        ptr = ptr->next;
    }

    newnode->next = ptr->next;
    newnode->prev = ptr;
    ptr->next->prev = newnode;
    ptr->next = newnode;
}


void traverse(){
    struct node *ptr;
    for(ptr = head; ptr != NULL; ptr = ptr->next){
        printf("%d ", ptr->data);
    }
}

int main(){
    int n, value, pos;

    printf("number of nodes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &value);
        insert_at_end(value);
    }

    printf("value and position: ");
    scanf("%d %d", &value, &pos);
    insert_at_given_pos(value, pos);

    traverse();
    return 0;
}
