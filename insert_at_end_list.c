#include<stdio.h>
#include<stdlib.h>
struct node {
int data;
struct node *link;
};
struct node *head=NULL;

void insert_end(int value){

struct node *newnode,*ptr=NULL;
newnode=malloc(sizeof(struct node));
newnode->data=value;
ptr =head;
if(head == NULL) {
    head = newnode;
    head->link=NULL;

    return;
}

while(ptr->link!=NULL)
{

    ptr=ptr->link;
}
ptr->link=newnode;
newnode->link=NULL;

}




void traverse(){
struct node *ptr=NULL;
 if(head==NULL){
        printf("empty");
     }
    ptr=head;
    while(ptr!=NULL){
        printf("%d",ptr->data);
        ptr=ptr->link;
    }
}
int main(){

int n,value;
scanf("%d",&n);
printf("enter the values");

for(int i = 0; i < n; i++){
    scanf("%d", &value);
    insert_end(value);
}


traverse();




return 0;}
