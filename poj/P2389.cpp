#include<stdio.h>
#include<string.h>
char a[100];
char b[100];
int r[200];
int c[100];
int d[100];
int la,lb,i,j;
int main()
{
	scanf("%s %s",a,b);
	la=strlen(a);
	for(i=la-1;i>=0;i--)
		c[la-i-1]=a[i]-'0';
	lb=strlen(b);
	for(i=lb-1;i>=0;i--)
		d[lb-i-1]=b[i]-'0';
	for(i=0;i<la;i++)
		for(j=0;j<lb;j++)
			r[i+j]+=c[i]*d[j];
	for(i=0;i<100;i++)
	{
		r[i+1]+=r[i]/10;
		r[i]%=10;
	}
	j=120;
	while(!r[j]&&j>=0)
		j--;
	for(;j>=0;j--)
		printf("%d",r[j]);
	return 0;
}