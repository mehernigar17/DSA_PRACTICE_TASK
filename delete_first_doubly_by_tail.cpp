#include<bits/stdc++.h>
using namespace std;


struct node{
int data;
node *prev;
node*next;
};
  node *head=NULL;
  node *tail=NULL;


  void insertlast(int data){
    node *newnode = new node;
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;

    if(head == NULL){
        head = tail = newnode;
    }
    else{
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}















  void delete_first(){

  if(head==NULL){
    return ;
  }
    node*curr=head;
  if(head==tail){
    head=tail=NULL;
  }
  else{
    head=head->next;
    head->prev=NULL;
  }

  delete curr;


  }


 void display(){
    node *temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}









  int main(){

    int n,x;

    cout<<"How many numbers: ";
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        insertlast(x);
    }
    delete_first();

    cout<<"List: ";
    display();

}
