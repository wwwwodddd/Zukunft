#include<stdio.h>
int p[5000],pp,t,n,re;
int P(int x)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return 0;
	return 1;
}
void F(int x,int y,int z,int w)
{
	if((long long)y*y*p[z]*p[z]>x)
		return;
	F(x,y,z+1,w);
	y*=p[z];
	re-=w*(x/(y*y));
	F(x,y,z+1,-w);
}
int main()
{
	for(int i=2;i<45000;i++)
		if(P(i))
			p[pp++]=i;
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		long long l=n,r=2*n;
		while(l<r)
		{
			re=(l+r)/2;
			F((l+r)/2,1,0,1);
			if(re<n)
				l=(l+r)/2+1;
			else
				r=(l+r)/2;
		}
		printf("%d\n",l);
	}
	return 0;
}
