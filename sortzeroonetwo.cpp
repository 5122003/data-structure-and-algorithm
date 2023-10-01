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

void sortZeroOneTwo(Node* &head){
    //step : find count of zeroes, ones and twos
    int zero=0;
    int one=0;
    int two=0;
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==0)
        zero++;
        else if(temp->data==1)
        one++;
        else if(temp->data==2)
        two++;
        temp=temp->next;

    }
    //step2:  fill 0,1and 2 in the orginal
    temp=head;
    
        // fill zeroes
        while(zero--){
            temp->data=0;
            temp=temp->next;
        }
        // fill ones
        while(one--){
            temp->data=1;
            temp=temp->next;
        }
        //fill two
        while(two--){
            temp->data=2;
            temp=temp->next;
        }
    }
    Node* sort2(Node* head){
        // create dummy nodes
        Node* ZeroHead=new Node(-1);
        Node* ZeroTail=ZeroHead;

        Node* oneHead=new Node(-1);
        Node* oneTail =oneHead;

        Node* twoHead=new Node(-1);
        Node* twoTail= twoHead;

        //traverse the original LL
        Node* curr=head;
        while(curr!=NULL){
            if(curr->data==0){
                //take out the zero wali node
                Node* temp=curr;
                curr=curr->next;
                temp->next=NULL;

                //append the zero node in zerohead ll
                ZeroTail->next=temp;
                ZeroTail=temp;


            }
            else if(curr->data==1){
                //take out the one wali nodes
                Node* temp=curr;
                curr=curr->next;
                temp->next=NULL;

                //append the zero node in zerohead LL
                oneTail->next=temp;
                oneTail=temp;

            }
            else if(curr->data==2){
                //take out the two wali nodes
                Node* temp=curr;
                curr=curr->next;
                temp->next=NULL;

                //append the zero node in zero in zerohead ll
                twoTail->next=temp;
                twoTail=temp;

            }
        }

        //ab yha pr, zero ,one,two,teeno LL ready h
        //join them
        // remove dummy nodes
        // modify one wali list
        Node* temp=oneHead;
        oneHead=oneHead->next;
        temp->next=NULL;
        delete temp;

        //modify two wali  list
        temp=twoHead;
        twoHead=twoHead->next;
        temp->next=NULL;
        delete temp;


        //join list
        if(oneHead!=NULL){
            // one wali list is an empty
            ZeroTail->next=oneHead;
            if(twoHead!=NULL)
            oneTail->next=twoHead;

        }
        else{
            //one wali list is empty
            if(twoHead!=NULL)
            ZeroTail->next=twoHead;

        }


        //remove zerohead dummy node
        temp=ZeroHead;
        ZeroHead=ZeroHead->next;
        temp->next=NULL;
        delete temp;

        //return head  of the modified linked list
        return ZeroHead;




    }

    

int main(){
    Node* head=new Node(1);
    Node* two=new Node(0);
    Node* three=new Node(1);
    Node* fourth=new Node(1);
    Node* fivth=new Node(1);
    Node* sixth=new Node(2);

    head->next=two;
    two->next=three;
    three->next=fourth;
    fourth->next=fivth;
    fivth->next=sixth;


    cout<<"input ll:";
    print(head);
    //sortZeroOneTwo(head);
    //print(head);

    cout<<"printing the sorted list"<<endl;
    Node* temp=NULL;
    head=sort2(head);
    print(head);

}