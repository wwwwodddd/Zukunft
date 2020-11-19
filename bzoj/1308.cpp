#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
struct Int{int a[500];}a;
int p[10]={1,1,2,6,4,1,6,2,6,4};
int f[4]={6,2,4,8};
char s[500];
int i;
Int div(Int a)
{
	int i;
	Int re;
	memset(&re,0,sizeof(re));
	for(i=1;i<=a.a[0];i++)
		re.a[i]=a.a[i]*2;
	for(i=1;i<=a.a[0];i++)
	{
		re.a[i+1]+=re.a[i]/10;
		re.a[i]%=10;
	}
	re.a[0]=a.a[0];
	if(re.a[re.a[0]+1])
		re.a[0]++;
	for(i=1;i<re.a[0];i++)
		re.a[i]=re.a[i+1];
	re.a[re.a[0]]=0;
	re.a[0]--;
	return re;
}
int work(Int a)
{
	Int re;
	int x;
	if(a.a[1]==0&&a.a[0]==0)
		return 1;
	re=div(a);
	if(re.a[1]==0&&re.a[0]==0)
		x=1;
	else
		x=f[(re.a[2]*10+re.a[1])%4];
	return work(re)*x*p[a.a[1]]%10;
}
int main()
{
	while(scanf("%s",s)+1)
	{
		memset(&a,0,sizeof(a));
		a.a[0]=strlen(s);
		for(i=0;i<a.a[0];i++)
			a.a[a.a[0]-i]=s[i]-'0';
		printf("%d\n",work(a));
	}
	return 0;
}