#include<stdio.h>
#include<stdlib.h>
int a[100000][3];
int f[500];
int n,m,cnt;
int i,j,k;
int F(int x)
{
	if(f[x]==x)
		return x;
	return f[x]=F(f[x]);
}
void U(int x,int y)
{
	f[F(x)]=F(y);
}
int cmp(const void *a,const void *b)
{
	return ((int*)a)[2]-((int*)b)[2];
}
int main()
{
	scanf("%d %d",&n,&m);
	cnt=n;
	for(i=0;i<=n;i++)
		f[i]=i;
	for(i=0;i<m;i++)
		scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
	qsort(a,m,12,cmp);
	for(i=0;i<m;i++)
		if(F(a[i][0])!=F(a[i][1]))
		{
			U(a[i][0],a[i][1]);
			cnt--;
			if(cnt==1)
				break;
		}
	printf("%d %d",n-1,a[i][2]);
	return 0;
}