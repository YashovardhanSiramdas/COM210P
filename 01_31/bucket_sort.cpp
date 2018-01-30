#include <iostream>
#include <stdlib.h>
using namespace std;

class bucket_sort
{
	private:
		int n,a[100],max;
		struct node
		{
			int key;
			struct node* link;
		};
		struct node *head[20];
		struct node *tail[20];

	public:
		void size_init();
		void read_input();
		void getMax();
		void insert_keys();
		void display();
};

void bucket_sort::size_init()
{
	cout<<"Enter size of Array\n";
	cin>>n;
}

void bucket_sort::read_input()
{
	cout<<"Enter "<<n<<" Integers\n";
	for(int i=0;i<n;i++)
		cin>>a[i];
}

void bucket_sort::getMax()
{
	int x=a[0];
	for(int i=1;i<n;i++)
		if(a[i]>x)
			x=a[i];
	max=x;
}

void bucket_sort::insert_keys()
{
	for(int i=0;i<n;i++)
	{
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		if(head[a[i]]==NULL)
		{
			temp->key=a[i];
			head[a[i]]=temp;
			tail[a[i]]=temp;
		}

		else
		{
			temp->key=a[i];
			tail[a[i]]->link=temp;
			tail[a[i]]=temp;
		}
	}
}

void bucket_sort::display()
{
	for(int i=0;i<max+1;i++)
	{
		if(head[i]!=NULL)
		{
			struct node *t=head[i];
			while(t!=NULL)
			{
				cout<<t->key<<" ";
				t=t->link;
			}

		}
	}
	cout<<"\n";
}
int main()
{
	bucket_sort S;
	S.size_init();
	S.read_input();
	S.getMax();
	S.insert_keys();
	S.display();
}