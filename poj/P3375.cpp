#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[100020],b[2020];
int f[2][100020];
int n,m,l,r,p,pr,pl;
int i,j,k;
int abss(int x)
{
	return x>-x?x:-x;
}
int min(int x,int y)
{
	return x<y?x:y;
}
int max(int x,int y)
{
	return x>y?x:y;
}
int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	while(scanf("%d %d",&m,&n)+1)
	{
		for(i=1;i<=m;i++)
			scanf("%d",a+i);
		for(i=1;i<=n;i++)
			scanf("%d",b+i);
		qsort(a+1,m,4,cmp);
		qsort(b+1,n,4,cmp);
		for(i=1;i<=n;i++)
		{
			while(p<=m&&a[p]<=b[i])
				p++;
			l=max(i,p-n);
			r=min(p+n,m);
			f[i&1][l]=f[1^i&1][max(min(l-1,pr),pl)]+abss(a[l]-b[i]);
			for(j=l+1;j<=r;j++)
				f[i&1][j]=min(f[i&1][j-1],f[1^i&1][min(j-1,pr)]+abss(a[j]-b[i]));
			pr=r,pl=l;
		}
		printf("%d\n",f[n&1][pr]);
	}
	return 0;
}
