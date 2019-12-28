#include<stdio.h>
#include<string.h>
int d[2020][2020];
int s[2020],t[2020];
int kase,n,m,i,j,k,x,y,w,h,p,ans,z;
int min(int x,int y,int z)
{
	x>y?x=y:0;
	x>z?x=z:0;
	return x;
}
int main()
{
	while(scanf("%d %d",&n,&m)+1)
	{
		memset(d,0,sizeof(d));
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
			{
				scanf("%d",&z);
				if(z==0)
					continue;
				d[i][j]=d[i-1][j]+1;
			}
		ans=0;
		for(i=1;i<=n;i++)
		{
			s[0]=-1;
			p=0;
			for(j=1;j<=m;j++)
			{
				w=0;
				h=d[i][j];
				while(s[p]>h)
				{
					w+=t[p];
					w*s[p]>ans?ans=w*s[p]:0;
					p--;
				}
				p++;
				s[p]=h;
				t[p]=w+1;
			}
			w=0;
			while(p)
			{
				w+=t[p];
				w*s[p]>ans?ans=w*s[p]:0;
				p--;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

