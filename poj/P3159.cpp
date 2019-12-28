#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#define INF 0x7fffffff
using namespace std;
int a[300020][3];//[0] last one [1] target [2] value
int c[30020];
int d[30020];
int q[100002];
int t[30020];
int sum;
int m,n;
int x,y,z;
int b,f,dd;
void bin(int x)
{
	t[x]=1;
	q[b++]=x;
	if(b>100000)
		b=0;
	return;

}
void fin(int x)
{
	q[f--]=x;
	if(f==-1)
		f=100000;
	return;
}
int pop()
{
	int re=q[f++];
	sum-=d[re];
	t[re]=0;
	if(f>100000)
		f=0;
	return re;
}
int size()
{
	return b-f>0?b-f:b-f+100000;
}
int check(int x)
{
	if(f==b||d[x]<=sum/size())
		return 1;
	bin(pop());
	return 0;
}
void in(int x)
{
	sum+=d[x];
	t[x]=1;
	if(d[x]<d[q[f]])
		fin(x);
	else
		bin(x);
	return;
}
int main()
	{
	int i,j;
	scanf("%d %d",&m,&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		a[i][0]=c[x];
		a[i][1]=y;
		a[i][2]=z;
		c[x]=i;
	}
	memset(d,0x7f,sizeof(d));
	d[1]=0;
	b=f=0;
	t[1]=1;
	bin(1);
	while(b!=f)
	{
	x=pop();
	if(check(x))
		for(i=c[x];i;i=a[i][0])
			if(d[a[i][1]]>d[x]+a[i][2])
			{
				dd=d[x]+a[i][2]-d[a[i][1]];	
				d[a[i][1]]=d[x]+a[i][2];
				if(t[a[i][1]])
					sum-=dd;
				else
					in(a[i][1]);
			}
	}
	printf("%d",d[m]);
	return 0;
}
/*
7 11
2 4 2
1 4 3
7 2 2
3 4 3
5 7 5
7 3 3
6 1 1
6 3 4
2 4 3
5 6 3
7 2 1
*/