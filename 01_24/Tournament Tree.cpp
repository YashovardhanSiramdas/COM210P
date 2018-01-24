/*
Author:- Yashovardhan Siramdas
CED16I028

Lab Session 4, 24-01-18
Tournament Tree
Find Min,Max in exactly (3*N)/2 comparisions where N is size of the array.N is in the form 2^k
*/

#include <iostream>
using namespace std;

class Tournament
{
	private:

	int a[64], size;

	public:

		void size_init();
		void read();
		void minmax();

};

void Tournament::size_init()
{
	cout<<"Enter size of array(Should be in the form 2^k)\n";
	cin>>size;
}

void Tournament::read()
{
	cout<<"Enter "<<size<<" Integers\n";
	for (int i = 0; i < size; i++)
		cin>>a[i];
}

void Tournament::minmax()
{
	int i = 0;
	int minc = size, maxc = 0;;
	while (i < size)
	{
		if (a[i] < a[i + 1])
		{
			a[minc] = a[i];
			minc++;
			a[maxc] = a[i + 1];
			maxc++;
		}
		else
		{
			a[minc] = a[i + 1];
			minc++;
			a[maxc] = a[i];
			maxc++;
		}
		i=i+2;
	}

	int max1 = maxc;
	while (maxc != 1)
	{
		int counter = 0;
		for (i = 0; i <maxc; i = i + 2)
		{
			if (a[i] < a[i + 1])
			{
				a[counter] = a[i + 1];
				counter++;
			}
			else
			{
				a[counter] = a[i];
				counter++;
			}
		}
		maxc = maxc / 2;
	}
	cout<<"Max: "<<a[0]<<endl;
	

	int j = 0;
	for( i =size; i < minc; i++)
	{
		a[j] = a[i];
		j++;
	}

	while (max1 != 1)
	{
		int counter = 0;
		for (i = 0; i < max1; i = i + 2)
		{
			if (a[i] > a[i + 1])
			{
				a[counter] = a[i + 1];
				counter++;
			}
			else
			{
				a[counter] = a[i];
				counter++;
			}
		}
		max1 = max1 / 2;
	}
	cout<<"Min: "<<a[0]<<endl;
}

int main()
{
	Tournament T;
	T.size_init();
	T.read();
	T.minmax();

	return (0);
}
