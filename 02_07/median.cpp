#include <iostream>
#include <cstdlib>
using namespace std;

class student
{
	private:
		int roll;
		char name[15];
		int ctc;
	public:
		void readData();
		int getRoll();

}s[20];

void student::readData()
{
	cout<<"Enter roll\n";
	cin>>roll;
	cout<<"Enter name\n";
	cin>>name;
	cout<<"Enter ctc\n";
	cin>>ctc;
}

int student::getRoll()
{
	return roll;
}

int partition(int l, int r)
{
    int x = s[r].getRoll(), i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (s[j].getRoll() <= x)
        {
            //swap(&arr[i], &arr[j]);
            student temp;
    		temp=s[i];
  		  	s[i]=s[j];
    		s[j]=temp;
            i++;
        }
    }
   // swap(&arr[i], &arr[r]);
        student temp;
      	temp=s[i];
    	s[i]=s[r];
      	s[r]=temp;
    return i;
}

int randomPartition(int l, int r)
{
    int n = r-l+1;
    int pivot = rand() % n;
    //swap(&arr[l + pivot], &arr[r]);
    student temp;
    temp=s[l+pivot];
    s[l+pivot]=s[r];
    s[r]=temp;
    return partition(l, r);
}

int select(int l,int r,int k)
{
	if (k > 0 && k <= r - l + 1)
	{
	    int pos = randomPartition(l, r);
	
	    if (pos-l == k-1)
	        return s[pos].getRoll();
	    if (pos-l > k-1)  
	        return select(l, pos-1, k);

	    return select(pos+1, r, k-pos+l-1);
	}
}





int main()
{
	int n;
	cout<<"Enter number of students\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		s[i].readData();
	}
	int median=select(0,n-1,(n+1)/2);
	cout<<"output\n";
	cout<<median<<endl;
}