#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* link;

};
struct node *head=NULL;
void creating_link_list(int n){
    struct node *newnode,*ptr;
    int i,value;
    for (int i=0;i<n;i++){
    newnode=malloc(sizeof (struct node));
    printf("Enter data: ");
        scanf("%d", &value);

    newnode->data=value;
    newnode->link=NULL;




    if(head==NULL){
        head=newnode;

    }
    else{
    ptr=head;
    while(ptr->link!=NULL){
            ptr=ptr->link;

    }
    ptr->link=newnode;
    }

}
}
void traverse_list(){
 struct node *ptr=NULL;
 if(head==NULL){
    printf("list is empty");

 }
 ptr=head;
 while(ptr!=NULL){

    printf("%d -> ", ptr->data);

    ptr=ptr->link;
 }
}



int main(){

int n;
printf("enter the number of nodes");
scanf("%d",&n);

creating_link_list(n);
traverse_list();




return 0;}
