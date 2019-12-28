#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
char s[1001];
int n,c0;
int d[700];
int e[100005][4];
int l,r,mid;
int len,bf;
int ls,flag;
int i,j,k;
void I(int x,int y,int z)
{
	e[c0][0]=x;
	e[c0][1]=y;
	e[c0][2]=z;
	c0++;
}
int C(char a,char b)
{
	return (a-'a')*26+b-'a';
}
int B()
{
	memset(d,0,sizeof(d));
	for(i=0;i<676;i++)
	{
		bf=0;
		for(j=0;j<c0;j++)
			if(d[e[j][1]]<d[e[j][0]]+e[j][3])
			{
				d[e[j][1]]=d[e[j][0]]+e[j][3];
				bf=1;
			}
		if (!bf)
			return 0;
	}
	for(j=0;j<c0;j++)
		if(d[e[j][1]]<d[e[j][0]]+e[j][3])
			return 1;
	return 0;
}
int main()
{
	while(scanf("%d",&n) && n)
	{
		c0=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			len=strlen(s);
			ls=max(ls,len);
			I(C(s[0],s[1]),C(s[len-2],s[len-1]),len*100);
		}
		l=0;
		r=ls*100;
		flag=0;
		while(r-l>=2)
		{
			mid=(r+l)/2;
			for(i=0;i<c0;i++)
				e[i][3]=e[i][2]-mid;
			if(B())
				flag=1,l=mid;
			else
				r=mid;
		}
		if(!flag)
			printf("No solution.\n");
		else
			printf("%.2f\n",(l+r)*0.005);
	}
}
