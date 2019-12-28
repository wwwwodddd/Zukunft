#include<stdio.h>
#include<string.h>
int v[20],f[20],z[20];
int P(int x,int y)
{
	int i,re=1;
	for(i=0;i<y;i++)
		re*=(x-i);
	return re;
}
int R(int x)
{
	int i;
	for(i=0;i<10&&x;i++)
		if(!v[i])
			x--;
	return i-1;
}
void S(int x,int y)
{
	x-=z[y-1];
	int i,u,p=P(9,y-1);
	memset(f,0,sizeof(f));
	memset(v,0,sizeof(v));
	for(i=0;i<y;i++)
	{
		u=x/p;
		x%=p;
		if(i==9)
			p=0x7fffffff;
		else
			p/=(10-i-1);
		if(i==0)
			f[y-i]=R(u+2);
		else
			f[y-i]=R(u+1);
		v[f[y-i]]=1;
	}
	for(i=y;i>0;i--)
		printf("%d",f[i]);
	printf("\n");
}
int main()
{
	int n,i;
	for(i=1;i<=10;i++)
		z[i]=z[i-1]+9*P(9,i-1);
	while(scanf("%d",&n)&&n)
	{
		for(i=0;z[i]<n&&i<10;i++);
			S(n-1,i);
	}
	return 0;
}