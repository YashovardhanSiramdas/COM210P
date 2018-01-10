/*
Author:- Yashovardhan Siramdas
CED16I028

Lab Session 2, 10-01-18
Implementation of Dictionary ADT using class
Supports Insert, Search, Delete, Display Operations
*/

#include <iostream>
#include <cmath>

using namespace std;

class ADT
{
	private:
		int asize;
		int a[100];

	public:
		ADT() : asize(-1) {}

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
 	

    		for (int j = low; j <= high - 1; j++)
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

		void insert(int key)
		{
			asize++;
			a[asize] = key;
			quickSort(a, 0, asize);
		}

		void display()
		{
			for (int i = 0; i <= asize; i++)
				cout<<a[i]<<" ";

			cout<<endl;
		}

		void binarySearch(int key)
		{
			int b = 0, e = asize, m;
			while (b <= e)
			{
				m = (b + e) / 2;
				if (key == a[m])
				{
					cout<<key<<" is found \n";
					return;		
				}	
				else if (key < a[m])
					e = m - 1;
				else
					b = m + 1;
			}
			cout<<key<<" is not found \n";
	
		}

		void del(int key)
		{
			int b = 0, e = asize, m;
			while (b <= e)
			{
				m = (b + e) / 2;
				if (key == a[m])
				{
					for (int i = m; i <= asize; i++)
						if (i != asize)
							a[i] = a[i + 1];
						
					asize--;
					cout<<key<<" is found and deleted \n";
					return;		
				}	
				else if (key < a[m])
					e = m - 1;
				else
					b = m + 1;
			}
			cout<<key<<" is not found,hence can't be deleted \n";
		}
};

int main()
{
	ADT obj;
	while(1)
	{
		int t, key;
		cout<<"1.Insert \n2.Search \n3.Delete \n4.Display \n5.Exit \n";
		cin>>t;
		switch(t)
		{
			case 1: 
			{
				cout<<"Enter Integer to be inserted \n";
				cin>>key;
				obj.insert(key);
			}
			break;

			case 2:
			{
				cout<<"Enter Integer to be searched \n";
				cin>>key;
				obj.binarySearch(key);
			}
			break;

			case 3:
			{
				cout<<"Enter Integer to be deleted \n";
				cin>>key;
				obj.del(key);
			}
			break;

			case 4:
			{
				cout<<"Integers in the array:- \n";
				obj.display();
			}
			break;

			case 5:
			{
				return (0);
			}
			break;
		}
	}
}
