#include<bits/stdc++.h>
using namespace std;
struct node{
int data;
 node*prev;
 node* next;
 };
struct node*head=NULL;
struct node*tail=NULL;
void insert_last(int data){

node*newnode=new node;

newnode->prev=NULL;
newnode->next=NULL;
newnode->data=data;
if(head==NULL){
    head=tail=newnode;
}
else{
    tail->next=newnode;
    newnode->next=NULL;
    tail=newnode;
}

}


void print(){
  struct node*curr=head;
  while(curr!=NULL){
         cout << curr->data << " ";
    curr=curr->next;
  }
    cout << endl;




   }



   int main(){

    int n, value;

    cout << "How many nodes: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> value;
        insert_last(value);
    }

    cout << "Linked List: ";
    print();

    return 0;
}
