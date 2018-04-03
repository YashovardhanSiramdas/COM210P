/*
Author:- Yashovardhan Siramdas
CED16I028

Lab Session 9, 07-03-18

Kruskal's Minimum Spanning Tree
Input each value of cost matrix as the cost of edge between two nodes.If there is no edge between two nodes,input as -1
*/

#include <iostream>
#include <climits>

using namespace std;

int del_min_cost(int *u, int *v, int c[][1024], int n, int *e)
{
	int min = INT_MAX;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(c[i][j] < min && c[i][j] != -1)
			{
				min = c[i][j];
				*u = i;
				*v = j;
			}
		}
	}
	c[*u][*v] = -1;
	*e = *e - 1;
	return min;
}

int find(int n, int parent[], int i)
{
	while(parent[i] >= 0)
		i = parent[i];
	return i;
}

void Union(int n, int parent[], int j, int k)
{
	int temp = parent[j] + parent[k];
	if(parent[j] > parent[k])
	{
		parent[j] = k;
		parent[k] = temp;
	}
	else
	{
		parent[k] = j;
		parent[j] = temp;	
	}
}

int main()
{
	int n; //nodes
	int e = 0;
	cout<<"Enter number of nodes in graph: ";
	cin>>n;   

	int c[n][1024];  //cost matrix
	cout<<"Enter cost matrix: \n";
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			cin>>c[i][j];
			if(c[i][j] != -1)
				e++;
		}

	e = e / 2;
	int t[n - 1][2];  //output edges
	int parent[n];
	for(int i = 0; i < n; i++)
		parent[i] = -1;
	
	int mincost = 0;
	int u, v, j, k;
	int i = 0;
	while(i < n - 1 && e > 0)
	{
		int min = del_min_cost(&u, &v, c, n, &e);
		j = find(n, parent, u);
		k = find(n, parent, v);
		if(j != k)
		{
			
			t[i][0] = u;
			t[i][1] = v;
			i++;
			mincost += min;
			Union(n, parent, j, k);
		}
	}
	
	if(i != n - 1)
		cout<<"There is no spanning tree\n";
	else
	{
		cout<<"MST:-\n";
		for(int i = 0; i<n - 1; i++)
		{
			cout<<t[i][0]+1<<"   "<<t[i][1]+1<<"\n";
		}
		cout<<"Mincost: "<<mincost<<endl;
	}
}
