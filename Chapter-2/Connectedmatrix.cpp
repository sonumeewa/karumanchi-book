#include<bits/stdc++.h>
using namespace std;

int getval(int arr[][100],int i, int j, int R, int C)
{
	if(i>R || i<0   || j<0 || j>C)
	return 0;
	return arr[i][j];
}

void findSize(int arr[][100], int i, int j, int R, int C, bool count[][100],int size, int &maxsize)
{
	if( i>R || j>C)
	return;
	count[i][j] = true;
	size++;
	if(size > maxsize)
	maxsize =size;
	
	int dir[][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,0},{1,-1},{1,1}};
	for( int r=0; r<8; r++)
	{
		int newi = i + dir[r][0];
		int newj = j + dir[r][1];
		int val = getval(arr, newi, newj, R,C);
	if(val==1 && count[newi][newj] == false )
		findSize(arr , newi, newj, R,C, count,size, maxsize);
	}
	 count[i][j] = false;
	
	
}

int Maxsize(int arr[][100], int R, int C)
{
	int maxsize=0;
	bool count[100][100];
	for(int i=0; i<R; i++)
	{
		for(int j=0; j<C; j++)
		{
			if(arr[i][j] ==1)
			findSize(arr, i, j, R, C,count,0, maxsize);
		}
	}
	return maxsize;
}

int main()
{
	int R,C;
	cin>>R>>C;
	int arr[100][100];
	for(int i=0; i<R; i++)
	{
		for(int j=0; j<C; j++)
		{
			cin>>arr[i][j];
		}
	}
	cout<<Maxsize(arr,R,C)<<endl;
}
