#include<iostream>
#include<algorithm>
using namespace std;
const int sup=30005;
int LDS[sup];//不升
int LIS[sup];//不降
int dp[sup];
int n;
int bsearch(int beg,int end,int p)
{
	int mid;
	while(beg<=end)//二分很掣肘，试了好几次
	{
		mid=(beg&end)+((beg^end)>>1);
		if(dp[mid]<=p)
			beg=mid+1;
		else if(dp[mid]>p)
			end=mid-1;
	}
	return beg;
}
int lis()
{
	int i;
	int top=-1;
	for(i=0;i<n;++i)
	{
		if(dp[top==-1?0:top]<=LIS[i])
			dp[++top]=LIS[i];
		else if(dp[top==-1?0:top]>LIS[i])
			dp[bsearch(0,top,LIS[i])]=LIS[i];
	}
	return n-top-1;
}
int lds()
{
	int i,top=-1;
	for(i=0;i<n;++i)
	{
		if(dp[top==-1?0:top]<=LDS[i])
			dp[++top]=LDS[i];
		else if(dp[top==-1?0:top]>LDS[i])
			dp[bsearch(0,top,LDS[i])]=LDS[i];//由于是拷贝lis的代码，导致其中的一个LIS米有改过来，WAWAWA
	}
	return n-top-1;
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		scanf("%d",&LIS[i]);
		LDS[n-i-1]=LIS[i];
	}
	int ans=lis();
	fill(dp,dp+sup,0);
	int t=lds();
	ans=ans<t?ans:t;
	if(ans!=-1)
	printf("%d\n",ans);
	else
		printf("0\n");
	return 0;
}