#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int n,m,l;
char s[5];
int a[200020][3],tot;
int h[10020];
int d[10020];
int v[10020];
void add(int x,int y,int z)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	a[tot][2]=z;
	h[x]=tot;
}
int main()
{
	for(;scanf("%d %d",&n,&m),n+m;)
	{
		memset(h,0,sizeof h);
		tot=0;
		n++,m++;
		fr(i,n)
		{
			fr(j,m-1)
			{
				scanf("%d %s",&l,s);
				if(l==0)
					continue;
				if(*s!='<')
					add(i*m+j,i*m+j+1,l);
				if(*s!='>')
					add(i*m+j+1,i*m+j,l);
			}
			if(i==n-1)
				break;
			fr(j,m)
			{
				scanf("%d %s",&l,s);
				if(l==0)
					continue;
				if(*s!='^')
					add(i*m+j,i*m+m+j,l);
				if(*s!='v')
					add(i*m+m+j,i*m+j,l);
			}
		}
		n*=m;
		memset(d,0x3f,sizeof d);
		memset(v,0,sizeof v);
		d[0]=0;
		int x,y;
		fr(i,n)
		{
			y=0x3f3f3f3f;
			fr(j,n)
				if(!v[j]&&d[j]<y)
					y=d[x=j];
			v[x]=1;
			for(int j=h[x];j;j=a[j][0])
				d[a[j][1]]=min(d[a[j][1]],d[x]+2520/a[j][2]);
		}
		if(d[n-1]!=0x3f3f3f3f)
			printf("%d blips\n",d[n-1]);
		else
			puts("Holiday");
	}
}
