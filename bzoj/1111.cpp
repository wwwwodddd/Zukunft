#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
const int mod=1000000000;
int l,n,v,i,j;
int a[2020],c[2020],q[2020],f[2020][2],g[2020][2];
char s[2020];
int main()
{
	scanf("%s",s);
	l=strlen(s);
	for(i=0;i<l;i++)
		a[l-i]=s[i]-'0';
	for(v=1;v;)
	{
		a[0]=v=0;
		for(i=l;i>0;i--)
		{
			if(a[i])
				v=1;
			a[i-1]+=a[i]%4*10;
			a[i]/=4;
		}
		q[n++]=a[0]/10;
	}
	g[n][0]=g[n][1]=f[n][1]=1;
	for(i=n-1;i>=0;i--)
		for(j=0;j<2;j++)
		{
			f[i][j]=min(f[i+1][0]+q[i]+j,f[i+1][1]+4-q[i]-j);
			if(f[i][j]==f[i+1][0]+q[i]+j)
				g[i][j]=(g[i][j]+g[i+1][0])%mod;
			if(f[i][j]==f[i+1][1]+4-q[i]-j)
				g[i][j]=(g[i][j]+g[i+1][1])%mod;
		}
	printf("%d\n",g[0][0]);
	return 0;
}