#include<iostream>
using namespace std;
struct listNode{
	int data;
	listNode * next;
};
int listLength(listNode * head)
{
	int count=0;
	if(!head)
	return 0;
	listNode * temp = head;
	do{
		count++;
		temp=temp->next;
	}while(temp!=head);
	return count;
}
void insertEnd(listNode ** head, int data)
{
	listNode * current = *head;
	listNode* newNode = (listNode *) malloc(sizeof(listNode));
	if(!newNode)
	{
		cout<<"memory error"<<endl;
		return;
	}
	newNode->data =data;
	while(current->next !=*head)
	current = current->next;
	newNode->next = *head;
	current->next = newNode;
}
void insertBeg(listNode ** head, int data)
{
	listNode* newNode = (listNode *) malloc(sizeof(listNode));
	if(!newNode)
	{
		cout<<"memory error"<<endl;
		return;
	}
	
	if(!head)
	{
		*head=newNode;
		newNode->data = data;
		newNode->next=NULL;
	}
	else
	{
		listNode * cur;
		newNode->data = data;
		newNode->next= *head;
		while(cur->next != *head)
		cur = cur->next;
		cur->next = newNode;
		*head = newNode;
	}
}
void deleteEnd(listNode ** head)
{
	listNode * temp, * cur;
	if(!head)
	{
		cout<<"Empty List"<<endl;
		return;
	}
	cur = *head;
	while(cur->next != *head)
	{
		temp = cur;
		cur=cur->next;
	}
	temp->next = cur->next;
	free(cur);
}
void deleteBeg(listNode ** head)
{
	listNode * temp, * cur;
	if(!head)
	{
		cout<<"Empty List"<<endl;
		return;
	}
	temp = *head;
	cur = *head;
	while(cur->next != *head)
	{
		temp = cur;
		cur=cur->next;
	}
	cur->next = temp->next;
	*head = (*head)->next;
	free(temp);
}
int main()
{
	
}
