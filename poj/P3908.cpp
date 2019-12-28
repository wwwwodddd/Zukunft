#include<stdio.h>
#include<iostream>
using namespace std;
int h[100020];
int f[100020];
char s[9];
int x,y,z1,z2,n;
int F(int x)
{
	return f[x]!=x?f[x]=F(f[x]):x;
}
void U(int x,int y)
{
	f[F(x)]=F(y);
}
int main()
{
	for(;~scanf("%d",&n);)
	{
		z1=z2=0;
		for(int i=1;i<=n;i++)
			h[i]=f[i]=i;
		for(;scanf("%s",s),*s!='e';)
		{
			if(*s=='c')
				scanf("%d %d",&x,&y),U(h[x],h[y]);
			else if(*s=='d')
			{
				n++;
				scanf("%d",&x);
				h[x]=f[n]=n;
			}
			else
				scanf("%d %d",&x,&y),F(h[x])==F(h[y])?z1++:z2++;
		}
		printf("%d , %d\n",z1,z2);
	}
	return 0;
}
