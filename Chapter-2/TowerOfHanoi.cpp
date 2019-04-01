#include<bits/stdc++.h>
using namespace std;

void tower(int n, char from, char aux, char to)
{
	if(n==1)
	printf("%c to %c\n",from,to);
	else
	{
		tower(n-1, from,to, aux);
		printf("%c to %c\n",from,to);
		tower(n-1,aux, from,to);
	}
}
char s[100];

int main()
{
	int n;
	cin>>n;
	tower(n,'A','B','C');
}
