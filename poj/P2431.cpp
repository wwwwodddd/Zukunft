#include<iostream>
#include<queue>
using namespace std;
priority_queue<int>q;
int a[10001][2];
int ans,i,j,k,l,n;
int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d %d",&a[i][0],&a[i][1]);
	scanf("%d %d",&l,&j);
	for(i=0;i<n;i++)
		a[i][0]=l-a[i][0];
	qsort(a,n,8,cmp);
	for(i=0;a[i][0]<0;i++);
	while(i<n&&j<l)
	{
		while(i<n&&a[i][0]<=j)
			q.push(a[i++][1]);
		if(q.empty())
			break;
		j+=q.top();
		q.pop();
		ans++;
	}
	printf("%d\n",j<l?-1:ans);
	return 0;
}