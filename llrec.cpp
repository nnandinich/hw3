#include "llrec.h"


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  //if list is empty
  if(head==NULL){
    smaller=NULL;
    larger=NULL;
  }
  else{
    Node* temp=head->next;
    //disconnect last node from list
    head->next=NULL;
    llpivot(temp,smaller,larger,pivot);
    //put node in smaller
    if(head->val<=pivot){
      head->next=smaller;
      smaller=head;
    }
    //put node in larger
    else{
      head->next=larger;
      larger=head;
    }
    head=NULL;
  }
}


