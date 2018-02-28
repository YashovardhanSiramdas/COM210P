#include <iostream>
using namespace std;

#define MEDIAN_GROUPS_SIZE 5 	

const int n=5,m=15;

int P[]={10, 12, 12, 64, 10};
int W[]={1, 2, 3, 4, 5};

struct object
{
	int price;
	int weight;
	float value;
}o[20];

int kp[100];
int knp=-1;
int a[100];

int partition(int beg, int end, int pivotIndex)
{
	object pivotValue = o[pivotIndex];

	o[pivotIndex] = o[end];
	o[end] = pivotValue;

	int i, curIndex = beg;
	object swapVar;

	for(i = beg; i < end; ++i)
	{
		if(o[i].value < pivotValue.value)
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
		while(j >= beg && o[j].value > key.value)
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

void swap(struct object *a,struct object *b)
{
	struct object t=*a;
	*a=*b;
	*b=t; 
}

void fill_weight(int beg,int end,int weight)
{

	int index=selectKth(beg,end,(beg+end)/2);
	int j=0;
	/*int index=partition(0,n-1,med_index);*/
	int wl=0,wm=0,wr=0;
	for(int i=0;i<n;i++)
	{
		if(o[i].value<o[index].value)
		{
			wl += o[i].weight; 
		}
		else if(o[i].value==o[index].value)
		{
			wm += o[i].weight;
			/*int a[j]=i;
			j++;*/
		}
		else
		{
			wr += o[i].weight; 
		}
	}
	int k=index+1;
	for(int i=index+1;i <= end;i++)
	{
		if(o[i].value == o[index].value)
		{
			swap(&o[i],&o[k]);
			k++;
		}	
	}
	if(wr>m)
	{
		//int j=index+1;

		fill_weight(k,end,weight);
	}
	else
	{	
		int j=index-1;
		for(int i=0;i<j;i++)
		{
			if(o[i].value == o[index].value)
			{
				swap(&o[i],&o[j]);
				j--;
			}
		}
		int l;
		for( l=j+1;l<=k-1;l++)
		{
			if(wr+o[l].weight<=weight)
			{
				++knp;
				kp[knp]=l;
				wr += o[l].weight;
			}

		}
		
		if(o[l].weight>weight-wr)
		{
			cout<<o[l].weight<<"\n\n";
			cout<<"Fraction= "<<float(weight-wr)/o[l].weight<<"\n";
		}
		if(wr==weight)
		{
			for(int i=k;i<=end;i++)
			{
				++knp;
				kp[knp]=i;

			}
		}
		else
		{
			fill_weight(beg,j,weight-wr);
		}

	}

}
int main()
{
	/*cin>>n;
	cin>>m;*/
	
	/*for(int i=0;i<n;i++)
	{
		cin>>o[i].price;
		cin>>o[i].weight;
		o[i].value=float(o[i].price)/o[i].weight;
	}*/

	for(int i=0;i<n;i++)
	{
		o[i].price=P[i];
		o[i].weight=W[i];
		o[i].value=float(o[i].price)/o[i].weight;
	}
	for(int i=0;i<100;i++)
		kp[i]=-1;	
	fill_weight(0,n-1,m);
	int w_sum=0,p_sum=0;
	for(int i=0;i<=knp;i++)
	{
		cout<<o[kp[i]].weight<<" "<<o[kp[i]].price<<"\n";
		w_sum += o[kp[i]].weight;
		p_sum += o[kp[i]].price;
	}
	cout<<w_sum<<" "<<p_sum<<"\n";
}