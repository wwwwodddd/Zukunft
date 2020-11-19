#include<stdio.h>
int f[30020];
int n,m,x,y,z,q;
double c[30020];
char s[105][105];
int F(int x)
{
	return f[x]!=x?f[x]=F(f[x]):x;
}
int U(int x,int y)
{
	f[F(x)]=F(y);
}
int C(int x,int y,int z)
{
	return z*n*m+x*m+y;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<3*n*m;i++)
		f[i]=i;
	for(int i=0;i<n;i++)
		scanf("%s",s[i]);
	for(int i=1;i<n;i++)
		for(int j=0;j<m;j++)
			if(s[i-1][j]==s[i][j])
				U(C(i-1,j,0),C(i,j,1)),U(C(i-1,j,2),C(i,j,0));
			else
				U(C(i-1,j,0),C(i,j,0)),U(C(i-1,j,2),C(i,j,1));
	for(int i=0;i<n;i++)
		for(int j=1;j<m;j++)
			if(s[i][j]=='1')
			{
				if(s[i][j-1]==s[i][j])
					U(C(i,j-1,0),C(i,j,2)),U(C(i,j-1,1),C(i,j,0));
				else
					U(C(i,j-1,0),C(i,j,0)),U(C(i,j-1,2),C(i,j,2));
			}
			else
			{
				if(s[i][j-1]==s[i][j])
					U(C(i,j-1,0),C(i,j,1)),U(C(i,j-1,2),C(i,j,0));
				else
					U(C(i,j-1,0),C(i,j,0)),U(C(i,j-1,1),C(i,j,1));
			}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			c[F(C(i,j,0))]+=2.4292036732051034;
			c[F(C(i,j,1))]+=0.7853981633974483;
			c[F(C(i,j,2))]+=0.7853981633974483;
		}
	for(scanf("%d",&q);q--;)
	{
		scanf("%d %d",&x,&y);
		if(x%2!=y%2)
			puts("0.0000");
		else
		{
			if(x%2)
				x/=2,y/=2,z=0;
			else if(x<2*n&&y<2*m)
				x/=2,y/=2,z=s[x][y]=='0';
			else if(x<2*n&&y==2*m)
				x/=2,--y/=2,z=s[x][y]=='1';
			else if(x==2*n&&y<2*m)
				--x/=2,y/=2,z=(s[x][y]=='1')*2;
			else
				--x/=2,--y/=2,z=(s[x][y]=='0')*2;
			printf("%.4lf\n",c[F(C(x,y,z))]);
		}
	}
	return 0;
}
