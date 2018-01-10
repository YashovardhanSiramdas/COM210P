#include <iostream>
#include <cmath>
using namespace std;

class comparisions
{
	public:		
		unsigned long long int function1(unsigned long long int i);
		unsigned long long int function2(unsigned long long int i);
};

unsigned long long int comparisions::function1(unsigned long long int i)
{
	return (100 * i * i);
}

unsigned long long int comparisions::function2(unsigned long long int i)
{
	return pow(2,i);
}

int main()
{
	comparisions obj;
	unsigned long long int i;
	cout<<"Smallest Value of n for which 100*n^2 is less than 2^n is:- \n";
	for (i = 2; ; i++)
	{
		if (obj.function1(i) < obj.function2(i))
		{
			cout<<i<<"\n";
			return 0;
		}
	}

	return (0);
}