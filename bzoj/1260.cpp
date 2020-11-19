#include<string.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int v[105][105];
int f[105][105];
char s[105];
int F(int l, int r)
{
	if(l==r)
		return 1;
	if(l>r)
		return 0;
	if(v[l][r])
		return f[l][r];
	v[l][r]=1;
	int i,&z=f[l][r];
	z=0x3f3f3f3f;
	for(i=l;i<r;i++)
		z=min(z,F(l,i)+F(i+1,r));
	if(s[l]!=s[r])
		return z;
	z=min(z,F(l+1,r-1)+1);
	for(i=l+1;i<r;i++)
		if(s[l]==s[i])
			z=min(z,F(l,i)+F(i+1,r-1));
	return z;
}
int main()
{
	scanf("%s",s);
	printf("%d\n",F(0,strlen(s)-1));
}