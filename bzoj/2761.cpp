#include<stdio.h>
#include<set>
using namespace std;
set<int>s;
int x,n,t;
int main()
{
	for(scanf("%d",&t);t--;puts(""))
		for(s.clear(),scanf("%d",&n);n--;)
		{
			scanf("%d",&x);
			if(!s.count(x))
				printf("%d ",x),s.insert(x);	
		}
}
