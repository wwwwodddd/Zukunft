#include<stdio.h>
#include<iostream>
using namespace std;
const int b=700;
int n,i,k,x,y,z,a[200020],w[200020],t[200020],r[200020];
void mk(int x, int y)
{
	t[x]=a[x]=y;
	w[x]=1;
	if(r[t[x]]==r[x])
	{
		w[x]+=w[t[x]];
		t[x]=t[t[x]];
	}
	for(i=x-1;i>=0&&r[i]==r[x];i--)
		if(r[a[i]]==r[x])
		{
			w[i]=1 + w[a[i]];
			t[i]=t[a[i]];
		}
}
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",a+i);
		t[i]=a[i]=min(i+a[i],n);
		r[i]=i/b;
		w[i]=1;
	}
	for(i=n-1;i>=0;i--)
		if(r[a[i]]==r[i])
		{
			w[i]+=w[a[i]];
			t[i]=t[a[i]];
		}
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		scanf("%d",&z);
		if(z==1)
		{
			scanf("%d",&x);
			z=0;
			while(x<n)
				z+=w[x],x=t[x];
			printf("%d\n",z);
		}
		else
		{
			scanf("%d%d",&x,&y);
			mk(x,min(x+y,n));
		}
	}
	return 0;
}