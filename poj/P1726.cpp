#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
const int max=100000000;
const char b[3]={'.','L','R'};
const int c[5][5]={{},{0,3,5,5,7},{0,5,3,7,5},{0,5,7,3,5},{0,7,5,5,3}};
int f[105][5][5][3],lx[100][5][5][3],ly[100][5][5][3],lz[100][5][5][3];
int a[105];
string s;
int n,i,j,k,l,ans,ansx,ansy,ansz;
int crossleft(int x,int y)
{
	if((x==2||x==3)&&y==1)
		return 1;
	return 0;
}
int crossright(int x,int y)
{
	if((y==2||y==3)&&x==4)
		return 1;
	return 0;
}
void dp(int x,int y,int p)
{
	if(!crossleft(x,y)||x==p) 
	{
		if(f[i+1][p][y][1]>f[i][x][y][0]+1)
		{
			f[i+1][p][y][1]=f[i][x][y][0]+1;
			lx[i+1][p][y][1]=x;
			ly[i+1][p][y][1]=y;
			lz[i+1][p][y][1]=0;
		}
		if(f[i+1][p][y][1]>f[i][x][y][2]+1)
		{
			f[i+1][p][y][1]=f[i][x][y][2]+1;
			lx[i+1][p][y][1]=x;
			ly[i+1][p][y][1]=y;
			lz[i+1][p][y][1]=2;
		}
		if(f[i+1][p][y][1]>f[i][x][y][1]+c[x][p])
		{
			f[i+1][p][y][1]=f[i][x][y][1]+c[x][p];
			lx[i+1][p][y][1]=x;
			ly[i+1][p][y][1]=y;
			lz[i+1][p][y][1]=1;
		}
	}
	if(!crossright(x,y)||(y==p))
	{
		if(f[i+1][x][p][2]>f[i][x][y][0]+1)
		{
			f[i+1][x][p][2]=f[i][x][y][0]+1;
			lx[i+1][x][p][2]=x;
			ly[i+1][x][p][2]=y;
			lz[i+1][x][p][2]=0;
		}
		if(f[i+1][x][p][2]>f[i][x][y][1]+1)
		{
			f[i+1][x][p][2]=f[i][x][y][1]+1;
			lx[i+1][x][p][2]=x;
			ly[i+1][x][p][2]=y;
			lz[i+1][x][p][2]=1;
		}
		if(f[i+1][x][p][2]>f[i][x][y][2]+c[y][p])
		{
			f[i+1][x][p][2]=f[i][x][y][2]+c[y][p];
			lx[i+1][x][p][2]=x;
			ly[i+1][x][p][2]=y;
			lz[i+1][x][p][2]=2;
		}
	}
}

void print(int i,int j,int k,int l)
{
	int x,y,z;
	if(i==0)
		return;
	x=lx[i][j][k][l];
	y=ly[i][j][k][l];
	z=lz[i][j][k][l];
	print(i-1,x,y,z);
	printf("%c",b[l]);
}

int main()
{
	while(cin>>s&&s[0]!='#')
	{
		n=s.length();
		s='$'+s;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='.')
				a[i]=0;
			else if(s[i]=='L')
				a[i]=1;
			else if(s[i]=='U')
				a[i]=2;
			else if(s[i]=='D')
				a[i]=3;
			else if(s[i]=='R')
				a[i]=4;
		}
		memset(f,0x3f,sizeof(f));
		f[0][1][4][0]=0;
		for(i=0;i<=n-1;i++)
			for(j=1;j<=4;j++)
				for(k=1;k<=4;k++)
					if(j!=k)
						if(a[i+1]!=0)
							dp(j,k,a[i+1]);
						else
						{
							for(l=1;l<=4;l++)
								dp(j,k,l);
							for(l=0;l<=2;l++)
								if(f[i+1][j][k][0]>f[i][j][k][l])
								{
									f[i+1][j][k][0]=f[i][j][k][l];
									lx[i+1][j][k][0]=j;
									ly[i+1][j][k][0]=k;
									lz[i+1][j][k][0]=l;
								}
						}
		ans=0x3f3f3f3f;
		for(i=1;i<=4;i++)
			for(j=1;j<=4;j++)
				for(k=0;k<=2;k++)
					if((i!=j)&&(f[n][i][j][k]<ans)) 
					{
						ans=f[n][i][j][k];
						ansx=i;
						ansy=j;
						ansz=k;
					}
		print(n,ansx,ansy,ansz);
		printf("\n");
	}
	return 0;
}
