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
int n,m,t,x,y,z;
int a[100020];
int h[100020];
int main()
{
	freopen("c.in","r",stdin);
	freopen("s.out","w",stdout);
	scanf("%d %d %d",&n,&m,&t);
	fo(i,n)
		scanf("%d",a+i);
	for(int i=0;i<t;i++)
	{
		memset(h,0,sizeof h);
		scanf("%d %d",&x,&y);
		x=(x+z)%n+1;
		y=(y+z)%n+1;
		if(x>y)
			swap(x,y);
		z=0;
		for(int i=x;i<=y;i++)
			h[a[i]]++;
		fo(i,m)
			if(h[i]>0&&(~h[i]&1))
				z++;
		printf("%d\n",z);
	}
}
