#include<iostream>
#include<algorithm>
using namespace std;
struct T
{
	int v,l,r,f;
	char s[100];
	void clear(){l=r=f=0;}
	bool operator<(T t){return strcmp(s,t.s)<0;}
}t[50010];
int n;
void ins(int i)
{
	int j=i-1;
	while(t[j].v<t[i].v)
		j=t[j].f;
	t[i].l=t[j].r;
	t[j].r=i;
	t[i].f=j;
}
void dfs(int i)
{
	if(i)
	{
		putchar('(');
		dfs(t[i].l);
		printf("%s/%d",t[i].s,t[i].v);
		dfs(t[i].r);
		putchar(')');
	}
}
int main()
{
	while(scanf("%d",&n),n)
	{
		int i;
		t[0].clear();
		t[0].v=1<<30;
		for(i=1;i<=n;i++)
		{
			t[i].clear();
			scanf("%*[ ]%[a-z]/%d",t[i].s,&t[i].v);
		}
		sort(t+1,t+n+1);
		for(i=1;i<=n;i++)
			ins(i);
		dfs(t[0].r);
		puts("");
	}
	return 0;
}