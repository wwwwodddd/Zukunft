#include<stdio.h>
#include<string.h>
int n,l[1001];
int x,y,z,ans;
int v[1001],g[1001][1001];
bool dfs(int x)
{
for(int i=1;i<100;i++)
{
if(g[x][i]&&!v[i])
{
v[i]=1;
if(l[i]==-1||dfs(l[i]))
{
l[i]=x;
return 1;
}
}
}
return 0;
}
int main()
{
int i,j,k,x,n;
while(scanf("%d",&n)+1)
{
memset(g,0,sizeof(g));
for(i=1;i<=n;i++)
{
scanf("%d",&z);
for(j=0;j<z;j++)
{
scanf("%d %d",&x,&y);
g[i][12*x+y]=1;
}
}
memset(l,-1,sizeof(l));
ans=0;
for(i=1;i<=n;i++)
{
memset(v,0,sizeof(v));
if(dfs(i))
ans++;
}
printf("%d\n",ans);
}
return 0;
}
