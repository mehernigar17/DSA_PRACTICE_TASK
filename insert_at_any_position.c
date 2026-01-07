
#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *link;
};


struct node *head = NULL;


void insert_end(int value) {
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = value;
    newnode->link = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    struct node *ptr = head;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = newnode;
}


int count_nodes() {
    int count = 0;
    struct node *ptr = head;
    while (ptr != NULL) {
        count++;
        ptr = ptr->link;
    }
    return count;
}

void insert_at_position(int value, int pos) {
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = value;
    newnode->link = NULL;

    int n = count_nodes();


    if (pos <= 1 || head == NULL) {
        newnode->link = head;
        head = newnode;
        return;
    }


    if (pos > n) {
        insert_end(value);
        return;
    }


    struct node *ptr = head;
    for (int i = 1; i < pos - 1; i++) {
        ptr = ptr->link;
    }

    newnode->link = ptr->link;
    ptr->link = newnode;
}


void traverse() {
    if (head == NULL) {
        printf("empty\n");
        return;
    }

    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}


int main() {
    int n, value, pos;

    printf("Enter number of elements to insert at end: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert_end(value);
    }

    printf("Current linked list: ");
    traverse();

    printf("Enter a value and position to insert: ");
    scanf("%d %d", &value, &pos);
    insert_at_position(value, pos);

    printf("Linked list after insertion: ");
    traverse();

    return 0;
}

