/*
Author:- Yashovardhan Siramdas
CED16I028

Lab Session 7, 21-02-18

0-1 Knapsack(Greedy on Profit / Size)
*/

#include <iostream>
using namespace std;

int n,m;

class process
{
	private:
		int size,profit;
		float res;
	public:
		void setSize();
		void setProfit();
		int getSize();
		int getProfit();
		float getRes();
}p[20];

void process::setSize()
{
	cin>>size;
}

void process::setProfit()
{
	cin>>profit;
	res=float(profit)/size;
}

int process::getSize()
{
	return size;
}

int process::getProfit()
{
	return profit;
}

float process::getRes()
{
	return res;
}

void merge(int beg,int end)
{
	int mid=(beg+end)/2;
	process t[20];
	int i=beg,j=mid+1,k=0;
	while(i<=mid && j<=end)
	{
		if(p[i].getProfit()<p[j].getProfit())
		{
			t[k]=p[i];
			i++;
			k++;
		}
		else
		{
			t[k]=p[j];
			j++;
			k++;
		}
	}

	while(i<=mid)
	{
		t[k]=p[i];
		i++;
		k++;
	}

	while(j<=end)
	{
		t[k]=p[j];
		j++;
		k++;
	}

	for(int l=beg;l<=end;l++)
		p[l]=t[l-beg];
}

void mergeSort(int beg,int end)
{
	int mid=(beg+end)/2;
	if(beg<end)
	{
		mergeSort(beg,mid);
		mergeSort(mid+1,end);
		merge(beg,end);
	}
}
int main()
{
	cout<<"Enter number of processes\n";
	cin>>n;
	cout<<"Enter size of RAM\n";
	cin>>m;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter size of process "<<i+1<<"\n";
		p[i].setSize();

		cout<<"Enter profit of process "<<i+1<<"\n";
		p[i].setProfit();
	}
	mergeSort(0,n-1);

	int cs=0,cp=0,i=n-1;
	while(1)
	{
		if(cs+p[i].getSize()<=m && i>=0)
		{
			cp=cp+p[i].getProfit();
			cs=cs+p[i].getSize();
			i--;
		}
		else
			break;
	}
	cout<<"Final RAM size: "<<cs<<endl;
	cout<<"Profit: "<<cp<<endl;

}