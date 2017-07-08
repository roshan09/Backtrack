/*
	Problem Definition:	
		The knight is placed on the first block of an empty board and, 
		moving according to the rules of chess, must visit each square exactly once.
		Knight(ghoda) 
	Author:roshan09
	link:http://www.geeksforgeeks.org/backtracking-set-1-the-knights-tour-problem/
	Type:Backtracking
	Description:
		Find a path such that total number of moves become 64, i.e find a path such that all the 
		places should be visited exactly 1,so total Number of moves is 64  
		Check all possible permutations 
*/
#include <bits/stdc++.h>
using namespace std;
#define size 8
int arr[size][size];
int xMove[size] = {  2, 1, -1, -2, -2, -1,  1,  2 }; // array to move knight(ghoda)
int yMove[size] = {  1, 2,  2,  1, -1, -2, -2, -1 }; 
void PrintSolution()
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
}
bool safe(int x,int y)
{
	if(x<0||x>(size-1)||y<0||y>(size-1))
		return false;
	if(arr[x][y]!=-1)
		return false;
	return true;
}
bool FindAll(int x,int y,int CurrMove)
{
	if(CurrMove==int(size)*int(size))
		return true;

	for(int i=0;i<size;i++)
	{
		int t1=x+xMove[i];
		int t2=y+yMove[i];
		if(safe(t1,t2))
		{
			arr[t1][t2]=CurrMove;
			if(FindAll(t1,t2,CurrMove+1))
				return true;
			else
				arr[t1][t2]=-1;
		}
	}
	return false;
}
int main()
{
	memset(arr,-1,sizeof(arr));
	arr[0][0]=0;
	if(FindAll(0,0,1))
		PrintSolution();
	else
		cout<<"Not possible "<<endl;
}