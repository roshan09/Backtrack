/*
	Problem Statement:
		Sudoku
	Author: roshan09
	Type :Backtracking	
	
*/
#include <bits/stdc++.h>
using namespace std;
#define uninitialised (int)0
void PrintSolution(int SudokuMatrix[9][9])
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			cout<<SudokuMatrix[i][j]<<" ";
		cout<<endl;
	}
}
bool CheckForColumn(int SudokuMatrix[9][9],int num,int Row,int Column)
{
	for(int i=0;i<9;i++)
	{
		if(SudokuMatrix[Row][i]==num)
			return false;
	}
	return true;
}

bool CheckForRow(int SudokuMatrix[9][9],int num,int Row,int Column)
{
	for(int i=0;i<9;i++)
	{
		if(SudokuMatrix[i][Column]==num)
			return false;
	}
	return true;
}

bool CheckForBox(int SudokuMatrix[9][9],int num,int Row,int Column)
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(SudokuMatrix[Row+i][Column+j]==num)
				return false;
		}
	}
	return true;
}

bool safe(int SudokuMatrix[9][9],int num,int Row,int Column)
{
	if(CheckForColumn(SudokuMatrix,num,Row,Column))
		if(CheckForRow(SudokuMatrix,num,Row,Column))
			if(CheckForBox(SudokuMatrix,num,Row-Row%3,Column-Column%3))
				return true;
	return false;		
}
bool AllFound(int SudokuMatrix[9][9],int &i,int &j)
{
	for(i=0;i<9;i++)
	{	
		for(j=0;j<9;j++)
			if(SudokuMatrix[i][j]==uninitialised)
				return false;
	}
	return true;
}
bool SudokuSolution(int SudokuMatrix[9][9])
{ 	
	int row,Column;
	if(AllFound(SudokuMatrix,row,Column))
		return true;

	for(int i=1;i<=9;i++)
	{
		if(safe(SudokuMatrix,i,row,Column))
		{
			SudokuMatrix[row][Column]=i;
			if(SudokuSolution(SudokuMatrix))
			{
				return true;
			}	
			else
			{
				SudokuMatrix[row][Column]=uninitialised;
			}
		}
	}
	return false;
}
int main()
{
 int SudokuMatrix[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
  if(SudokuSolution(SudokuMatrix))
  {
  	cout<<"Solution Exist"<<endl;
  	PrintSolution(SudokuMatrix);
  }
  else
  {
  	cout<<"Solution Does nnot Exist"<<endl;
  }                    
}