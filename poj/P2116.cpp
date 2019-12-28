#include<iostream>
using namespace std;
char s[41],c[41];
int f[43]={1,1};
int i,j,l,ls,lc,a,b,z,m;
void print(int x)
{
	int i=l;
	if(x==0)
	{
		puts("0");
		return;
	}
	else
	{
		while(x<f[i])
		{
			printf(" ");
			i--;
		}
		for(;i>0;i--)
			if(x>=f[i])
			{
				printf("1");
				x-=f[i];
			}
			else
				printf("0");
	}
	printf("\n");
	return;
}
int main()
{
	for(i=2;i<43;i++)
		f[i]=f[i-1]+f[i-2];
	while(scanf("%s %s",s,c)+1)
	{
		ls=strlen(s);
		lc=strlen(c);
		a=b=0;
		for(i=0;i<ls;i++)
			if(s[i]=='1')
				a+=f[ls-i];
		for(j=0;j<lc;j++)
			if(c[j]=='1')
				b+=f[lc-j];
		z=a+b;
		l=42;
		while(z<f[l])
			l--;
		if(z==0)
			l=1;
		m=l;
		printf("  ");
		print(a);
		printf("+ ");
		print(b);
		printf("  ");
		while(m--)
			printf("-");
		printf("\n  ");
		print(z);
		printf("\n");
	}
	return 0;
}