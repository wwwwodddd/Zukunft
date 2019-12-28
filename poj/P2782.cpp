#include<algorithm>
#include<iostream>
using namespace std;
int n,m,l,r,i;
int f[100020];
int cmp(int a, int b)
{
	return a>b;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",&f[i]);
	sort(f,f+n,cmp);
	for(l=0,r=n-1;l<=r;l++)
		if(f[l]+f[r]<=m)
			r--;
	printf("%d\n",l);
	return 0;
}