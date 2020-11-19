#include<stdio.h>
#include<iostream>
using namespace std;
char s[3][120];
int l[3],p[3],mx,mn;
int main()
{
	for(int i=0;i<3;i++)
		scanf("%d %s",l+i,s[i]);
	for(int i=0;i<3;i++)
	{
		int j=(i+1)%3;
		for(;p[i]<l[i];p[i]++)
			if(s[i][p[i]]!=s[j][p[i]])
				break;
	}
	mx=max(p[0],max(p[1],p[2]));
	mn=min(p[0],min(p[1],p[2]));
	printf("%d\n",l[0]+l[1]+l[2]-mx-2*mn);
	return 0;
}
