#include<stdio.h>
int i,j,k,n,c;
char a[30020];
int check(int x,int y)
{
	if(x>=y)
		return 0;
	if(a[x]<a[y])
		return 0;
	if(a[x]>a[y])
		return 1;
	return check(x+1,y-1);
}
int main()
{
	while(scanf("%d",&n)+1)
	{
		for(i=0;i<n;i++)
			scanf("%s",a+i);
		i=0;
		j=n-1;
		c=1;
		while(i<j)
		{
			if(check(i,j))
			{
				printf("%c",a[j]);
				j--;
			}
			else
			{
				printf("%c",a[i]);
				i++;
			}
			if(c%80==0)
				printf("\n");
			c++;
		}
		printf("%c\n",a[i]);
	}
	return 0;
}