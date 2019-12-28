#include<iostream>
#include<string.h>
using namespace std;
char c[120],s[120];
int i,j,x,y,z;
int main()
{
	while(cin>>c)
	{
		memset(s,0,sizeof(s));
		x=0;
		for(i=strlen(c)-1;i>1;i--)
		{
			y=c[i]-'0';
			for(j=0;j<x||y;j++)
			{
				z=y*10+(j<x?s[j]-'0':0);
				s[j]=z/8+'0';
				y=z%8;
			}
			x=j;
		}
		s[j]='\0';
		cout<<c<<" [8] = 0."<<s<<" [10]"<<endl;
	}
	return 0;
}
