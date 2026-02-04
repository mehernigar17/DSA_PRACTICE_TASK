
#include<stdio.h>
#include<stdlib.h>
struct node{

int data ;
struct node *link;





};

struct node *head=NULL;
void insert(int n){
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data=n;
    if(head==NULL){
        head=newnode;
        newnode->link=NULL;
        return;
    }
    else{

       struct node*ptr=head;
       while(ptr->link!=NULL){
        ptr=ptr->link;
       }
       ptr->link=newnode;
       newnode->link=NULL;
    }

}


int frequency(int value){
int count=1;
struct node*ptr=head;
while(ptr->link!=NULL){

    if(ptr->data==value){
        count++;
    }
      ptr=ptr->link;
}

return count;

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
printf("enter the element to be counted");
for(int i=0;i<n;i++){
scanf("%d",&value);
}


int result = frequency(value);
    printf("Frequency = %d\n", result);









}
