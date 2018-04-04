#include <iostream>
using namespace std;

int main()
{
	int n,r;
	cin>>n>>r;
	unsigned long long int a[n+1][n+1];
	a[0][0]=a[1][0]=a[1][1]=1;
	int i,j,c=0;
	for(i=2;i<=n;i++)
	{
		for(j=0;j<=i;j++)
		{
			c++;
			if(j==0 || j==i)
				a[i][j]=1;
			else
			{
				a[i][j]=a[i-1][j]+a[i-1][j-1];
			}
			//cout<<"test "<<a[i][j]<<endl;
			//c++;
			if(i==n && j==r)
				break;
		}
	}
	cout<<a[n][r]<<"  Count: "<<c<<endl;
}