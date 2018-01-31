#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
	int rollno;
	int marks;
	char name[15];
	int year;
};

class bucket_sort
{
	private:
		
		struct node *temp;

	public:
		void node_init();
		void read_input();
		void display();
}S[15];


void bucket_sort::node_init()
{
	temp=(struct node *)malloc(sizeof(struct node));
}

void bucket_sort::read_input()
{
	cout<<"Enter roll number\n";
	cin>>temp->rollno;
	cout<<"Enter marks\n";
	cin>>temp->marks;
	cout<<"Enter name\n";
	cin>>temp->name;
	cout<<"Enter year\n";
	cin>>temp->year;
}

void bucket_sort::display()
{
	
	cout<<temp->rollno<<" "<<temp->marks<<" "<<temp->name<<" "<<temp->year<<"\n";
}

int main()
{
	int n;
	cout<<"Enter number of student records\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		S[i].node_init();
		S[i].read_input();
	}
	/*for(int i=0;i<n;i++)
	{
		S[i].display();
	}*/
}