#include<stdio.h>
#include<string.h>
int t;
int n,m,K;
int g[151][11],f[2][60000];
int P[11],Q[11];
int ans;
int x,y;
int getf(int *p)
{
	int i,x=0;
	for(i=1;i<=m;i++)
	x=x*3+p[i];
	return x;
}
void getCode(int *p,int x)
{
	int i=m;
	while(x)
	{
		p[i]=x%3;
		x/=3;
		i--;
	}
	for(;i>=0;i--)
	p[i]=0;
}
void dfs(int i,int k,int* a,int* b,int c)
{
	int p,q;
	p=getf(a);
	q=getf(b);
	for(int j=k;j<=m+3;j++)
	{
		if(c>f[i%2][q])
			f[i%2][q]=c;
		if(c>ans)
			ans=c;
		if(j>=m)
			return;
		else
		{
			if(a[j]==0&&a[j+1]==0&&b[j]==0&&b[j+1]==0)
			{
				b[j]=b[j+1]=2;
				dfs(i,j+2,a,b,c+1);
				b[j]=b[j+1]=0;
			}
			if(j+2<=m)
				if(b[j]==0&&b[j+1]==0&&b[j+2]==0)
				{
					b[j]=b[j+1]=b[j+2]=2;
					dfs(i,j+3,a,b,c+1);
					b[j]=b[j+1]=b[j+2]=0;
				}
		}
	}
}
int main()
{
	int i,j,state,k;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d %d %d",&n,&m,&K);
		memset(g,0,sizeof(g));
		memset(f,-1,sizeof(f));
		for(i=1;i<=K;i++)
		{
			scanf("%d %d",&x,&y);
			g[x][y]=1;
		}
		state=1;
		for(i=1;i<=m;i++)
		{
			P[i]=g[1][i]+1;
			state*=3;
		}
		f[0][getf(P)]=0;
		for(i=1;i<n;i++)
		{
			memset(f[i%2],-1,sizeof(f[i%2]));
			for(j=0;j<state;++j)
			{
				if(f[(i-1)%2][j]==-1)
					continue;
				getCode(P,j);
				for(k=1;k<=m;k++)
				{
					Q[k]=(P[k]==0?P[k]:P[k]-1);
					if(g[i+1][k]==1)
						Q[k]=2;
				}
				dfs(i,1,P,Q,f[(i-1)%2][j]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
