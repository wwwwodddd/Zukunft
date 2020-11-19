#include<stdio.h>
#define inf 0x3fffffff;
int n[1000020],p[1000020],w[1000020];
int ans,m,u,tot;
void ins(int x,int y)
{
	p[y]=x;
	n[y]=n[x];
	p[n[x]]=y;
	n[x]=y;
}
void del(int x)
{
	n[p[x]]=n[x];
	p[n[x]]=p[x];
}
void work()
{
	int i,j,k;
	for(k=1;k<m;k++)
	{
		for(i=n[0];;i=n[i])
			if(w[p[i]]<=w[n[i]])
				break;
		u=w[i]+w[p[i]];
		ans+=u;
		for(j=p[p[i]];w[j]<=u;j=p[j]);
		w[tot]=u;
		ins(j,tot);
		tot++;
		del(i);
		del(p[i]);
	}
}
int main()
{
	int i;
	scanf("%d",&m);
	tot=m+2;
	ans=0;
	w[0]=w[m+1]=inf;
	for(i=0;i<=m+1;i++)
	{
		p[i]=i-1;
		n[i]=i+1;
	}
	for(i=1;i<=m;i++)
		scanf("%d",&w[i]);
	work();
	printf("%d\n",ans);
	return 0;	
}
