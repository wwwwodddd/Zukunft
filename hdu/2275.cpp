#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
char o[5];
int n,x;
multiset<int>s;
int main()
{
	while(~scanf("%d",&n))
	{
		s.clear();
		while(n--)
		{
			scanf("%s %d",o,&x);
			if(o[1]=='u')
				s.insert(x);
			else
			{
				multiset<int>::iterator it=s.upper_bound(x);
				if(it==s.begin())
					puts("No Element!");
				else
					printf("%d\n",*--it),s.erase(it);
			}
		}
		puts("");
	}
	return 0;
}