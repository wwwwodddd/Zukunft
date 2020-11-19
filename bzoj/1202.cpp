#include<stdio.h>
int f[105],c[105];
int s[105],ss;
int n,m,i,csc;
int F(int x,int &w)
{
	int i;
	ss=0;
	while(f[x]!=x)
	{
		s[ss++]=x;
		x=f[x];
	}
	s[ss]=x;
	for(i=ss-1;i>=0;i--)
	{
		f[s[i]]=x;
		c[s[i]]+=c[s[i+1]];
	}
	w=c[s[0]];
	return x;
}
int U(int x,int y,int z)
{
	int wx,wy;
	int fx=F(x,wx);
	int fy=F(y,wy);
	if(fx!=fy)
	{
		f[fy]=fx;
		c[fy]=z+wx-wy;
		return 0;
	}
	else
		return wy-wx!=z;
}
int main()
{
	int ans,x,y,z;
	scanf("%d",&csc);
	while(csc--)
	{
		ans=0;
		scanf("%d %d",&n,&m);
		for(i=1;i<=n+1;i++)
			f[i]=i,c[i]=0;
		for(i=1;i<=m;i++)
		{
			scanf("%d %d %d",&x,&y,&z);
			if(ans==1)
				continue;
			if(U(x,y+1,z))
				ans=1;
		}
		puts(ans?"false":"true");
	}
	return 0;
}