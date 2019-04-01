#include<iostream>
using namespace std;
struct listNode{
	int data;
	listNode* next;
};

struct q{
	listNode *front;
	listNode *rear;
};

q* createQ(){
	struct q* Q;
	struct listNode *temp;
	Q = (q*) malloc(sizeof(q));
	if(!Q)
	cout<<"memory bhar gayi hai"<<endl;
	temp = (listNode *)malloc(sizeof(listNode));
	Q->front = Q->rear = NULL;
	return Q;
}
bool isEmpty(q* Q)
{
	return Q->front==NULL;
}

void enQ(q* Q, int data)
{
	struct listNode * newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	if(!newNode)
	return;
	newNode->data = data;
	newNode->next = NULL;
	if(Q->rear)
	Q->rear->next = newNode;
	Q->rear = newNode;
	if(Q->front ==NULL)
	Q->front = Q->rear;
}
int deQ(q* Q)
{
	int data =0;
	listNode* temp;
	if(isEmpty(Q))
	{
		cout<<"underflow"<<endl;
		return 0;
	}
	else
	{
		temp = Q->front;
		data = Q->front ->data;
		Q->front = Q->front->next;
		free(temp);
	}
	return data;
}
void deleteQ(q* Q)
{
	listNode* temp;
	
	while(Q)
	{
		temp = Q->front;
		Q->front = temp->next;
		free(temp);
	}
	free(Q);
}
int main()
{
	q* Q = createQ();
	enQ(Q, 1);
	enQ(Q, 2);
	enQ(Q, 3);
	enQ(Q, 4);
	enQ(Q, 5);

  cout<<"\nDeQueue:"<<deQ(Q)<<endl;

	
}
