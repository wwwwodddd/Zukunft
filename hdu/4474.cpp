#include<stdio.h>
#include<string.h>
int p[10020];
int q[10020];
int n,m,a[20],b,f,k;
void P(int x)
{
	if(p[x])
		P(p[x]);
	printf("%d",(x-10*p[x]%n+n)%n);
}
int main()
{
	while(~scanf("%d %d",&n,&m))
	{
		memset(a,0,sizeof a);
		memset(p,-1,sizeof p);
		for(int x,i=b=f=0;i<m;i++)
			scanf("%d",&x),a[x]=1;
		printf("Case %d: ",++k);
		for(int i=1;i<10;i++)
			if(!a[i])
			{
				if(i%n==0)
				{
					printf("%d\n",i);
					goto end;
				}
				if(p[i%n]==-1)
					p[q[f++]=i%n]=0;
			}
		for(;b<f;)
		{
			int u=q[b++];
			for(int i=0;i<10;i++)
				if(!a[i])
				{
					if((u*10+i)%n==0)
					{
						P(u);
						printf("%d\n",i);
						goto end;
					}
					if(p[(u*10+i)%n]==-1)
						p[q[f++]=(u*10+i)%n]=u;
				}
		}
		puts("-1");
		end:;
	}
	return 0;	
}
