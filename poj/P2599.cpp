#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
vector<int>a[1020];
int F(int x,int y)
{
	fe(i,a[x])
		if(*i!=y)
			if(!F(*i,x))
				return *i;
	return 0;
}
int n,s,x,y;
int main()
{
	scanf("%d %d",&n,&s);
	for(int i=1;i<n;i++)
		scanf("%d %d",&x,&y),a[x].push_back(y),a[y].push_back(x);
	sort(a[s].begin(),a[s].end());
	int z=F(s,0);
	if(z)
		printf("First player wins flying to airport %d\n",z);
	else
		puts("First player loses");
	return 0;
}
