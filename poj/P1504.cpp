#include<stdio.h>
#include<iostream>
using namespace std;
int a[202],b[202];
char c[202],d[202];
void plu()
{
	for(int i=1;i<200;i++)
		a[i]+=b[i];
	for(int i=1;i<200;i++)
	{
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	a[0]=200;
	while(!a[a[0]]&&a[0])
		a[0]--;
	return;
}
void scand(char *s,int *a)
{
	a[0]=strlen(s);	
	for(int i=0;i<a[0];i++)
		a[i+1]=s[i]-'0';
	return;
}
void print()
{
	int i=1;
	while(!a[i])
		i++;
	for(;i<=a[0];i++)
		printf("%d",a[i]);
	printf("\n");
	return;	
}
int main()
{
	int x,i,t;
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		scanf("%s %s",c,d);
		scand(c,a);
		scand(d,b);
		plu();
		print();
	}
	return 0;
}