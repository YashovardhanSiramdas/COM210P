#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

class MCSSS{
	private:
		char s1[100];
		char s2[100];
	public:
		void insert();
		int check();
}s;

void MCSSS :: insert()
{
	cout<<"Enter 1st string:";
	cin>>s1;
	cout<<"Enter 2nd string:";
	cin>>s2;
}

int MCSSS :: check()
{
	int pos=0;
	
	for(int i=0;i<strlen(s1);i++){
		if(s1[i] == s2[pos]){
			pos++;
		}
		else if(pos>0){
			pos=0;
			i--;
		}
		if(pos==strlen(s2)){
			break;
		}
	}
	if(pos == strlen(s2)){
		return 1;
	}
	else{
		return 0;
	}
}

int main()
{
	s.insert();
	int x = s.check();
	if(x == 1){
		cout<<"Contains.\n";
	}
	else{
		cout<<"Does not contain.\n";
	}
	return 0;
}