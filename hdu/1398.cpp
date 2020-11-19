#include<stdio.h>
int f[320]={1},n;
int main()
{
	for(int i=1;i<18;i++)
		for(int j=i*i;j<=300;j++)
			f[j]+=f[j-i*i];
	while(scanf("%d",&n),n)
		printf("%d\n",f[n]);
	return 0;
}
