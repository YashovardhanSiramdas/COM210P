#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	char s[n][5];
	cout<<"Enter strings\n";
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(int k=3;k>=0;k--)
	{
		int f[26];
		for(int j=0;j<26;j++)
			f[j]=0;

		for(int j=0;j<n;j++)
		{
			f[s[j][k]-'a']++;
		}
		int cf[26];
		cf[0]=f[0];
		for(int i=1;i<26;i++)
		{
			cf[i]=cf[i-1]+f[i];
		}

		char b[n];
		
		for(int i=n-1;i>=0;i--)
		{
			
			cf[s[i][k]-'a']--;
			b[cf[s[i][k]-'a']]=s[i][k];
		}
		char s1[n][5];
		int flag[n]={0};
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(b[i]==s[j][k] && flag[j]==0)
				{
					strcpy(s1[i],s[j]);
					flag[j]=1;
					break;
				}
			}
		}
		for(int i=0;i<n;i++)
			strcpy(s[i],s1[i]);
	}
	cout<<"Output\n";
	for(int i=0;i<n;i++)
		cout<<s[i]<<endl;
	
}


