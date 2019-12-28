#include<iostream>
using namespace std;
int d[1020];
int c[1020];
int p[1020];
int a[10020][4];
int h[1020];
int v[1020];
int l[1020];
int n,m;
int tot;
void add(int x,int y,int z)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=x;
	a[tot][2]=y;
	a[tot][3]=z;
	h[x]=tot;
	tot++;
	a[tot][0]=h[y];
	a[tot][1]=y;
	a[tot][2]=x;
	a[tot][3]=0;
	h[y]=tot;
}
int isap(int s,int t)
{
	int i=s,j,z;
	int re=0;
	memset(p,-1,sizeof(p));
	p[s]=s;
	while(d[s]<m)
	{
		for(j=h[i];j;j=a[j][0])
			if(a[j][3]>0&&d[i]==d[a[j][2]]+1)
				break;
		if(j)
		{
			p[a[j][2]]=j;
			i=a[j][2];
			if(i==t)
			{
				z=0x7fffffff;
				for(i=t;i!=s;i=a[p[i]][1])
					z=min(z,a[p[i]][3]);
				for(i=t;i!=s;i=a[p[i]][1])
					a[p[i]][3]-=z,a[p[i]^1][3]+=z;
				re+=z;
			}
		}
		else
		{
			c[d[i]]--;
			if(c[d[i]]==0)
				return re;
			d[i]=m;
			for(j=h[i];j;j=a[j][0])
				if(a[j][3]>0)
					d[i]=min(d[i],d[a[j][2]]+1);
			c[d[i]]++;
			if(i!=s)
				i=a[p[i]][1];
		}
	}
	return re;
}
int i,j,w,x,y,z,M,N;
int main()
{
	scanf("%d %d",&M,&N);
	m=M+N+2;
	tot=1;
	for(i=1;i<=M;i++)
	{
		scanf("%d",&w);
		add(0,i,w);
		l[i]=i;
	}
	for(i=1;i<=N;i++)
	{
		
		scanf("%d",&x);
		for(j=1;j<=x;j++)
		{
			scanf("%d",&y);
			add(l[y],M+i,0x3fffffff);
			l[y]=M+i;
		}
		scanf("%d",&w);
		add(M+i,m-1,w);
	}
	printf("%d",isap(0,m-1));
	return 0;
}