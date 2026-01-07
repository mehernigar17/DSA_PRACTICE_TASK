
#include<stdio.h>
#include<stdlib.h>
struct node {
int data;
struct node *link;};
struct node *head=NULL;
    void insert_at_begin(int n){

    struct node * newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    if(head==NULL){
            head=newnode;
            head->link=NULL;

     return;
    }


    else{


        newnode->link=head;
        head=newnode;
    }



    }
     void traverse_list(){

     if(head==NULL){
        printf("empty");
     }
      struct node *ptr;


        for(ptr=head;ptr!=NULL;ptr=ptr->link){
            printf("%d",ptr->data);

        }






     }
    int main(){

    int n,value;
    printf ("number of nodes");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {

        scanf("%d",&value);
          insert_at_begin(value);



    }
 traverse_list();


    return 0;}
