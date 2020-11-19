#include<stdio.h>
int f[1000020];
int	i,n;
int main()
{
	scanf("%d",&n);
	f[0]=1;
	for(i=1;i<=n;i++)
		if(i&1)
			f[i]=f[i-1];
		else
			f[i]=(f[i-1]+f[i/2])%1000000000;
	if(n<902)
		printf("%d",f[n]);
	else
		printf("%09d",f[n]);
	while(1);
	return 0;
}
