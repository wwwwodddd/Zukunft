#include<stdio.h>
int a[1050000],b[1050000];
int n=1,h,d,c,k=1,i,l,r;
void dfs(int x,int y)
{
	if(x>h||y>=n)
		return;
	if(x<h&&2*y<n)
		dfs(x+1,2*y);
	if(x<h&&2*y+1<n)
	{
		d++;
		dfs(x+1,2*y+1);
	}
	b[++c]=a[y]-d;
}
int main()
{
	scanf("%d",&h);
	while(scanf("%d",&a[n])+1)
		n++;
	dfs(1,1);
	for(int i=1;i<n;i++)
	{
		l=1;
		r=k;
		while(r>l)
		{
			int mid=(r+l)>>1;
			if(a[mid]>b[i])
				r=mid;
			else
				l=mid+1;
		}
		if(l==k)
			k++;
		a[l]=b[i];
	}
	printf("%d\n",n-k);
	return 0;
}