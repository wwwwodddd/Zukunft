#include<iostream>
using namespace std;
int d[420];
int g[420][420];
int r[420][420];
int c[420];
int p[420];
int n,m;
int isap(int s,int t)
{
	c[0]=m;
	int re=0,i=s,j,z;
	memset(p,-1,sizeof(p));
	p[s]=s;
	while(d[s]<m)
	{
		for(j=0;j<m;j++)
			if(g[i][j]>0&&d[i]==d[j]+1)
				break;
		if(j<m)
		{
			p[j]=i;
			i=j;
			if(i==t)
			{
				z=0x7fffffff;
				for(i=t;i!=s;i=p[i])
					z=min(z,g[p[i]][i]);
				for(i=t;i!=s;i=p[i])
					g[p[i]][i]-=z,g[i][p[i]]+=z;
				re+=z;
			}
		}
		else
		{
			c[d[i]]--;
			if(c[d[i]]==0)
				return re;
			d[i]=m;
			for(j=0;j<m;j++)
				if(g[i][j]>0)
					d[i]=min(d[i],d[j]+1);
			c[d[i]]++;
			i=p[i];
		}
	}
	return re;
}
int i,j,w,x,y,sum,M,N,csc;
int z[420],zz,tp;
char s[220],pp;
int scan()
{
	int re=0;
	while(!(s[pp]>='0'&&s[pp]<='9')&&s[pp])pp++;
	if(!s[pp])
		return -1;
	re=s[pp]-'0';
	pp++;
	while((s[pp]>='0'&&s[pp]<='9'))
		re=re*10+s[pp]-'0',pp++;
	return re;
}
int main()
{
	scanf("%d\n",&csc);
	while(csc--)
	{
		N=0;
		sum=0;
		pp=0;
		memset(r,0,sizeof(r));
		gets(s);
		while((z[N+1]=scan())!=-1)
		{
			N++;
			sum+=z[N];
		}
		m=N+N*N+2;
		for(i=1;i<=N;i++)
			r[0][i]=z[i];
		for(i=1;i<=N*N;i++)
			r[N+i][m-1]=1;
		for(i=1;i<=N;i++)
			for(j=i+1;j<=N;j++)
			{
				r[i][N+(i-1)*N+j]=1;
				r[j][N+(i-1)*N+j]=1;
			}
		for(i=N-1;i>0;i--)
		{
			for(j=i+1;j<=N;j++)
				if(z[j]>z[i])
					r[j][N+(i-1)*N+j]=0;
			memcpy(g,r,sizeof(r));
			memset(d,0,sizeof(d));
			memset(c,0,sizeof(c));
			if(sum!=isap(0,m-1))
				break;
		}
		printf("%d\n",N-i);
	}
	return 0;
}