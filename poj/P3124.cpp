#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n,sum;
int a[72][2];
int i,j,k;
int f[2102][2102];
int tmp,ans,t;
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
	return *(int*)b-*(int*)a;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d %d",&a[i][0],&a[i][1]);
		qsort(a,n,8,cmp);
		memset(f,0x3f,sizeof(f));
		sum=f[0][0]=0;
		for(i=1;i<n;i++)
		{
			sum+=a[i][1];
			for(j=sum;j>=0;j--)
				for(k=sum;k>=0;k--)
				{
					if(j>a[i][1])
						f[j][k]=min(f[j][k],f[j-a[i][1]][k]);
					else if(j==a[i][1])
						f[j][k]=min(f[j][k],f[0][k]+a[i][0]);
					if(k>a[i][1])
						f[j][k]=min(f[j][k],f[j][k-a[i][1]]);
					else if(k==a[i][1])
						f[j][k]=min(f[j][k],f[j][0]+a[i][0]);
				}
		}
		ans=0x7fffffff;
		for(i=1;i<=sum;i++)
			for(j=i;j<=sum;j++)
				if(f[i][j]!=0x3f3f3f3f)
				{
					tmp=(f[i][j]+a[0][0])*max(sum-i-j+a[0][1],max(i,j));
					if(tmp==17400)
						printf("%d %d %d\n",i,j,f[i][j]);
					ans=min(ans,tmp);
				}
		printf("%d\n",ans);
	}
	return 0;
}
