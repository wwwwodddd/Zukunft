#include<stdio.h>
#include<vector>
using namespace std;
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
vector<int>a[100020];
int n,k,x,y,z;
int F(int x,int y)
{
	int c=0;
	if(a[x].size()==1)
		c++;
	fe(i,a[x])
		if(*i!=y)
			c+=F(*i,x);
	if(c<=k*2)
		return z+=c/2,c%2;
	else
		return z+=k,0;
}
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<n;i++)
		scanf("%d %d",&x,&y),a[x].push_back(y),a[y].push_back(x);
	F(1,0);
	printf("%d\n",z);
	return 0;
}
