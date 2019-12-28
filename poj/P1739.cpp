#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#define fr(i,n) for(int i=0;i<n;i++)
using namespace std;
int p[10]={1,3,9,27,81,243,729,2187,6561,19683};
int q[20000],qc;
char s[20][20];
int f[10][10][20000];
int n,m,x,y;
int main()
{
	fr(i,p[9])
	{
		int z=0,f=1;
		for(int j=i;j;j/=3)
		{
			int u=j%3;
			z+=(u==1)-(u==2);
			if(z<0)
			{
				f=0;
				break;
			}
		}
		if(f&&z==0)
			q[qc++]=i;
	}
	while(scanf("%d %d",&n,&m),n+m)
	{
		fr(i,n)
			scanf("%s",s[i]);
		memset(f,0,sizeof f);
		f[0][0][0]=1;
		fr(i,n)
		{
			fr(j,m)
				for(int c=0,k=q[c];q[c]<p[m+1]&&c<qc;k=q[++c])
					if(f[i][j][k])
					{
						x=k/p[j]%3;
						y=k/p[j+1]%3;
						if(s[i][j]=='#')
						{
							if(x==0&&y==0)
								f[i][j+1][k]+=f[i][j][k];
						}
						else
						{
							if(x==0&&y==0)
								f[i][j+1][k+p[j]+2*p[j+1]]+=f[i][j][k];
							else if(x==0||y==0)
							{
								f[i][j+1][k]+=f[i][j][k];
								if(y==1)
									f[i][j+1][k+p[j]-p[j+1]]+=f[i][j][k];
								else if(x==1)
									f[i][j+1][k-p[j]+p[j+1]]+=f[i][j][k];
								else if(y==2)
									f[i][j+1][k+2*p[j]-2*p[j+1]]+=f[i][j][k];
								else if(x==2)
									f[i][j+1][k-2*p[j]+2*p[j+1]]+=f[i][j][k];
							}
							else if(x==2&&y==1)
								f[i][j+1][k-2*p[j]-p[j+1]]+=f[i][j][k];
							else if(x==1&&y==1)
							{
								int z=0,l;
								for(l=j+2;l<=m;l++)
								{
									int u=k/p[l]%3;
									if(z==0&&u==2)
										break;
									z+=(u==1)-(u==2);
								}
								f[i][j+1][k-p[j]-p[j+1]-p[l]]+=f[i][j][k];
							}
							else if(x==2&&y==2)
							{
								int z=0,l;
								for(l=j-1;l>=0;l--)
								{
									int u=k/p[l]%3;
									if(z==0&&u==1)
										break;
									z+=(u==1)-(u==2);
								}
								f[i][j+1][k-2*p[j]-2*p[j+1]+p[l]]+=f[i][j][k];
							}
						}
					}
			fr(j,p[m])
				f[i+1][0][j*3]=f[i][m][j];
		}
		printf("%d\n",f[n][0][2*p[m]+3]);
	}
	return 0;
}