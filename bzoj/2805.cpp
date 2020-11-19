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
vector<int>a[50020];
double k[50020];
double b[50020],sb[50020];
double u[50020],su[50020];
int v[50020],f[50020];
int n,m,x,y,z;
char s[5];
void bd(int x)
{
	v[x]=1;
	k[x]=a[x].size();
	fe(i,a[x])
		if(!v[*i])
			f[*i]=x,bd(*i),k[x]-=k[*i];
	k[x]=1/k[x];
}
void cg(int x,int y)
{
	u[x]+=y;
	su[f[x]]+=y;
	for(;x;x=f[x])
	{
		sb[f[x]]-=b[x];
		b[x]=(sb[x]+su[x]-u[x])*k[x];
		sb[f[x]]+=b[x];
	}
}
double qy(int x)
{
	return x?k[x]*qy(f[x])+b[x]:0;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		if(a[i].size()==1)
		{
			a[0].push_back(i);
			a[i].push_back(0);
		}
	bd(0);
	for(int i=0;i<m;i++)
	{
		scanf("%s",s);
		if(*s=='C')
		{
			scanf("%d %d %d",&x,&y,&z);
			if(f[x]!=y)
				swap(x,y),z=-z;
			cg(x,z);
		}
		else
		{
			scanf("%d",&x);
			printf("%.10lf\n",qy(x));
		}
	}
	while(1);
	return 0;
}
