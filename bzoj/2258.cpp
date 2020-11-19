#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
char s[100020],o[5];
int p[100020];
int h[100020];
int v[100020];
int u[100020];
int l,q,x,y,z;
int main()
{
	p[0]=1;
	for(int i=1;i<100010;i++)
		p[i]=p[i-1]*131;
	scanf("%s",s+1);
	l=strlen(s+1);
	for(int i=1;i<=l;i++)
		h[i]=h[i-1]*131+s[i],u[i]=v[i]=i;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		scanf("%s",o);
		if(*o=='Q')
		{
			z=0;
			scanf("%d %d",&x,&y);
			x=u[x]-1,y=u[y]-1;
			for(int i=1<<16;i;i>>=1)
				if(x+i<=l&&y+i<=l&&h[x+i]-h[x]*p[i]==h[y+i]-h[y]*p[i])
					x+=i,y+=i,z+=i;
			printf("%d\n",z);
		}
		else if(*o=='I')
		{
			scanf("%s %d",o,&x);
			l++;
			x=min(x,l);
			for(int i=l;i>x;i--)
				s[i]=s[i-1],u[v[i]=v[i-1]]=i;
			s[x]=*o;
			v[x]=0;
			for(int i=x;i<=l;i++)
				h[i]=h[i-1]*131+s[i];
		}
	}
	return 0;
}
