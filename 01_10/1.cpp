/*
Author:- Yashovardhan Siramdas
CED16I028

Lab Session 2, 10-01-18
Finding the values of n(input size) for which insertion sort beats merge sort
*/

#include <iostream>
#include <cmath>

using namespace std;

class comparisions
{
	public:		
		int insertion_sort(int i);
		int merge_sort(int i);
};

int comparisions::insertion_sort(int i)
{
	return (8 * i * i);
}

int comparisions::merge_sort(int i)
{
	return (64 * i * log(i) / log(2));
}

int main()
{
	comparisions obj;
	int i;
	cout<<"Values of n for which Insertion sort beats Merge Sort:- \n";
	for (i = 2; ; i++)
	{
		if (obj.insertion_sort(i) < obj.merge_sort(i))
			cout<<i<<" ";
		else
		{
			cout<<endl;
			break;
		}
	}

	return (0);
}
