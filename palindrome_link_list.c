#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* head = NULL;

// Insert at end
void insert(int n){
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = n;
    newnode->link = NULL;

    if(head == NULL){
        head = newnode;
        return;
    }

    struct node* ptr = head;
    while(ptr->link != NULL){
        ptr = ptr->link;
    }
    ptr->link = newnode;
}

// Forward traverse and build number
long long traverse_number(){
    struct node* ptr = head;
    long long num = 0;

    while(ptr != NULL){
        num = num * 10 + ptr->data;  // number build
        ptr = ptr->link;
    }
    return num;
}

// Helper for reverse traverse number using recursion
void reverse_number_helper(struct node* ptr, long long* num){
    if(ptr == NULL) return;
    reverse_number_helper(ptr->link, num);
    *num = *num * 10 + ptr->data;
}

// Reverse traverse number
long long reverse_number(){
    long long num = 0;
    reverse_number_helper(head, &num);
    return num;
}

int main(){
    int n, x;
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        scanf("%d", &x);
        insert(x);
    }

    long long forward = traverse_number();
    long long backward = reverse_number();

    printf("Forward number: %lld\n", forward);
    printf("Reverse number: %lld\n", backward);

    if(forward == backward){
        printf("Palindrome\n");
    } else {
        printf("Not Palindrome\n");
    }

    return 0;
}

