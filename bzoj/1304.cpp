#include<stdio.h>
#include<iostream>
using namespace std;
int n,m,x,y;
int c[100020];
int h[100020];
int a[200020][2],tot;
int f[100020][3];
void add(int x,int y)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	h[x]=tot;
}
void F(int x,int y)
{
	if(c[x]==1)
		return f[x][0]=f[x][2]=1,f[x][1]=0,void();
	if(c[x]==2)
		return f[x][0]=f[x][1]=1,f[x][2]=0,void();
	int s0=0,s1=0,s2=0;
	for(int i=h[x];i;i=a[i][0])
		if(a[i][1]!=y)
		{
			F(a[i][1],x);
			s0+=f[a[i][1]][0];
			s1+=min(f[a[i][1]][0],f[a[i][1]][1]);
			s2+=min(f[a[i][1]][0],f[a[i][1]][2]);
		}
	f[x][0]=min(s0,min(s1,s2)+1);
	f[x][1]=min(s1,s2+1);
	f[x][2]=min(s1+1,s2);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d",c+i),c[i]++;
	for(int i=1;i<n;i++)
		scanf("%d %d",&x,&y),add(x,y),add(y,x);	
	F(m+1,0);
	printf("%d",f[m+1][0]);
	return 0;
}
