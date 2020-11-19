#include<stdio.h>
#include<string.h>
#include<set>
using namespace std;
set<int>s;
char a[2][1000020],c[2];
int x,y,t,n,k;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		printf("Case %d:\n",++k);
		memset(a,0,sizeof a);
		s.clear();
		scanf("%s%s",a[0],a[1]);
		for(x=0;a[0][x];x++)
			if(a[0][x]!=a[1][x])
				s.insert(x);
		s.insert(x);
		for(scanf("%d",&n);n--;)
		{
			scanf("%d",&x);
			if(x>1)
				scanf("%d",&x),printf("%d\n",*s.lower_bound(x)-x);
			else
				scanf("%d%d%s",&x,&y,c),a[--x][y]=*c,a[0][y]!=a[1][y]?s.insert(y),0:s.erase(y);
		}
	}
	return 0;
}
