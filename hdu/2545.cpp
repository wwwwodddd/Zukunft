#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[200020][2],tot;
int h[100020];
int d[100020];
int c[100020];
int q[100020],bb,ff;
int n,m,i,r;
void add(int x,int y)
{
    tot++;
    a[tot][0]=h[x];
    a[tot][1]=y;
    h[x]=tot;
}
void bfs(int x)
{
    int u,i;
    bb=ff=0;
    q[ff++]=x;
    while(bb<ff)
    {
        u=q[bb++];
        for(i=h[u];i;i=a[i][0])
            if(d[a[i][1]]>d[u]+1)
            {
                d[a[i][1]]=d[u]+1;
                q[ff++]=a[i][1];
            }
    }
    return;
}
int main()
{
    int x,y;
    while(scanf("%d %d",&n,&m),n+m)
    {
        memset(h,0,sizeof(h));
        memset(c,0,sizeof(c));
        for(i=1;i<n;i++)
        {
            scanf("%d %d",&x,&y);
            add(x,y);
            c[y]++;
        }
        memset(d,0x3f,sizeof(d));
		r=min_element(c+1,c+1+n)-c;
        d[r]=0;
        bfs(r);
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&x,&y);
            puts(d[y]<d[x]?"pfz":"lxh");
        }
    }
    return 0;    
}
