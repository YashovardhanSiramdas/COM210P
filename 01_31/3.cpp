/*
Given n ordered pairs (xi,yi) inside the circle x^2 + y^2 =1,find the ascending order of these points base on distance from center 
*/
#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

struct point
{
	float x;
	float y;
	float res;
	struct point *link;
};
struct point *head[10];
int main()
{
	int n;
	cout<<"Enter number of ordered pairs\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		struct point *p=(struct point *)malloc(sizeof(struct point));
		cin>>p->x>>p->y;
		p->res=sqrt((p->x*p->x)+(p->y*p->y));
		p->res=p->res*10;
		int x=p->res;
			if(head[x]==NULL)
			{
				head[x]=p;
			}
			else
			{
				struct point *t=head[x];
				while(t!=NULL)
				{
					if(p->res>t->res && p->res<=t->res)
						break;
				}
				p->link=t->link;
				t->link=p;

			}

	}
	for(int i=0;i<10;i++)
	{
		if(head[i]!=NULL)
		{
			struct point *t=head[i];
			while(t!=NULL)
			{
				cout<<t->x<<","<<t->y<<"\n";
				t=t->link;
			}
		}
	}
	cout<<"\n";




}