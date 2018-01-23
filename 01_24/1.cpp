#include <iostream>
using namespace std;

int main()
{
	int a[20],size=-1;
	while(1)
	{
		if(size==-1)
		{
			size++;
			cin>>a[size];
		}
		else
		{
			int x;
			cin>>x;
			int i=0,f=0;
			while(i<=size)
			{
				if(x<a[i])
				{
					size++;
					for(int j=size;j>=i;j--)
					{
						a[j+1]=a[j];
					}
					a[i]=x;
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
				size++;
				a[size]=x;
			}
		}
		for(int i=0;i<=size;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}	
}