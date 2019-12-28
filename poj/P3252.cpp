#include<stdio.h>
long long a,b;
long long c(long long m,long long n)
{
	if(n>m||n<0)
		return 0;
	long long re=1,i;
	for(i=1;i<=n;i++)
	{
		re*=(m-n+i);
		re/=i;
	}
	return re;
}
long long r(long long x,long long y)
{
	if(x==0&&y<=0)
		return 1;
	if(x==0&&y>0)
		return 0;
	long long re=0,i;
	for(i=y;i<=x;i++)
		re+=c(x,i);
	return re;
}
long long F(long long u)
{
	long long v[40],q,i,o=0,z=0;
	long long re=0;
	for(q=1;u;q++)
	{
		v[q]=u&1;
		u>>=1;
	}
	q--;
	for(i=1;i<q;i++)
		re+=r(i-1,(i+1)/2);
	o++;
	for(i=q-1;i>0;i--)
		if(v[i])
		{
			re+=r(i-1,(q+1)/2-(z+1));
			o++;
		}
		else
			z++;
	return re;
}
int main()
{
	scanf("%I64d %I64d",&a,&b);
	printf("%I64d",F(b+1)-F(a));
}