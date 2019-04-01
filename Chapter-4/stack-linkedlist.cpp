#include<iostream>
using namespace std;
struct st{
	int data;
	struct st * next;
};

struct st * createStack()
{
	return NULL;
}
void push(st **top, int data)
{
	struct st* temp;
	temp = (st* )malloc(sizeof(st));
	if(!temp) return;
	temp->data = data;
	temp->next = *top;
	*top = temp;
}
bool isEmpty(st* top)
{
	return top==NULL;
}
int pop(st **top)
{
	int data;
	st* temp;
	if(isEmpty(*top))
	return INT_MIN;
	temp = *top;
	*top = (*top)->next;
	data = temp->data;
	free(temp);
	return data;
}
int top(st* top)
{
	if(isEmpty(top))
	return INT_MIN;
	return top->data;
}
void deleteStack(st **top)
{
	st* temp,*p;
	p = *top;
	while(p->next)
	{
		temp = p->next;
		p->next = temp->next;
		free(temp);
	}
	free(p);
}
int main()
{
	st *A =createStack();
	push(&A,5);
	push(&A,6);
	push(&A,9);
	push(&A,10);
	cout<<top(A);
	pop(&A);
	delete(A);
}
