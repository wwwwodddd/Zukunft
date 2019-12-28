#include<iostream>
using namespace std;
int n,m,t,d,i,j,k,l;
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		printf("Scenario #%d:\n",++l);
		scanf("%d",&n);
		m=n*2+1;
		for(i=0;i<m;i++)
		{
			printf("slice #%d:\n",i+1);
			for(j=0;j<m;j++)
			{
				for(k=0;k<m;k++)
				{
					d=abs(j-n)+abs(k-n);
					if(d+abs(i-n)>n)
						putchar('.');
					else
						printf("%d",d+abs(i-n));
				}
				putchar('\n');
			}
		}
		putchar('\n');
	}
	return 0;
}