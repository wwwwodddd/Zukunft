#include<iostream>
using namespace std;
long long p[64],n;
int a[64];
int r,i,m;
void P(int x)
{
	int k=0;
	for(i=0;i<60;i++)
		if(a[i]==x)
			printf("%s%I64d",k?",":"",p[i]),k=1;
	if(!k)
		printf("empty");
}
int main()
{
	p[0]=1;
	for(i=1;i<64;i++)
		p[i]=p[i-1]*3;
	scanf("%d",&m);
	while(m--)
	{
		memset(a,0,sizeof(a));
		scanf("%I64d",&n);
		for(i=0;n!=0;i++)
		{
			a[i]=(n+1)%3-1;
			n=(n-a[i])/3;
		}
		P(-1);
		printf(" ");
		P(1);
		printf("\n");
	}
}