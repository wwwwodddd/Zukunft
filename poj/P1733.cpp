#include <iostream>
using namespace std;
bool T=false;
struct node
{
    int v,x;
    node* n;
}hm[9941];
int f[10005],N[10005],u=0;
char c[10005];
int find(int x)
{
    int y=x%9941;
    node *p,*q;
    p=&hm[y],q=hm[y].n;
    while (q)
        if(q->v==x)
			return q->x;
        else
			p=q,q=q->n;
    node *temp=new node();temp->v=x,temp->x=++u,p->n=temp,N[u]=x;
    return u;
}
int F(int x)
{
    int t;
    if(f[x]!=x)
	{
		t=f[x];
		f[x]=F(f[x]);
		c[x]=c[t]^c[x];
	}
    return f[x];
}
int main()
{
    int i,l,n,s,t,r1,r2,v,ans;
    char ch[5];
    for(i=0;i<10005;i++)f[i]=i,c[i]=0;
    scanf("%d\n%d",&l,&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d %d %s",&s,&t,ch);
        if(T)
			continue;
        v=(ch[0]=='e')?0:1;
        s=find(s-1);
		t=find(t);
        r1=F(s);
		r2=F(t);
        if(r1==r2&&(c[s]^c[t]^v))
		{
				T=true;
				ans=i-1;
		}
        else if(r1!=r2)
        {
            if(N[r1]<N[r2])f[r2]=r1,c[r2]=c[s]^c[t]^v;
            else f[r1]=r2,c[r1]=c[s]^c[t]^v;
        }
    }
    printf("%d\n",T?ans:n);
    return 0;
}
