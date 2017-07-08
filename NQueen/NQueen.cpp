/*
	Problem Definition:	
		The N Queen is the problem of placing N chess queens 
		on an N×N chessboard so that no two queens attack each other.
	Author:roshan09
	link:http://www.geeksforgeeks.org/backtracking-set-3-n-queen-problem/
	Type:Backtracking
	Description:

*/
#include <bits/stdc++.h>
using namespace std;
#define N 4
void PrintSolution(int arr[N][N])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
}
bool safe(int arr[N][N],int i,int j)
{
	int x=i;int y=j;
	while(i>=0&&j>=0)
	{
		if(arr[i][j])
			return false;
		i--,j--;
	}
	int k=x,l=y;
	while(y>=0&&x<4)
	{

		if(arr[x][y])
			return false;
		x++,y--;
	}
	while(l>=0)
	{
		if(arr[k][l])
			return false;
		l--;
	}
//	cout<<"aaa";
	return true;
}
bool Plot(int arr[N][N],int j)
{
	if(j==4)
		return true;
	for(int i=0;i<4;i++)
	{
		if(safe(arr,i,j))
		{
			arr[i][j]=1;
			if(Plot(arr,j+1))
			return true;	
			else
				arr[i][j]=0;
		}
	}
	return false;
}
int main()
{
	int arr[N][N]  =  { {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
 
	if(Plot(arr,0))
		PrintSolution(arr);
	else
		cout<<"Not possible"<<endl;

	return 0;
}