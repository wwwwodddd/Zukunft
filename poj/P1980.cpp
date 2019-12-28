#include<stdio.h>
int p,q,a,n,ans;
int cmp(int p1,int q1,int p2, int q2)
{
	return p1*q2-p2*q1;
}
void sub(int &p,int &q,int d)
{
	p=p*d-q;
	q=q*d;
}
void dfs(int z,int u,int v,int cnt,int w)
{
	int x,y;
	if(cnt<=n&&u==0)
		ans++;
	if(cnt==n&&u!=0||u==0)
		return;
	for(int d=z;d<=w;d++)
	{
		if(cmp(u,v,1,d)<0)
			continue;
		sub(x = u,y = v,d);
		if(cmp(x,y,n-cnt,d)>0)
			break;
		if(x&&cmp(x,y,1,w/d)<0)
			continue;
		dfs(d,x,y,cnt+1,w/d);
	}
}
int main()
{
	while(scanf("%d %d %d %d",&p,&q,&a,&n)&&p)
	{
		ans=0;
		dfs(1,p,q,0,a);
		printf("%d\n",ans);
	}
	return 0;
}

