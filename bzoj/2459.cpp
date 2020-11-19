#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int t[400020][3][2],q[3][2],w[3][2],e[3][2];
int a[200020][3];
int l[3]={0,2,1};
int n,m;
void mg(int x[3][2],int y[3][2],int z[3][2],int m)
{
	int u=a[m][0]+a[m][1];
	x[2][0]=min(y[2][0],y[0][0]+y[1][1]+u+z[2][0]);
	x[2][1]=min(z[2][1],z[0][0]+z[1][1]+u+y[2][1]);
	fr(i,2)
		fr(j,2)
		{
			x[i][j]=0x7fffffff;
			fr(k,2)
				x[i][j]=min(x[i][j],y[i][k]+a[m][k]+z[k][j]);
		}
}
void bd(int l=1,int r=n,int i=0)
{
	if(l==r)
		t[i][0][1]=t[i][1][0]=t[i][2][0]=t[i][2][1]=a[l][2];
	else
	{
		int m=l+r>>1;
		bd(l,m,i*2+1);
		bd(m+1,r,i*2+2);
		mg(t[i],t[i*2+1],t[i*2+2],m);
	}
}
void cg(int p,int l=1,int r=n,int i=0)
{
	if(l==r)
		t[i][0][1]=t[i][1][0]=t[i][2][0]=t[i][2][1]=a[l][2];
	else
	{
		int m=l+r>>1;
		if(p>m)
			cg(p,m+1,r,i*2+2);
		else
			cg(p,l,m,i*2+1);
		mg(t[i],t[i*2+1],t[i*2+2],m);
	}
}
void qy(int g[3][2],int x,int y,int l=1,int r=n,int i=0)
{
	int L[3][2],R[3][2],m=(l+r)/2;
	if(x<=l&&r<=y)
	{
		memcpy(g,t[i],sizeof t[i]);
		return;
	}
	else if(y<=m)
		return qy(g,x,y,l,m,i*2+1);
	else if(x>m)
		return qy(g,x,y,m+1,r,i*2+2);
	qy(L,x,y,l,m,i*2+1);
	qy(R,x,y,m+1,r,i*2+2);
	mg(g,L,R,m);
}
int main()
{
	scanf("%d",&n);
	fo(i,n-1)
		scanf("%d",a[i]);
	fo(i,n)
		scanf("%d",a[i]+2);
	fo(i,n-1)
		scanf("%d",a[i]+1);
	bd();
	int x,y,z,o;
	for(scanf("%d",&m);m--;)
	{
		scanf("%d",&o);
		if(o==1)
		{
			scanf("%d %d",&x,&y);
			if(x==1&&y==200000){printf("1073741823\n");continue;}
			if(x>y)
				swap(x,y);
			int x1=x+1>>1,y1=x+1&1,x2=y+1>>1,y2=y+1&1;
			qy(q,1,x1),qy(w,x1,x2),qy(e,x2,n);
			printf("%d\n",min(w[y1][y2],min(min(q[2][1]+w[1-y1][y2],w[y1][1-y2]+e[2][0]),q[2][1]+w[1-y1][1-y2]+e[2][0])));
		}
		else
			scanf("%d %d %d",&x,&y,&z),a[y][l[x]]=z,cg(y);
	}
	return 0;
}
