
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* prev;
    node* next;
};

node* head = NULL;
node* tail = NULL;

void insert_first(int data){
struct node *newnode=new node;
newnode->prev=NULL;
newnode->next=NULL;
newnode->data=data;
if(head==NULL){
    head=tail=newnode;
}
else{
    head->prev=newnode;
     newnode->next = head;
    head=newnode;

}

}

void print_forward(){
    node* curr = head;
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main(){

    int n, value;

    cout << "How many nodes: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> value;
        insert_first(value);
    }

    cout << "Linked List: ";
    print_forward();

    return 0;
}
