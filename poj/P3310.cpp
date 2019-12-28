#include<iostream>
#include<vector>
using namespace std;
vector<int>v[101];
int f[101];
int b[101];
int n,m;
bool s[101];
int i,j,k,x,y,c=0,count;
int F(int x)
{
	return f[x]==x?x:f[x]=F(f[x]);
}
void U(int x,int y)
{
	f[F(x)]=f[F(y)];
}
int check()
{
	for(int i=1;i<n;i++)
		if(F(i)!=F(i+1))
			return 0;
	return 1;
}
int S()
{
	int re=0;
	if(n-m<1||!check())
			return 0;
	for(i=1;i<=n;i++)
		if(v[i].size()==1)
			b[v[i][0]]--;
	count=0;
	for(i=1;i<=n;i++)
		if(v[i].size()>1&&b[i]==1)
			re++;
	if(re>2)
		return 0;
	else
		return 1;
}
int main()
{
	while(cin>>n,n!=0)
	{
		for(i=1;i<=n;i++)
			v[i].clear();
		for(i=1;i<=n;i++)
			f[i]=i;
		memset(b,0,sizeof(b));
		memset(s,0,sizeof(s));
		cin>>m; 
		for(i=1;i<=m;i++)
		{
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
			b[x]++;
			b[y]++;
			U(x,y); 
		}
		printf("Graph %d is%s a caterpillar.\n",++c,S()?"":" not");
	}
	return 0;
}
