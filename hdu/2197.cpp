#include<stdio.h>
#include<string.h>
int mo=2008,a[40],b[40],c,z,n,m;
int F(int x)
{
	int _=1,t=2;
	for(;x;x>>=1)
	{
		if(x&1)
			_=_*t%mo;
		t=t*t%mo;
	}
	return _;
}
int dfs(int x,int y,int w)
{
	if(x==c)
		z=(z+w*F(n/y))%mo;
	else
		dfs(x+1,y,w),dfs(x+1,y*a[x],-w);
}
int main()
{
	while(~scanf("%d",&n))
	{
		z=c=0,m=n;
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		for(int i=2;i*i<=m;i++)
			if(m%i==0)
			{
				a[c]=i;
				while(m%i==0)
					m/=i,b[c]++;
				c++;
			}
		if(m>1)
			a[c]=m,b[c]=1,c++;
		dfs(0,1,1);
		printf("%d\n",(z+mo)%mo);
	}
	return 0;
}
