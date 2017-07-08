/*
	Problem Definition:	
A Maze is given as N*N binary matrix of blocks where source block is the upper left most block i.e., 
maze[0][0] and destination block is lower rightmost block i.e., maze[N-1][N-1]. 
A rat starts from source and has to reach destination. 
The rat can move only in two directions: forward and down.
In the maze matrix, 0 means the block is dead end and 1 means the block can be used in the path from source to destination.
Note that this is a simple version of the typical Maze problem. For example, 
a more complex version can be that the rat can move in 4 directions and a more complex version can be with limited number of moves.
	
	Author:roshan09
	link:http://www.geeksforgeeks.org/backttracking-set-2-rat-in-a-maze/
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
	if(i<0||i>3||j<0||j>3)
		return false;
	if(!arr[i][j])
		return false;
	return true;
}
bool FindPath(int arr[N][N],int i,int j)
{
	if(i==(N-1)&&j==(N-1)){
		arr[i][j]=5;
		return true;
	}
	if(safe(arr,i+1,j))
	{
		if(FindPath(arr,i+1,j))
		{
			arr[i][j]=5;
			return true;
		}
		else
			arr[i][j]=1;
	}
	if(safe(arr,i,j+1))
	{
		if(FindPath(arr,i,j+1))
		{
			arr[i][j]=5;
			return true;
		}
		else
			arr[i][j]=1;
	}

return false;
}
int main()
{
	int arr[N][N]  =  { {1, 1, 0, 0},
        {0, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
 
	if(FindPath(arr,0,0))
		PrintSolution(arr);
	else
		cout<<"Not possible"<<endl;

	return 0;
}