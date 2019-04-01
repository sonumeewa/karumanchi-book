#include<iostream>
#define MAXX 100
using namespace std;
struct dst{
	int top;
	int capacity;
	int *array;
};

struct dst * createStack()
{
	dst *s = (dst*)malloc(sizeof(dst));
	if(!s) return NULL;
	s->capacity = 1;
	s->top=-1;
	s->array = (int *)malloc(s->capacity*sizeof(int));
	if(!s->array) return NULL;
	return s;
}
bool isEmpty(dst* s)
{
	return s->top == -1;
}

bool isFull(dst *s)
{
	return (s->top ==s->capacity -1);
}
void doubleStack(dst *s)
{
	s->capacity = 2*s->capacity;
	s->array = (int *)realloc(s->array, s->capacity);
}
void push(dst* s, int data)
{
	if(isFull(s))
	doubleStack(s);
	else
	{
		s->array[++s->top] = data;
	}
}
int pop(dst*s)
{
	if(isEmpty(s))
	cout<<"stack underflow\n";
	else
	return (s->array[s->top--]);
}
int top(dst* s)
{
	if(isEmpty(s))
	cout<<"stack underflow\n";
	else
	return s->array[s->top];
}
void deleteStack(dst* s)
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
	dst * A = createStack();
	push(A, 5);
	push(A,6);
	push(A,10);
	push(A,6);
	push(A,10);
	push(A,6);
	push(A,10);
	push(A,6);
	push(A,10);
	push(A,6);
	push(A,10);
	push(A,6);
	push(A,10);
	push(A,6);
	push(A,10);
	cout<<A->capacity;
	top(A);
	cout<<pop(A);
	cout<<isEmpty(A);
	cout<<isFull(A);
	cout<<pop(A);
	return 0;
}
