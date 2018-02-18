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
 
struct node getMinMax(int arr[], int low, int high)
{
  struct node minmax, mml, mmr;       
  int mid;

  if (low == high) {
     minmax.max = arr[low];
     minmax.min = arr[low];     
     return (minmax);
  }    

  if (high == low + 1) {
     if (arr[low] > arr[high]) {  
        minmax.max = arr[low];
        minmax.min = arr[high];
     }  
     else {
        minmax.max = arr[high];
        minmax.min = arr[low];
     }  
     return (minmax);
  }

  mid = (low + high) / 2;  
  mml = getMinMax(arr, low, mid);
  mmr = getMinMax(arr, mid + 1, high);  

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
  int arr_size;
  cout<<"Enter size of the Array: \n";
  cin>>arr_size;
  int arr[arr_size];
  cout<<"Enter "<<arr_size<<" Integers\n";
  int i;
  for (i = 0; i < arr_size; ++i)
    cin>>arr[i];

  struct node minmax = getMinMax(arr, 0, arr_size - 1);
  cout<<"Min: "<<minmax.min<<endl;
  cout<<"Max: "<<minmax.max<<endl;
  
  return (0);
}

