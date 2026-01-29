#include<stdio.h>
#include<stdlib.h>
struct node {
int data;
struct node *next;
struct node*prev;

};
struct node *head=NULL;
void insert_at_begin(int data){

struct node *newnode=malloc(sizeof(struct node));
 newnode->data = data;
if(head==NULL){

    newnode->next=NULL;
    newnode->prev=NULL;
    head=newnode;
}

else{

    newnode->next=head;
    newnode->prev=NULL;
    head->prev=newnode;
    head=newnode;

}





}

void traverse(){
struct node *ptr;
if(head==NULL){
    printf("list is empty");
}
else{
    for(ptr=head;ptr!=NULL;ptr=ptr->next){
        printf("%d ",ptr->data);
    }
}




}


int main(){


int a;
scanf("%d",&a);
int n;

for(int i=0;i<a;i++){
    scanf("%d",&n);
    insert_at_begin(n);
}



traverse();







return 0;}
