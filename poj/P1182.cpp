#include<stdio.h>
int f[150020];
int n,m,x,y,z,x1,x2,x3,y1,y2,y3,ans,i;
int F(int x)
{
	if(f[x]==x)
		return x;
	return f[x]=F(f[x]);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(i=1;i<=3*n;i++)
		f[i]=i;
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&z,&x,&y);
		if(x>n||y>n)
		{
			ans++;
			continue;
		}
		x1=F(x);
		x2=F(x+n);
		x3=F(x+2*n);
		y1=F(y);
		y2=F(y+n);
		y3=F(y+2*n);
		if(z==1)
		{
			if(x1==y2||y1==x2)
				ans++;
			else
			{
				f[x1]=y1;
				f[x2]=y2;
				f[x3]=y3;
			}
		}
		else if(z==2)
		{
			if(x1==y1||x1==y2)
				ans++;
			else
			{
				f[y1]=x2;
				f[y2]=x3;
				f[y3]=x1;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}