#include<stdio.h>
#include<algorithm>
#include<set>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> ii;
ii a[800020];
multiset<int>s;
int n,z,sm;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d",&a[i].Y,&a[i].X);
	sort(a,a+n);
	s.insert(0);
	for(int i=0;i<n;i++)
		if(sm+a[i].Y<=a[i].X)
			s.insert(a[i].Y),sm+=a[i].Y;
		else if(a[i].Y<*s.rbegin())
			sm+=a[i].Y-*s.rbegin(),s.erase(--s.end()),s.insert(a[i].Y);
	printf("%d\n",s.size()-1);
}
