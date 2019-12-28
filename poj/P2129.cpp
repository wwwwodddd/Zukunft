#include<stdio.h>
int d,n,i,j,ans;
int main()
{
	scanf("%d %d",&d,&n);
	for(i=0;i<=d;i++)
		for(j=i%n;j+i<=d;j+=n)
			ans++;
	printf("%d",ans);
}