#include<stdio.h>
int s[100010],d[100010]={0,1};
int i,j,l,n,e,a,p=1,t[3];
int main()
{
	scanf("%d",&n);
	while(p<n)
		d[p+1]=(d[p++]<<1)%1000000;
	scanf("%d %d %d",t,t+1,t+2);
	for(i=0;i<3;i++)
		while(t[i]--)
		{
			scanf("%d",&l);
			s[l]=i;
		}
	printf("%d\n",s[n]+1);
	e=s[n];
	while(--n>0)
		if(s[n]!=e)
		{
			a+=d[n];
			a=a>=1000000?a-1000000:a;
			e=3-s[n]-e;
		}
	printf("%d\n",a);
	return 0;
}
