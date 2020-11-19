#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int v[60],l[60],tim,n,k;
double xa[60],ya[60];
double xb[60],yb[60];
vector<int>a[60];
int dfs(int x)
{
	for(vector<int>::iterator i=a[x].begin();i!=a[x].end();i++)
		if(v[*i]!=tim)
		{
			v[*i]=tim;
			if(l[*i]==0||dfs(l[*i]))
				return l[*i]=x,1;
		}	
	return 0;
}
int match()
{
	int re=0;
	memset(v,0,sizeof v);
	memset(l,0,sizeof l);
	for(tim=1;tim<=n;tim++)
		re+=dfs(tim);
	return re;
}
int ok1(double len)
{
	for(int i=1;i<=n;i++)
		a[i].clear();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if((xa[i]-xb[j])*(xa[i]-xb[j])+(ya[i]-yb[j])*(ya[i]-yb[j])<len)
				a[i].push_back(j);	
	return match();
}
int ok2(double len)
{
	for(int i=1;i<=n;i++)
		a[i].clear();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if((xa[i]-xb[j])*(xa[i]-xb[j])+(ya[i]-yb[j])*(ya[i]-yb[j])>len)
				a[i].push_back(j);	
	return n-match();
}
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",xa+i,ya+i);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",xb+i,yb+i);
	double ll=0,rr=1e8;
	for(int _=100;_--;)
	{
		if(ok1((ll+rr)/2)<k)
			ll=(ll+rr)/2;
		else
			rr=(ll+rr)/2;
	}
	printf("%.2f ",sqrt(ll));
	if(k<n)
	{
		ll=0,rr=1e8;
		for(int _=100;_--;)
		{
			if(ok2((ll+rr)/2)<=k)
				ll=(ll+rr)/2;
			else
				rr=(ll+rr)/2;
		}
		printf("%.2f",sqrt(ll));
	}
	else
		puts("+INF");
	return 0;
}
