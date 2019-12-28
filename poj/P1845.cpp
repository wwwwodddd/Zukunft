#include<stdio.h>
#include<math.h>
#include<string.h>
long long a[20];
long long b[20];
long long f[10000];
int i,j,k=0;
long long c,d;
long long n,x,y,z;
long long fs,sum,ans;
int sqrt(long long x)
{
	return (int)sqrt((double)x);
}
void exgcd(long long a,long long b,long long &d,long long &x,long long &y)//扩展GCD d=gcd(a,b) 求出a，b使ax+by=d；
{
	if(b==0)
	{
		d=a;
		x=1;
		y=0;
		return;
	}
	long long xx,yy,dd;
	exgcd(b,a%b,dd,xx,yy);
	d=dd;
	x=yy;
	y=xx-yy*(a/b);
	return;
}
int mod(int a,int b)//快速幂 a的b次方mod 9901；
{
	int i,r=1,y=a%9901;
	while(b)
	{
		if(b&1)
			r*=y;
		r%=9901;
		y*=y;
		y%=9901;
		b>>=1;
	}
	return r;
}
int main()
{
	scanf("%I64d %I64d",&c,&d);//分解质因数a[]为底，b[]为指数
	for(i=2;i<=sqrt(c);i++)
	{
		if(c%i==0)
		{
			a[k]=i;
			while(c%i==0)
			{
				b[k]++;
				c/=i;
			}
			k++;
		}
	}
	if(c!=1)
	{
		a[k]=c,b[k]=1;
		k++;
	}
	ans=1;//分解质因数完；
	/*
	下面只需让ans依次乘以a[i]的(b[i]*d+1)除以(a[i]-1)即可；
	下面分两种情况，
	如果((a[i]-1)mod 9901=0)
	这意味着这个等比数列的每一项mod 9901 之后都是1只需让ans=ans*(b[i]*d+1)mod 9901;即可
	如果((a[i]-1)mod 9901<>0)
	就需求(a[i]-1)对于9901的乘法逆元x；
	乘法逆元是指可以使(a[i]-1)*x mod 9901=0的x；
	如果(a[i]-1)和9901互质；
	那么x在1到9900之间只有一个满足条件。
	求乘法逆元用扩展欧几里得
	使用乘法逆元也很简单，比如本身是要除以(a[i]-1)，只需乘以(a[i]-1)的乘法逆元x即可。
	*/
	for(i=0;i<k;i++)//对于每个质数
	{
		if((a[i]-1)%9901==0)//第一种情况
			ans=ans*(b[i]*d+1)%9901;
		else
		{
			ans=ans*(mod(a[i],(b[i]*d+1)%9900)-1)%9901;//乘以等差数列的分子
			exgcd(a[i]-1,9901,z,x,y);//求乘法逆元
			ans=ans*x%9901;//乘上去
		}
	}
	printf("%I64d\n",(ans+9901)%9901);
	return 0;
}
/*



__int64 sum(__int64 p,__int64 n)//求1+p+p^2+...+p^n;
{
	if(n==0)
		return 1;
	if(n&1)//偶数个
		return (((1+pow(p,n/2+1))%mod)*(sum(p,n/2)%mod))% mod;
	else//奇数个
		return (((1+pow(p,n/2+1))%mod)*(sum(p,(n-1)/2)%mod)+pow(p,n/2)%mod)%mod;
}


*/