#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int a[1000020];
int b[1000020];
int f[40],g[40],l[40];
int w[40];
int i,j,n,m,k;
int ans;
int main()
{
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	for(i=0;i<m;i++)
		scanf("%d",&a[i]);
	sort(a,a+m);
	for(i=0;i<m;i++)
	{
		if(a[i]!=w[k])
			w[++k]=a[i];
		f[k]++;
	}
	w[k+1]=0x3fffffff;
	for(i=0;i<n;i++)
		for(j=1;j<=k;j++)
			g[j]+=b[i]%w[j+1]/w[j];
	g[k+1]=1;
	for(i=1;i<=k;i++)
		while(f[i]>0)
		{
			for(j=i;g[j]==0;j++);
			if(j>k)
				goto end;
			f[i]--;
			g[j]--;
			ans++;
			while(j-->i)
				g[j]=w[j+1]/w[j]-1;
		}
	end:
	printf("%d",ans);
	return 0;
}