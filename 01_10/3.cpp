#include <iostream>
#include <cmath>
using namespace std;

class ADT
{
	private:
		int asize=-1;
		int a[100];
	public:
		void swap(int* a, int* b)
		{
    		int t = *a;
    		*a = *b;
    		*b = t;
		}

		int partition (int a[], int low, int high)
		{
    		int pivot = a[high];  
    		int i = (low - 1); 
 	

    		for (int j = low; j <= high- 1; j++)
    		{
        		if (a[j] <= pivot)
        		{
            		i++;  
            		swap(&a[i], &a[j]);
        		}
    		}
    		swap(&a[i + 1], &a[high]);
    		return (i + 1);
		}
 
		void quickSort(int a[], int low, int high)
		{
    		if (low < high)
    		{
        		int pi = partition(a, low, high);
        		quickSort(a, low, pi - 1);
        		quickSort(a, pi + 1, high);
    		}
		}
		void insert()
		{
			asize++;
			cin>>a[asize];
			quickSort(a,0,asize);
		}
		void display()
		{
			for(int i=0;i<=asize;i++)
				cout<<a[i]<<endl;
		}
		void bsearch(int x)
		{
			int b=0,e=asize,m;
			while(b<=e)
			{
				m=(b+e)/2;
				if(key==a[m])
				{
					break;		
				}	
				else if(key<a[m])
				{
					e=m-1;
				}
				else
				{
					b=m+1;
				}
			}
	
			return c;
		}

};

int main()
{
	ADT obj;
	obj.insert();
	obj.insert();
	obj.insert();
	obj.insert();
	obj.display();
}