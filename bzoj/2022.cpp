#include<iostream>
#include<stdio.h>
#include<string.h>
#define F(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int m,n,f[21][15001],c[21],w[21];
int main()
{
	cin>>m>>n;
	F(i,1,m)
		cin>>c[i];
	F(i,1,n)
		cin>>w[i];
	f[0][7500]=1;
	F(i,1,n)
		F(j,-7500,7500)
			if(f[i-1][j+7500]!=0)
				F(k,1,m)
					f[i][j+c[k]*w[i]+7500]+=f[i-1][j+7500];
	cout<<f[n][7500];
	return 0;
}