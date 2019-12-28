#include<stdio.h>
#include<iostream>
using namespace std;
int a[105][2];
int n,k,t,r,cnt,f,x,y;
int i,j,ans;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ans=r=0;
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%d %d %d %d",&a[i][0],&x,&a[i][1],&y);
			if(a[i][0]>a[i][1])
				swap(a[i][0],a[i][1]);
			if(r<a[i][1])
				r=a[i][1];
		}
		a[n][0]=a[n][1]=-1;
		for(i=0;i<=r;i++)
		{
			cnt=0;
			for(j=0;j<n;j++)
				if(a[j][0]<=i&&a[j][1]>=i)
					cnt++;
			cnt-=k;
			while(cnt-->0)
			{
				f=n;
				for(j=0;j<n;j++)
					if(a[j][0]<=i&&a[j][1]>=i&&a[f][1]<a[j][1])
						f=j;
				a[f][1]=-1;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}