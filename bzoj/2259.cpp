#include<iostream>
#include<stdio.h>
using namespace std;
int a[1000020],d[1000020],q[1000020];
int i,j,k,n,z,b,f,u;
void push(int x,int y)
{
	if(x>=n)
		z=min(z,x-n+y);
	else if(d[x]==-1)
		d[x]=y,q[f++]=x;
}
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
		d[i]=-1,scanf("%d",a+i);
	d[0]=0;
	b=f=0;
	q[f++]=0;
	z=0x7fffffff;
	while(b!=f)
	{
		u=q[b++];
		for(k=u;k<n;k=j)
		{
			j=k+a[k]+1;
			if(j<n&&d[j]!=-1)
				break;
			push(j,d[u]);
		}
		push(u+1,d[u]+1);
		push(u-1,d[u]+1);
	}
	printf("%d\n",z);
	return 0;
}