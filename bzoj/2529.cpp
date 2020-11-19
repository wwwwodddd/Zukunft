#include<stdio.h>
#include<iostream>
#include<algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int,int>ii;
ii a[1000020];
int n,m,k,z;
int i,j;
int work()
{
	j=-1;
	for(i=0;i<n-1;i++)
		if(a[i].y!=a[i+1].y)
		{
			if(j!=-1&&a[j].y!=a[i+1].y)
				if(a[j].x+a[i].x>a[i+1].x)
				{
					printf("%d %d %d %d %d %d",a[j].y,a[j].x,a[i].y,a[i].x,a[i+1].y,a[i+1].x);
					return 1;
				}
			j=i;
		}
	return 0;
}
int main()
{
	scanf("%d",&k);
	for(i=1;i<=k;i++)
	{
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d",&z);
			a[n++]=ii(z,i);
		}
	}
	sort(a,a+n);
	if(!work())
		puts("NIE");
	return 0;
}