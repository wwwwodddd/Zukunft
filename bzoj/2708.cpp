#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int a[120];
int f[120];
int n;
int main()
{
	for(;~scanf("%d",&n);)
	{
		memset(a,0,sizeof a);
		memset(f,0,sizeof f);
		fo(i,n)
			scanf("%d",a+i);
		sort(a+1,a+1+n);
		fo(i,n)
			fr(j,i)
				fr(k,i-j)
				{
					int _;
					for(_=j+1;_<=i-k;_++)
						if(a[_+k]-a[_]>1)
							break;
					if(_>i-k&&abs(a[i-k+1]-a[j+k])>1)
						f[i]=max(f[i],f[j]+k);
				}
		printf("%d\n",f[n]);
	}
}
