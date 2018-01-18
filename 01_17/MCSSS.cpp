#include <iostream>
#include <cmath>
using namespace std;

#define INT_MIN -32767

class MCSSS
{
	private:
		int n,a[100];
		int start,end,s;
		int bruteBeg,bruteEnd;
		int incBeg,incEnd;
		int DCBeg,DCEnd;
		int pBeg,pEnd;

	public:
		MCSSS()
		{
			start=s=end=0;
		}
		int size();
		void insert();
		int bruteForce();
		int incrementalDesign();
		int divideAndConquer(int beg,int end);
		int pruning();
		void indices();

};

int MCSSS::size()
{
	return n-1;
}

void MCSSS::insert()
{
	cout<<"Enter Array size\n";
	cin>>n;

	cout<<"Enter "<<n<<" Integers\n";
	for(int i=0;i<n;i++)
		cin>>a[i];
}

int MCSSS::bruteForce()
{

	int msum=0,i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			int csum=0;
			for(k=i;k<=j;k++)
				csum=csum+a[k];
			if(msum<csum)
			{
				msum=csum;
				bruteBeg=i;
				bruteEnd=j;
			}
		}
	}

	return msum;
}

int MCSSS::incrementalDesign()
{
	int msum=0,i,j;
	for(i=0;i<n;i++)
	{
		int csum=0;
		for(j=i;j<n;j++)
		{
			csum=csum+a[j];
			if(msum<csum)
			{
				msum=csum;
				incBeg=i;
				incEnd=j;
			}
		}
	}

	return msum;
}

int MCSSS::divideAndConquer(int beg,int end)
{
	if(beg==end)
		return (a[beg]>0?a[beg]:0);

	int mid=(beg+end)/2;
	int lsp=divideAndConquer(beg,mid);
	int rsp=divideAndConquer(mid+1,end);

	int csum=0,lsum=0,rsum=0;
	int stl=mid,enr=mid;
	for(int i=mid;i>=beg;i--)
	{
		csum=csum+a[i];
		if(lsum<csum)
		{
			lsum=csum;
			stl=i;
		}
	}
	csum=0;

	for(int i=mid;i<=end;i++)
	{
		csum=csum+a[i];
		if(rsum<csum)
		{
			rsum=csum;
			enr=i;
		}
	}
	int k=max(max(lsp,lsum+rsum-a[mid]),max(lsum+rsum-a[mid],rsp));
	if(k==lsp)
	{
		DCBeg=beg;
		DCEnd=mid-1;
	}
	else if(k==rsp)
	{
		DCBeg=mid+1;
		DCEnd=end;
	}
	else
	{
		DCBeg=stl;
		DCEnd=enr;
	}

	return k;
}

int MCSSS::pruning()
{
    int msum = INT_MIN, csum = 0;
 
    for (int i = 0; i < n; i++)
    {
        csum = csum + a[i];
        if (msum < csum)
        {
            msum = csum;
            start = s;
            end = i;
        }
 
        if (csum < 0)
        {
            csum = 0;
            s = i + 1;
        }
    }
    return msum;
}

void MCSSS::indices()
{
	cout<<"Brute "<<bruteBeg<<" "<<bruteEnd<<endl;
	cout<<"Inc "<<incBeg<<" "<<incEnd<<endl;
	cout<<"DC "<<DCBeg<<" "<<DCEnd<<endl;
	cout<<"Pruning "<<start<<" "<<end<<endl;
}


int main()
{
	MCSSS s;

	s.insert();
	cout<<"Brute Force: "<<s.bruteForce()<<endl;
	cout<<"Incremental Design: "<<s.incrementalDesign()<<endl;
	cout<<"Divide and Conquer: "<<s.divideAndConquer(0,s.size())<<endl;
	cout<<"Kadane's Algorithm: "<<s.pruning()<<endl;
	s.indices();

	return 0;
}