/*
Author:- Yashovardhan Siramdas
CED16I028

Lab Session 12, 04-04-18

Finding nth Fibonacci Number in Dynamic and Non-Dynamic approach
*/

#include <iostream>
using namespace std;

int c = 0;

unsigned long long int non_dynamic(int n)
{
	c++;
	if(n == 1 || n == 2)
		return 1;
	else
		return non_dynamic(n - 1) + non_dynamic(n - 2);
}

void dynamic(int n, unsigned long long int a[])
{
	c++;
	if(n == 1 || n == 2)
		a[n] = 1;
	else
	{
		if(a[n - 1] == -1)
			dynamic(n - 1, a);
		if(a[n - 2] == -1)
			dynamic(n - 2, a);
		a[n] = a[n - 1] + a[n - 2];
	}
	
}

int main()
{
	int n;
	cout<<"Enter n: " ;
	cin>>n;

	unsigned long long int a[n];
	cout<<"F("<<n<<") : "<<non_dynamic(n)<<endl;
	cout<<"No. of key Operations using Non Dynamic Approach: "<<c<<endl;

	c = 0;
	for(int i = 0; i <= n; i++)
		a[i] = -1;
	dynamic(n, a);
	cout<<"F("<<n<<") : "<<a[n]<<endl;
	cout<<"No. of key Operations using Dynamic Approach: "<<c<<endl;
}
