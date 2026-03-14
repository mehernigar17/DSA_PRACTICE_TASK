
#include<bits/stdc++.h>
using namespace std;
struct node{
int data;
node* prev;
node * next;
};
node *head=NULL;
node*tail=NULL;
void insertlast(int data){

node*newnode=new node;
newnode->data = data;
newnode->prev=NULL;
newnode->next=NULL;
if(head==NULL){
    head=tail=newnode;
}
else{
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
}


}

void search_element(int target){

node* curr=head;

while(curr!=NULL){
     if(curr->data==target){

        cout<<"element found"<<endl;
        return;
     }
     curr=curr->next;


}
cout<<"not found"<<endl;


}








 int main(){

    int n,x;

    cout<<"How many numbers: ";
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        insertlast(x);
    }
    int target;
    cin>>target;
 search_element(target);

}
