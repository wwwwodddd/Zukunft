#include<stdio.h>
double a[10020],sum;
char s[10020];
int c[30],i,n;
int main()
{
	scanf("%s",s);
	for(i=0;s[i];i++)
		c[s[i]-'A']++;
	n=i;
	a[1]=(double)(n-1)*(n-1)/n;
	for(i=1;i<n;i++)
		a[i+1]=2*a[i]-a[i-1]-(n-1.)/(n-i);
	for(i=0;i<26;i++)
		sum+=a[c[i]];
	printf("%.1lf",sum);
	return 0;
}