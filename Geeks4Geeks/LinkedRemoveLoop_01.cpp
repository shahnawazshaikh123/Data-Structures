#include<iostream>
#include<unordered_set>
using namespace std;
class Node{
    public:
  int data;
    Node* next;
};
void createNode(Node** head,int data){
  Node* newNode=new Node();
  newNode->data=data;
  if(*head==NULL){
    *head=newNode;
    newNode->next=NULL;
    return;
  }
   newNode->next=*head;
   *head=newNode;
}
void removeLoop(Node* loop_node,Node* head){
 
  Node* ptr1=head;
  Node* ptr2;
  while(1){
  ptr2=loop_node;

    while(ptr2->next!=loop_node && ptr2->next!=ptr1)
         ptr2=ptr2->next;
    if(ptr2->next==ptr1)
        break;   
  }
 ptr2->next=NULL;
 


}
void detectLoop(Node* head){
  Node* p1=head;
  Node* p2=head;
  while(p2!=NULL && p2->next!=NULL){
    p2=p2->next->next;
    p1=p1->next;
    if(p1==p2){
        cout<<endl<<" exist";
        removeLoop(p1,head);

      }  
  }
}

void pirntList(Node** head){
  Node* temp=*head;
  while(temp!=NULL){
     cout<<temp->data<<" ";
      temp=temp->next;
  }
  cout<<endl;
}
int main(){
Node* head=NULL;
int T;
cin>>T;
while(T--){
int data; 
cin>>data;
createNode(&head,data);
}

pirntList(&head);
 head->next->next->next=head;  // To allow Loop exist


detectLoop(head); //? cout<<"Loop exist:"<<endl : cout<<"Not exist: ";   

pirntList(&head);




}