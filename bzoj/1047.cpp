#include<stdio.h>
#include<iostream>
using namespace std;
int c[1020][1020];
int mn[1020][1020];
int mx[1020][1020];
int an[1020][1020];
int ax[1020][1020];
int q1[1020],b1,f1;
int q2[1020],b2,f2;
int a,b,n;
int i,j,k,ans;
int main()
{
	scanf("%d %d %d",&a,&b,&n);
	for(i=0;i<a;i++)
		for(j=0;j<b;j++)
			scanf("%d",&c[i][j]);
	for(i=0;i<a;i++)
	{
		b1=f1=b2=f2=0;
		for(j=0;j<b;j++)
		{
			while(b1<f1&&c[i][j]<c[i][q1[f1-1]])
				f1--;
			q1[f1++]=j;
			while(b1<f1&&q1[b1]<=j-n)
				b1++;
			mn[i][j]=c[i][q1[b1]];
			while(b2<f2&&c[i][j]>c[i][q2[f2-1]])
				f2--;
			q2[f2++]=j;
			while(b2<f2&&q2[b2]<=j-n)
				b2++;
			mx[i][j]=c[i][q2[b2]];
		}
	}
	for(j=0;j<b;j++)
	{
		b1=f1=b2=f2=0;
		for(i=0;i<a;i++)
		{
			while(b1<f1&&mn[i][j]<mn[q1[f1-1]][j])
				f1--;
			q1[f1++]=i;
			while(b1<f1&&q1[b1]<=i-n)
				b1++;
			an[i][j]=mn[q1[b1]][j];
			while(b2<f2&&mx[i][j]>mx[q2[f2-1]][j])
				f2--;
			q2[f2++]=i;
			while(b2<f2&&q2[b2]<=i-n)
				b2++;
			ax[i][j]=mx[q2[b2]][j];
		}
	}
	ans=0x7fffffff;
	for(i=n-1;i<a;i++)
		for(j=n-1;j<b;j++)
			ans=min(ans,ax[i][j]-an[i][j]);
	printf("%d",ans);
	return 0;
}