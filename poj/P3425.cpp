#include<iostream>
using namespace std;
int v[1000020];
int x,y,z,n,ans;
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(v[x]&&y)
			ans+=10;
		if(z&&y)
			ans+=40;
		else if(y)
			ans+=20;
		else
			ans+=10;
		if(y)
			v[x]=1;
	}
	printf("%d",ans);
	return 0;
}
