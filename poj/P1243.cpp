#include<stdio.h>
int f[32][32];
int m,n,k;
int work(int m,int n)
{
	if(f[m][n]!=0)
		return f[m][n];
	if(n==0)
		return f[m][n]=m;
	if(m==1)
		return f[m][n]=1;
	return f[m][n]=1+work(m-1,n-1)+work(m-1,n);
}
int main()
{
	while(scanf("%d%d",&m,&n)&&m+n)
		printf("Case %d: %d\n",++k,work(m,n));
	return 0;
}
