#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<assert.h>
using namespace std;
int f[1050][1050];
int c[30];
char s[1050];
bool v[1050][1050];
int i,t,n,d,z;
int R(int x)
{
	if(x==0)
		return 1;
	return x*R(x-1);
}
int F(int x,int y)
{
	if(y==0)
	{
		if(x==0)
			return 1;
		return 0;
	}
	if(v[x][y])
		return f[x][y];
	v[x][y]=1;
	int re=0,i;
	for(i=0;i<n;i++)
		if(((y>>i)&1))
			re+=F((x*10+s[i]-'0')%d,y^(1<<i));
	return f[x][y]=re;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(f,0,sizeof(f));
		memset(v,0,sizeof(v));
		memset(c,0,sizeof(c));
		scanf("%s",s);
		scanf("%d",&d);
		n=strlen(s);
		for(i=0;i<n;i++)
			c[s[i]-'0']++;
		sort(s,s+n);
		z=F(0,(1<<n)-1);
		for(i=0;i<10;i++)
			z/=R(c[i]);
		printf("%d\n",z);
	}
	return 0;
}