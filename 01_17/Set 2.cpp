/*
Author:- Yashovardhan Siramdas
CED16I028

Lab Session 3, 17-01-18
Given a string of length "N",output "YES" if it contains the word "computer",else "NO" in atmost N character comparisions
*/

#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

class MCSSS
{

	private:

		char s[100];

	public:

		void insert();
		int check();
}s;

void MCSSS :: insert()
{
	cin>>s;
}

int MCSSS :: check()
{
	int pos = 0;
	string cmp = "computer";
	
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == cmp[pos])
			pos++;

		else if (pos > 0)
		{
			pos = 0;
			i--;
		}
		if (pos == 8)
			break;
	}
	if (pos == cmp.size())
		return 1;
	else
		return 0;
}

int main()
{
	s.insert();
	int x = s.check();

	if(x == 1)
		cout<<"YES\n";
	else
		cout<<"NO\n";

	return 0;
}