#include<stdio.h>
int a[30],s[30];
int i,j;
int min(int a,int b)
{
	return a<b?a:b;
}
int F(int x)
{
	int r=0;
	s[0]=x;
	for(int i=1;i<21;i++)
		s[i]=a[i];
	for(int i=1;i<21;i++)
		if(s[i-1])
		{
			s[i-1]^=1;
			s[i]^=1;
			s[i+1]^=1;
			r++;
		}
	return s[20]==0?r:99;
}
int main()
{
	for(i=1;i<21;i++)
		scanf("%d",&a[i]);
	printf("%d",min(F(0),F(1)));
	return 0;
}