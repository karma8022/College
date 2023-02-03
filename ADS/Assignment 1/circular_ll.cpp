#include <iostream>
using namespace std;

struct Node {
   int coef;
   int exp;
   struct Node *next;
}head;

void insert(struct Node* head){
   struct Node* temp;
   temp = head;
   int choice;
   cout<<"Enter choice";
   cin>>choice;
   while(choice == 1){
      struct Node* curr = (struct Node*)malloc(sizeof(struct Node));
      cout<<"Enter coef";
      cin>>curr->coef;
      cout<<"Enter exp";
      cin>>curr->exp;
      curr->next=head;
      temp->next=curr;
      temp = curr;
      cin>>choice;
   }
}

void display(struct Node*head){
   struct Node* temp = head;
   while(temp->next!=head){
      temp = temp->next;
      cout<<temp->coef;
      cout<<temp->exp;
   }
}

void addition(struct Node* head){

}

int main(){
   struct Node* head = (struct Node*)malloc(sizeof(struct Node));
   head->next=head;
   insert(head);
   display(head);
   return 0;
}
  