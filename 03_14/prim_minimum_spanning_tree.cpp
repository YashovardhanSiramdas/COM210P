/*
Author:- Yashovardhan Siramdas
CED16I028

Lab Session 10, 14-03-18

Prim's Minimum Spanning Tree
Input each value of cost matrix as the cost of edge between two nodes.If there is no edge between two nodes,input as -1
*/

#include <iostream>
#include <climits>
using namespace std;

int find_min_edge(int *k, int *l, int n, int c[][1024], int *e)
{
	int min = INT_MAX;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			if(c[i][j] < min)
			{
				min = c[i][j];
				*k = i;
				*l = j;
			}
		}
	*e = *e - 1;
	return min;
}

int new_edge(int c[][1024], int near[], int n, int *e)
{
	int min = INT_MAX, j;
	for(int i = 0; i < n; i++)
	{
		if(near[i] != 0 && c[i][near[i]] < min)
		{
			min = c[i][near[i]];
			j = i;

		}
	}
	*e = *e - 1;
	return j;
}

int main()
{
	int n; //nodes
	cout<<"Enter number of nodes in graph: ";
	cin>>n;   
	int e=n * (n - 1);
	int c[n][1024];  //cost matrix
	cout<<"Enter cost matrix: \n";
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			cin>>c[i][j];
			if(c[i][j] == -1)
			{
				c[i][j] = INT_MAX;
				e--;
			}
		}

	e = e / 2;
			
	int t[n - 1][2];  //output edges
	int near[n];
	int k, l;
	int mincost = 0;
	mincost += find_min_edge(&k, &l, n, c, &e);
	t[0][0] = k;
	t[0][1] = l;

	for(int i = 0; i < n; i++)
	{
		if(c[i][l] < c[i][k])
			near[i] = l;
		else
			near[i] = k;
	}
	near[k] = near[l] = 0;

	int i;
	for(i = 1;i < n - 1, e > 0; i++)
	{
		int j = new_edge(c, near, n, &e);
		t[i][0] = j;
		t[i][1] = near[j];
		mincost += c[j][near[j]];
		near[j] = 0;

		for(int k = 0; k < n; k++)
		{
			if(near[k] != 0 && c[k][near[k]] > c[k][j])
				near[k] = j;
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
