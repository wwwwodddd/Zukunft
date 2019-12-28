#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int c[100020];
int l[100020];
int r[100020];
int a[200020][2];
int h[100020];
int s[100020];
int tot,tim;
int i,j,k;
int n,m,x,y;
char o;
int max(int x,int y)
{
	return x>y?x:y;
}
void R(int x,int v)
{
	for(int i=x;i<=n;i+=(i&(-i)))
		c[i]+=v;
}
int G(int x)
{
	int q=0;
	for(int i=x;i>0;i-=(i&(-i)))
		q+=c[i];
	return q;
}
void add(int x,int y)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	h[x]=tot;
	return;
}
void dfs(int x,int y)
{
	tim++;
	l[x]=tim;
	for(int i=h[x];i;i=a[i][0])
		if(a[i][1]!=y)
			dfs(a[i][1],x);
	r[x]=tim;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		s[i]=1,R(i,1);
	for(i=1;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	scanf("%d",&m);
	while(m--)
	{
		scanf("%s",&o);
		if(o=='C')
		{
			scanf("%d",&x);
			if(s[x])
				R(l[x],-1);
			else
				R(l[x],1);
			s[x]^=1;
		}
		else if(o=='Q')
		{
			scanf("%d",&x);
			printf("%d\n",G(r[x])-G(l[x]-1));
		}
	}
	return 0;
}

