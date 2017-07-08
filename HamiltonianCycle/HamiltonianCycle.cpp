/*
  Problem Definition:
    Hamiltonian Path in an undirected graph is a path that visits each vertex exactly once.
    A Hamiltonian cycle (or Hamiltonian circuit) is a Hamiltonian Path such that 
    there is an edge (in graph) from the last vertex to the first vertex of the Hamiltonian Path.
    Determine whether a given graph contains Hamiltonian Cycle or not. If it contains, 
    then print the path. Following are the input and output of the required function.
  Author:roshan09
  Link:http://www.geeksforgeeks.org/backtracking-set-7-hamiltonian-cycle/
  Type:Backtracking  
*/
#include <bits/stdc++.h>
#define V 5
using namespace std;
int visited[V];
int last,start;
int path[10];

void PrintSolution()
{
    for(int j=0;j<=V;j++)
      cout<<path[j]<<" ";
    cout<<endl; 
}

bool hamCycle(int graph1[V][V],int curr,int move)
{
  if(move==V){
    //cout<<move<<" "<<path[move-1]<<endl;
    path[V]=last;
    if(graph1[path[move-1]][start]==1)    
    return true;
    else
      return false;
  }

  for(int i=0;i<V;i++)
  {
    if(graph1[curr][i]&&(!visited[i])&&i!=start)
    {
    //  cout<<"aaaa"<<i<<endl;
      visited[i]=1;
      path[move]=i;
      //graph1[curr][i]=move;
      if(hamCycle(graph1,i,move+1))
        return true;
      else
      {
          path[move-1]=-1;
        visited[i]=0;
      //  graph1[curr][i]=0;
      }
    }
  }
  return false;
}

 // driver program to test above function
int main()
{
   /* Let us create the following graph
      (0)--(1)--(2)
       |   / \   |
       |  /   \  |
       | /     \ |
      (3)-------(4)    */
   int graph1[V][V] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0},
                     };
 
  memset(visited,0,sizeof(visited));
    last=2;
    start=2;
    visited[start]=0;
   
    path[0]=start;
    if(hamCycle(graph1,start,1)){
      cout<<"Possible"<<endl;
      PrintSolution(  );
    }
    else
      cout<<"Not Possible";
 
   /* Let us create the following graph
      (0)--(1)--(2)
       |   / \   |
       |  /   \  |
       | /     \ |
      (3)       (4)    */
    int graph2[V][V] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 0},
                      {0, 1, 1, 0, 0},
                     };
 
    // Print the solution
    memset(visited,0,sizeof(visited));
    last=2;
    start=2;
    visited[start]=0;
   
    path[0]=start;

    if(hamCycle(graph2,0,0))
    {
      cout<<"Possible"<<endl;
     PrintSolution();     
    }
    else
      cout<<"Not Possible"<<endl;
 
    return 0;
}  
