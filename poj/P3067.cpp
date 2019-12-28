#include<iostream>
using namespace std;
int f[1000001][2];
int a[1000001];
int b[1000001];
__int64 s;
int t,n,m,k,i,j,cse;
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
int cmp(const void *a,const void *b)
{
	if(((int*)a)[0]==((int*)b)[0])
		return ((int*)a)[1]-((int*)b)[1];
	return ((int*)a)[0]-((int*)b)[0];
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		s=0;
		scanf("%d %d %d",&m,&k,&n);
		for(i=0;i<n;i++)
			scanf("%d %d",&f[i][0],&f[i][1]);
		qsort(f,n,8,cmp);
		for(i=0;i<n;i++)
			a[i]=f[i][1];
		ms(a,0,n-1);
		printf("Test case %d: %I64d\n",++cse,s);
	}
	return 0;
}