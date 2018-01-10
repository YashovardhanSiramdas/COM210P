/*
Author:- Yashovardhan Siramdas
CED16I028

Lab Session 2, 10-01-18
Find the smallest value of "n" such that an Algorithm which takes 100(n^2) run time is faster than the Algorithm
which takes 2^n run time
*/

#include <iostream>
#include <cmath>

using namespace std;

class comparisions
{
	public:		
		int function1(int i);
		int function2(int i);
};

int comparisions::function1(int i)
{
	return (100 * i * i);
}

int comparisions::function2(int i)
{
	return (pow(2, i));
}

int main()
{
	comparisions obj;
	int i;
	cout<<"Smallest Value of n for which 100*(n^2) is less than 2^n is:- ";
	for (i = 2; ; i++)
	{
		if (obj.function1(i) < obj.function2(i))
		{
			cout<<i<<"\n";
			return (0);
		}
	}
}
