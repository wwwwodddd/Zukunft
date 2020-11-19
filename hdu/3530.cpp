#include<stdio.h>
#include<iostream>
#include<set>
using namespace std;
multiset<int>s;
int n,m,k,b,f,z;
int a[100020];
int main()
{
	while(~scanf("%d %d %d",&n,&m,&k))
	{
		s.clear();
		b=f=z=0;
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		while(1)
		{
			if(!s.size()||*s.rbegin()-*s.begin()<=k)
			{
				if(s.size()&&*s.rbegin()-*s.begin()>=m)
					z=max(z,f-b);
				if(f==n)
					break;
				s.insert(a[f++]);
			}
			else
				s.erase(s.find(a[b++]));
		}
		printf("%d\n",z);
	}
}
