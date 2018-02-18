/*
Author:- Yashovardhan Siramdas
CED16I028

Lab Session 6, 07-02-18

kth Minimum-Worst Case O(N)
Each object has Roll No, Name and CTC. Consider CTC as sorting parameter.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

#define MEDIAN_GROUPS_SIZE 5

class student
{
	private:

		int roll;
		char name[15];
		int ctc;

	public:

		void readData();
		int getRoll();
		void getName();
		int getCTC();

}s[20];

void student::readData()
{
	cout<<"Enter Roll No.\n";
	cin>>roll;
	cout<<"Enter Name\n";
	cin>>name;
	cout<<"Enter CTC\n";
	cin>>ctc;
}

int student::getRoll()
{
	return roll;
}

void student::getName()
{
	cout<<name<<endl;
}

int student::getCTC()
{
	return ctc;
}

int partition(int beg, int end, int pivotIndex)
{
	student pivotValue = s[pivotIndex];

	s[pivotIndex] = s[end];
	s[end] = pivotValue;

	int i, curIndex = beg;
	student swapVar;

	for(i = beg; i < end; ++i)
	{
		if(s[i].getCTC() < pivotValue.getCTC())
		{
			swapVar = s[curIndex];
			s[curIndex] = s[i];
			s[i] = swapVar;

			curIndex++;
		}
	}

	s[end] = s[curIndex];
	s[curIndex] = pivotValue;

	return curIndex;
}

void insertionSort(int beg, int end)
{
	int i, j;
	student key;

	for(i = beg + 1; i <= end; ++i)
	{
		key = s[i];

		j = i - 1;
		while(j >= beg && s[j].getCTC() > key.getCTC())
		{
			s[j + 1] = s[j];
			--j;
		}

		s[j + 1] = key;
	}
}

int getMedianOfMedians(int beg, int end)
{
	int arraySize = end - beg + 1;

	if(arraySize <= MEDIAN_GROUPS_SIZE)
		return beg + (arraySize / 2);

	int i = beg, medGroupsEnd = beg,medianPos, j;
	student swapVar;

	while(i <= end)
	{
		j = i + MEDIAN_GROUPS_SIZE - 1;
		if(j > end)
			j = end;

		insertionSort(i, j);

		medianPos = i + (j - i + 1) / 2;

		swapVar = s[medGroupsEnd];
		s[medGroupsEnd] = s[medianPos];
		s[medianPos] = swapVar;

		medGroupsEnd++;
		i = j + 1;
	}

	return getMedianOfMedians(beg, medGroupsEnd);
}

int selectKth(int beg, int end, int k)
{
	if(end <= beg)
		return beg;

	int pivotIndex = partition(beg, end, getMedianOfMedians(beg, end));

	if(pivotIndex == k - 1)
		return pivotIndex;

	else if(pivotIndex < k - 1)
		return selectKth(pivotIndex + 1, end, k);

	else 
		return selectKth(beg, pivotIndex - 1, k);
}

int main()
{
	int n;
	cout<<"Enter number of students\n";
	cin>>n;

	for(int i=0;i<n;i++)
		s[i].readData();

	int median_index=selectKth(0, n - 1, (n + 1) / 2);   //Median is (n + 1) / 2 th element

	cout<<"Record which has CTC as Median:-\n";
	cout<<"Roll No: "<<s[median_index].getRoll()<<endl;
	cout<<"Name: ";
	s[median_index].getName();
	cout<<"CTC: "<<s[median_index].getCTC()<<endl;
}
