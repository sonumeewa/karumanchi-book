#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct sll {
  int data;
  struct sll *next;
}sll;
void insert (sll **head, int data, int pos){
  sll *newNode = NULL, *temp=*head, *curr = NULL;
  int k = 1;
  newNode = (sll*) malloc (sizeof(sll));
  newNode->data = data;
  newNode->next = NULL;
  if (pos == 1){
    newNode->next = *head;
    *head = newNode;
    return;
  }

  while ((temp != NULL) && (k < pos - 1)){
    temp = temp->next;
    k ++;
  }

  newNode->next = temp->next;
  temp->next = newNode;
  return;
}

void printsll (sll **head){
  sll *temp = *head;
  while (temp != NULL){
    cout<<temp->data<<"->";
    temp = temp->next;
  }

}

sll * nthnode(sll **head)
{
	
}
int main()
{
    sll * head = NULL;
    insert(&head,8,1);
    insert(&head, 9,2);
    insert(&head, 10,3);
    insert(&head, 6,4);
    insert(&head, 5,5);
    insert(&head, 3,6);
    printsll(&head);
}
