/*
Author:- Yashovardhan Siramdas
CED16I028

Lab Session 13, 11-04-18

Bellman-Ford Algorithm and Detecttion of Negative Cycle. Input:- Adjacency Matrix. Input 100 if there is no edge between two nodes.
*/

#include <iostream>
#include <climits>
using namespace std;

#define MAX 100

int main()
{
	int n, v;
	cout<<"Enter number of Nodes in Graph: ";
	cin>>n;

	int c[n][1024];
	cout<<"Enter cost matrix\n";
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin>>c[i][j];
			if(c[i][j] == MAX)
				c[i][j] = INT_MAX;
		}
	}

	cout<<"Enter Source Node: ";
	cin>>v;

	int d[n];
	for(int i = 0; i < n; i++)
		d[i] = INT_MAX;
	d[v] = 0;

	int iterations = n - 1;

	while(iterations--)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(c[i][j] != INT_MAX && d[i] != INT_MAX && d[j] > d[i] + c[i][j])
				{
					d[j] = d[i] + c[i][j];
				}
			}
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(c[i][j] != INT_MAX && d[i] != INT_MAX && d[j] > d[i] + c[i][j])
			{
				cout<<"Negative weight cycle exists\n";
				return 0;
			}
		}
	}

	cout<<"Distance of each node from Source Vertex:-\n";
	for(int i = 0; i < n; i++)
		cout<<d[i]<<" ";
	cout<<endl;
}
