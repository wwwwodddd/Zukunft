#include<stdio.h>
int f[3200]={0,1},n;
int main()
{
	for(int i=2;i<3186;i++)
		f[i]=(f[i-1]+2*f[i-2]+1)%200907;
	while(scanf("%d",&n),n)
		printf("%d\n",f[n%3186]);
	return 0;
}
