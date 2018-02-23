//BUG IN THE CODE

/*
Author:- Yashovardhan Siramdas
CED16I028

Lab Session 5, 31-01-18
Application of Bucket Sort (Extra Credit)
Given n ordered pairs (xi,yi) inside the circle x^2 + y^2 =1,find the ascending order of these points based on distance from center
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
	for (int i = 0; i < n; i++)
	{
		struct point *p=(struct point *)malloc(sizeof(struct point));
		cin>>p->x>>p->y;
		p->res=((p->x * p->x) + (p->y * p->y));
		p->res = p->res*10;
		int x = p->res;
			if(head[x] == NULL)
				head[x]=p;
			else
			{
				struct point *t = head[x];
				while(t != NULL)
				{
					if(p->res<t->res && t->link==NULL)
					{
						
						break;
					}
					t=t->link;
				}
				p->link=t->link;
				t->link=p;
			}

	}
	cout<<"Sorted Order:-\n";
	for (int i = 0; i < 10; i++)
	{
		if (head[i] != NULL)
		{
			struct point *t = head[i];
			while (t != NULL)
			{
				cout<<"("<<t->x<<","<<t->y<<")"<<"\n";
				t = t->link;
			}
		}
	}
	cout<<"\n";
}
