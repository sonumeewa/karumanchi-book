#include<bits/stdc++.h>
using namespace std;

void kstrings(int n, char s[])
{
	if(n<1)
	cout<<s<<endl;
	else
	{
	s[n-1]='0';
	kstrings(n-1, s);
	s[n-1]='1';
	kstrings(n-1, s);
	}
}
char s[100];

int main()
{
	long long int n,q;
	cin>>n;
	kstrings(n,s);
}
