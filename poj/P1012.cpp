#include <stdio.h>
int a[14]={0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};
int main()
{
	while(scanf("%d",a)&&*a!=0)
		printf("%d\n",a[*a]);
    return 0;
}

