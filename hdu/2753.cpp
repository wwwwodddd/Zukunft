#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int f[20020];
int m,n,x,t;
int main()
{
	for(;~scanf("%d",&t);)
	{
		for(;t--;)
		{
			memset(f,0x3f,sizeof f);
			scanf("%d %d",&m,&n);
			f[0]=0;
			for(int i=0;i<n;i++)
			{
				scanf("%d",&x);
				for(int i=m;~i;i--)
					f[i+x]=min(f[i+x],f[i]+1);
			}
			for(;f[m]==0x3f3f3f3f;)
				m++;
			printf("%d %d\n",m,f[m]);
		}
	}
}
