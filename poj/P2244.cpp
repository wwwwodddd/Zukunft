#include<stdio.h>
int J(int n,int m)
{
	int p=n*m;
	while(p>n)
		p=p-n+(p-n-1)/(m-1);
	return p;
}
int S(int n)
{
	int i=1;
	while(J(n,i)!=1)
		i++;
	return i;
}
int main()
{
	int x;
	while(scanf("%d",&x)&&x)
		printf("%d\n",S(x-1));
	return 0;
}
/*
#include <stdio.h>
int main()
{
	int i,n,m,p;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		p=n*m;
		while(p>n)
			p=p-n+(p-n-1)/(m-1);
		printf("%d\n",p);
	}
}*/