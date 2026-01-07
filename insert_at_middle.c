#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *head = NULL;

// Insert at the end
void insert_end(int value) {
    struct node *newnode = malloc(sizeof(struct node));
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


void insert_middle(int value) {
    int n = count_nodes();

    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = value;
    newnode->link = NULL;

    if (head == NULL || n == 1) {
        insert_end(value);
        return;
    }

    struct node *ptr = head;

    for (int i = 0; i < (n / 2) - 1; i++) {
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
    int n, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert_end(value);
    }

    printf("Current linked list: ");
    traverse();

    printf("Enter a value to insert in the middle: ");
    scanf("%d", &value);
    insert_middle(value);

    printf("Linked list after inserting in middle: ");
    traverse();

    return 0;
}
