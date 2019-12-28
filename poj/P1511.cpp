#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<queue>
#define INF 0x7fffffff
using namespace std;
int a[2000020][3];
int p[1000020];
int c[1000020];
int v[1000020];
__int64 sum;
int m,n,now,tar;
struct node
{
	int v,c;
	bool operator < (const node &a) const
	{
		return a.c<c;
	}
}x,y;
queue<node>qwe;
int cmp(const void *a,const void *b)
{
if(tar==0)
return ((int *)a)[0]-((int *)b)[0];
else
return ((int *)a)[1]-((int *)b)[1];
}
void spfa(int vx)
{
	int i;
	for(i=2;i<=m;i++)
        v[i]=INF;
	tar=vx;
    qsort(a,n,12,cmp);
    memset(c,0,sizeof(c));
	while(!qwe.empty())
		qwe.pop();
	for(i=0;i<n;i++)
		c[a[i][vx]]++;
    for(i=1;i<=m;i++)
        c[i]+=c[i-1];
	x.v=1;
	x.c=0;
	qwe.push(x);
    while(!qwe.empty())
    {
	y=qwe.front();
    qwe.pop();
    if(y.c!=v[y.v])
		continue;
	now=y.v;
    for(i=c[now-1];i<c[now];i++)
        if(v[a[i][vx^1]]>v[now]+a[i][2])
        {
            v[a[i][vx^1]]=v[now]+a[i][2];
			x.v=a[i][vx^1];
			x.c=v[a[i][vx^1]];
			qwe.push(x);
		}          
    }
	for(i=1;i<=m;i++)
	sum+=v[i];
}
int main()
    {
	freopen("C:\\c.in","r",stdin);
	freopen("C:\\c2.out","w",stdout);
    int i,j;
	scanf("%d",&j);
	while(j--)
		{
		sum=0;
		scanf("%d %d",&m,&n);
		for(i=0;i<n;i++)
			scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
		spfa(0);
		spfa(1);
		printf("%I64d\n",sum);
		}
	return 0;
}