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
int main()
{
	
}
