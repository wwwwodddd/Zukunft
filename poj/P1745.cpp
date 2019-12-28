#include<stdio.h>
#include<string.h>
int a[2][200];
int main()
{
	int n,i,j,k,l;
	scanf("%d %d",&n,&k);
	a[0][0]=1;
	for(i=0;i<n;i++)
	{
		memset(a[1^i&1],0,sizeof(a[0]));
		scanf("%d",&j);
		if(j<0)
			j=-j;
		j%=k;
		for(l=k;l<k+k;l++)
			if(a[i&1][l%k])
				a[1^i&1][(l-j)%k]=a[1^i&1][(l+j)%k]=1;
	}
	printf("%s\n",a[i&1][0]==1?"Divisible":"Not divisible");
	return 0;
}