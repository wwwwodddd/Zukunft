#include<stdio.h>
#include<map>
#include<set>
using namespace std;
multiset<int>s;
map<int,int>g;
int p[100020];
int a[100020];
int n,m,z;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	for(int i=n-1;i>=0;i--)
	{
		if(!g.count(a[i]))
			g[a[i]]=n;
		p[i]=g[a[i]];
		g[a[i]]=i;
	}
	for(int i=0;i<n;i++)
	{
		if(s.find(i)==s.end())
		{
			z++;
			if(s.size()==m)
				s.erase(--s.end());
		}
		else
			s.erase(s.find(i));
		s.insert(p[i]);
	}
	printf("%d\n",z);
	return 0;
}
