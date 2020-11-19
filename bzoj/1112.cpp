#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define id(x) (x+1)
struct node
{
	long long s,w;
	int size,fa,a[2];
	bool rev;
}t[300000];
int tot,head,Null,first;
int pos[100020],did;
int ab(int x)
{
	return x>0?x:-x;
}
int newnode(int k)
{
	tot++;
	t[tot].s=t[tot].w=k;
	t[tot].size=1;
	t[tot].fa=t[tot].a[1]=t[tot].a[0]=Null;
	return tot;
}
void ud(int x)
{
	if(x==Null) return;
	t[x].size=t[t[x].a[0]].size+t[t[x].a[1]].size+1;
	t[x].s=t[x].w+t[t[x].a[0]].s+t[t[x].a[1]].s;
}
void rotate(int x,int p)
{
	int k=t[x].fa;
	t[k].a[!p]=t[x].a[p];
	if(t[x].a[p]!=Null) t[t[x].a[p]].fa=k;
	t[x].fa=t[k].fa;
	if(t[k].fa!=Null) t[t[k].fa].a[t[t[k].fa].a[1]==k]=x;
	t[k].fa=x;
	t[x].a[p]=k;
	if(k==head) head=x;
	ud(k);
}
void splay(int x,int f)
{
	int k,p1,p2;
	for(;t[x].fa!=f;)
	{
		k=t[x].fa;
		if(t[k].a[0]==x) p1=0;
		else p1=1;
		if(t[t[k].fa].a[0]==k) p2=0;
		else p2=1;
		if(t[k].fa==f) rotate(x,1-p1);
		else if(p1==p2) {rotate(k,1-p1);rotate(x,1-p1);}
		else {rotate(x,1-p1);rotate(x,1-p2);}
	}
	ud(x);
}
void select(int k,int f)
{
	int now;
	for(now=head;;)
	{
		int tmp=t[t[now].a[0]].size;
		if(tmp+1==k) break;
		if(k<=tmp) now=t[now].a[0];
		else now=t[now].a[1],k-=tmp+1;
	}
	splay(now,f);
}
void del(int x)
{
	splay(x,Null);
	int ls=t[t[x].a[0]].size;
	select(id(ls-1),Null);
	select(id(ls+1),head);
	t[t[head].a[1]].a[0]=Null;
	ud(t[head].a[1]);
	ud(head);
	splay(t[head].a[1],Null);
}
void ins(int x)
{
	int now=head,last=head;
	int re=0x7fffffff;
	while(now!=Null)
	{
		if(x>t[now].w)
			last=now,now=t[now].a[1];
		else
			last=now,now=t[now].a[0];
	}
	int nd=newnode(x);
	if(x>t[last].w)
		t[last].a[1]=nd;
	else
		t[last].a[0]=nd;
	t[nd].fa=last;
	splay(nd,Null);
	pos[did]=nd;
	return;
}
void init()
{
	Null=newnode(0);
	t[Null].size=0;
	t[Null].s=0;
	head=newnode(-100000000);
	t[head].a[1]=newnode(100000000);
	t[t[head].a[1]].fa=head;
	ud(head);
}
int main()
{
	int n,k,i,x;
	long long ans,lt,rt;
	scanf("%d %d",&n,&k);
	init();
	for(i=1;i<=k;i++)
	{
		scanf("%d",&x);
		did=i;
		ins(x);
	}
	select(id((k+1)/2),Null);
	lt=t[head].w*(t[t[head].a[0]].size-1)-(t[t[head].a[0]].s+100000000);
	rt=(t[t[head].a[1]].s-100000000)-t[head].w*(t[t[head].a[1]].size-1);
	ans=lt+rt;
	for(i=k+1;i<=n;i++)
	{
		scanf("%d",&x);
		did=i;
		ins(x);
		del(pos[i-k]);
		select(id((k+1)/2),Null);
		lt=t[head].w*(t[t[head].a[0]].size-1)-(t[t[head].a[0]].s+100000000);
		rt=(t[t[head].a[1]].s-100000000)-t[head].w*(t[t[head].a[1]].size-1);
		ans=min(ans,lt+rt);
	}
	printf("%lld\n",ans);
	return 0;
}