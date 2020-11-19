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
int a[220][220];
int b[220][220];
int n,m,s,z;
int ok(int x,int y)
{
	memset(b,0,sizeof b);
	fo(i,n+1)
		fo(j,m+1)
			b[i][j]=a[i][j]-a[i-1][j]-a[i][j-1]+a[i-1][j-1];
	fo(i,n)
		fo(j,m)
		{
			b[i+x][j+y]-=b[i][j];
			b[i+x][j]+=b[i][j];
			b[i][j+y]+=b[i][j];
			b[i][j]=0;
		}
	fo(i,n+x)
		fo(j,m+y)
			if(b[i][j])
				return 0;
	return 1;
}
int main()
{
	scanf("%d %d",&n,&m);
	z=0xffffff;
	fo(i,n)
		fo(j,m)
			scanf("%d",a[i]+j),s+=a[i][j];
	fo(i,n)
		if(s%i==0)
			fo(j,m)
				if(s%(i*j)==0)
					if(s/(i*j)<z&&ok(i,j))
						z=s/(i*j);
	printf("%d",z);
	return 0;
}
