#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
long long f[1020][1020][2];
int s[1020],sm,n,sx;
struct P
{
	int x,y,z;
}p[1020];
bool operator<(const P&a,const P&b)
{
	return a.x<b.x;
}
int main()
{
	scanf("%d %d",&n,&sx);
	for(int i=0;i<n;i++)
		scanf("%d",&p[i].x);
	for(int i=0;i<n;i++)
		scanf("%d",&p[i].y);
	for(int i=0;i<n;i++)
		scanf("%d",&p[i].z);
	sort(p,p+n);
	for(int i=0;i<n;i++)
		s[i+1]=s[i]+p[i].z,sm+=p[i].y;
	for(int i=0;i<n;i++)
		f[i][i][0]=f[i][i][1]=s[n]*abs(sx-p[i].x);
	for(int l=1;l<n;l++)
		for(int i=0;i<n;i++)
			f[i][i+l][0]=min(f[i+1][i+l][0]+(p[i+1].x-p[i].x)*(s[n]-s[i+l+1]+s[i+1]),f[i+1][i+l][1]+(p[i+l].x-p[i].x)*(s[n]-s[i+l+1]+s[i+1])),f[i][i+l][1]=min(f[i][i+l-1][0]+(p[i+l].x-p[i].x)*(s[n]-s[i+l]+s[i]),f[i][i+l-1][1]+(p[i+l].x-p[i+l-1].x)*(s[n]-s[i+l]+s[i]));
	printf("%.3f",(sm-min(f[0][n-1][0],f[0][n-1][1]))*1e-3);
	return 0;
}
