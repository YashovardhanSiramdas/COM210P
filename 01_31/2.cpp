#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
	int roll;
	int marks;
	char name[15];
	int year;
	struct node *link;
};

class bucket_sort
{
	private:
		struct node *data;
	public:
		void data_init();
		void insert_data();
		int getRoll();
		struct node *getAddress();

}S[15];

void bucket_sort::data_init()
{
	data=(struct node *)malloc(sizeof(struct node));
}

void bucket_sort::insert_data()
{
	cout<<"Enter roll no\n";
	cin>>data->roll;
	cout<<"Enter marks\n";
	cin>>data->marks;
	cout<<"Enter name\n";
	cin>>data->name;
	cout<<"Enter year\n";
	cin>>data->year;
}

int bucket_sort::getRoll()
{
	return data->roll;
}

struct node * bucket_sort:: getAddress()
{
	return data;
}

int getMax(int n)
{
	int x=S[0].getRoll();
	for(int i=1;i<n;i++)
		if(S[i].getRoll()>x)
			x=S[i].getRoll();
	return x;
}

int main()
{
	int n;
	cout<<"Enter number of records\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		S[i].data_init();
		S[i].insert_data();
	}
	int k=getMax(n);
	struct node *head[k+1];
	struct node *tail[k+1];
	for(int i=0;i<=k;i++)
	{
		head[i]=tail[i]=NULL;
	}

	for(int i=0;i<n;i++)
	{
		if(head[S[i].getRoll()]==NULL)
		{
			head[S[i].getRoll()]=tail[S[i].getRoll()]=S[i].getAddress();
		}
		else
		{
			tail[S[i].getRoll()]->link=S[i].getAddress();
			tail[S[i].getRoll()]=S[i].getAddress();
		}
	}

	for(int i=0;i<=k;i++)
	{
		if(head[i]!=NULL)
		{
			struct node *t=head[i];
			while(t!=NULL)
			{
				cout<<t->roll<<" "<<t->marks<<" "<<t->name<<" "<<t->year<<" ";
				t=t->link;
			}

		}
	}
	cout<<"\n";

}