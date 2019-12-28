#include<stdio.h>
#include<math.h>
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
char s[100];
int main()
{
	int m,k,n,a,b,i,j,x,y,l;
	while(scanf("%s",s),s[1])
	{
		x=y=1000000000;
		for(i=2,n=0,l=0;s[i]!='.';i++)
		{
			n=n*10+s[i]-48;
			l++;
		}
		for(m=n,k=1,i=1;i<=l;i++)
		{
			m/=10;
			k*=10;
			a=n-m;
			b=(int)pow(10.0,l-i)*(k-1);
			j=gcd(a,b);
			if(b/j<y)
				x=a/j,y=b/j;
		}
		printf("%d%c%d\n",x,'/',y);
	}
	return 0;
}
