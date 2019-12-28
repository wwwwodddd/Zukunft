#include<iostream>
#include<string>
using namespace std;
int g[101][101];
string o;
int n,x,y,l,i,j,ans;
int main()
{
	cin>>n;
	while(n--)
	{
		cin>>o>>x>>y>>l;
		if(o=="BLACK")
			for(i=x;i<x+l;i++)
				for(j=y;j<y+l;j++)
					g[i][j]=1;
		if(o=="WHITE")
			for(i=x;i<x+l;i++)
				for(j=y;j<y+l;j++)
					g[i][j]=0;
		if(o=="TEST")
		{
			ans=0;
			for(i=x;i<x+l;i++)
				for(j=y;j<y+l;j++)
					ans+=g[i][j];
			cout<<ans<<endl;
		}
	}
	return 0;
}