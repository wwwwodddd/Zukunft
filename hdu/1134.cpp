#include<stdio.h>
#include<string.h>
#include<iostream>
int a[500];
int p[500],pp;
int v[500];
int c[500];
int n;
void P()
{
	int i,j;
	for(i=2;i<230;i++)
	{
		if(!v[i])
			p[pp++]=i;
		for(j=0;j<pp&&p[j]*i<230;j++)
		{
			v[p[j]*i]=1;
			if(i%p[j]==0)
				break;
		}
	}
}
void div(int x)
{
	int i,j;
	for(i=0;i<pp;i++)
		for(j=x;j;)
			c[i]+=(j/=p[i]);
	return;
}
void mul(int x)
{
	int i;
	for(i=0;i<100;i++)
		a[i]*=x;
	for(i=0;i<100;i++)
	{
		a[i+1]+=a[i]/10000;
		a[i]%=10000;
	}
	return;
}
int main()
{
	int i,l;
	P();
	while(scanf("%d",&n),n+1)
	{
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		div(2*n);
		div(-n);
		div(-n-1);
		a[0]=1;
		for(i=0;i<pp;i++)
			while(c[i]--)
				mul(p[i]);
		l=100;
		while(!a[l]&&l)
			l--;
		printf("%d",a[l]);
		for(l--;l>=0;l--)
			printf("%04d",a[l]);
		puts("");
	}
	return 0;
}
