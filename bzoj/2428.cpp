#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<numeric>
#include<algorithm>
#define fr(i,n) for(int i=0;i<n;i++)
using namespace std;
int a[20],n,k,ans;
int cal()
{
	int w[6]={},re=0;
	fr(i,n)
		*min_element(w,w+k)+=a[i];
	fr(i,k)
		re+=w[i]*w[i];
	return re;
}
int main()
{
	cin>>n>>k;
	fr(i,n)
		scanf("%d",a+i);
	ans=0x3fffffff;
	fr(_,100)
	{
		random_shuffle(a,a+n);
		int cur=cal();
		fr(o,10000)
		{
			int x=rand()%n,y=rand()%n;
			swap(a[x],a[y]);
			int ncur=cal();
			if(cur>ncur)
				cur=ncur;
			else
				swap(a[x],a[y]);
		}
		ans=min(ans,cur);
	}
	double sum=accumulate(a,a+n,.0);
	double ret=ans-sum*sum/k;
	printf("%.2f\n",sqrt(ret/k));
	return 0;
}
