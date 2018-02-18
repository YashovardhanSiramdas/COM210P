/*
Author:- Yashovardhan Siramdas
CED16I028

Lab Session 3, 17-01-18
Finding Maximum contiguous sub sequence sum in 4 different ways
*/

#include <iostream>
#include <cmath>
using namespace std;

#define INT_MIN -32767

class MCSSS
{
	private:

		int n, a[100];
		int bruteBeg, bruteEnd;
		int incBeg, incEnd;
		int DCBeg, DCEnd;
		int pBeg, pEnd;

	public:

		int getSize();
		void insert();
		int bruteForce();
		int incrementalDesign();
		int divideAndConquer(int beg, int end);
		int pruning();
		void printIndices();

};

int MCSSS::getSize()
{
	return n - 1;
}

void MCSSS::insert()
{
	cout<<"Enter Array size\n";
	cin>>n;

	cout<<"Enter "<<n<<" Integers\n";
	for (int i = 0; i < n; i++)
		cin>>a[i];
}

int MCSSS::bruteForce()
{

	int msum = 0, i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			int csum = 0;
			for (k = i; k <= j; k++)
				csum = csum + a[k];
			if (msum < csum)
			{
				msum = csum;
				bruteBeg = i;
				bruteEnd = j;
			}
		}
	}

	return msum;
}

int MCSSS::incrementalDesign()
{
	int msum = 0, i, j;
	for (i = 0; i < n; i++)
	{
		int csum = 0;
		for (j = i; j < n; j++)
		{
			csum = csum + a[j];
			if (msum < csum)
			{
				msum = csum;
				incBeg = i;
				incEnd = j;
			}
		}
	}

	return msum;
}

int MCSSS::divideAndConquer(int beg, int end)
{
	if (beg ==end )
		return (a[beg] > 0 ? a[beg] : 0);

	int mid = (beg + end) / 2;
	int lsp = divideAndConquer(beg, mid);
	int rsp = divideAndConquer(mid + 1, end);

	int csum = 0, lsum = 0, rsum = 0;

	for (int i = mid; i >= beg; i--)
	{
		csum = csum + a[i];
		if (lsum < csum)
		{
			lsum = csum;
			DCBeg = i;
		}
	}
	csum=0;

	for (int i = mid + 1; i <= end; i++)
	{
		csum = csum + a[i];
		if (rsum < csum)
		{
			rsum = csum;
			DCEnd = i;
		}
	}

	return max(max(lsp, rsp), lsum + rsum);
}

int MCSSS::pruning()
{
    int msum = 0, csum = 0, k = 0;
 
    for (int i = 0; i < n; i++)
    {
        csum = csum + a[i];
        if (msum < csum)
        {
            msum = csum;
            pBeg = k;
            pEnd = i;
        }
 
        if (csum < 0)
        {
            csum = 0;
            k = i + 1;
        }
    }
    return msum;
}

void MCSSS::printIndices()
{
	cout<<"Brute Force: "<<bruteBeg<<"-"<<bruteEnd<<endl;
	cout<<"Incremental Design: "<<incBeg<<"-"<<incEnd<<endl;
	cout<<"Divide and Conquer: "<<DCBeg<<"-"<<DCEnd<<endl;
	cout<<"Pruning: "<<pBeg<<"-"<<pEnd<<endl;
}


int main()
{
	MCSSS s;

	s.insert();
	cout<<"Maximum contiguous sum :-\n\n";

	cout<<"Brute Force: "<<s.bruteForce()<<endl;
	cout<<"Incremental Design: "<<s.incrementalDesign()<<endl;
	cout<<"Divide and Conquer: "<<s.divideAndConquer(0,s.getSize())<<endl;
	cout<<"Pruning: "<<s.pruning()<<endl<<endl;

	cout<<"Starting and Ending Indices of optimal subsequence :-\n\n";
	s.printIndices();

	return 0;
}