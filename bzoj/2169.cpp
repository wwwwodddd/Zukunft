#include<stdio.h>
int mod=10007;
int n,k,m,sn;
int f[1020][1020];
int F(int x,int y)
{
	if(f[x][y]+1)
		return f[x][y];
	if(x==0)
		return f[x][y]=(y==0);
	if(x+x<y||y>n)
		return 0;
	int re=0;
	if(n>=y+2)
		re=(re+F(x-1,y+2)*(((n-y)*(n-y-1)>>1)%mod))%mod;
	if(n-y&&y)
		re=(re+F(x-1,y)*((n-y)*y%mod))%mod;
	if(y>=2)
		re=(re+F(x-1,y+2)*(((n-y)*(n-y-1)>>1)%mod))%mod;
	if(x>=2)
		re=(re-F(x-2,y)*((sn-x+2)*(x-1)%mod))%mod;
	if(re<0)
		re+=mod;
	return f[x][y]=re;
}
int pw(int x,int y)
{
	int re=1;
	for(;y;y>>=1)
	{
		if(y&1)
			re=re*x%mod;
		x=x*x%mod;
	}
	return re;
}
int c[1020];
int main()
{
	scanf("%d %d %d",&n,&m,&k);
	
}
