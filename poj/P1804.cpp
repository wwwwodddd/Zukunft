#include <iostream>
using namespace std;
int a[1020];
int b[500001];
int n,l,k;
__int64 s;
void mg(int *a,int l,int m,int r)
{
	int i=l,j=m+1;
	while(1)
	{
		if(a[i]<=a[j])
			{
			b[l++]=a[i++];
			if(i>m)
				break;
			}
		else
		{
			b[l++]=a[j++];
			s+=m-i+1;
			if(j>r)
				break;
		}
	}
	while(i<=m)
		b[l++]=a[i++];
	while(j<=r)
		b[l++]=a[j++];
}
void ms(int *a,int l,int r)
{
	if(l==r)
		return;
	int m=(l+r)>>1;
	ms(a,l,m);
	ms(a,m+1,r);
	mg(a,l,m,r);
	memcpy(a+l,b+l,(r-l+1)*4);
}
int main()
{
	scanf("%d",&l);
	while(l--)
	{
		s=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		s=0;
		ms(a,0,n-1);
		printf("Scenario #%d:\n%I64d\n\n",++k,s);
	}
return 0;
}

