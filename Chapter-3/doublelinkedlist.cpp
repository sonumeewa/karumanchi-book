#include<iostream>
using namespace std;
struct listNode{
	int data;
	listNode * next;
	listNode * prev;
};
void insert(listNode ** head, int data, int position)
{
	int k=1;
	listNode *newNode = (listNode *)malloc(sizeof(listNode));
	listNode * p=*head,*q;
	newNode->data = data;
	if(position==1)
	{
		newNode->prev = NULL;
		if(*head)
		newNode->next = *head;
		*head = newNode;	
	}
	else
	{
		while((k<position)&& p->next!=NULL)
		{
			p= p->next;
		}
		if(k!=position)
		{
			cout<<"position does not exist"<<endl;
			return;
		}
		else
		{
			newNode->next = p->next;
			p->next = newNode;
			newNode->prev = p;
			if(newNode->next)
			newNode->next->prev = newNode;
		}
	}
}

void deleteNode(listNode ** head,int position)
{
	int k=1;
	listNode *temp;
	listNode * p=*head,*q;
	if(!head)
	{
	cout<<"EMPTY LIST"<<endl;
	return;
	}
	if(position==1)
	{
		temp=*head;
		(*head)->next->prev = NULL;
		*head = (*head)->next;
		free(temp);
	}
	else
	{
		while((k<position)&& p->next!=NULL)
		{
			p= p->next;
		}
		if(k!=position)
		{
			cout<<"position does not exist"<<endl;
			return;
		}
		else
		{
			temp = p->prev;
			temp->next = p->next;
			if(p->next)
			p->next->prev = temp;
			free(p);
		}
	}
}
int main()
{
	
}
