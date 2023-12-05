#include <iostream>
using namespace std;

class Node{
   public:
    int data;
    Node* next;

     Node(int data){
        this->data = data;
        this->next = NULL;
     }
};

  Node* checkforduplicates(Node* &head){
      if(head == NULL){
          cout<<"linked list is empty"<<endl;
      }
    
     if(head->next == NULL){
       cout<<"linked list is not duplicate"<<endl;
        return head;
     }
  
     Node* curr = head;
      
      while(curr->next != NULL){
           if( ( curr->next != NULL) &&(curr -> data == curr->next->data)){
             //curr->next = curr->next->next; 
             // or this code
              Node* temp = curr->next;
               curr->next = curr->next->next;
               temp->next = NULL;
               
               delete temp;
            
           }
      
        else{
           curr = curr->next;
        }
    }
     return head;
  
  }

 void printll(Node* &head){
   Node* temp = head;
   while(temp != NULL){
     cout<<temp->data<<" ";
     temp = temp->next;
   }
    
 }

int main(){
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(2);
    Node* fourth = new Node(3);
    Node* fifth = new Node(4);
    Node* sixth = new Node(4);
  
   head->next = second;
   second->next = third;
   third->next = fourth;
   fourth->next = fifth;
   fifth->next = sixth;

   checkforduplicates(head);
   printll(head);
}