#include<iostream>
#include<algorithm>
using namespace std;
int i,j,n,a,b,t,x,y,ans;
int f[1020];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&a,&b);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			if(y)
				f[i]=a*2-x;
			else
				f[i]=x;
		}
		sort(f,f+n);
		ans=a+b/n*2*a;
		b%=n;
		if(b==0)
			ans-=2*a-f[n-1];
		else
			ans+=f[b-1];
		printf("%d\n",ans);
	}
	return 0;
}