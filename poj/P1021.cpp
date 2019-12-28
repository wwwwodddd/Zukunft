#include<iostream>
#include<algorithm>
using namespace std;
#define N 32768
int f[N],g[N],x[N],y[N],v[128][128];
int n,w,h,t,i,j;
void S(int f[])
{
	memset(v,0,sizeof(v));
	for(i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
		v[++x[i]][++y[i]]=1;
	}
	for(i=0;i<n;i++)
	{
		f[i]=0;
		for(j=x[i]-1;v[j][y[i]];j--)f[i]++;
		for(j=x[i]+1;v[j][y[i]];j++)f[i]++;
		for(j=y[i]-1;v[x[i]][j];j--)f[i]++;
		for(j=y[i]+1;v[x[i]][j];j++)f[i]++;
	}
	sort(f,f+n);
}
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>w>>h>>n;
		S(f),S(g);
		for(i=0;i<n&&f[i]==g[i];i++);
		puts(i==n?"YES":"NO");
	}
	return 0;
}