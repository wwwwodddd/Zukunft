#include<stdio.h>
#include<iostream>
using namespace std;
int a[16020][3],d[16020],q[16020];
int f[105][16020];
int n,m,i,j,k,l,r;
int cmp(const void *a,const void *b)
{
	return ((int*)a)[2]-((int*)b)[2];
}
int main()
{
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
		scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
	qsort(a,m,12,cmp);
	for(i=0;i<m;i++)
	{
		for(j=0;j<a[i][2];j++)
			f[i][j]=f[i-1][j];
		l=1;
		r=1;
		d[1]=-1;
		q[1]=0;
		for(j=max(0,a[i][2]-a[i][0]);j<a[i][2];j++)
		{
			k=f[i-1][j]-a[i][1]*j;
			while(l<=r&&k>=d[r]) 
				r--;
			r++;
			q[r]=j;
			d[r]=k;
		}
		for(j=a[i][2];j<=n;j++)
		{
			while(l<=r&&q[l]<j-a[i][0])
				l++;
			f[i][j]=max(f[i-1][j],f[i][j-1]);
			if(l<=r)
				f[i][j]=max(f[i][j],d[l]+a[i][1]*j);
		}
	}
	printf("%d\n",f[m-1][n]);
	return 0;
}