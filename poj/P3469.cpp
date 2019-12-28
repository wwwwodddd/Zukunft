#include<iostream>
using namespace std;
int d[20020];
int c[20020];
int p[20020];
int a[800020][4];
int h[20020];
int v[20020];
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
}
int isap(int s,int t)
{
	int i=s,j,z;
	int re=0;
	memset(p,-1,sizeof(p));
	memcpy(v,h,sizeof(h));
	p[s]=s;
	while(d[s]<m)
	{
		for(j=v[i];j;j=a[j][0])
			if(a[j][3]>0&&d[i]==d[a[j][2]]+1)
				break;
		v[i]=j;
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
			v[i]=h[i];
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
int i,j,w,x,y,z,M,N,ans;
int main()
{
	scanf("%d %d",&M,&N);
	tot=1;
	m=M+2;
	for(i=1;i<=M;i++)
	{
		scanf("%d %d",&x,&y);
		add(0,i,x);
		add(i,0,0);
		add(i,m-1,y);
		add(m-1,i,0);
	}
	for(i=0;i<N;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	printf("%d",isap(0,m-1));
	return 0;
}