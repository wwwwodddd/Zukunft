#include<stdio.h>
#include<string.h>
char a[20];
int i,j,k,l,b,n,x;
int r[2000];
int main()
{
	while(scanf("%s%d",a,&n)+1)
	{
		memset(r,0,sizeof r);
		l=b=x=0;
		for(i=0;i<6;i++)
		{
			if(a[i]=='.')
			{
				x=i+1;
				continue;
			}
			else
				b=b*10+a[i]-'0';
		}
		if(x!=0)
			x=6-x;
		r[0]=1;
		for(i=0;i<n;i++)
		{
			for(j=0;j<1000;j++)
				r[j]*=b;
			for(j=0;j<1000;j++)
			{
				r[j+1]+=r[j]/10;
				r[j]%=10;
			}
		}
		k=1000;
		while(!r[k])
			k--;
		while(!r[l]&&l<x*n)
			l++;
		if(k<x*n-1)
		{
			printf(".");
			for(j=x*n-1;j>k&&j>l;j--)
				printf("0");
		}
		for(;k>=l;k--)
		{
			if(k==x*n-1)
				printf(".");
			printf("%d",r[k]);
		}
		puts("");
	}
	return 0;
}
