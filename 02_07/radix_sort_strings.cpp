/*
Author:- Yashovardhan Siramdas
CED16I028

Lab Session 6, 07-02-18
Radix Sort on Strings.Couting Sort is applied on each letter of the String.
*/

#include <iostream>
#include <string.h>
using namespace std;

class radix
{
	private:
		int n;
		char a[20][5];

	public:
		void size_init();
		void read_input();
		void radix_sort();
		void display();

};

void radix::size_init()
{
	cout<<"Enter No. of strings: ";
	cin>>n;
}

void radix::read_input()
{
	cout<<"Enter "<<n<<" strings of length 4\n";
	for (int i = 0; i < n; i++)
		cin>>a[i];
}

void radix::radix_sort()
{
	for (int i = 3; i >= 0; i--)
	{
		int f[26],cf[26];

		for (int j = 0; j < 26; j++)
			f[j] = cf[j] = 0;

		for (int k = 0; k < n; k++)
			f[a[k][i] - 'a']++;

		cf[0] = f[0];
		for (int k = 1; k < 26; k++)
			cf[k] = cf[k - 1] + f[k];

		char b[n][5];
		for (int k = n - 1; k >= 0; k--)
		{
			cf[a[k][i] - 'a']--;
			strcpy(b[cf[a[k][i] - 'a']], a[k]);
		}
		for (int k = 0; k < n; k++)
			strcpy(a[k], b[k]);

	}	
}

void radix::display()
{
	cout<<"Sorted order:- \n";
	for (int i = 0; i < n; i++)
		cout<<a[i]<<endl;
}

int main()
{
	radix R;
	R.size_init();
	R.read_input();
	R.radix_sort();
	R.display();
}
