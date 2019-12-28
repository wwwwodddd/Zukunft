#include<stdio.h>
#include<iostream>
using namespace std;
int z,x,n,m;
char s[120];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		for(int j=0;j<m;j++)
			if(s[j]=='.')
				z+=x+x;
			else
				x^=1,z++;
	}
	printf("%d",z>>1);
	return 0;
}
