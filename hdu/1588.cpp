#include<stdio.h>
#include<string.h>
long long w,m,n,k,p=1000000007LL;
struct M
{
	long long a[5][5];
	M()
	{
		memset(this, 0, sizeof(*this));
		for(int i=0;i<m;i++)
			a[i][i]=1;
	}
}e,o;
M a,b,c,d;
M operator*(const M &x,const M &y)
{
	M re;
	re=o;
	int i,j,k;
	for(i=0;i<m;i++)
		for(j=0;j<m;j++)
			for(k=0;k<m;k++)
				re.a[i][j]=(re.a[i][j]+x.a[i][k]*y.a[k][j])%p;
	return re;
}
M operator+(const M &x,const M &y)
{
	M re;
	int i,j;
	for(i=0;i<m;i++)
		for(j=0;j<m;j++)
			re.a[i][j]=(x.a[i][j]+y.a[i][j])%p;
	return re;
}
M pw(M a,long long x)
{
	M re;
	int i,j,k;
	while(x)
	{
		if(x&1)
			re=re*a;
		a=a*a;
		x>>=1;
	}
	return re;
}
M pws(M q,long long x)
{
	if(x==0)
		return o;
	M re,u;
	u=pws(q,x/2);
	re=u+u*pw(q,x/2);
	if(x&1)
		re=re*q+e;
	return re;
}
long long work()
{
	a=b=o;
	b.a[1][0]=b.a[0][1]=b.a[1][1]=1;
	a.a[0][1]=1;
	c=pw(b,w);
	d=pw(b,k);
	a=a*c;
	a=a*pws(d,n);
	return a.a[0][0];
}
int main()
{
	m=2;
	for(int i=0;i<m;i++)
		e.a[0][0]=e.a[1][1]=1;
	while(scanf("%I64d%I64d%I64d%I64d",&k,&w,&n,&p)+1)
		printf("%I64d\n",work());
	return 0;
}