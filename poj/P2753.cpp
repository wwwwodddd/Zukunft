#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<assert.h>
using namespace std; 
#define fr(i,n) for(int i=0;i<n;i++)
struct N
{
	int w,c,n;
}a[300020];
bool operator<(const N&a,const N&b)
{
	return a.w*b.c>b.w*a.c;
}
int b[505][505];
int u[505][505];
int d[505][505];
int ac;
int mn1,mn2,maxx;
int i,j,n;
long long ans;
long long lans;
long long nd;
int main()
{
	while(scanf("%d",&n)+1)
	{
		ans=lans=0;
		ac=0;
		memset(a,0,sizeof a);
		fr(i,n)
			for(int j=i;j<n;j++)
			{
				scanf("%d",&b[i][j]);
				scanf("%d",&d[i][j]);
				scanf("%d",&u[i][j]);
			}
		fr(i,n)
			for(int j=i;j<n;j++)
			{
				ans+=(long long)d[i][j]*b[i][j];
				nd-=d[i][j];
				if(i!=j)
					nd-=d[i][j];
				u[i][j]-=d[i][j];
				d[i][j]=0;
			}
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				{
					N tt;
					tt.w=b[i][j];
					tt.c=2;
					tt.n=u[i][j];
					a[ac++]=tt;
				}
		for(int i=0;i<n;i++)
		{
			N tt;
			tt.w=b[i][i];
			tt.c=1;
			tt.n=u[i][i];
			a[ac++]=tt;
		}
		N tt;
		mn1=mn2=0x3f3f3f3f;
		tt.w=-0x3f3f3f3f;
		tt.c=1;
		tt.n=1;
		a[ac++]=tt;
		sort(a,a+ac);
		for(int i=0;i<ac;i++)
		{
			int tmp=min(nd/a[i].c,(long long)a[i].n);
			if(a[i].c==1)
			{
				if(tmp>0)
					mn2=mn1,mn1=a[i].w;
				if(tmp>1)
					mn2=mn1,mn1=a[i].w;
			}
			lans+=tmp*a[i].w;
			nd-=tmp*a[i].c;
			a[i].n-=tmp;
		}
		maxx=0xcccccccc;
		for(int i=0;i<ac;i++)
		{
			if(a[i].c==2)
			{
				if(a[i].n)
				{
					maxx=a[i].w;
					break;
				}	
			}
		}
		lans=max(lans,lans-mn1-mn2+maxx);
		cout<<ans+lans<<endl;
	}
	return 0;
}