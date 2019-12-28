#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<queue>
#define INF 0x7fffffff
using namespace std;
int a[200020][3];
int c[1020];
int v[1020];
int b[1020];
int t[1020];
int m,n,f,s;
int y,e;
queue<int>q;
int cmp(const void *a,const void *b)
{
if(f==0)
return ((int *)a)[0]-((int *)b)[0];
else
return ((int *)a)[1]-((int *)b)[1];
}
void spfa(int x)
{
	int i;
	for(i=1;i<=m;i++)
        v[i]=INF;
	f=x;
    qsort(a,n,12,cmp);
    memset(c,0,sizeof(c));
	while(!q.empty())
		q.pop();
	for(i=0;i<n;i++)
		c[a[i][x]]++;
    for(i=1;i<=m;i++)
        c[i]+=c[i-1];
	v[s]=0;
	q.push(s);
    while(!q.empty())
    {
	y=q.front();
    q.pop();
	t[y]=0;
    for(i=c[y-1];i<c[y];i++)
        if(v[a[i][x^1]]>v[y]+a[i][2])
        {
            v[a[i][x^1]]=v[y]+a[i][2];
				if(!t[a[i][x^1]])
			q.push(a[i][x^1]);
		}          
    }
}
int main()
    {
//	freopen("C:\\c.txt","r",stdin);
//	freopen("C:\\o.txt","w",stdout);
    int i,j;
	scanf("%d %d %d",&m,&n,&s);
	for(i=0;i<n;i++)
		scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
	spfa(0);
	memcpy(b,v,sizeof(b));
	spfa(1);
	for(i=1;i<=m;i++)
		if(e<b[i]+v[i])
			e=b[i]+v[i];
	printf("%d\n",e);
	return 0;
}
