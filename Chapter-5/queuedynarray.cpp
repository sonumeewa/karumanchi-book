#include<iostream>
using namespace std;
struct q{
	int front, rear;
	int capacity;
	int * array;
};

q* createQ(int size)
{
	q* Q = (q*)malloc(sizeof(q));
	if(!Q)
	return NULL;
	Q->capacity = size;
	Q->front = Q->rear = -1;
	Q->array = (int *)malloc(Q->capacity*sizeof(int));
	if(!Q->array)
	{
		return NULL;
	}
	return Q;
}

bool isEmpty(q * Q)
{
	return Q->front == -1;
}

bool isFull(q * Q)
{
	return ((Q->rear+1)%Q->capacity == Q->front);
}

int Qsize(q* Q)
{
	return (Q->capacity - Q->front + Q->rear+ +1)% Q->capacity;
}

void resizeQ(q* Q)
{
	int size = Q->capacity;
	Q->capacity = Q->capacity * 2;
	Q->array = (int *)realloc(Q->array, Q->capacity);
	if(!Q->array)
	{
		cout<<"Memory Error"<<endl;
		return;
	}
	if(Q->front > Q->rear)
	{
		for(int i=0; i < Q->front; i++)
		{
			Q->array[i+size] = Q->array[i];
		}
		Q->rear = Q->rear + size;
	}
}
void enQ(q* Q, int data)
{
	if(isFull(Q))
	cout<<"overflow"<<endl;
	else
	{
		Q->rear = (Q->rear+1)%Q->capacity;
		Q->array[Q->rear] = data;
		if(Q->front == -1)
		{
			Q->front = Q->rear;
		}
	}
}

int deQ(q* Q)
{
	int data = 0;
	if(isEmpty(Q))
	{
		cout<<"underflow\n";
		return 0;
	}
	else
	{
		data = Q->array[Q->front];
		if(Q->front == Q->rear) Q->front = Q->rear-1;
		else Q->front = (Q->front + 1)%Q->capacity;
	}
	return data;
}

void deleteQ(q *Q)
{
	if(Q)
	{
		if(Q->array)
		free(Q->array);
		free(Q);
	}
}
int main()
{
		q* Q = createQ(20);
	cout<<isFull(Q)<<endl;
	enQ(Q,5);
	enQ(Q,19);
	
	cout<<isEmpty(Q)<<endl;
	enQ(Q,6);
	enQ(Q,19);
	enQ(Q,4);
	cout<<isEmpty(Q)<<endl;
	cout<<isFull(Q)<<endl;
	enQ(Q,9);
	enQ(Q,2);
	enQ(Q,1);
	cout<<deQ(Q)<<endl;
	cout<<deQ(Q)<<endl;
	cout<<deQ(Q)<<endl;
	cout<<deQ(Q)<<endl;
	cout<<deQ(Q)<<endl;
	cout<<deQ(Q)<<endl;
	cout<<isEmpty(Q)<<endl;
	cout<<isFull(Q)<<endl;

}
