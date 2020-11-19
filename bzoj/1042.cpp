#include<iostream>
using namespace std;
long long f[100020];
int a[4],c[4],i,j,t,s;
long long dfs(int x,int y,int z)
{
	if(z<0)
		return 0;
	if(x==4)
	{
		if(y&1)
			return -f[z];
		else
			return f[z];
	}
	return dfs(x+1,y+1,z-c[x]*(a[x]+1))+dfs(x+1,y,z);
}
int main()
{
	for(i=0;i<4;i++)
		cin>>c[i];
	cin>>t;
	f[0]=1;
	for(i=0;i<4;i++)
		for(j=c[i];j<100020;j++)
			f[j]+=f[j-c[i]];
	while(t--)
	{
		for(i=0;i<4;i++)
			cin>>a[i];
		cin>>s;
		cout<<dfs(0,0,s)<<endl;
	}
	return 0;
}