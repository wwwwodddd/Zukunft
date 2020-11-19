#include<stdio.h>
#include<iostream>
#define inf 0x3fffffff
using namespace std;
int w[100020][6];
struct N
{
	int ll[6][6],rr[6][6],lr[6][6],mm[6][6];
	int l,r;
}t[400020];
int chg;
void ud(int x)
{
	N &L=t[x*2],&R=t[x*2+1];
	int dd[6][6];
	int l=t[x].l,r=t[x].r,m=l+r>>1;
	int i,j,k;
	for(i=0;i<6;i++)
		for(j=0;j<6;j++)
			dd[i][j]=min(L.rr[i][j]+w[m][i]+w[m][j],R.ll[i][j]);
	for(k=0;k<6;k++)
		for(i=0;i<6;i++)
			for(j=0;j<6;j++)
				dd[i][j]=min(dd[i][j],dd[i][k]+dd[k][j]-w[m][k]);
//	printf("%d\n",dd[0][0]);
	for(i=0;i<6;i++)
		for(j=0;j<6;j++)
			if(t[x].mm[i][j]!=dd[i][j])
			{
				t[x].mm[i][j]=dd[i][j];
				chg=1;
			}
	int d[6];
	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
		{
			d[j]=inf;
			for(k=0;k<6;k++)
				d[j]=min(d[j],L.lr[i][k]+dd[k][j]);
		}
		for(j=0;j<6;j++)
		{
			int u=L.ll[i][j];
			for(k=0;k<6;k++)
				u=min(u,L.lr[j][k]+d[k]);
			if(t[x].ll[i][j]!=u)
			{
				t[x].ll[i][j]=u;
				chg=1;
			}
		}
		for(j=0;j<6;j++)
		{
			int u=inf;
			for(k=0;k<6;k++)
				u=min(u,d[k]+R.lr[k][j]-w[m][k]);
			if(t[x].lr[i][j]!=u)
			{
				t[x].lr[i][j]=u;
				chg=1;
			}
		}
		for(j=0;j<6;j++)
		{
			d[j]=inf;
			for(k=0;k<6;k++)
				d[j]=min(d[j],R.lr[k][i]+dd[k][j]-w[m][k]);
		}
		for(j=0;j<6;j++)
		{
			int u=R.rr[i][j];
			for(k=0;k<6;k++)
				u=min(u,d[k]+R.lr[k][j]-w[m][k]);
			if(t[x].rr[i][j]!=u)
			{
				t[x].rr[i][j]=u;
				chg=1;
			}
		}
	}
}
int s[7];
void bd(int l,int r,int x)
{
	int i,j;
	t[x].l=l;
	t[x].r=r;
	if(l+1==r)
	{
		int *w=::w[l];
		for(i=0;i<6;i++)
			s[i+1]=s[i]+w[i];
		for(i=0;i<6;i++)
			for(j=0;j<6;j++)
				t[x].ll[i][j]=t[x].rr[i][j]=t[x].lr[i][j]=t[x].mm[i][j]=s[max(i,j)+1]-s[min(i,j)];
		return;
	}
	bd(l,l+r>>1,2*x);
	bd(l+r>>1,r,2*x+1);
	ud(x);
}
void cg(int l,int x)
{
	if(l<t[x].l||l>=t[x].r)
		return;
	int i,j;
	if(t[x].l+1==t[x].r)
	{
		int *w=::w[l];
		for(i=0;i<6;i++)
			s[i+1]=s[i]+w[i];
/*		for(i=0;i<6;i++)
			printf("%d\n",s[i+1]);*/
		for(i=0;i<6;i++)
			for(j=0;j<6;j++)
				t[x].ll[i][j]=t[x].rr[i][j]=t[x].lr[i][j]=t[x].mm[i][j]=s[max(i,j)+1]-s[min(i,j)];
		chg=1;
		return;
	}
	cg(l,2*x);
	cg(l,2*x+1);
	//if(chg)
	{
		chg=0;
		ud(x);
		return;
	}
}
void lud(int dl[],int dr[],int x)
{
	N &L=t[x*2],&R=t[x*2+1];
	int l=t[x].l,r=t[x].r,m=l+r>>1;
	int i,j;
	int d[6];
	for(i=0;i<6;i++)
	{
		d[i]=inf;
		for(j=0;j<6;j++)
			d[i]=min(d[i],dr[j]+t[x].mm[j][i]);
	}
	for(i=0;i<6;i++)
		for(j=0;j<6;j++)
			dl[i]=min(dl[i],d[j]+L.lr[i][j]);
	for(i=0;i<6;i++)
	{
		dr[i]=inf;
		for(j=0;j<6;j++)
			dr[i]=min(dr[i],d[j]+R.lr[j][i]-w[m][j]);
	}
/*	for(i=0;i<6;i++)
		printf("%d ",dl[i]);
	puts("");
	for(i=0;i<6;i++)
		printf("%d ",dr[i]);
	puts("");*/
	return;
}
void rud(int dl[],int dr[],int x)
{
	N &L=t[x*2],&R=t[x*2+1];
	int l=t[x].l,r=t[x].r,m=l+r>>1;
	int i,j;
	int d[6];
	for(i=0;i<6;i++)
	{
		d[i]=inf;
		for(j=0;j<6;j++)
			d[i]=min(d[i],dl[j]+t[x].mm[j][i]-w[m][j]);
	}
	for(i=0;i<6;i++)
		for(j=0;j<6;j++)
			dr[i]=min(dr[i],d[j]+R.lr[j][i]-w[m][j]);
	for(i=0;i<6;i++)
	{
		dl[i]=inf;
		for(j=0;j<6;j++)
			dl[i]=min(dl[i],d[j]+L.lr[i][j]);
	}
	return;
}
void qy1(int x1,int y1,int dl1[],int dr1[],int x)
{
	int i;
	if(t[x].l+1==t[x].r)
	{
		for(i=0;i<6;i++)
			dl1[i]=dr1[i]=t[x].mm[x1][i];
		return;
	}
	int l=t[x].l,r=t[x].r,m=l+r>>1;
	if(y1<m)
	{
		qy1(x1,y1,dl1,dr1,x*2);
		lud(dl1,dr1,x);
	}
	else
	{
		qy1(x1,y1,dl1,dr1,x*2+1);
		rud(dl1,dr1,x);
	}
	return;
}
int qy2(int x1,int y1,int x2,int y2,int dl1[],int dr1[],int dl2[],int dr2[],int x)
{
	int i,j;
	if(t[x].l+1==t[x].r)
	{
		for(i=0;i<6;i++)
		{
			dl1[i]=dr1[i]=t[x].mm[x1][i];
			dl2[i]=dr2[i]=t[x].mm[x2][i];
		}
		return t[x].mm[x1][x2];
	}
	int l=t[x].l,r=t[x].r,m=l+r>>1;
	if(y2<m)
	{
		int re=qy2(x1,y1,x2,y2,dl1,dr1,dl2,dr2,x*2);
		for(i=0;i<6;i++)
			for(j=0;j<6;j++)
				re=min(re,dr1[i]+t[x].mm[i][j]+dr2[j]);
		lud(dl1,dr1,x);
		lud(dl2,dr2,x);
		return re;
	}
	else if(y1>=m)
	{
		int re=qy2(x1,y1,x2,y2,dl1,dr1,dl2,dr2,x*2+1);
		for(i=0;i<6;i++)
			for(j=0;j<6;j++)
				re=min(re,dl1[i]+t[x].mm[i][j]+dl2[j]-w[m][i]-w[m][j]);
		rud(dl1,dr1,x);
		rud(dl2,dr2,x);
		return re;
	}
	else
	{
		qy1(x1,y1,dl1,dr1,x*2);
		qy1(x2,y2,dl2,dr2,x*2+1);
		int re=inf;
		for(i=0;i<6;i++)
			for(j=0;j<6;j++)
				re=min(re,dr1[i]+t[x].mm[i][j]+dl2[j]-w[m][j]);
		lud(dl1,dr1,x);
		rud(dl2,dr2,x);
		return re;
	}
}
int i,j,n;
int main()
{
	scanf("%d",&n);
	for(j=0;j<6;j++)
		for(i=0;i<n;i++)
			scanf("%d",&w[i][j]);
	bd(0,n,1);
	int q,o;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&o);
		if(o==1)
		{
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			x--,y--;
			w[y][x]=z;
			cg(y,1);
		}
		else
		{
			int x1,y1,x2,y2;
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			x1--,x2--,y1--,y2--;
			if(y1>y2)
				swap(x1,x2),swap(y1,y2);
			static int dl1[6],dr1[6],dl2[6],dr2[6];
			printf("%d\n",qy2(x1,y1,x2,y2,dl1,dr1,dl2,dr2,1));
		}
	}
	return 0;
}