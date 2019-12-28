#include<stdio.h>
int i,j,k,l,n,x;
int main()
{
	freopen("C:\\c2.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=2;j<=i;j++)
			for(k=j;k<=i;k++)
			{
				x=i*i*i-j*j*j-k*k*k;
				for(l=k;l<=i;l++)
					if(l*l*l==x)
						printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,l);
			}
	return 0;
}