#include<stdio.h>
#include<string.h>
int dx[2][3]={0,0,1,0,0,-1};
int dy[2][3]={1,-1,0,1,-1,0};
int op[3]={1,0,2};
int x,n,i,x1,y1,x2,y2;
char o[20];
int a[2][100020][3];
int f[300020][3][2];
int tmp,aa[3][2],bb[3][2],cc[3][2];
inline void swap(int&x,int&y)
{
	x^=y^=x^=y;
}
void mg(int x[3][2],int y[3][2],int z[3][2],int m)
{
	int i,j,k;
	tmp=a[0][m][0]&a[1][m][0];
	x[2][0]=y[2][0]|tmp&y[0][0]&y[1][1]&z[2][0];
	x[2][1]=z[2][1]|tmp&z[0][0]&z[1][1]&y[2][1];
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
		{
			x[i][j]=0;
			for(k=0;k<2;k++)
				x[i][j]|=y[i][k]&a[k][m][0]&z[k][j];
		}
}
void ud(int i,int l,int r)
{
	if(l==r)
		f[i][2][0]=f[i][2][1]=f[i][0][1]=f[i][1][0]=a[0][l][2];
	else
	{
		if(x>(l+r)/2)
			ud(i*2+1,(l+r)/2+1,r);
		else
			ud(i*2,l,(l+r)/2);
		mg(f[i],f[i*2],f[i*2+1],(l+r)/2);
	}
}
void R(int x1,int y1,int x2,int y2,int z)
{
	for(i=0;i<3;i++)
		if(x1+dx[x1][i]==x2&&y1+dy[x1][i]==y2)
		{
			a[x1][y1][i]=z;
			a[x2][y2][op[i]]=z;
			break;
		}
	x=y1;
	ud(1,1,n);
}
void qy(int g[3][2],int i,int l,int r,int x,int y)
{
	int L[3][2],R[3][2],m=(l+r)/2;
	if(l>=x&&r<=y)
	{
		memcpy(g,f[i],sizeof(f[i]));
		return;
	}
	if(y<=m)
	{
		qy(g,i*2,l,m,x,y);
		return;
	}
	if(x>m)
	{
		qy(g,i*2+1,m+1,r,x,y);
		return;
	}
	qy(L,i*2,l,m,x,y);
	qy(R,i*2+1,m+1,r,x,y);
	mg(g,L,R,m);
	return;
}
void bd(int i,int l,int r)
{
	if(l==r)
		f[i][0][0]=f[i][1][1]=1;
	else
	{
		bd(i*2,l,(l+r)/2);
		bd(i*2+1,(l+r)/2+1,r);
	}
}
int main()
{
	scanf("%d",&n);
	bd(1,1,n);
	while(1)
	{
		scanf("%s",o);
		if(o[0]=='E')
			break;
		if(o[0]=='O')
		{
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			R(x1-1,y1,x2-1,y2,1);
		}
		if(o[0]=='C')
		{
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			R(x1-1,y1,x2-1,y2,0);
		}
		if(o[0]=='A')
		{
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			if(y1>y2)
				swap(x1,x2),swap(y1,y2);
			qy(aa,1,1,n,y1,y2);
			qy(bb,1,1,n,1,y1);
			qy(cc,1,1,n,y2,n);
			puts(aa[x1-1][x2-1]||bb[2][1]&&aa[2-x1][x2-1]||cc[2][0]&&aa[x1-1][2-x2]||bb[2][1]&&aa[2-x1][2-x2]&&cc[2][0]?"Y":"N");
		}
	}
}