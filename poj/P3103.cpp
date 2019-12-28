#include<stdio.h>
int i,n,x,y,z;
int main()
{
	scanf("%d%d%d%d",&x,&y,&z,&n);
	for(i=0;i<n;i++)
		printf("0 0 %.8f %d %d %.8f\n",1.0*z*i/n,x,y,1.0*(i+1)*z/n);
	return 0;
}
