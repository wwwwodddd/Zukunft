#include<stdio.h>
int v[1000020],n,c;
int main()
{
	for(int i=2,j;i<=1000000;i++)
		if(!v[i])
			for(j=i,c++;j<1000000;j+=i)
				v[j]=c;
	while(~scanf("%d",&n))
		printf("%d\n",v[n]);
}
