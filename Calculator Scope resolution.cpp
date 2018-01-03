#include <iostream>
using namespace std;

class calculator
{
	private:
		int x,y,z;
	public :
		void read();
		void add();
		void sub();
		void mul();
		void div();
};

void calculator::read()
{
	cout<<"Enter x\n";
	cin>>x;
	cout<<"Enter y\n";
	cin>>y;
}
void calculator::add()
{
	z=x+y;
	cout<<x<<"+"<<y<<"="<<z<<endl;
}
void calculator::sub()
{
	z=x-y;
	cout<<x<<"-"<<y<<"="<<z<<endl;
}
void calculator::mul()
{
	z=x*y;
	cout<<x<<"*"<<y<<"="<<z<<endl;
}
void calculator::div()
{
	z=x/y;
	cout<<x<<"/"<<y<<"="<<z<<endl;
}

int main()
{
	calculator obj;
	obj.read();
	obj.add();
	obj.sub();
	obj.mul();
	obj.div();

	return 0;
}