#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this-> data=data;
        this->next=NULL;
    }
};
Node* reverse(Node* head){
    Node* prev=NULL;
    Node* curr=head;
    Node* next=curr->next;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
bool checkpalindrone(Node* head){
    if(head==NULL){
        cout<<"LL is empty"<<endl;
        return true;
    }
    if(head->next==NULL){
        //only one node

        return true;
    }
    //
    //middle
    //more than one node
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
    }
    //slow pointer is pointing to the middle node



    //step b : reverse LL after middle node
    Node* reverseLLkahead=reverse(slow->next);
    slow->next=reverseLLkahead;

    //step c comparison
    Node* temp1=head;
    Node* temp2=reverseLLkahead; 
    while(temp2!=NULL){
        if(temp1->data!=temp2->data){
            //not a palindrone
            return false;
        }
        else{
            //if data is equal then palindrone is right
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    return true;


}

int main(){
    Node* head=new Node(10);
    Node* second=new Node(20);
    Node* third=new Node(300);
    Node* fourth= new Node(300);
    Node* fivth=new Node(20);
    Node* sixth=new Node(10);

    
    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fivth;
    fivth->next=sixth;
    
    


    bool ispalindrone=checkpalindrone(head);
    if(ispalindrone){
        cout<<"LL is palindrone"<<endl;

    }
    else{
        cout<<"LL is not palindrone"<<endl;
    }
    return 0;

}