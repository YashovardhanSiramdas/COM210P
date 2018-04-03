/*
Author:- Yashovardhan Siramdas
CED16I028

Lab Session 11, 28-03-18

Dijkstra's Shortest path Algorithm
Input each value of cost matrix as the cost of edge between two nodes.If there is no edge between two nodes,input as -1
*/

#include <iostream>
#include <climits>
using namespace std;

int find_node(int n,bool s[],int d[])
{
	int u, min = INT_MAX;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == 0 && d[i] < min)
		{
			u = i;
			min = d[i];
		}
	}
	return u;
}

int main()
{
	int n, v; //nodes
	cout<<"Enter number of Nodes in graph: ";
	cin>>n;   
	int c[n][1024];  //cost matrix

	cout<<"Enter Cost Matrix: \n";
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			cin>>c[i][j];
			if(c[i][j] == -1)
			{
				c[i][j] = INT_MAX;
			}
		}

	cout<<"Enter Source Node: ";
	cin>>v;
	v--;
	bool s[n];
	int d[n];

	for(int i = 0; i < n; i++)
	{
		s[i] = 0;
		d[i] = c[v][i];
	}
	s[v] = 1;
	d[v] = 0;
	
	for(int i = 1;i < n - 1; i++)
	{
		int u = find_node(n, s, d);
		s[u] = 1;

		for(int w = 0; w < n; w++)
		{
			if(s[w] == 0 && c[u][w] != INT_MAX)
			{
				if(d[w] > d[u] + c[u][w])
					d[w] = d[u] + c[u][w];
			}
		}

	}
	cout<<"Distance of each Node from Source Node:-\n";
	for(int i = 0; i < n; i++)
		cout<<d[i]<<"  ";
	cout<<endl;
}
