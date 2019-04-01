#include<iostream>
#define MAXX 100
using namespace std;
struct st{
	int top;
	int capacity;
	int *array;
};

struct st * createStack()
{
	st *s = (st*)malloc(sizeof(st));
	if(!s) return NULL;
	s->capacity = MAXX;
	s->top=-1;
	s->array = (int *)malloc(s->capacity*sizeof(int));
	if(!s->array) return NULL;
	return s;
}
bool isEmpty(st* s)
{
	return s->top == -1;
}

bool isFull(st *s)
{
	return (s->top ==s->capacity -1);
}
void push(st* s, int data)
{
	if(isFull(s))
	cout<<"stack overflow\n";
	else
	{
		s->array[++s->top] = data;
	}
}
int pop(st*s)
{
	if(isEmpty(s))
	cout<<"stack underflow\n";
	else
	return (s->array[s->top--]);
}
int top(st* s)
{
	if(isEmpty(s))
	cout<<"stack underflow\n";
	else
	return s->array[s->top];
}
void deleteStack(st* s)
{
	if(s)
	{
		if(s->array)
		free(s->array);
		free(s);
	}
}
int main()
{
	st * A = createStack();
	push(A, 5);
	push(A,6);
	push(A,10);
	top(A);
	cout<<pop(A);
	cout<<isEmpty(A);
	cout<<isFull(A);
	cout<<pop(A);
	return 0;
}
