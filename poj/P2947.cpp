#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
int a[350][350],z[350],t,n,m,p;
char s[10],e[10],w[8][5]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int C(char *c)
{
	fr(i,7)
		if(strcmp(c,w[i])==0)
			return i;
}
int equ()
{
	int r,c;
	for(r=c=0;r<m&&c<n;r++,c++)
	{
		int k=r;
		for(int j=r+1;j<m;j++)
			if(abs(a[j][c])>abs(a[k][c]))
				k=j;
		for(int j=0;j<=n;j++)
			swap(a[r][j],a[k][j]);
		if(a[r][c]==0)
			r--;
		else
			for(int j=0;j<m;j++)
				if(j!=r)
					for(int u=a[r][c],v=a[j][c],k=0;k<=n;k++)
						a[j][k]=(a[j][k]*u-a[r][k]*v)%7;
	}
	for(int i=r;i<m;i++)
		if(a[i][n])
			return -1;
	if(r<n)
		return 1;
	for(int i=0;i<n;i++)
	{
		while(a[i][n]%a[i][i])
			a[i][n]+=7;
		z[i]=(a[i][n]/a[i][i]+4)%7+3;
	}
	fr(i,n)
		printf("%d ",z[i]);
	puts("");
	return 0;
}
int main()
{
	while(scanf("%d %d",&n,&m),n+m)
	{
		int k,x;
		memset(a,0,sizeof a);
		fr(i,m)
		{
			scanf("%d %s %s",&k,s,e);
			a[i][n]=(C(e)-C(s)+8)%7;
			fr(j,k)
			{
				scanf("%d",&x);
				x--;
				a[i][x]=(a[i][x]+1)%7;
			}
		}
		k=equ();
		if(k==-1)
			puts("Inconsistent data.");
		else if(k==1)
			puts("Multiple solutions.");
	}
	return 0;
}