/*
Author:- Yashovardhan Siramdas
CED16I028

Lab Session 4, 24-01-18
Tournament Tree
Find Min,Max in exactly (1.5 * N) -2 comparisions where N is size of the array.N is in the form 2^k
*/

#include<iostream>
using namespace std;

struct node
{
  int min;
  int max;
};

class Tournament
{
	private:

	int a[64], size;

	public:

		void size_init();
		void read();
		int getSize();
		struct node getMinMax(int low, int high);

};

void Tournament::size_init()
{
	cout<<"Enter size of array(Should be in the form 2^k)\n";
	cin>>size;
}

void Tournament::read()
{
	cout<<"Enter "<<size<<" Integers\n";
	for (int i = 0; i < size; i++)
		cin>>a[i];
}

int Tournament::getSize()
{
	return size - 1;
}
 
struct node Tournament::getMinMax(int low, int high)
{
  struct node minmax, mml, mmr;       
  int mid;

  if (low == high) {
     minmax.max = a[low];
     minmax.min = a[low];     
     return (minmax);
  }    

  if (high == low + 1) {
     if (a[low] > a[high]) {  
        minmax.max = a[low];
        minmax.min = a[high];
     }  
     else {
        minmax.max = a[high];
        minmax.min = a[low];
     }  
     return (minmax);
  }

  mid = (low + high) / 2;  
  mml = getMinMax(low, mid);
  mmr = getMinMax(mid + 1, high);  

  if (mml.min < mmr.min)
    minmax.min = mml.min;
  else
    minmax.min = mmr.min;     

  if (mml.max > mmr.max)
    minmax.max = mml.max;
  else
    minmax.max = mmr.max;     
  
  return (minmax);
}

int main()
{
  
  Tournament T;
  T.size_init();
  T.read();
  struct node minmax = T.getMinMax(0, T.getSize());

  cout<<"Minimum Integer in the Array: "<<minmax.min<<endl;
  cout<<"Maximum Integer in the Array: "<<minmax.max<<endl;
  
  return (0);
}

