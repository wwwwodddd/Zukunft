#include<iostream>
#include<set>
using namespace std;
int a[5][5];
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
set<int>ss;
void dfs(int x,int y,int s,int v)
{
	if(x<0||y<0||x>=5||y>=5)
		return;
	if(s==6)
		ss.insert(v*10+a[x][y]);
	else
		for(int i=0;i<4;i++)
			dfs(x+dx[i],y+dy[i],s+1,v*10+a[x][y]);
}
int main()
{
	int i,j;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			cin>>a[i][j];
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			dfs(i,j,1,0);
	cout<<ss.size()<<endl;
	return 0;
}

