#include<stdio.h>
#include<math.h>
int n,m,r;
int a[100];
int *p=a;
int main()
{
	r=-2;
	scanf("%d",&n);
	if(n!=0)
	{
		while(n!=0)
		{
			m=n/r;
			*p=n-m*r;
			if(*p<0)
			{
				*p=*p+abs(r);
				m++;
			}
			p++;
			n=m;
		}
		for(m=p-a-1;m>=0;m--)
			printf("%d",a[m]);
	}
	else
		printf("0");
	return 0;
}