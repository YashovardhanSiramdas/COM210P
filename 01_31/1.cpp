#include <iostream>
using namespace std;

class counting_sort
{
	private:
		int n,a[100],b[100],f[50],cf[50];

	public:
		void init_f_cf();
		void size_init();
		void read_input();
		int getMax();
		void populate_f_cf();
		void sort();
		void display();
		void range();
};

void counting_sort::init_f_cf()
{
	for(int i=0;i<50;i++)
		f[i]=cf[i]=0;
}

void counting_sort::size_init()
{
	cout<<"Enter size of Array\n";
	cin>>n;
}

void counting_sort::read_input()
{
	cout<<"Enter "<<n<<" Integers\n";
	for(int i=0;i<n;i++)
		cin>>a[i];
}

int counting_sort::getMax()
{
	int x=a[0];
	for(int i=1;i<n;i++)
		if(a[i]>x)
			x=a[i];
	return x;
}

void counting_sort::populate_f_cf()
{
	for(int i=0;i<n;i++)
	{
		f[a[i]]++;
	}

	for(int i=0;i<getMax()+1;i++)
	{
		if(i==0)
			cf[i]=f[i];
		else
		{
			cf[i]=cf[i-1]+f[i];
		}
	}

	/*for(int i=0;i<getMax()+1;i++)
		cout<<f[i]<<" ";
	cout<<"\n";

	for(int i=0;i<getMax()+1;i++)
		cout<<cf[i]<<" ";
	cout<<"\n";*/

}

void counting_sort::sort()
{
	for(int i=n-1;i>=0;i--)
	{
		cf[a[i]]--;
		b[cf[a[i]]]=a[i];
	}
}

void counting_sort::display()
{
	for(int i=0;i<n;i++)
		cout<<b[i]<<" ";
	cout<<"\n";
}

void counting_sort::range()
{
	cout<<"Enter a\n";
	int a,b;
	cin>>a;
	cout<<"Enter b\n";
	cin>>b;
	cout<<"Number of integers in the range = "<<cf[b]-cf[a]+1<<"\n";

}

int main()
{
	counting_sort S;
	S.init_f_cf();
	S.size_init();
	S.read_input();
	S.populate_f_cf();
	S.sort();
	S.display();
	S.range();
}