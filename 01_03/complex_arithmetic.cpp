#include <iostream>
using namespace std;

class complex
{
	private:
		float a,b,c,d;
	public :
		void read();
		void add();
		void sub();
		void mul();
		void div();
};

void complex::read()
{
	cout<<"Enter a\n";
	cin>>a;
	cout<<"Enter b\n";
	cin>>b;
	cout<<"Enter c\n";
	cin>>c;
	cout<<"Enter d\n";
	cin>>d;
}
void complex::add()
{
	cout<<"Addition: "<<"("<<a<<"+"<<b<<"i)"<<"+"<<"("<<c<<"+"<<d<<"i)"<<"="<<a+c<<"+"<<b+d<<"i"<<endl;
}
void complex::sub()
{
	cout<<"Subtraction: "<<"("<<a<<"+"<<b<<"i)"<<"-"<<"("<<c<<"+"<<d<<"i)"<<"="<<a-c<<"+"<<b-d<<"i"<<endl;
}
void complex::mul()
{
	cout<<"Multiplication: "<<"("<<a<<"+"<<b<<"i)"<<"*"<<"("<<c<<"+"<<d<<"i)"<<"="<<(a*c)-(b*d)<<"+"<<(a*d)+(b*c)<<"i"<<endl;
}
void complex::div()
{
	cout<<"Division: "<<"("<<a<<"+"<<b<<"i)"<<"/"<<"("<<c<<"+"<<d<<"i)"<<"="<<((a*c)+(b*d))/((c*c)+(d*d))<<"+"<<((b*c)-(a*d))/((c*c)+(d*d))<<"i"<<endl;
}

int main()
{
	complex obj;
	obj.read();
	obj.add();
	obj.sub();
	obj.mul();
	obj.div();

	return 0;
}