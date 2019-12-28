#include<iostream>
using namespace std;
const int inf=0x3fffffff;
int dn[250][250],up[250][250],ct[250][250],in[250],ot[250];
int d[250];
int c[250];
int p[250];
int a[200020][4];
int h[250];
int v[250];
char s[20];
int n,m;
int N,M,L,tot,i,j,ans,csc,sum;
int x,y,z,sumn,summ;
int flag;
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
void ins(int x,int y,int w,int u)
{
	int i,j;
	if(x&&y)
		dn[x][y]=max(dn[x][y],w),up[x][y]=min(up[x][y],u);
	if(!x&&y)
		for(i=1;i<=N;i++)
			dn[i][y]=max(dn[i][y],w),up[i][y]=min(up[i][y],u);
	if(x&&!y)
		for(i=1;i<=M;i++)
			dn[x][i]=max(dn[x][i],w),up[x][i]=min(up[x][i],u);
	if(!x&&!y)
		for(i=1;i<=N;i++)
			for(j=1;j<=M;j++)
				dn[i][j]=max(dn[i][j],w),up[i][j]=min(up[i][j],u);
}
int main()
{
	scanf("%d",&csc);
	while(csc--)
	{
		scanf("%d %d",&N,&M);
		memset(dn,0,sizeof(dn));
		memset(up,0x3f,sizeof(up));
		memset(h,0,sizeof(h));
		memset(in,0,sizeof(in));
		memset(ot,0,sizeof(ot));
		memset(d,0,sizeof(d));
		memset(c,0,sizeof(c));
		tot=1;
		sum=0;
		m=N+M+4;
		flag=1;
		sumn=summ=0;
		for(i=1;i<=N;i++)
		{
			scanf("%d",&x);
			sumn+=x;
			in[i]+=x;
			ot[N+M+1]+=x;
		}
		for(i=1;i<=M;i++)
		{
			scanf("%d",&x);
			summ+=x;
			ot[i+N]+=x;
			in[N+M+2]+=x; 
		}
		scanf("%d",&L);
		for(i=1;i<=L;i++)
		{
			scanf("%d%d%s%d",&x,&y,&s,&z);
			if(s[0]=='=')
				ins(x,y,z,z);
			if(s[0]=='>')
				ins(x,y,z+1,inf);
			if(s[0]=='<')
				ins(x,y,0,z-1);
		}
		if(sumn!=summ)
			flag=0;
		for(i=1;i<=N;i++) 
			for(j=1;j<=M;j++)
			{
				in[j+N]+=dn[i][j];
				ot[i]+=dn[i][j];
				if(up[i][j]<dn[i][j])
					flag=0;
				add(i,j+N,up[i][j]-dn[i][j]);
				add(j+N,i,0);
				ct[i][j]=tot;
			}
		for(i=1;i<=N+M+2;i++)
		{
			j=in[i]-ot[i];
			if(j>0)
			{
				add(0,i,j);
				add(i,0,0);
				sum+=j;
			}
			if(j<0)
			{
				add(i,m-1,-j);
				add(m-1,i,0);
			}
		}
		add(N+M+2,N+M+1,inf);
		if(isap(0,m-1)!=sum)
			flag=0;
		if(flag)
		{
			for(i=1;i<=N;i++)
			{
				for(j=1;j<=M;j++)
					printf("%d ",dn[i][j]+a[ct[i][j]][3]);
				printf("\n");
			}
		}
		else
			puts("IMPOSSIBLE");
		puts("");
	}
	return 0;
}
