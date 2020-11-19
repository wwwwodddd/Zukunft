#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int a[6000][3200];
int l[6000];
int p[100020],pp;
int v[100020];
int g[8020];
char s[30020];
int len,lg,lz,ly;
void P()
{
	int i,j;
	for(i=2;i<100000;i++)
	{
		if(!v[i])
			v[i]=i,p[pp++]=i;
		for(j=0;j<pp&&p[j]*i<100000;j++)
		{
			v[p[j]*i]=p[j];
			if(v[i]==p[j])
				break;
		}
	}
}
void mul(int x,int k)
{
	int i;
	long long j=0;
	for(i=0;i<l[k];i++)
	{
		j+=(long long)a[k][i]*x;
		a[k+1][i]=j%100000000;
		j/=100000000;
	}
	l[k+1]=l[k];
	if(j)
		a[k+1][l[k+1]++]=j;
	return;
}
bool check(int m)
{
	if(l[m]>lg)
		return 0;
	if(l[m]<lg)
		return 1;
	for(int i=lg-1;i>=0;i--)
		if(a[m][i]>g[i])
			return 0;
		else if(a[m][i]<g[i])
			return 1;
	return 1;
}
int main()
{
	int i,t,n;
	P();
	a[0][0]=l[0]=1;
	for(i=0;i<60;i++)
		mul(p[i],i);
	scanf("%d",&t);
	while(t--)
	{
		memset(g,0,sizeof g);
		memset(s,0,sizeof s);
		scanf("%s",s);
		len=strlen(s);
		reverse(s,s+len);
		for(i=0;i<len;i++)
			s[i]-='0';
		for(i=0;i<(len+7)/8;i++)
//		for(i=0;i<=len/8;i++)
			g[i]=s[i*8]+10*s[i*8+1]+100*s[i*8+2]+1000*s[i*8+3]+10000*(s[i*8+4]+10*s[i*8+5]+100*s[i*8+6]+1000*s[i*8+7]);
		lg=i;
		int ll=0,rr=59,m;
		while(ll<rr)
		{
			m=(ll+rr+1)/2;
			if(check(m))
				ll=m;
			else
				rr=m-1;
		}
		printf("%d",a[ll][l[ll]-1]);
		for(i=l[ll]-2;i>=0;i--)
			printf("%08d",a[ll][i]);
		puts("");
	}
	return 0;
}

