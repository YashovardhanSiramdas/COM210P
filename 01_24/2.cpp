#include <iostream>
using namespace std;

class Set
{
	private:
		int size1,a1[30];
		int size2,a2[30];
	public:
		void size_init();
		void read_array1();
		void read_array2();
		void display_array1();
		void display_array2();

};

void Set::size_init()
{
	size1=size2=-1;
}

void Set::read_array1()
{
	int t;
	cout<<"Enter size of Array 1\n";
	cin>>t;
	cout<<"Enter "<<t<<" Integers\n";
	while(t--)
	{ 
		if(size1==-1)
		{
			size1++;
			cin>>a1[size1];
		}
		else
		{
			int x;
			cin>>x;
			int i=0,f=0;
			while(i<=size1)
			{
				if(x<a1[i])
				{
					size1++;
					for(int j=size1;j>=i;j--)
					{
						a1[j+1]=a1[j];
					}
					a1[i]=x;
					f=1;
					break;
				}
				else
				{
					i++;
				}
			}
			if(f==0)
			{
				size1++;
				a1[size1]=x;
			}
		}
	}	
}

void Set::read_array2()
{
	int t;
	cout<<"Enter size of Array 2\n";
	cin>>t;
	cout<<"Enter "<<t<<" Integers\n";
	while(t--)
	{ 
		if(size2==-1)
		{
			size2++;
			cin>>a2[size2];
		}
		else
		{
			int x;
			cin>>x;
			int i=0,f=0;
			while(i<=size2)
			{
				if(x<a2[i])
				{
					size2++;
					for(int j=size2;j>=i;j--)
					{
						a2[j+1]=a2[j];
					}
					a2[i]=x;
					f=1;
					break;
				}
				else
				{
					i++;
				}
			}
			if(f==0)
			{
				size2++;
				a2[size2]=x;
			}
		}
	}	
}

void Set::display_array1()
{
	cout<<"Integers in Array1:-\n";
	for(int i=0;i<=size1;i++)
		cout<<a1[i]<<" ";
	cout<<endl;
}

void Set::display_array2()
{
	cout<<"Integers in Array2:-\n";
	for(int i=0;i<=size2;i++)
		cout<<a2[i]<<" ";
	cout<<endl;
}

int main()
{
	Set S;
	S.size_init();
	S.read_array1();
	S.display_array1();
	S.read_array2();
	S.display_array2();

}