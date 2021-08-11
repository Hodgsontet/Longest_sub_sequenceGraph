#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;  

int s = 8;
int A[8] =  {-7,10,9,2,3,8,8,1};

int mat[8][8];


int main()
{   int inDegree[8];
	int LIS[8];
  memset(mat, 0, sizeof mat);
	memset(inDegree, 0, sizeof inDegree);
	memset(LIS, 0, sizeof LIS);

// initialize matrix	

	for (int i = 0; i <s; ++i)
	{
		for (int j = i+1; j < s; ++j)
		{
			if (A[j]>A[i])
			{
				mat[i][j] = 1;
			}
		}
	}
 
 // creeate indrgree array

for (int i = 0; i <s; ++i)
	{
		for (int j = 0; j < s; ++j)
		{
			if (mat[j][i]==1)
			{
				inDegree[i] = inDegree[i]+1;
			}
		}
	}    
/// initial indegree
cout<<'\n';
for (int j = 0; j < s; ++j)
		{
			cout<<inDegree[j];
		}

cout<<'\n';
cout<<'\n';
/////////////////////////


//////////// calculate the LIS
for (int i = 0; i <s; ++i)
	{
		if (inDegree[i]==0)
		{
		       	inDegree[i]= -1;
		      //find all edges from that node going out and update those vertices
		      for (int j = 0; j < s; ++j)
		   {
			      if (mat[i][j] == 1)
			         {
				           inDegree[j] = inDegree[j]-1;
				           LIS[j] = max(LIS[j],1+LIS[i]);
			        }
		   }
		

		}
		
	}

//////////////////////////////
	for (int i = 0; i <s; ++i)
	{
		for (int j = 0; j < s; ++j)
		{
			cout<<mat[i][j];
		}
		cout<<'\n';
	}
cout<<'\n';cout<<'\n';cout<<'\n';
cout<<"indegree array  ---";
	for (int j = 0; j < s; ++j)
		{
			cout<<inDegree[j];
		}

	cout<<'\n';
	cout<<"LIS  ---";
	for (int j = 0; j < s; ++j)
		{
			cout<<LIS[j];
		}

	return 0;
}





///////you should also implement it with a adjacency list to reduce time complexity;