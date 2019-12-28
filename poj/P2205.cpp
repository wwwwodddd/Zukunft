#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int ss,n,b;
int s[2020][2020];
int a[2020];
void dfs(int x,int y)
{
	if(x==n)
	{
		if(a[x-1]||n==1)
		{
			memcpy(s[ss],a,sizeof a);
			ss++;
		}
		return;
	}
	for(int i=0;i<b;i++)
	{
		int tmp=y;
		a[x]=i;
		for(int j=0;j<=x;j++)
			tmp+=a[j]*a[x-j];
		if(tmp%b==i)
			dfs(x+1,tmp/b);
	}
}
int cmp(const void *a,const void *b)
{
	int *A=(int*)a,*B=(int*)b;
	for(int i=n;i--;)
		if(A[i]!=B[i])
			return A[i]-B[i];
}
int main()
{
	while(~scanf("%d %d",&b,&n))
	{
		ss=0;
		dfs(0,0);
		qsort(s,ss,sizeof s[0],cmp);
		printf("%d\n",ss);
		for(int i=0;i<ss;i++,puts(""))
			for(int j=n-1;~j;j--)
				if(s[i][j]>=10)
					printf("%c",s[i][j]-10+'A');
				else
					printf("%d",s[i][j]);
	}
}
