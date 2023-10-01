#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(){
        this->data=0;
        this->next=NULL;
        this->prev=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->next=NULL;
    }

};
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int getLength(Node* head){
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}


int main(){
    Node* first=new Node(20);
    Node* second=new Node(30);
    Node* third=new  Node(40);
    Node* fourth=new Node(60);
    Node* fivth=new Node(70);
    Node* head=first;
    Node* tail=fivth;
    


    first->next=second;
    second->prev=first;

    second->next=third;
    third->prev=second;

    third->next=fourth;
    fourth->prev=third;

    fourth->next=fivth;
    fivth->prev=fourth;
  //   tail->next=head;
    // head->prev=tail;

    
    cout<<endl;
    print(head);

}