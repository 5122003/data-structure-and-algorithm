#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;

    }

};
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void removeDuplicate(Node* head){
    if(head==NULL){
        cout<<"LL is empty"<<endl;
        return;

    }
    //single linklist
    if(head->next==NULL){
        cout<<"single node in ll"<<endl;
        return;
    }
    //more than one node
    Node* curr=head;
    while(curr!=NULL){
        if((curr->next!=NULL) &&(curr->data==curr->next->data) ){
            //equal
            Node* temp=curr->next;
            curr->next=curr->next->next;
            //delete node
            temp->next=NULL;
            delete temp;
        }
        else{
            //not equal
            curr=curr->next;
        }
    }

}



int main(){
    Node* head=new Node(1);
     Node* second=new Node(2);
      Node* third=new Node(2);
       Node* fourth=new Node(4);
        Node* fivth=new Node(4);
         Node* sixth=new Node(6);
          Node* seventh=new Node(7);

          head->next=second;
          second->next=third;
          third->next=fourth;
          fourth->next=fivth;
          fivth->next=sixth;
          sixth->next=seventh;
          cout<<"input LL: is"<<endl;
          print(head);

          removeDuplicate(head);
          cout<<"output LL"<<" ";
          print(head);

}