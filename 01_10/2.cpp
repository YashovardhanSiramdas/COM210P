/*
Author:- Yashovardhan Siramdas
CED16I028

Lab Session 2, 10-01-18
Given different f(n)'s and t's, assuming Algorithm takes f(n) seconds to run, find maximum possible values of n
for which f(n) seconds will not exceed respective t. 
*/

#include <iostream>
#include <cmath>

using namespace std;

#define SEC 1
#define MIN 60
#define HOUR 60*60
#define DAY 60*60*24
#define MONTH 60*60*24*30
#define YEAR 60*60*24*30*365
#define CENTURY 60*60*24*30*365*100

void n_square(unsigned long long int a[6]);
void n_cube(unsigned long long int a[6]);
void two_n(unsigned long long int a[6]);
void n_factorial(unsigned long long int a[6]);
unsigned long long int fact(unsigned long long int x);

int main()
{
	unsigned long long int a[6];
	a[0] = SEC, a[1] = MIN, a[2] = HOUR, a[3] = DAY, a[4] = MONTH, a[5] = YEAR;
	n_square(a);
	n_cube(a);
	two_n(a);
	n_factorial(a);

	return (0);
}

void n_square(unsigned long long int a[6])
{
	unsigned long long int n;
	cout<<"n^2\t";
	for (int i = 0; i < 6; i++)
	{
		n = sqrt(a[i]);
		cout<<n<<" ";
	}
	cout<<endl;
}

void n_cube(unsigned long long int a[6])
{
	unsigned long long int n;
	cout<<"n^3\t";
	for (int i = 0; i < 6; i++)
	{
		n = cbrt(a[i]);
		cout<<n<<" ";
	}
	cout<<endl;
}

void two_n(unsigned long long int a[6])
{
	unsigned long long int n;
	cout<<"2^n\t";
	for (int i = 0; i < 6; i++)
	{
		n = log(a[i]) / log(2);
		cout<<n<<" ";
	}
	cout<<endl;
}

void n_factorial(unsigned long long int a[6])
{
	unsigned long long int n, x = 1;
	cout<<"n!\t";
	for (int i = 0; i < 6; i++)
	{
		n = a[i];

		while (fact(x) < n)
			x++;

		cout<<x - 1<<" ";
		x=1;
	}
	cout<<endl;
}

unsigned long long int fact(unsigned long long int x)
{
	if (x == 1)
		return (x);

	unsigned long long int s = 1;
	while (x > 1)
	{
		s = s * x * (x - 1);
		x = x - 2;
	}
	return (s);
}
