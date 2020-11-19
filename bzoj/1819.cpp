#include<iostream>
using namespace std;
int n,m,s,z,l;
int t[500020][30];
int v[500020];
int ins(char *p)
{
	int z=0,k;
	for(;*p;p++)
	{
		k=*p-'a';
		if(t[z][k]==-1)
			t[z][k]=++s;
		z=t[z][k];
	}
	if(t[z][26]==-1)
		t[z][26]=n+1;
	return t[z][26];
}
int A(char *p)
{
	int z=0,k;
	for(;*p;p++)
	{
		k=*p-'a';
		if(t[z][k]==-1)
			return 0;
		z=t[z][k];
	}
	if(t[z][26]>0)
	{
		if(v[z]==m+1)
			return 0;
		v[z]=m+1;
		return 1;
	}
	return 0;
}
char c[30],q[30];
int main()
{
	int i,j;
	memset(t,-1,sizeof(t));
	scanf("%d %d",&n,&m);
	while(n--)
		scanf("%s",c),ins(c);
	while(m--)
	{
		scanf("%s",c);
		if(A(c))
		{
			puts("-1");
			continue;
		}
		z=0;
		for(l=0;c[l];l++);
		for(i=0;i<l;i++)
			q[i]=c[i];
		q[l]=0;
		for(i=0;i<l;i++)
		{
			for(j='a';j<='z';j++)
			{
				q[i]=j;
				z+=A(q);
			}
			q[i]=c[i];
		}
		for(i=1;i<l;i++)
			q[i-1]=c[i];
		q[l-1]=0;
		for(i=0;i<l;i++)
		{
			z+=A(q);
			q[i]=c[i];
		}
		for(i=0;i<l;i++)
			q[i+1]=c[i];
		q[l+1]=0;
		for(i=0;i<=l;i++)
		{
			for(j='a';j<='z';j++)
			{
				q[i]=j;
				z+=A(q);
			}
			q[i]=c[i];
		}
		printf("%d\n",z);
	}
	return 0;
}