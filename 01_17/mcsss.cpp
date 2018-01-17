#include <iostream>
#include <cmath>
using namespace std;

#define INT_MIN -32767
int start = 0,end=0,s=0;

int bruteForce(int a[],int n)
{

	int msum=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			int csum=0;
			for(int k=i;k<=j;k++)
				csum=csum+a[k];
			if(msum<csum)
				msum=csum;
		}
	}

	return msum;
}

int incrementalDesign(int a[],int n)
{
	int msum=0;
	for(int i=0;i<n;i++)
	{
		int csum=0;
		for(int j=i;j<n;j++)
		{
			csum=csum+a[j];
			if(msum<csum)
				msum=csum;
		}
	}

	return msum;
}

int divideAndConquer(int a[],int beg,int end)
{
	if(beg==end)
		return (a[beg]>0?a[beg]:0);

	int mid=(beg+end)/2;
	int lsp=divideAndConquer(a,beg,mid);
	int rsp=divideAndConquer(a,mid+1,end);

	int csum=0,lsum=0,rsum=0;

	for(int i=mid;i>=beg;i--)
	{
		csum=csum+a[i];
		if(lsum<csum)
			lsum=csum;
	}
	csum=0;

	for(int i=mid+1;i<=end;i++)
	{
		csum=csum+a[i];
		if(rsum<csum)
			rsum=csum;
	}

	return max(max(lsp,lsum+rsum),max(lsum+rsum,rsp));
}

int kadanesAlgorithm(int a[], int n)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

/*int kadanesAlgorithmIndices(int a[], int n)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }
 
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    return max_so_far;
}*/

/*int kadanesAlgorithm(int a[], int n)
{
   int max_so_far = a[0];
   int curr_max = a[0];
 
   for (int i = 1; i < n; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}*/

/*int kadanesAlgorithm(int a[], int n)
{
   int max_so_far = 0, max_ending_here = 0;
   for (int i = 0; i < n; i++)
   {
       max_ending_here = max_ending_here + a[i];
       if (max_ending_here < 0)
           max_ending_here = 0;
       
       else if (max_so_far < max_ending_here)
           max_so_far = max_ending_here;
   }
   return max_so_far;
}*/

int main()
{
	int n;
	cout<<"Enter Array size\n";
	cin>>n;

	int a[n];
	cout<<"Enter "<<n<<" Integers\n";
	for(int i=0;i<n;i++)
		cin>>a[i];

	cout<<"Brute Force: "<<bruteForce(a,n)<<endl;
	cout<<"Incremental Design: "<<incrementalDesign(a,n)<<endl;
	cout<<"Divide and Conquer: "<<divideAndConquer(a,0,n-1)<<endl;
	cout<<"Kadane's Algorithm: "<<kadanesAlgorithm(a,n)<<endl;

	return 0;
}