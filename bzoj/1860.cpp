#include<stdio.h>
#include<set>
using namespace std;
typedef unsigned long long ull;
ull p[120],h;
int t,a[120];
set<ull>s;
int F(int x,int y,ull h)
{
	if(!s.insert(h).second)
		return 0;
	if(!h)
		return 1;
	while(x<100&&!a[x])
		x++;
	if(a[x]&&a[x+1]&&a[x+2])
	{
		a[x]--,a[x+1]--,a[x+2]--;
		ull o=h-p[x]-p[x+1]-p[x+2];
		if(F(x,y,o))
			return 1;
		a[x]++,a[x+1]++,a[x+2]++;
	}
	if(a[x]>2)
	{
		a[x]-=3;
		ull o=h-p[x]*3;
		if(F(x,y,o))
			return 1;
		a[x]+=3;
	}
	if(a[x]>3)
	{
		a[x]-=4;
		ull o=h-p[x]*4;
		if(F(x,y,o))
			return 1;
		a[x]+=4;
	}
	if(a[x]>1&&y)
	{
		a[x]-=2;
		ull o=h-p[x]*2-p[100];
		if(F(x,!y,o))
			return 1;
		a[x]+=2;
	}
	return 0;
}
int main()
{
	for(int i=p[0]=1;i<101;i++)
		p[i]=p[i-1]*131;
	for(scanf("%d",&t);t--;)
	{
		s.clear();
		h=p[100];
		for(int i=0;i<100;i++)
			scanf("%d",a+i),h+=a[i]*p[i];
		puts(F(0,1,h)?"Yes":"No");
	}
	return 0;
}
