#include<stdio.h>
#include<iostream>
#define fr(i,n) for(int i=0;i<n;i++)
using namespace std;
int a[105][105],c[105],n,m;
inline int A(int i,int j)
{
	int re=0;
	for(int k=1,w=a[i][j];i-k>=0&&j-k>=0&&i+k<n&&j+k<m&&a[i-k][j]==w&&a[i+k][j]==w&&a[i][j+k]==w&&a[i][j-k]==w;k++)
		re++;
	return re;
}
int main()
{
	int q,x,y,z;
	char o[10];
	scanf("%d %d %*d %d",&n,&m,&q);
	fr(i,n)
		fr(j,m)
			scanf("%d",&a[i][j]);
	fr(i,n)
		fr(j,m)
			c[a[i][j]]+=A(i,j);
	while(q--)
	{
		scanf("%s",o);
		if(*o=='Q')
		{
			scanf("%d",&z);
			printf("%d\n",c[z]);
		}
		else
		{
			scanf("%d %d %d",&x,&y,&z);
			x--,y--;
			fr(i,n)
				c[a[i][y]]-=A(i,y);
			fr(i,m)
				if(i!=y)
					c[a[x][i]]-=A(x,i);
			a[x][y]=z;
			fr(i,n)
				c[a[i][y]]+=A(i,y);
			fr(i,m)
				if(i!=y)
					c[a[x][i]]+=A(x,i);
		}
	}
	return 0;
}
