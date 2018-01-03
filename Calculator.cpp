#include <iostream>
using namespace std;

class calculator
{
	private:
		int x,y,z;
	public :
		void read()
		{
			cout<<"Enter x\n";
			cin>>x;
			cout<<"Enter y\n";
			cin>>y;
		}
		void add()
		{
			z=x+y;
			cout<<x<<"+"<<y<<"="<<z<<endl;
		}
		void sub()
		{
			z=x-y;
			cout<<x<<"-"<<y<<"="<<z<<endl;
		}
		void mul()
		{
			z=x*y;
			cout<<x<<"*"<<y<<"="<<z<<endl;
		}
		void div()
		{
			z=x/y;
			cout<<x<<"/"<<y<<"="<<z<<endl;
		}
};

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