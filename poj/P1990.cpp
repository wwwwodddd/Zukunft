#include<iostream>
using namespace std;
int c[20010];
int s[20010];
int i,n;
__int64 ans,sum;
int a[20010][2];
int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}
void R(int x,int y,int z[])
{
	for(int i=x;i<20010;i+=i&-i)
		z[i]+=y;
}
__int64 G(int x,int z[])
{
	__int64 re=0;
	for(int i=x;i>0;i-=i&-i)
		re+=z[i];
	return re;
}
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d",&a[i][0],&a[i][1]);
	qsort(a,n,8,cmp);
	for(i=0;i<n;i++)
	{
		ans+=(a[i][1]*(2*G(a[i][1],c)-i)-2*G(a[i][1],s)+sum)*a[i][0];
		sum+=a[i][1];
		R(a[i][1],1,c);
		R(a[i][1],a[i][1],s);
	}
	printf("%I64d\n",ans);
	return 0;
}