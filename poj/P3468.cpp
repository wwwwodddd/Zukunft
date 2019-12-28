#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
long long c[100020];
long long b[100020];
int i,j,k,n,m;
long long x,y,z;
char s[5];
long long max(long long x,long long y)
{
	return x>y?x:y;
}
void R1(long long x,long long v)
{
	for(long long i=x;i<=n;i+=(i&(-i)))
		b[i]+=v;
}
long long G1(long long x)
{
	long long q=0;
	for(long long i=x;i>0;i-=(i&(-i)))
		q+=b[i];
	return q;
}
void R2(long long x,long long v)
{
	for(long long i=x;i<=n;i+=(i&(-i)))
		c[i]+=v;
}
long long G2(long long x)
{
	long long q=0;
	for(long long i=x;i>0;i-=(i&(-i)))
		q+=c[i];
	return q;
}
long long Q(long long x)
{
	return x*G1(x)-G2(x);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%I64d",&y);
		R1(i,y-x);
		R2(i,(y-x)*i);
		x=y;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%s",s);
		if(s[0]=='Q')
		{
			scanf("%I64d %I64d",&x,&y);
			printf("%I64d\n",Q(y+1)-Q(x));
		}
		else if(s[0]=='C')
		{
			scanf("%I64d %I64d %I64d",&x,&y,&z);
			R1(x,z);
			R1(y+1,-z);
			R2(x,x*z);
			R2(y+1,-(y+1)*z);
		}
	}
	return 0;
}
