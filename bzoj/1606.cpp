#include<stdio.h>
bool f[50020];
int c,n,a,i,j;
int main()
{
	scanf("%d%d",&c,&n);
	f[0]=1;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a);
		for(j=c;j>=a;j--)
			f[j]|=f[j-a];
		if(f[c])
			break;
	}
	for(i=c;!f[i];i--);
	printf("%d\n",i);
}