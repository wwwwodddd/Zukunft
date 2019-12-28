#include<stdio.h>
#include<iostream>
int v[30],p[30],q[30];
int c[2],w[2],ans,n,d;
void dfs(int x,int y)
{
	if(x==n)
		ans=std::max(ans,c[1]);
	else
		for(int i=0;i<n;i++)
			if(!v[i])
			{
				v[i]=1;
				w[y]+=p[i];
				c[y]+=q[i];
				dfs(x+1,y^(w[y]>w[1^y]+d));
				w[y]-=p[i];
				c[y]-=q[i];
				v[i]=0;
			}
}
int main()
{
	scanf("%d %d",&n,&d);
	for(int i=0;i<n;i++)
		scanf("%d %d",p+i,q+i);	
	dfs(0,0);
	printf("%d",ans);
}
