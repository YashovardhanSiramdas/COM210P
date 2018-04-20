/*
Author:- Yashovardhan Siramdas
CED16I028

Lab Session 14, 18-04-18

Subset Sum using Brute Force
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cout<<"Enter Array Size: ";
	cin>>n;

	int a[n];
	cout<<"Enter "<<n<<" positive integers\n";
	for(int i = 0; i < n; i++)
		cin>>a[i];

	int t;
	cout<<"Enter Sum: ";
	cin>>t;

	int itr = pow(2, n);
	itr--;
	int f=0;

	while(itr >= 0)
	{
		int i = n-1;
		int b[n] = {0};
		int beq = itr;
		while(beq >= 1)
		{
			int x = beq % 2;
			b[i] = x;
			i--;
			beq = beq / 2;
		}

		int sum = 0;
		for(int j = 0; j < n; j++)
		{
			sum += a[j] * b[j];
		}
		if(sum == t)
		{
			f = 1;
			cout<<"Output Vector: ";
			for(int j = 0; j < n; j++)
			{
				cout<<b[j]<<" ";
			}
			cout<<endl;
		}
		itr--;
	}

	if(f == 0)
		cout<<"No Solution found\n";
}