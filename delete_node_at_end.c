#include<stdio.h>
#include<stdlib.h>
struct node{

int data;
struct node *link;






};
struct node *head=NULL;
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
void delete_end(){
if(head==NULL){
    printf("empty list");
}
else{

  struct node *ptr=head;
   struct node *ptr1;
  while(ptr->link!=NULL)  {
    ptr1=ptr;
    ptr=ptr->link;
  }

  ptr1->link=NULL;
  free(ptr);
}
}


void traverse(){
    struct node *ptr = head;
    if(ptr == NULL){
        printf("List is empty\n");
        return;
    }
    while(ptr != NULL){
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}






int main(){


int n,value;
printf("number of elements");
scanf("%d",&n);

for(int i=0;i<n;i++){
    scanf("%d",&value);
    insert(value);
}

delete_end();
traverse();





return 0;
}
