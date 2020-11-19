#include<stdio.h>
#include<algorithm>
using namespace std;
int a[200020][2],tot;
int h[100020];
int w[100020];
int s[100020],ss=1;
int n,x,y,z,q;
void add(int x,int y)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	h[x]=tot;
}
void dfs(int x,int y)
{
	y+=w[x];
	s[ss++]=y;
	if(*lower_bound(s,s+ss,y-q)==y-q)
		z++;
	for(int i=h[x];i;i=a[i][0])
		dfs(a[i][1],y);
	ss--;
}
int main()
{
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",w+i);
	for(int i=1;i<n;i++)
		scanf("%d %d",&x,&y),add(x,y);
	dfs(1,0);
	printf("%d",z);
	return 0;
}
