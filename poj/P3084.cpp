#include<iostream>
#define inf 0xffffff
using namespace std;
int d[405];
int c[405];
int p[405];
int a[20020][4];
int h[405];
int v[405];
int i;
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
	p[s]=s;
	for(j=0;j<m;j++)
		v[j]=h[j];
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
int j,x,y,z,ans,csc;
char s[20];
int main()
{
	scanf("%d",&csc);
	while(csc--)
	{
		scanf("%d %d",&m,&n);
		memset(h,0,sizeof(h));
		memset(d,0,sizeof(d));
		memset(c,0,sizeof(c));
		tot=1;
		add(n+1,m+1,inf);
		add(m+1,n+1,0);
		for(i=1;i<=m;i++)
		{
			scanf("%s %d",s,&n);
			if(s[0]=='I')
			{
				add(0,i,inf);
				add(i,0,0);
			}
			for(j=0;j<n;j++)
			{
				scanf("%d",&x);
				x++;
				add(i,x,inf);
				add(x,i,1);
			}
		}
		m+=2;
		c[0]=m;
		ans=isap(0,m-1);
		if(ans>=inf)
			printf("PANIC ROOM BREACH\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}