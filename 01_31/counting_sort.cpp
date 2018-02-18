/*
Author:- Yashovardhan Siramdas
CED16I028

Lab Session 5, 31-01-18
Counting Sort
Use Counting to sort Integer Keys.(Stable Sorting)
*/

#include <iostream>
using namespace std;

class counting_sort
{
	private:
		int n, a[100], b[100], f[100], cf[100];

	public:
		void init_f_cf();
		void size_init();
		void read_input();
		int getMax();
		void populate_f_cf();
		void sort();
		void display();
};

void counting_sort::init_f_cf()
{
	for (int i = 0; i < 100; i++)
		f[i] = cf[i] = 0;
}

void counting_sort::size_init()
{
	cout<<"Enter size of Array\n";
	cin>>n;
}

void counting_sort::read_input()
{
	cout<<"Enter "<<n<<" Integers\n";
	for (int i = 0; i < n; i++)
		cin>>a[i];
}

int counting_sort::getMax()
{
	int x = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > x)
			x = a[i];
	return x;
}

void counting_sort::populate_f_cf()
{
	for (int i = 0; i < n; i++)
		f[a[i]]++;

	for (int i = 0; i < getMax() + 1; i++)
	{
		if (i == 0)
			cf[i] = f[i];
		else
			cf[i] = cf[i - 1] + f[i];
	}

}

void counting_sort::sort()
{
	for (int i = n - 1; i >= 0; i--)
	{
		cf[a[i]]--;
		b[cf[a[i]]] = a[i];
	}
}

void counting_sort::display()
{
	for (int i = 0; i < n; i++)
		cout<<b[i]<<" ";
	cout<<"\n";
}

int main()
{
	counting_sort S;
	S.init_f_cf();
	S.size_init();
	S.read_input();
	S.populate_f_cf();
	S.sort();
	cout<<"Sorted Order:- \n";
	S.display();
}
