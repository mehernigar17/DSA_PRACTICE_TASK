
#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *link;

};

struct node *head=NULL;
void insert (int n){
struct node *newnode;
newnode=malloc(sizeof(struct node));
newnode->data=n;
struct node*ptr=head;





if(head == NULL) {
    head = newnode;
    head->link=NULL;

    return;
}




while(ptr->link!=NULL){
    ptr=ptr->link;
}

ptr->link=newnode;
newnode->link=NULL;



}

void elements(int v){

struct node*ptr=head;
while(ptr->link!=NULL){

    if(ptr->data<5){
       printf("%d",ptr->data);
    }
    ptr=ptr->link;


}




}


int main(){

int n;
scanf("%d",&n);
int x;
for(int i=0;i<n;i++){
    scanf("%d",&x);
    insert(x);
}
int value;
printf("enter the element ");
scanf("%d",&value);


 elements(value);





return 0;}
