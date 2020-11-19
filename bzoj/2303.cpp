#include<stdio.h>
int n,m,k,l,cnt,i,x,y,z;
int f[4000020];
int F(int x)
{
	return f[x]!=x?f[x]=F(f[x]):x;
}
void U(int x,int y)
{
	int fx=F(x);
	int fy=F(y);
	if(fx!=fy)
		cnt--;
	f[fx]=fy;
	return;	
}
int pw(int x)
{
	long long re=1,b=2;
	while(x)
	{
		if(x&1)
			re=re*b%1000000000;
		b=b*b%1000000000;
		x>>=1;
	}
	return re;
}
int main()
{
	scanf("%d %d %d",&n,&m,&k);
	cnt=2*(l=n+m);
	for(i=1;i<=2*l;i++)
		f[i]=i;
	for(i=0;i<k;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		z^=(x|y)&1;
		if(z)
			U(x,l+n+y),U(l+x,n+y);
		else
			U(x,n+y),U(l+x,l+n+y);
	}
	for(i=1;i<=l;i++)
		if(F(i)==F(i+l))
		{
			puts("0");
			return 0;
		}
	printf("%d",pw(cnt/2-1));
	return 0;
}