#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
typedef map<int,vi> mivi;
int l[100020],r[100020];
int a[100020],c[100020];
mivi p;
int n;
void R(int x,int y)
{
	for(x++;x<=n;x+=x&-x)
		c[x]+=y;
}
int G(int x)
{
	int re=0;
	for(x++;x;x-=x&-x)
		re+=c[x];
	return re;
}
int ok(int x)
{
	return l[x]&&r[x];
}
void ud(int x,int d)
{
	int s=ok(x);
	if(d==1)
		l[x]++;
	else
		r[x]--;
	R(x,ok(x)-s);
}
int main()
{
	int x,y,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		p[x].push_back(y);
		a[i]=y;
	}
	sort(a,a+n);
	unique(a,a+n);
	for(mivi::iterator it=p.begin();it!=p.end();it++)
	{
		vi&v=it->second;
		for(i=0;i<v.size();i++)
			v[i]=lower_bound(a,a+n,v[i])-a,r[v[i]]++;
		sort(v.begin(),v.end());
	}
	long long ans=0;
	for(mivi::iterator it=p.begin();it!=p.end();it++)
	{
		vi&v=it->second;
		for(i=0;i<v.size();i++)
			ud(v[i],-1);
		ans+=G(v[v.size()-1])-G(v[0]-1);
		for(i=0;i<v.size();i++)
			ans-=ok(v[i]);
		for(i=0;i<v.size();i++)
			ud(v[i],1);
	}
	printf("%I64d",ans+n);
	return 0;
}