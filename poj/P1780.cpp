#include<stdio.h>
int n,m,zc,ss,u;
int a[100020];
int s[1000020];
char z[1000020];
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	for(;scanf("%d",&n),n;)
	{
		for(int i=m=1;i<n;i++)
			m*=10;
		for(int i=0;i<m;i++)
			a[i]=0;
		s[ss++]=ss=0;
		zc=n+m*10;
		for(;ss;)
		{
			u=s[--ss];
			z[--zc]=u%10+'0';
			u/=10;
			for(int w;a[u]<10;)
			{
				w=10*u+a[u]++;
				s[ss++]=w;
				u=w%m;
			}
		}
		for(;zc;)
			z[--zc]='0';
		z[n+m*10-1]=0;
		puts(z);
	}
}
