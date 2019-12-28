#include<iostream>
using namespace std;
int d[405];
int c[405];
int p[405];
int a[20020][4];
int h[405];
int v[405];
int in[405];
int out[405];
int du[405];
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
int j,x,y,z,cnt,csc;
int main()
{
	scanf("%d",&csc);
	while(csc--)
	{
		scanf("%d %d",&m,&n);
		cnt=0;
		memset(h,0,sizeof(h));
		memset(d,0,sizeof(d));
		memset(c,0,sizeof(c));
		memset(du,0,sizeof(du));
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		tot=1;
		for(i=1;i<=n;i++)
		{
			scanf("%d %d %d",&x,&y,&z);
			if(z==1)
			{
				du[x]++;out[x]++;
				du[y]++;in[y]++;
			}
			else if(z==0)
			{
				du[x]++;
				du[y]++;
				add(x,y,1);
				add(y,x,1);
			}
		}
		for(i=1;i<=m;i++)
		{
			if(du[i]%2==1||du[i]/2<in[i]||du[i]/2<out[i])
			{
				printf("impossible\n");
				break;
			}
		}
		if(i!=m+1)
			continue;
		for(i=1;i<=m;i++)
		{
			if(in[i]<out[i])
			{
				add(i,m+1,out[i]-in[i]);
				add(m+1,i,0);
				cnt+=out[i]-in[i];
			}
			else if(in[i]>out[i])
			{
				add(0,i,in[i]-out[i]);
				add(i,0,0);
			}
		}
		m+=2;
		c[0]=m;
		printf("%spossible\n",isap(0,m-1)>=cnt?"":"im");
	}
	return 0;
}