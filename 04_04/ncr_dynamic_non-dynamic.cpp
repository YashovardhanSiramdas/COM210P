/*
Author:- Yashovardhan Siramdas
CED16I028

Lab Session 12, 04-04-18

Finding nCr in Dynamic and Non-Dynamic approach
*/

#include <iostream>
using namespace std;

int c = 0;

unsigned long long int non_dynamic(int n, int r)
{
	c++;
	if(r == 0 || r == n)
		return 1;
	else
		return non_dynamic(n - 1, r) + non_dynamic(n - 1, r - 1);
}

void dynamic(int n, int r, unsigned long long int a[][50])
{
	c++;
	if(r == 0 || r == n)
		a[n][r] = 1;
	else
	{
		if(a[n - 1][r] == -1)
			dynamic(n - 1, r, a);

		if(a[n - 1][r - 1] == -1)
			dynamic(n - 1 ,r - 1, a);

		a[n][r]=a[n - 1][r] + a[n - 1][r - 1];
	}
	
}

int main()
{
	int n,r;
	cout<<"Enter n: " ;
	cin>>n;
	cout<<"Enter r: " ;
	cin>>r;

	unsigned long long int a[50][50];
	cout<<n<<"C"<<r<<": "<<non_dynamic(n,r)<<endl;
	cout<<"No. of key Operations using Non Dynamic Approach: "<<c<<endl;

	c = 0;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= n; j++)
			a[i][j] = -1;
	dynamic(n,r,a);
	
	cout<<n<<"C"<<r<<": "<<a[n][r]<<endl;
	cout<<"No. of key Operations using Dynamic Approach: "<<c<<endl;
}
