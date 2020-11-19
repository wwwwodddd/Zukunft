#include<stdio.h>
#include<iostream>
using namespace std;
int n,m,j,x,y,z,_;
int h[1000020],s[1000020],c[1000020],a[100020],p[100020];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		p[i]=h[a[i]];
		h[a[i]]=i;
		s[a[i]]++;
		if(a[i]!=a[i-1])
			_++;
	}
	for(int i=0;i<=1000000;i++)
		c[i]=i;
	for(int i=0;i<m;i++)
	{
		scanf("%d",&z);
		if(z==1)
		{
			scanf("%d %d",&x,&y);
			if(s[c[x]]>s[c[y]])
				swap(c[x],c[y]);
			x=c[x],y=c[y];
			if(x==y||s[x]==0)
				continue;
			for(j=h[x];j;j=p[j])
				_-=(a[j-1]==y)+(a[j+1]==y);
			for(j=h[x];a[j]=y,p[j];j=p[j])
				;
			p[j]=h[y];
			h[y]=h[x];
			s[y]+=s[x];
			s[x]=h[x]=0;
		}
		else
			printf("%d\n",_);
	}
}
