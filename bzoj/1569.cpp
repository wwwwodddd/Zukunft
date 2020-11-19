#include<stdio.h>
int i,j,n,x,y,z,a,b;
int main()
{
	scanf("%d %d %d %d %d %d",&n,&x,&y,&z,&a,&b);
	a+=((b-1)/y+1)*x;
	for(i=0;i<50;i++)
		for(j=0;j<i/3+2;j++)
		{
			int sm=0;
			int l=j;
			int m=-1;
			int nn=n;
			int k;
			for(k=0;k<i;k++)
			{
				m--;
				if(m==0)
					nn++;
				if(m<=0&&l&&sm>=z)
				{
					sm-=z;
					m=3;
					l--;
				}
				sm+=nn*x;
			}
			if(sm>=a)
				goto end;
		}
	end:
	printf("%d",i);
	return 0;
}
