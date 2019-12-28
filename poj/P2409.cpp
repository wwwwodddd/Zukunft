#include<stdio.h>
int m,n;
long long ans;
long long pw(int x,int y)
{
if(y==0)
	return 1;
return x*pw(x,y-1);
}
int gcd(int a,int b)
{
if(b==0)
	return a;
return gcd(b,a%b);
}
int main()
{
int i;
while(scanf("%d %d",&m,&n)&&m!=0&&n!=0)
	{
	ans=0;
	for(i=1;i<=n;i++)
		ans+=pw(m,gcd(n,i));
	if(n&1==1)
		ans+=n*pw(m,(n>>1)+1);
	else
		ans+=(n>>1)*pw(m,(n>>1))*(m+1);
	printf("%I64d\n",ans/2/n);
	}
return 0;
}