#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int lg(int x)
{
	if(x==1)
		return 0;
	return lg(x/2)+1;
}
int sg(int x,int y)
{
	if(x==0||y==0)
		return lg((x+y+1)&-(x+y+1));
	return x+y;
}
int i,j,csc,n,m,z;
int v[256];
char c;
int main()
{
	scanf("%d",&csc);
	while(csc--)
	{
		memset(v,0,sizeof(v));
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				cin>>c;
				if(c=='T')
					v[sg(i,j)]^=1;
			}
		z=0;
		for(i=0;i<n+m;i++)
			z|=v[i];
		puts(z?"-_-":"=_=");
	}
	return 0;
}