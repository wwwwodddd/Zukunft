#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
const int mod=1000000007;
int a[20][20];
int b[20][20];
long long c[40][40];
long long s[20][20][40];
int t[40];
int n,m,q,x,y,z;
int gcd(int a,int b,int &x,int &y)
{
	if(b==0)
		return x=1,y=0,a;
	int g=gcd(b,a%b,y,x);
	y-=a/b*x;
	return g;
}
int rev(int u,int mod)
{
	int x,y;
	gcd(u,mod,x,y);
	return x;
}
void work(int *t,long long *s)
{
	for(int i=39;i>0;i--)
	{
		s[i]=(long long)t[i-1]*rev(i,mod)%mod;
		for(int j=0;j<i;j++)
			t[j]=(t[j]+((i-j)%2?-1:1)*c[i][j]*s[i])%mod;
	}
}
int main()
{
	fr(i,40)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)	
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
	scanf("%d %d %d",&n,&m,&q);
	fr(i,n)
		fr(j,m)
			scanf("%d",&a[i][j]);
	fr(i,n)
		fr(j,m)
			scanf("%d",&b[i][j]);
	fr(i,n)
		fr(j,m)
		{
			memset(t,0,sizeof t);
			fr(k,i)
				fr(l,40)
					t[l]=(t[l]+s[k][j][l]*a[k][j])%mod;
			fr(k,j)
				fr(l,40)
					t[l]=(t[l]+s[i][k][l]*a[i][k])%mod;
			work(t,s[i][j]);
			s[i][j][0]=b[i][j];
		}
	fr(i,q)
	{
		scanf("%d %d %d",&x,&y,&z);
		x--,y--,z--;
		long long re=0;
		for(int j=39;j>=0;j--)
		{
			re=(re*z+s[x][y][j])%mod;	
			if(re<0)
				re+=mod;
		}
		cout<<re<<endl;
	}
	return 0;
}
