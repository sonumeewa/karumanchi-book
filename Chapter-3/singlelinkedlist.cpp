#include<iostream>
using namespace std;
struct listNode{
	int data;
	listNode * next;
};
int listLength(listNode * head)
{
	int count =0;
	listNode * p = head;
	while(p!=NULL)
	{
		p = p->next;
		count++;
		cout<<p->data;
	}
	return count;
}
void insert(listNode ** head, int data, int position)
{
	int k=1;
	listNode* newNode = (listNode *)malloc(sizeof(listNode));
	newNode->data = data;
	newNode->next = NULL;
	listNode* p = *head;
	listNode*q = NULL;
	if(k==1)
	{
		newNode->next = *head;
		*head = newNode;
	}
	else{
		while((k<position) && p!=NULL)
		{
			k++;
			q = p;
			p = p->next;
		}
		q->next = newNode;
		newNode->next = p;
	}
}
void deleteNode(listNode ** head, int position)
{
	int k=1;
	listNode* temp;
	listNode* p = *head;
	listNode*q = NULL;
	if(!head)
	{
		cout<<"EMPTY LIST"<<endl;
		return;
	}
	if(position==1)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	else{
		while((k<position) && p!=NULL)
		{
			k++;
			q = p;
			p = p->next;
		}
		if(k!=position)
		{
		cout<<"position does not exist"<<endl;
		return;
		}
		q->next = p->next;
		free(p);
	}
}
void deleteList(listNode **head)
{
	listNode * aux, *itr;
	itr=*head;
	while(itr)
	{
		aux = itr->next;
		free(itr);
		itr = aux;
	}
	*head=NULL;
}
int main()
{
	
}
