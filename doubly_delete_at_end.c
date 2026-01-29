#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*prev;
struct node*next;


};
struct node *head=NULL;


void insert_at_end(int data){

struct node *newnode=malloc(sizeof(struct node));
newnode->data = data;

if(head==NULL){
    newnode->prev=NULL;
    newnode->next = NULL;

    head=newnode;

}
else{
    struct node*ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=newnode;
    newnode->prev=ptr;
    newnode->next=NULL;
}

}





void delete_at_end(){

if(head==NULL){
    printf("list is empty");
}

else{
    struct node*ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->prev->next=NULL;
    free(ptr);
}




}
void traverse(){

struct  node*ptr;

for(ptr=head;ptr!=NULL;ptr=ptr->next){
    printf("%d ",ptr->data);
}

}








int main(){


  int n,value;
    printf ("number of nodes");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {

        scanf("%d",&value);
          insert_at_end(value);

    }

    delete_at_end();
 traverse();
return 0;
}








