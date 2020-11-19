#include<stdio.h>
int f[300]={1},n;
int main()
{
	for(int i=1;i<300;i+=2)
		for(int j=300;j>=i;j--)
			f[j]+=f[j-i];
	while(~scanf("%d",&n))
		printf("%d\n",f[n]);
	return 0;
}
