/*
Author:- Yashovardhan Siramdas
CED16I028

Lab Session 14, 18-04-18

0-1 Knapsack using Brute Force
*/

#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int main()
{
	int n;
	cout<<"Enter Number of objects: ";
	cin>>n;

	int w[n], p[n];
	cout<<"Enter weights of "<<n<<" objects\n";
	for(int i = 0; i < n; i++)
		cin>>w[i];

	cout<<"Enter prices of "<<n<<" objects\n";
	for(int i = 0; i < n; i++)
		cin>>p[i];

	int m;
	cout<<"Enter Knapsack capacity: ";
	cin>>m;

	int itr = pow(2, n);
	int weight[itr] = {0};
	int price[itr] = {0};
	itr--;

	while(itr >= 0)
	{
		int i = n - 1;
		int b[n] = {0};
		int beq = itr;
		while(beq >= 1)
		{
			int x = beq % 2;
			b[i] = x;
			i--;
			beq = beq / 2;
		}
		
		for(int j = 0; j < n; j++)
		{
			weight[itr] += w[j] * b[j];
			price[itr] += p[j] * b[j];
			
		}
		itr--;
	}

	int maxprice = INT_MIN;
	for(int i = 0; i < pow(2, n); i++)
	{
		if(weight[i] <= m && price[i] >= maxprice)
			maxprice = price[i];
	}
	cout<<"Max Profit: "<<maxprice<<endl;
}
