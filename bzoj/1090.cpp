#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
char s[120];
int v[120][120];
int f[120][120];
int ck(int x,int y,int z)
{
	if(y%z)
		return 0;
	for(int i=0;i<y;i++)
		if(s[x+i]!=s[x+i%z])
			return 0;
	return 1;
}
int w(int x)
{
	if(x<10)
		return 1;
	return 1+w(x/10);
}
int F(int l,int r)
{
	int&x=f[l][r],i;
		if(v[l][r])
			return x;
	v[l][r]=1;
	if(l==r)
		return x=1;
	x=r-l+1;
	for(i=l;i<r;i++)
		x=min(x,F(l,i)+F(i+1,r));
	for(i=1;i<r-l+1;i++)
		if(ck(l,r-l+1,i))
			x=min(x,F(l,l+i-1)+2+w((r-l+1)/i));
	return x;
}
int main()
{
	scanf("%s",s);
	printf("%d",F(0,strlen(s)-1));
	return 0;
}