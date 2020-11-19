#include<stdio.h>
#include<algorithm>
#include<map>
#define X first
#define Y second
using namespace std;
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int v[400020];
int a[400020];
int n,m,x,y,w,t,o,c;
int b[20];
typedef pair<int,int>ii;
map<ii,int>g;
long long F(long long x)
{
	return x*(x+1)/2;
}
int main()
{
	for(int i=2;i<=400000;i++)
		if(!v[i])
			for(int j=i;j<=400000;j+=i)
				v[j]=i;
	for(scanf("%d",&t);t--;)
	{
		g.clear();
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++)
			a[i]=i;
		for(int i=0;i<m;i++)
		{
			scanf("%d",&o);
			if(o==1)
			{
				scanf("%d %d %d",&x,&y,&w);
				x--;
				long long z=0,k;
				c=0;
				fe(i,g)
					if(i->X.X>x&&i->X.X<=y&&__gcd(w,i->X.Y)==1)
						z+=i->X.Y*i->Y;
				for(;v[w];w/=v[w])
					b[c++]=v[w];
				c=unique(b,b+c)-b;
				for(int i=0;i<1<<c;i++)
				{
					k=1;
					for(int j=0;j<c;j++)
						if(i>>j&1)
							k*=b[j];
					if(__builtin_popcount(i)&1)
						z-=(F(y/k)-F(x/k))*k;
					else
						z+=(F(y/k)-F(x/k))*k;
				}
				printf("%I64d\n",z);
			}
			else if(o==2)
			{
				scanf("%d %d",&x,&y);
				g[ii(x,a[x])]--;
				a[x]=y;
				g[ii(x,a[x])]++;
			}
		}
	}
	return 0;
}
