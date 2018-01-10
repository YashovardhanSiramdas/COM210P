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
				if(x==a[m])
				{
					cout<<x<<" is found\n";
					return;		
				}	
				else if(x<a[m])
				{
					e=m-1;
				}
				else
				{
					b=m+1;
				}
			}
			cout<<x<<" is not found\n";
	
		}
		void del(int x)
		{
			int b=0,e=asize,m;
			while(b<=e)
			{
				m=(b+e)/2;
				if(x==a[m])
				{
					for(int i=m;i<=asize;i++)
					{
						if(i!=asize)
						{
							a[i]=a[i+1];	
						}
						
					}
					asize--;
					cout<<x<<" is found and deleted\n";
					return;		
				}	
				else if(x<a[m])
				{
					e=m-1;
				}
				else
				{
					b=m+1;
				}
			}
			cout<<x<<" is not found,hence can't be deleted\n";
		}
		

};

int main()
{
	ADT obj;
	obj.insert();
	obj.insert();
	obj.insert();
	obj.insert();
	obj.insert();
	obj.insert();
	obj.display();
	obj.bsearch(4);
	obj.bsearch(6);
	obj.bsearch(3);
	obj.bsearch(2);
	obj.del(2);
	obj.del(4);
	obj.del(7);
	obj.display();
}#include <iostream>
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
				if(x==a[m])
				{
					cout<<x<<" is found\n";
					return;		
				}	
				else if(x<a[m])
				{
					e=m-1;
				}
				else
				{
					b=m+1;
				}
			}
			cout<<x<<" is not found\n";
	
		}
		void del(int x)
		{
			int b=0,e=asize,m;
			while(b<=e)
			{
				m=(b+e)/2;
				if(x==a[m])
				{
					for(int i=m;i<=asize;i++)
					{
						if(i!=asize)
						{
							a[i]=a[i+1];	
						}
						
					}
					asize--;
					cout<<x<<" is found and deleted\n";
					return;		
				}	
				else if(x<a[m])
				{
					e=m-1;
				}
				else
				{
					b=m+1;
				}
			}
			cout<<x<<" is not found,hence can't be deleted\n";
		}
		

};

int main()
{
	ADT obj;
	obj.insert();
	obj.insert();
	obj.insert();
	obj.insert();
	obj.insert();
	obj.insert();
	obj.display();
	obj.bsearch(4);
	obj.bsearch(6);
	obj.bsearch(3);
	obj.bsearch(2);
	obj.del(2);
	obj.del(4);
	obj.del(7);
	obj.display();
}