#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(){
        this->data=0;
        this->next=NULL;
    }
    Node( int data){
        this->data=data;
        this->next=NULL;
    }
    ~Node(){

    }

};
//i want to insert a node right at the head of linked list
void insertAtHead(Node* &head,Node* tail,int data){
    //check for empty LL:// if LL is empty
    if(head==NULL){
        Node*newNode=new Node(data);
        head=newNode;
        tail=newNode;
        
    }
    // if LL is non empty
    else{
        //first step
    Node* newNode=new Node(data);
    //step2:
    newNode->next=head;
    //step3:
    head=newNode;
    }
    
}
//i want to insert a node right at the end of linkedlist
void insertAtTail(Node* &head,Node* &tail,int data){
    if(head==NULL){
        Node*newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    //step1:create a node
    Node* newNode=new Node(data);
    //step2: connect with tail node
    tail->next=newNode;
    //step3
    tail=newNode;
}
 void print(Node* head){
        Node*temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    int findLength(Node* &head){
        int len=0;
        Node* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
        return len;
    }
    void insertAtposition(int data,int position,Node* &head,Node* &tail){
        //if LL is empty
        if(head==NULL){
            Node* newNode=new Node(data);
            head=newNode;
            tail=newNode;
            return;
        }
        //step1: find the positon previous and current
        if(position==0){
            insertAtHead(head,tail,data);
            return;
        }
        //for positon last node
        int len=findLength(head);
        if(position>=len){
            insertAtTail(head,tail,data);
            return;
        }
        //step: find the postion:prev& current:
        int i=1;
        Node* prev=head;
        while(i<position){
            prev=prev->next;
            i++;
        }
        Node* curr=prev->next;
        //step2:
        Node* newNode=new Node(data);
        //step3:
        newNode->next=curr;
        //step4:
        prev->next=newNode;

    }
    void deleteNode(int position,Node* &head,Node* &tail){
        if(head==NULL){
            cout<<"cannot delete LLis empty";
            return;
        }
        //delte first node
        if(position==1){
            Node* temp=head;
            head=head->next;
            temp->next=NULL;
            delete(temp);
            return;

        }
        int len=findLength(head);
        //delete last node
        if(position==len){
            //find prev
            int i=1;
            Node* prev=head;
            while(i<position-1){
                prev=prev->next;
                i++;
            }


            //step2
            prev->next=NULL;
            //step3
            Node* temp=tail;
            delete temp;
            return;
        }
        //deleting middle node
        //step: find prev and curr
        int i=1;
        Node* prev=head;
        while(i<position-1){
            prev=prev->next;
            i++;

        }
        Node* curr=prev->next;
        //step2
        prev->next=curr->next;
        //step3
        curr->next=NULL;
        //step4
        delete curr;
         

    }
int main(){
    Node* head=NULL;
    Node* tail=NULL;
    insertAtTail(head,tail,76);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,70);
    insertAtHead(head,tail,60);
    insertAtHead(head,tail,90);
    
    print(head);
    cout<<endl;
    
  //  cout<<"head"<<" "<<head->data<<endl;
    //cout<<"tail"<<" "<<tail->data<<endl;

    //insertAtposition(100, 3,head,tail);
    //cout<<"printing after insert at position call"<<endl;
    //print(head);
    //cout<<endl;
   // cout<<"head"<<" "<<head->data<<endl;
    //cout<<"tail"<<" "<<tail->data<<endl;
    deleteNode(3,head,tail);
    cout<<endl;
    print(head);
    cout<<endl;

    
   


    return 0;




}