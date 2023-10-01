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
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node* getmiddle(Node* &head){
    //if emptylinklist
    if(head==NULL){
        cout<<" LL is empty"<<endl;
        return head;
    }
    //only one node
    if(head->next==NULL){
        //only 1node inLL
        return head;
    }
    //LL have>1 node
    Node* slow=head;
    Node* fast=head;
    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;

        }

    }
    return slow;
       

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
Node* reverseNodes(Node* &head,int k){
    if(head==NULL){
        cout<<"LL is empty"<<endl;
         return NULL;
            
        }
        int len=getLength(head);
        if(k>len){
            cout<<" enter the valid for k"<<endl;
            return head;
        }
        //it means number of nodes in link list>> k
        //stepA: reverse first K nodes of LL
        Node* prev=NULL;
        Node* curr=head;
        Node* forward=curr->next;
        int count=0;
        while(count<k){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            count++;
        }
        //steps b
        if(forward!=NULL){

            //we still have nodes left to reverse
            head->next=reverseNodes(forward,k);
        }
       //stepc: return head of  the modified LL
       return prev;
}
bool checkforLoop(Node* &head){
    if(head==NULL){
        cout<<"LL is empty"<<endl;
        return false;
    }
    Node* slow =head;
    Node* fast=head;

    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        if(slow==fast){
            //loop present
            return true;
        }
        
    }
    //fast Null hogaya
    return false;
}
Node* startingpointLoop(Node* &head){
    if(head==NULL){
        cout<<"ll is empty"<<endl;
        return NULL;
    }
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        if(slow==fast){
            slow=head;
            break;
        }
    }
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;

}
Node* removeLoop(Node* head){
    if(head==NULL){
        cout<<"ll is empty"<<endl;
        return NULL;
    }
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL){
        fast=fast->next;
        if(slow==fast){
            slow=head;
            break;
        }
    }
    Node* prev=fast;
    while(slow!=fast){
        prev=fast;
        slow=slow->next;
        fast=fast->next;
    }
    prev->next=NULL;
    return slow;
}


int main(){
    Node* head=new Node(10);
    Node* second= new Node(20);
    Node* third=new Node(30);
    Node* fourth=new Node(40);
    Node* fivth=new Node(50);
    Node* sixth=new Node(70);
    Node* seventh=new Node(80);
    Node* eight=new Node(90);
    Node* ninth=new Node(100);




    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fivth;
    fivth->next=sixth;
    sixth->next=seventh;
    seventh->next=eight;
    eight->next=ninth;
    ninth->next=fourth;

   
    print(head);
   //head= reverseNodes(head,3);
  // cout<<endl;
   //print(head);
   // cout<<"middle Node is "<< getmiddle(head)->data<<endl;
   cout<<"middle node is:"<<getmiddle(head)->data<<endl;
   cout<<"loop is present or not"<<checkforLoop(head)<<endl;
   cout<<"starting point of loop is "<<startingpointLoop(head)->data<<endl;
   removeLoop(head);
   print(head);
   cout<<" loop is present or not "<<checkforLoop(head)<<endl;
   return 0;
    
    
}