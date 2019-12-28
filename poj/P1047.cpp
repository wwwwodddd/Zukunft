#include<stdio.h>
#include<string.h>
int a[120],b[120],c[12],d[12];
char s[120];
int ans;
void multipy(int x)
{
	for(int i=1;i<=a[0];i++)
		b[i]=a[i]*x;
	for(int i=1;i<=a[0]+10;i++)
	{
		b[i+1]+=b[i]/10;
		b[i]%=10;
	}
	b[0]=a[0];
	return;
}
void count(int *x,int *y)
{
	for(int i=y[0];i>0;i--)
		x[y[i]]++;
	return;
}
int check(int x)
{
	multipy(x);
	memset(d,0,sizeof(d));
	count(d,b);
	for(int i=0;i<10;i++)
		if(c[i]!=d[i])
			return 0;
	return 1;
}
void sscan(int *a,char *s)
{
	a[0]=strlen(s);
	for(int i=a[0];i>0;i--)
		a[i]=s[a[0]-i]-'0';
	return;
}
int main()
{
	while(scanf("%s",s)!=EOF)
	{
		ans=1;
		sscan(a,s);
		memset(c,0,sizeof(c));
		count(c,a);
		for(int i=1;i<=a[0];i++)
			if(!check(i))
			{
				ans=0;
				break;
			}
		printf("%s is%s cyclic\n",s,ans==1?"":" not");
	}
	return 0;
}