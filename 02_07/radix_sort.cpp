/*
Author:- Yashovardhan Siramdas
CED16I028

Lab Session 6, 07-02-18
Practise Problem.Radix Sort for 3 digit Integers.Bucket Sort is used in Intermediatery steps.
*/

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <math.h>

using namespace std;

struct data
{
	int n;
	int digit;
	struct data *link;
};

struct data *head[10]={NULL};
struct data *tail[10]={NULL};


int main()
{
	int size;
	cout<<"Enter number of 3 digit integers\n";
	cin>>size;
	
	cout<<"Enter "<<size<<" 3-digit integers\n";
	int arr[size];
	for(int i=0;i<size;i++)
		cin>>arr[i];

	for(int d=0;d<3;d++)
	{
		int j=0;
		for(int i=0;i<size;i++)
		{
			struct data *temp=(struct data *)malloc(sizeof(struct data));
			temp->n=arr[j];
			j++;

			temp->digit=fmod(temp->n/pow(10,d),10);

			int index=temp->digit;
			if(head[index]==NULL)
			{
				head[index]=tail[index]=temp;
			}
			else
			{
				tail[index]->link=tail[index]=temp;
			}

		}

		j=0;
		for(int i=0;i<10;i++)
		{
			struct data *t=head[i];
			while(t!=NULL)
			{
				arr[j]=t->n;
				j++;
				t=t->link;
			}
		}

		for(int i=0;i<10;i++)
			head[i]=tail[i]=NULL;
	}
	
	cout<<"Sorted Order:-\n";
	for(int i=0;i<size;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}