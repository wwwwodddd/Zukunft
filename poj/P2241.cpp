#include<stdio.h>
int n,x,y,z;
int t,f,ans;
int i,j,k;
int d[100][100];
int a[100][3];
int max(int a,int b)
{
	return a>b?a:b;
}
int m(int x,int y)
{
	if((a[x][0]>a[y][0]&&a[x][1]>a[y][1])||(a[x][0]>a[y][1]&&a[x][1]>a[y][0]))
		return a[y][2];
	else
		return -0x3fffffff;
}
void add(int x,int y,int z)
{
	a[t][0]=x;
	a[t][1]=y;
	a[t++][2]=z;
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
		t=0;
		for(i=0;i<n;i++)
		{
			scanf("%d %d %d",&x,&y,&z);
			add(x,y,z);
			add(y,z,x);
			add(z,x,y);
		}
		for(i=0;i<t;i++)
			for(j=0;j<t;j++)
				d[i][j]=m(i,j);
		for(k=0;k<t;k++)
			for(i=0;i<t;i++)
				for(j=0;j<t;j++)
					if(d[i][j]<d[i][k]+d[k][j])
						d[i][j]=d[i][k]+d[k][j];
		ans=0;
		for(i=0;i<t;i++)
			for(j=0;j<t;j++)
				ans=max(ans,d[i][j]+a[i][2]);
		printf("Case %d: maximum height = %d\n",++f,ans);
	}
	return 0;
}