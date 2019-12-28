#include<stdio.h>
#include<string.h>
int a[20020][2];
int s[10020];
int v[10020];
int h[10020];
int n,e,x,y,i;
int F(int x)
{
	int p=0,i,r=0;
	v[x]=1;
	for(i=h[x];i;i=a[i][0])
	{
		if(v[a[i][1]])
			continue;
		r+=F(a[i][1]);
		if(p==2)
			continue;
		if(s[a[i][1]]==0)
			p=2;
		if(s[a[i][1]]==2)
			p=1;
	}
	s[x]=p;
	return r+p/2;
}
void add(int x,int y)
{
	e++;
	a[e][0]=h[x];
	a[e][1]=y;
	h[x]=e;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	add(n+1,1);
	add(1,n+1);
	printf("%d\n",F(n+1));
	return 0;
}
