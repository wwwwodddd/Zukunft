#include<iostream>
#include<stack>
#include<queue>
using namespace std;
queue<int>z;
stack<int>u,v,w;
int n,i,j,k,o,ans;
int f[128];
int g[128];
int gcd(int x,int y)
{
	if(y==0)
		return x;
	return gcd(y,x%y);
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
		for(i=1;i<=n;i++)
			z.push(i);
		k=1440;
		while(k--)
		{
			o=z.front();
			z.pop();
			if(u.size()==4)
			{
				for(i=0;i<4;i++)
				{
					z.push(u.top());
					u.pop();
				}
				if (v.size()==11)
				{
					for(i=0;i<11;i++)
					{
						z.push(v.top());
						v.pop();
					}
					if(w.size()==11)
					{
						for(i=0;i<11;i++)
						{
							z.push(w.top());
							w.pop();
						}
						z.push(o);
					}
					else
						w.push(o);
				}
				else
					v.push(o);
			}
			else
			u.push(o);
		}
		for(i=1;i<=n;i++)
		{
			f[i]=z.front();
			z.pop();
		}
		for(i=1;i<=n;i++)
			g[i]=1;
		for(i=1;i<=n;i++)
			for(o=f[i];o!=i;o=f[o])
				g[i]++;
		ans=1;
		for(i=1;i<=n;i++)
			ans=ans*g[i]/gcd(ans,g[i]);
		cout<<n<<" balls cycle after "<<ans<<" days."<<endl;
	}
	return 0;
}