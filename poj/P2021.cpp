#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct P{
	string u;
	int a;
}p[110];
bool cmp(P a,P b)
{
	if(a.a==b.a)
		return a.u<b.u;
	return a.a>b.a;
}
int a[110],d[110],n;
string f[110];
int DFS(int x)
{
	int i;
	if(f[x]=="Ted")
	{
		a[x]=100-d[x];
		return a[x];
	}
	if(a[x]!=-1)
		return a[x];
	for(i=0;i<n;i++)
		if(p[i].u==f[x])
			return a[x]=DFS(i)-d[x];
}
int main()
{
	int i,j,t,k=1;
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(a,-1,sizeof(a));
		for(i=0;i<n;i++)
			cin>>f[i]>>p[i].u>>d[i];
		for(i=0;i<n;i++)
			DFS(i);
		for(i=0;i<n;i++)
			p[i].a=a[i];
		sort(p,p+n,cmp);
		cout<<"DATASET "<<k++<<endl;
		for(i=0;i<n;i++)
			cout<<p[i].u<<" "<<p[i].a<<endl;
	}
	return 0;
}
