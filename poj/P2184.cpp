#include<iostream>
#include<algorithm>
using namespace std;
int n;
int s[102][2];
int cmp(const void *a,const void *b)
{
	return ((int*)b)[0]-((int*)a)[0];
}
int f[100020];
int t[100020];
int main()
{
	int i,j,ans;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d%d",&s[i][0],&s[i][1]);
		qsort(s,n,8,cmp);
		memset(t,0,sizeof(t));
		memset(f,0xc0,sizeof(f));
		f[0]=0;
		t[0]=1;
		for(i=0;i<n;i++)
			if(s[i][0]>0)
			{
				for(j=100000;j>=s[i][0];j--)
					if(t[j-s[i][0]]!=0)
					{
						t[j]=1;
						f[j]=max(f[j],f[j-s[i][0]]+s[i][1]);
					}
			}
			else
			{
				for(j=0;j-s[i][0]<=100000;j++)
					if(t[j-s[i][0]]!=0)
					{
						t[j]=1;
						f[j]=max(f[j],f[j-s[i][0]]+s[i][1]);
					}
			}
		ans=0;
		for(i=0;i<=100000;i++)
			if(t[i]&&f[i]>=0)
				ans=max(ans,f[i]+i);
		printf("%d\n",ans);
	}
	return 0;
}