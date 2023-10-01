#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(){
        this->data=0;
        this->prev=NULL;
        this->next=NULL;
    }
    Node(int data){

this->data=data;
this->prev=NULL;
this->next=NULL;
    }
    ~Node(){
        cout<<"node with value"<<this->data<<"delete";
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
void inserAtHead(Node* &head, Node* &tail,int data){
    //if dobuly linklist is empty
    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
        
    }
    else{
    //non empty LL
    //create node step1
    Node* newNode=new Node(data);
    //step2
    newNode->next=head;
    //step3
    head->prev=newNode;
    //step4
    head=newNode;
    }

}
void inserAtTail(Node* &head,Node* tail,int data){
    //if linklist is empty
    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
    }
    else{
        // if LL listlist is non empty
        //first step create a Node
        Node* newNode=new Node(data);
        //sescond step
        tail->next=newNode;
        //third step
        newNode->prev=newNode;
        //fourth step
        tail=newNode;

    }
}
void insertAtposition(Node* head,Node* tail,int data,int position){
    //if linklist is empty
    if(head== NULL){
        //newNode create
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
    }
    //if linllist not empty
    else{
        //if data insert in first
        if(position==1){
            inserAtHead(head,tail,data);
            return;

        }
        //if data insert in last
        int len=getLength(head);
        if(position>len){
            inserAtTail(head,tail,data);
            return;
        }
        //insertion in middle
        //step1: find prev && curr
        int i=1;
        Node* prevNode=head;
        while(i<position-1){
            prevNode=prevNode->next;
            i++;
        }
        Node* curr=prevNode->next;
        //step2
        Node* newNode=new Node(data);
        //step3
        prevNode->next=newNode;
        newNode->prev=prevNode;
        curr->prev=newNode;
        newNode->next=curr;
         

    }
}
void deltetefrompos(Node* head,Node* tail,int position){
    //if linkedlist is empty
    if(head==NULL){
        cout<<"Linkedlist is empty";
        return;

    }
    if(head->next==NULL){
        //single node
        Node* temp=head;
        head=NULL;
        tail=NULL;
        delete temp;
        return; 

    }
    int len=getLength(head);
    if(position>len){
        cout<<" please enter a valid position"<<endl;
        return;
    }

    if(position==1){
        //want to delete first node
        Node* temp=head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        delete temp;
        return;


    }

    //int len=getLength(head);
    if(position==len){
        //delete last node
        Node* temp=tail;
        //2nd step
        tail=tail->prev;
        //3rd
        temp->prev=NULL;
        //4th
        tail->next=NULL;
        delete temp;
        return;

    }
    //delete from middle of linked list
    //step1: find left,current ,right
    int i=1;
    Node* left=head;
    while(i<position-1){
        left=left->next;
        i++;
    }
    Node* curr=left->next;
    Node* right=curr->next;
    //step2
    left->next=right;
    //step3
    right->prev=left;
    //step4
    curr->next=NULL;
    curr->prev=NULL;
    delete curr;




}
Node* reverse(Node* &prev, Node* curr){
    //base case
    if(curr==NULL){
        //LL is reverse ho chuki
        return prev;
     }
     //i case solve then recursion will take care
     Node* forward=curr->next;
     curr->next=prev;
     reverse(curr,forward);
}
Node* reverseusingloop(Node* head){
    Node* prev=NULL;
    Node* curr=head;
    while(curr!=NULL){
        Node* temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}
Node* reverseusingRecursion(Node* prev,Node* curr){
    //base case
    if(curr==NULL)
    return prev;
    //1 case solve
    Node* temp=curr->next;
    curr->next=prev;
    prev=curr;
    curr=temp;

    //recursion sambhal lega
    return reverseusingRecursion(prev,curr);
}
int main(){
    Node* first=new Node(20);
    Node* second=new Node(30);
    Node* third=new Node(40);
    Node* fourth=new Node(50);
    Node* head=first;
    Node* tail=fourth;

    first->next=second;
   second->prev=first;

    second->next=third;
    third->prev=second;


    third->next=fourth;
    fourth->prev=third;

   // print(first);
   // cout<<endl;
    inserAtHead(head,tail,102);
    cout<<endl;
    print(head);
    inserAtTail(head,tail,88);
    cout<<endl;
    print(head);
    //cout<<endl;
   // insertAtposition(head,tail,202,5);
  //   print(head);
  //  cout<<endl;
   // deltetefrompos(head,tail,5);
    //cout<<endl;
    //print(head);
    cout<<endl;
    Node* prev=NULL;
    Node* curr=head;
    cout<<"printing reverse list"<<endl;
    head=reverseusingRecursion(prev,curr);
    cout<<endl;
    print(head);
    cout<<endl;


    

}