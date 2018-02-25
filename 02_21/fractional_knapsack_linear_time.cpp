/*
Author:- Yashovardhan Siramdas
CED16I028

Lab Session 7, 21-02-18

Fractional Knapsack.Greedy on Price/Weight.
Linear Time Algorithm. O(N)
*/

#include <iostream>
using namespace std;

#define MEDIAN_GROUPS_SIZE 5

int n,m;

class object
{
	private:
		int price;
		int weight;
		float value;

	public:
		void setPrice();
		void setWeight();
		void computeValue();
		int getPrice();
		int getWeight();
		float getValue();
}o[20];

void object::setPrice()
{
	cin>>price;
}

void object::setWeight()
{
	cin>>weight;
}

void object::computeValue()
{
	value = float(price) / weight;
}

int object::getPrice()
{
	return price;
}

int object::getWeight()
{
	return weight;
}

float object::getValue()
{
	return value;
}

int partition(int beg, int end, int pivotIndex)
{
	object pivotValue = o[pivotIndex];

	o[pivotIndex] = o[end];
	o[end] = pivotValue;

	int i, curIndex = beg;
	object swapVar;

	for(i = beg; i < end; ++i)
	{
		if(o[i].getValue() < pivotValue.getValue())
		{
			swapVar = o[curIndex];
			o[curIndex] = o[i];
			o[i] = swapVar;

			curIndex++;
		}
	}

	o[end] = o[curIndex];
	o[curIndex] = pivotValue;

	return curIndex;
}

void insertionSort(int beg, int end)
{
	int i, j;
	object key;

	for(i = beg + 1; i <= end; ++i)
	{
		key = o[i];

		j = i - 1;
		while(j >= beg && o[j].getValue() > key.getValue())
		{
			o[j + 1] = o[j];
			--j;
		}

		o[j + 1] = key;
	}
}

int getMedianOfMedians(int beg, int end)
{
	int arraySize = end - beg + 1;

	if(arraySize <= MEDIAN_GROUPS_SIZE)
		return beg + (arraySize / 2);

	int i = beg, medGroupsEnd = beg, medianPos, j;
	object swapVar;

	while(i <= end)
	{
		j = i + MEDIAN_GROUPS_SIZE - 1;
		if(j > end)
			j = end;

		insertionSort(i, j);

		medianPos = i + (j - i + 1) / 2;

		swapVar = o[medGroupsEnd];
		o[medGroupsEnd] = o[medianPos];
		o[medianPos] = swapVar;

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
	cout<<"Enter Number of objects: ";
	cin>>n;
	cout<<"Enter capacity of Knapsack: ";
	cin>>m;
	cout<<"\n";

	for(int i = 0; i < n; i++)
	{
		cout<<"Enter Price of object "<<i + 1<<": ";
		o[i].setPrice();
		cout<<"Enter Weight of object "<<i + 1<<": ";
		o[i].setWeight();
		o[i].computeValue();
	}

	cout<<"\n\n";
	for(int i = 0; i < n; i++)
	{
		cout<<"Price of object "<<i + 1<<": "<<o[i].getPrice()<<endl;
		cout<<"Weight of object "<<i + 1<<": "<<o[i].getWeight()<<endl;
		cout<<"Value of object "<<i + 1<<": "<<o[i].getValue()<<endl;
		cout<<"\n\n";
	}

	int remainingWeight = m;
	int currentWeight = 0;
	float currentPrice = 0;

	int k = n;  //k is nth minimum or 1st maximum
	while(k >= 1)
	{
		int index=selectKth(0, k - 1, k);
		if(currentWeight + o[index].getWeight() <= m)
		{
			currentWeight += o[index].getWeight();
			remainingWeight = remainingWeight - o[index].getWeight();
			currentPrice += o[index].getPrice();
		}
		else if(remainingWeight > 0)
		{
			currentWeight = m;
			currentPrice +=  remainingWeight * o[index].getValue();
			remainingWeight = 0;
			break;
		}
		k--;
	}

	cout<<"Final weight inside Knapsack: "<<currentWeight<<endl;
	cout<<"Final price of the Knapsack: "<<currentPrice<<endl;
}
