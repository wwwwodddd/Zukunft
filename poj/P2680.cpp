#include<stdio.h>
#include<string.h>
int a[500],n;
int m[1001][500];
void B()
{
	for(int i=1;i<=a[0];i++)
		a[i]<<=1;
	for(int i=1;i<=a[0];i++)
		if(a[i]>9)
		{
			a[i+1]+=a[i]/10;
			a[i]%=10;
		}
	a[0]=499;
	while(!a[a[0]])
		a[0]--;
	return;
}
void div(int *a)
{
	int re=0;
	for(int i=a[0];i>0;i--)
	{
		re=re*10+a[i];
		a[i]=re/3;
		re%=3;
	}
	a[0]=499;
	while(!a[a[0]])
		a[0]--;
	return ;
}
void print(int *a)
{
	for(int i=a[0];i>1;i--)
		printf("%d",a[i]);
	printf("%d\n",a[1]);
	return;
}
int main()
{
	a[0]=a[1]=1;
	for(int i=2;i<1001;i++)
	{
		B();
		memcpy(m[i],a,sizeof(a));
		i&1?m[i][1]--:m[i][1]++;
		div(m[i]);
	}
	while(scanf("%d",&n)+1)
		print(m[n]);
	return 0;
}
//n=2*m时结果为(2^(n-1)+1)/3
//n=2*m+1时结果为(2^(n-1)-1)/3