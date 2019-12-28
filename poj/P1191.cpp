

/*POJ1191棋盘分隔，刘汝佳黑书面有解析，大概思路如下：
 *	根据方差公式推倒出如果需要方差最小，则需要每个被减数的平方最小，即每块棋盘的总分平方和最小
 *	考虑左上角坐标为(x1,y1),右下角坐标为(x2,y2)的棋盘，设它的总和为sum[x1,y1,x2,y2]切割k次以后得到
 *	k+1块矩形的总分平方和最小值为d[k,x1,y1,x2,y2]，则它可以沿着横线切，也可以沿着竖线切，然后选一
 *  块继续切（递归）。。
 *	状态转移方程：
 *	d[k,x1,y1,x2,y2]=min{
 *	min{d[k-1,x1,y1,a,y2]+s[a+1,y1,x2,y2]^2,d[k-1,a+1,y1,x2,y2]+s[x1,y1,a,y2]^2},
 *	min{d[k-1,x1,y1,x2,b]+s[x1,b+1,x2,y2]^2,d[k-1,x1,b+1,x2,y2]+s[x1,y1,x2,b]^2}}
 *	其中：(x1<=a<x2),(y1<=b<y2);
 *	为便于理解，这里用的是递归的方法，另附网上牛人循环的办法。
*/
#include<iostream>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int m[9][9];
int sum[9][9];
int d[15][9][9][9][9];
int needsum(int x1,int y1,int x2,int y2)
{return sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1];}
int min(int a,int b)
{ return a>b?b:a; }
int fun(int k,int x1,int y1,int x2,int y2)
{
	int t,a,b,c,e,MIN=10000000;
	if(d[k][x1][y1][x2][y2] !=-1)
		return d[k][x1][y1][x2][y2];
	if(k==0)
	{
		t=needsum(x1,y1,x2,y2);
		d[k][x1][y1][x2][y2]=t*t;
		return t*t;
	}
	for(a=x1;a<x2;a++)
	{
		c=needsum(a+1,y1,x2,y2);
		e=needsum(x1,y1,a,y2);
		t=min(fun(k-1,x1,y1,a,y2)+c*c,fun(k-1,a+1,y1,x2,y2)+e*e);
		if(MIN>t) MIN=t;
	}
	for(b=y1;b<y2;b++)
	{
		c=needsum(x1,b+1,x2,y2);
		e=needsum(x1,y1,x2,b);
		t=min(fun(k-1,x1,y1,x2,b)+c*c,fun(k-1,x1,b+1,x2,y2)+e*e);
		if(MIN>t) MIN=t;
	}
	d[k][x1][y1][x2][y2]=MIN;
	return MIN;
}
int main()
{
	memset(sum ,0 ,sizeof(sum));
	memset(d ,-1 ,sizeof(d));
	int n;
	cin>>n;
	for (int i=1;i<9;i++)
		for (int j=1,rowsum=0;j<9;j++)
		{
			cin>>m[i][j];
			rowsum +=m[i][j];
			sum[i][j] += sum[i-1][j] + rowsum;
		}
	double result = n*fun(n-1,1,1,8,8)-sum[8][8]*sum[8][8];
	cout<<setiosflags(ios::fixed)<<setprecision(3)<<sqrt(result/(n*n))<<endl;	
	return 0;
}
/*int fun(int k)
{
	int t,a,b,c,e,d,MIN,i,j,m,n;
	for(i=1;i<=8;i++)
		for(j=1;j<=8;j++)
			for(m=1;m<=8;m++)
				for(n=1;n<=8;n++)
				{
					t=needsum(i,j,m,n);
					d[0][i][j][m][n]=t*t;
				}
				for(a=1;a<=k;a++)
					for(i=1;i<=8;i++)
						for(j=1;j<=8;j++)
							for(m=1;m<=8;m++)
								for(n=1;n<=8;n++)
								{
									MIN=10000000;
									if((m-i+1)*(n-j+1)<a+1) {d[a][i][j][m][n]=MIN;continue;}
									for(d=i;d<m;d++)
									{
										c=needsum(d+1,j,m,n);
										e=needsum(i,j,d,n);
										t=min(d[a-1][i][j][d][n]+c*c,d[a-1][d+1][j][m][n]+e*e);
										if(MIN>t) MIN=t;
									}
									for(b=j;b<n;b++)
									{
										c=needsum(i,b+1,m,n);
										e=needsum(i,j,m,b);
										t=min(d[a-1][i][j][m][b]+c*c,d[a-1][i][b+1][m][n]+e*e);
										if(MIN>t) MIN=t;
									}
									d[a][i][j][m][n]=MIN;
								}
								return d[k][1][1][8][8];
}*/
/*#include<stdio.h>
#include<math.h>
#define F(x) for(x=1;x<9;x++)
float f[16][9][9][9][9];
int a[9][9],sum[9][9];
int n,h,i,j,k,l,o;
float ans,m,p;
float min(float x,float y)
{
	if(x<y)
		return x;
	else
		return y;
}
float sqr(float x)
{
	return x*x;
}
int main()
{
	scanf("%d",&n);
	F(i)
		F(j)
		{
			scanf("%d",&a[i][j]);
			sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+a[i][j];
		}
	m=sum[8][8]/n;
	for(h=0;h<=n;h++)
		F(i)
			F(j)
				F(k)
					F(l)
						f[h][i][j][k][l]=2147483647;
	f[1][1][8][1][8]=0;
	for(h=1;h<n;h++)
		F(i)
			F(j)
				F(k)
					F(l)
						if(f[h][i][j][k][l]!=2147483647)
						{
							for(o=i;o<=j;o++)
							{
								if(o!=i)
									f[h+1][o][j][k][l]=min(f[h+1][o][j][k][l],f[h][i][j][k][l]+sqr(sum[o-1][l]-sum[i-1][l]-sum[o-1][k-1]+sum[i-1][k-1]-m));
								if(o!=j)
									f[h+1][i][o][k][l]=min(f[h+1][i][o][k][l],f[h][i][j][k][l]+sqr(sum[j][l]-sum[o][l]-sum[j][k-1]+sum[o][k-1]-m));
							}
							for(o=k;o<=l;o++)
							{
								if(o!=k)
									f[h+1][i][j][o][l]=min(f[h+1][i][j][o][l],f[h][i][j][k][l]+sqr(sum[j][o-1]-sum[j][k-1]-sum[i-1][o-1]+sum[i-1][k-1]-m));
								if(o!=l)
									f[h+1][i][j][k][o]=min(f[h+1][i][j][k][o],f[h][i][j][k][l]+sqr(sum[j][l]-sum[j][o]-sum[i-1][l]+sum[i-1][o]-m));
							}
						}
	ans=2147483647;
	F(i)
		F(j)
			F(k)
				F(l)
				if(f[n][i][j][k][l]!=2147483647)
				{
					p=f[n][i][j][k][l]+sqr(sum[j][l]-sum[i-1][l]-sum[j][k-1]+sum[i-1][k-1]-m);
					if(p<ans)
						ans=p;
				}
	printf("%.3lf",sqrt(ans/n));
	return 0;
}*/