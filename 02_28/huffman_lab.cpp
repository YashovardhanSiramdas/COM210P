#include <iostream>
using namespace std;

struct node
{
	char c;
	int f;
	struct node* lcptr;
	struct node* rcptr;
	bool isLeaf;
};
struct node *root=NULL;

int hsize=0;

struct heap
{
	char c;
	int f;
}h[20];



struct node *heapify(struct node *root,char a,int f)
{
	if(root==NULL)
	{

	}
}

int min(int a,int b)
{
	return a<b?a:b;
}
void swap(struct heap *a,struct heap *b)
{
	struct heap t=*a;
	*a=*b;
	*b=t;
}

void heapinsert(char key,int key_f)
{
	hsize++;
	h[hsize].c=key;
	h[hsize].f=key_f;
	int i=hsize;
	while(i>1 && h[i].f>h[i/2].f)
	{
		swap(&h[i],&h[i/2]);
		i=i/2;
	}
	//printf("%d is successfully inserted in Heap\n",key);
}

struct heap delMin()
{
	/*if(H.hsize==0)
	{
		printf("Heap is empty,delMax can't be performed\n");
		return ;
	}*/

	heap x;
	x=h[1];
/*	x.f=h[1].f;
	x.c=h[1].c;*/

	h[1]=h[hsize];
	hsize--;
	int i=1;
	while((2*i)<=hsize)
	{
		if((2*i)+1<=hsize && h[i].f>min(h[2*i].f,h[(2*i)+1].f))
		{
			if(h[(2*i)+1].f>h[2*i].f)
			{
				swap(&h[i],&h[(2*i)]);
				i=(2*i);
			}
			else
			{
				swap(&h[i],&h[(2*i)+1]);
				i=(2*i)+1;	
			}

		}
		else if((2*i)+1>H.hsize && H.a[i]>H.a[2*i])
		{
			swap(&h[i],&h[(2*i)]);
			break;
		}
		else
			break;
	}
	return x;

}

int main()
{
	int n;
	hsize=0;
	cout<<"I/P size\n";
	cin>>n;
	cout<<"Enter Input\n";
	char key_b[n];
	int key_fb[n];
	char key;
	int key_f;
	for(int i=0;i<n;i++)
	{
		cin>>key;
		cin>>key_f;
		key_b[i]=key;
		key_fb[i]=key_f;
		heapinsert(key,key_f);
	}
	/*for(int i=1;i<=n;i++)
	{
		cout<<"c: "<<h[i].c<<endl;
		cout<<"f: "<<h[i].f<<endl;
		cout<<"\n";
	}*/
	/*for(int i=0;i<;i++)
	{
		root=heapify(root,a[i],f[i]);
	}
*/
	for(int i=1;i<=n-1;i++)
	{
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		
	}
}
