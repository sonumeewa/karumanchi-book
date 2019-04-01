#include<iostream>
using namespace std;
struct st{
	char data;
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
	char data;
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
int prec(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 
int main()
{
	string s,ns;
	cin>>s;
	int l = s.length();
	st * A = createStack();
	push(&A,'N');
	for(int i = 0; i < l; i++) 
    { 
        // If the scanned character is an operand, add it to output string. 
        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z')) 
        ns+=s[i]; 
  
        // If the scanned character is an ‘(‘, push it to the stack. 
        else if(s[i] == '(') 
          
        push(&A,'('); 
          
        // If the scanned character is an ‘)’, pop and to output string from the stack 
        // until an ‘(‘ is encountered. 
        else if(s[i] == ')') 
        { 
            while(top(A) != 'N' && top(A) != '(') 
            { 
                char c = top(A); 
                pop(&A); 
               ns += c; 
            } 
            if(top(A) == '(') 
            { 
                char c = top(A); 
                pop(&A); 
            } 
        } 
          
        //If an operator is scanned 
        else{ 
            while(top(A) != 'N' && prec(s[i]) <= prec(top(A))) 
            { 
                char c = top(A); 
                pop(&A); 
                ns += c; 
            } 
            push(&A,s[i]); 
        } 
  
    } 
    //Pop all the remaining elements from the stack 
    while(top(A) != 'N') 
    { 
        char c = top(A); 
        pop(&A); 
        ns += c; 
    } 
      
    cout << ns << endl; 
  
}
