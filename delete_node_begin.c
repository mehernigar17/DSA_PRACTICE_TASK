
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *head = NULL;


void insert(int value) {
    struct node *newnode, *ptr;

    newnode = malloc(sizeof(struct node));
    newnode->data = value;
    newnode->link = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        ptr = head;
        while (ptr->link != NULL) {
            ptr = ptr->link;
        }
        ptr->link = newnode;
    }
}


void delete_begin() {
    struct node *ptr;
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        ptr = head;
        head = head->link;
        printf("%d deleted from beginning\n", ptr->data);
        free(ptr);
    }
}


void traverse() {
    struct node *ptr = head;
    if (ptr == NULL) {
        printf("List is empty\n");
        return;
    }
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}

int main() {

    int n, i, value;

    printf("How many nodes you want to insert: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {

        scanf("%d", &value);
        insert(value);
    }

    printf("\nLinked list:\n");
    traverse();

    delete_begin();

    printf("\nAfter deleting from beginning:\n");
    traverse();

    return 0;
}
